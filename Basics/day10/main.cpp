#include <iostream>
#include <string>

using namespace std;

class NPC
{
    private:
        string name;

    public:
        NPC(const string& n)
            :name{n}
        {
            cout<<name<<" created\n";
        }

        ~NPC()
        {
            cout<<name<<" destroyed\n";
        }

};

int main()
{
    cout<<"A\n";

    {
        NPC goblin{"Goblin"};
        cout<<"B\n";
    }

    cout<<"C\n";
}