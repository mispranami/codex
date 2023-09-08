#include<iostream>

using namespace std;
int main()
{
  float a;
  float b;
  cout<<"enter 1st number";
  cin>>a;
  cout<<"enter 2nd number";
  cin>>b;
  char ch;
  cout<<"enter operator";
  cin>>ch;
  switch (ch)
  {
case '+':

  cin>>b;
    cout<<a+b;
    break;
case '-':
   cout<<a-b;
case '*':
  cout<<a*b;
case '/':
 cout<<a/b;
case 'A':
 float c;
 cout<<"enter no.";
 cin>>c;
if(c>0)
{ cout<<c;
}
else if(c<0)
{ 
    c=c*(-1);
cout<<c;
}
else 
cout<<c; 
  default:
   cout<<"error";
    break;
  }
}