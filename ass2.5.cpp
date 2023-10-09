#include<iostream>
using namespace std;
int main()
{
    int p;
    const int pass=1234;
    do
    {
       cout<<"enter password "<<endl;
       cin>>p;
    } while (pass!=p );
    cout<<"you entered correct password"<<endl;
    return 0;

}
