//NPC Target Manager practice

#include <iostream>
#include <string>

using namespace std;

struct NPC
{
    string name;
    int health;

};

void print_npc(const NPC& npc)
{
    cout << "\n-- NPC 상태 --\n";
    cout << "이름: " << npc.name << '\n';
    cout << "체력: " << npc.health << '\n';
}

void take_damage(NPC* target, int damage)
{
    static int attack_count{0};
    ++attack_count;

    (*target).health -= damage;

    if ((*target).health < 0)
    {
        (*target).health = 0;
    }

    cout << target->name << "이(가) "<< damage << "의 피해를 받았습니다.\n";

    cout << "누적 공격 횟수: "<< attack_count << '\n';
}

void heal(NPC& target, int amount)
{
    target.health += amount;

    if (target.health > 100)
    {
        target.health = 100;
    }

    cout << target.name << "이(가) "<< amount << "만큼 회복했습니다.\n";
}

int main()
{
    NPC civil{"Civil", 100};

    NPC* current_target{&civil};

    print_npc(civil);

    int damage{};

    cout<<"\n입힐 피해량: ";
    cin>>damage;

    take_damage(current_target, damage);

    print_npc(civil);
    
    int heal_amount{};

    cout<<"\n회복량: ";
    cin>>heal_amount;

    heal(civil, heal_amount);

    print_npc(civil);

    return 0;

}