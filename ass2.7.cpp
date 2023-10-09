#include<iostream>
using namespace std;

int main()
{ 
    cout<<"even numbers between 1 to 20 (except 10) are;"<<endl;
    for (int i = 1; i <=20; i++)
    {
       if(i%2==0)
       {
        if (i==10)
        {
            continue;
        }
        else
        {
            cout<<i<<endl;
        }
       



        
       }
    }
    
}