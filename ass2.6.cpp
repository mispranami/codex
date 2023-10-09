#include<iostream>
using namespace std;
int main() 
{
    int n;
    int c=0;
    cout<<"firts 5 prime numbers are:"<<endl; 
     for (int i = 2; i < 15; i++)
     {
       int t=0;
        for(int j=2;j<i;j++)
        {

            if(i%j==0)
            t++;
        }
        if(t==0)
        {
            cout<<i<<endl;
            c++;

        }
        if (c==5)
        {
         break;
        }
        
     }

     

}

