//NPC's day life

#include <iostream>
#include <string>
using namespace std;

struct NPC
{
    string name;
    int hunger;
    int energy;
    int food;
};

void pass_time(NPC& npc)
{
    npc.hunger+=15;
    npc.energy-=10;

    if (npc.hunger>100)
    {
        npc.hunger=100;
    }

    if (npc.energy<0)
    {
        npc.energy=0;
    }
}

void eat(NPC& npc)
{
    if(npc.food >0)
    {
        npc.food-=1;
        if (npc.hunger>=40)
        {
            npc.hunger-=40;
        }    
        else
        {
            npc.hunger=0;
        }

        cout<<npc.name<<"eats food.\n";
    }
    else
    {
        cout<<npc.name<<"has no food.\n";
    }
}

void rest(NPC& npc)
{
    if (npc.energy<100)
    {
        
        if (npc.energy<=50)
        {
            npc.energy+=50;
        }
        else
        {
            npc.energy=100;
        }

        cout<<npc.name<<"gains energy.\n";
    }
    else
    {
        cout<<npc.name<<"doesn't need to rest.\n";
    }
}
void work(NPC& npc)
{
    if (npc.energy>0)
    {
        if (npc.energy>=40)
        {
            npc.energy-=40;
            npc.food+=2;
            cout<<npc.name<<"works hard.\n";
        }
        else
        {
            cout<<npc.name<<"has not enough energy.\n";
        }
    }
    else
    {
        cout<<npc.name<<"has no energy.\n You need to rest.\n";
    }
}
bool choose_action(NPC& npc)
{
    string command;

    cout<<"Choose action: ";
    cin>>command;

    if (command=="eat")
    {
        eat(npc);
        return true;
    }
    else if (command=="rest")
    {
        rest(npc);
        return true;
    }
    else if (command=="work")
    {
        work(npc);
        return true;
    }
    else
    {
        cout<<"Unknown action.\n";
        cout<<"Choose again.\n";
        return false;
    }
    
}
void print_status(NPC& npc)
{
    cout<<"NAME : "<<npc.name<<'\n';
    cout<<"Hunger : "<<npc.hunger<<'\n';
    cout<<"Energy : "<<npc.energy<<'\n';
    cout<<"Food : "<<npc.food<<'\n';
}

int main()
{
    NPC npc{"Jack",70,50,2};

    const int simulation_days(7);

    for (int day(1); day<=simulation_days;)
    {
        cout<<"\n=======================\n";
        cout<<"\n========day "<<day<<"=========\n";
        cout<<"========================\n";

        print_status(npc);

        bool action_completed{choose_action(npc)};

        if (!action_completed)
        {
            continue;
        }
        else
        {
            pass_time(npc);
            ++day;
        }
        

    }

    cout<<"\n====================\n";
    cout<<"Final Status\n";
    cout<<"=====================\n";

    print_status(npc);

    cout<<"Simulation Ended.\n";

    return 0;

}