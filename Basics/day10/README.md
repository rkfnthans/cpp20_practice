# Day 10 — RAII, `shared_ptr`, and Custom Deleters

## Topic

RAII, `shared_ptr`, and custom deleters using a simplified `GameWorld` and `NPC` example.

## What I Studied

- `GameWorld` manages the creation and removal of `NPC` objects.
- `spawnNPC()` creates a new `NPC` on the heap and returns its address as `NPC*`.
- A raw pointer stores the address of an object.
- `->` accesses a member through a pointer.
- `shared_ptr` manages the lifetime of an object.
- Multiple `shared_ptr` objects can share ownership of the same object.
- The managed object is destroyed when the last shared owner disappears.
- `use_count()` shows the current number of shared owners.
- A custom deleter defines how a `shared_ptr` should clean up the object it manages.
- `operator()` allows an object to be called like a function.
- A custom NPC deleter can keep `GameWorld` alive while an NPC may still need to be removed through that world.
- Each `shared_ptr<NPC>` manages one specific NPC object.
- NPCs can have the same name while still being separate objects at different memory addresses.
- RAII connects resource lifetime to object lifetime.

## `spawnNPC()`

```cpp
NPC* spawnNPC(const string& name)
{
    return new NPC{name};
}
```

`spawnNPC()` dynamically creates a new `NPC` object and returns the address of that object as `NPC*`.

Conceptually:

```text
spawnNPC("Goblin")
-> new NPC{"Goblin"}
-> create an NPC on the heap
-> return its address
```

## Pointer Member Access

A raw pointer stores an object's address.

The `->` operator accesses a member through a pointer.

```cpp
world->spawnNPC("Goblin");
```

Conceptually:

```text
world
-> the GameWorld object it points to
-> spawnNPC()
```

## `shared_ptr`

`shared_ptr` manages shared ownership of an object.

Multiple `shared_ptr` objects may refer to the same managed object. The object remains alive while at least one shared owner exists.

`use_count()` can be used to inspect the current number of shared owners.

## Custom Deleter

A custom deleter specifies how the managed object should be cleaned up.

```cpp
struct npc_deleter
{
    shared_ptr<GameWorld> world;

    void operator()(NPC* npc) const
    {
        world->removeNPC(npc);
    }
};
```

`operator()` makes `npc_deleter` callable like a function.

When the custom deleter receives an `NPC*`, it asks the associated `GameWorld` to remove that specific NPC.

## Why the Deleter Stores `shared_ptr<GameWorld>`

```cpp
shared_ptr<GameWorld> world;
```

The deleter stores shared ownership of the `GameWorld` because the world must remain alive while an NPC may still need to be removed through:

```cpp
world->removeNPC(npc);
```

This creates an object-lifetime dependency:

```text
NPC may still need removal
-> npc_deleter may still need GameWorld
-> GameWorld must remain alive
```

## Managing an NPC

```cpp
shared_ptr<NPC> goblin{
    world->spawnNPC("Goblin"),
    npc_deleter{world}
};
```

This combines:

```text
managed object
-> NPC* returned by spawnNPC()

cleanup rule
-> npc_deleter{world}
```

The NPC is managed through `shared_ptr`, while the custom deleter defines how it should be removed.

## Object Identity

Two NPCs may both have:

```text
name = "Goblin"
```

and still be different objects because they are stored at different memory addresses.

The name is object data; it is not the object's identity in memory.

## RAII Flow

```text
create GameWorld
-> create NPC
-> shared_ptr manages NPC
-> custom deleter keeps GameWorld alive
-> last NPC owner disappears
-> npc_deleter is called
-> GameWorld::removeNPC()
-> NPC is destroyed
-> GameWorld is destroyed when its last owner disappears
```

## Key Idea

RAII connects resource lifetime to object lifetime.

```text
object/resource is acquired
-> object is used
-> ownership ends
-> cleanup happens automatically
```

In this practice, `shared_ptr` and the custom deleter are used to connect NPC cleanup to ownership lifetime rather than requiring manual cleanup at every exit path.
