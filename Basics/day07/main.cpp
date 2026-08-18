#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    try
    {
        double a, b, c;
        char op;

        cout<<"첫 번째 숫자 입력 : ";
        cin>>a;
        cout<<"연산자 입력 : ";
        cin>>op;
        cout<<"두 번째 숫자 입력 : ";
        cin>>b;

        
        if (op=='+')
        {
            c=a+b;
            cout<<"결과 : "<<c<<'\n';
        }
        else if (op=='-')
        {
            c=a-b;
            cout<<"결과 : "<<c<<'\n';
        }
        else if (op=='*')
        {
            c=a*b;
            cout<<"결과 : "<<c<<'\n';
        }
        else if (op=='/')
        {
            if (b==0)
            {
                throw 1;
            }
            c=a/b;
            cout<<"결과 : "<<c<<'\n';
            
        }
        else
        {
            throw 2;
        }
    }
    catch(int error)
    {
        if (error==1)
        {
            cout<<"0으로 나눌수 없습니다.\n";
        }
        else if (error==2)
        {
            cout<<"잘못된 연산자입니다.\n";
        }
    }

    return 0;
    
}



/*
[DAY 07 NOTES]

- TOPIC: Exception handling
- MATERIAL: Do it! C++ Complete Guide

- try: code that may cause an exception
- throw: raises an exception
- catch: handles the exception

- Flow: try -> throw -> catch
- Code after throw is skipped.
- catch matches the thrown type.

- Exceptions can be used for invalid input or invalid operations.
- Multiple error cases can be handled with one catch using different values.

Examples:
- throw 1; -> division by zero
- throw 2; -> invalid operator

- '=' is assignment.
- '==' is comparison.
*/