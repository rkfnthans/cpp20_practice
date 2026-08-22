#include <iostream>
#include <string>
#include <memory>

using namespace std;

class NPC
{
    public:
        string name;

    NPC(const string& n)
        :name{n}
    {
        cout<<name<<" spawned\n";
    }
};

class GameWorld
{
    public:
        GameWorld()
        {
            cout<<"GameWorld created\n";
        }
        ~GameWorld()
        {
            cout<<"GameWorld destroyed\n";
        }
        NPC* spawnNPC(const string& name)
        {
            return new NPC{name};
        }

        void removeNPC(NPC* npc)
        {
            cout<<npc->name<<" removed form world\n";
            delete npc;
        }
};

struct npc_deleter
{
    shared_ptr<GameWorld> world;

    void operator()(NPC* npc) const
    {
        world->removeNPC(npc);
    }
};

int main()
{
    auto world{make_shared<GameWorld>()};

    shared_ptr<NPC> goblin{
        world->spawnNPC("Goblin"),
        npc_deleter{world}
    };

    cout<<"Battle Started\n";

    return 0;
}

/*
[DAY 10 NOTES]

- TOPIC: RAII, shared_ptr, and custom deleters

- GameWorld manages the creation and removal of NPC objects.

- spawnNPC() creates a new NPC on the heap
  and returns its address as NPC*.

Example:
NPC* spawnNPC(const string& name)
{
    return new NPC{name};
}

- A raw pointer stores the address of an object.
- '->' accesses a member through a pointer.

Example:
world->spawnNPC("Goblin");

- shared_ptr manages the lifetime of an object.
- Multiple shared_ptr objects can share ownership of the same object.
- The managed object is destroyed when the last owner disappears.

- use_count() shows the current number of shared owners.

- A custom deleter defines how a shared_ptr should
  clean up the object it manages.

Example:
struct npc_deleter
{
    shared_ptr<GameWorld> world;

    void operator()(NPC* npc) const
    {
        world->removeNPC(npc);
    }
};

- operator() allows an object to be called like a function.

- npc_deleter stores a shared_ptr<GameWorld>
  because GameWorld must remain alive while an NPC
  may still need to be removed through GameWorld.

- Each shared_ptr<NPC> manages one specific NPC object.
- NPCs may have the same name but still be different objects
  because they exist at different memory addresses.

Example:
shared_ptr<NPC> goblin{
    world->spawnNPC("Goblin"),
    npc_deleter{world}
};

Flow:
create GameWorld
-> create NPC
-> shared_ptr manages NPC
-> custom deleter keeps GameWorld alive
-> last NPC owner disappears
-> npc_deleter is called
-> GameWorld::removeNPC()
-> NPC is destroyed
-> GameWorld is destroyed when its last owner disappears

- RAII connects resource lifetime to object lifetime.
- Resources are acquired when objects are created
  and released automatically when object ownership ends.
*/