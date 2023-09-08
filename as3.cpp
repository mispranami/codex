#include<iostream>
using namespace std;
int main()
{
    int num1;
    int num2;
    int num3;
    cout<<"enter 1st number \n";
    cin>>num1;
    cout<<"enter 2nd number \n";
    cin>>num2;
    cout<<"enter 3rd number \n";
    cin>>num3;
    if(num1>=num2 && num1>=num3)
    {
        cout<<"greatest number is \n"<<num1;
    }
    else if(num2>=num3 && num2>=num1)
    {
        cout<<"greatest number is \n"<<num2;
    }
    else if(num3>=num1 && num3>=num2)
    {
        cout<<"greatest number is \n"<<num3;
    }
    
    return 0;

}

