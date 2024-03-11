#include<iostream>
#include "maths.h"
using namespace std;

int main()
{
	math obj;
	int a, b;
	cout<<"enter two numbers to add : ";
	cin>>a>>b;
	cout<<"The addition of  "<<a<<" and "<<b<<" is : "<<obj.add(a, b)<<endl;
	cout<<"\nenter first number for subtraction : ";
	cin>>a;
	cout<<"enter second number for subtraction : ";
	cin>>b;
	cout<<"The subtraction  "<<a<<" - "<<b<<" is : "<<obj.sub(a, b)<<endl;
	cout<<"\nenter two numbers to multiply : ";
	cin>>a>>b;
	cout<<"The multiplication of  "<<a<<" and "<<b<<" is : "<<obj.mul(a, b)<<endl;
	cout<<"\nenter the base number : ";
	cin>>a;
	cout<<"enter the index number : ";
	cin>>b;
	cout<<"The value of  "<<a<<" raise to "<<b<<" is : "<<obj.pow(a, b)<<endl;
	cout<<"\nenter the divident : ";
	cin>>a;
	cout<<"enter the divisor :";
	cin>>b;
	cout<<"The floor division of  "<<a<<" divided by "<<b<<" is : "<<obj.div(a, b)<<endl;
	return 0;
}
