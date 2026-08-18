#include <iostream>
#include <string>
using namespace std;


int main()
{
    try
    {
        int month, day;
        cout<<"월을 입력하세요: ";
        cin>>month;
        cout<<"일을 입력하세요: ";
        cin>>day;

        if (month<1 or month>12)
        {
            
            throw 1;
        }
        if (month>=3 and month<=5)
        {
            cout<<"봄";
        }
        if (month>=6 and month<=8)
        {
            cout<<"여름";
        }
        if (month >=9 and month<=11)
        {
            cout<<"가을";
        }
        if (month==12 or (month<=2 and month>=1))
        {
            cout <<"겨울";
        }
        
    }
    catch(int a)
    {
        std::cout<<"out_of_range";
    }
    catch(char[])
    {
        cout<<"입력하신 날짜의 계절은 "<<char[]<<"입니다.\n";
    }
    
    return 0;
}



/*
[DAY 07 NOTES]

1)
- TOPIC: Exception handling

- try: code that may fail
- throw: raises an exception
- catch: handles the exception

- Flow: try -> throw -> matching catch
- Code after throw is skipped.

Examples:
- int   -> catch(int)
- float -> catch(float)
- char  -> catch(char)

2)
- TOPIC: Exception handling with input validation

- Invalid input can be handled with throw and catch.
- Store the normal result in a variable, then print once after the if statements.
- Use if / else if when only one condition should be selected.

Flow:
input
-> validate
-> throw if invalid
-> set season
-> print result
*/