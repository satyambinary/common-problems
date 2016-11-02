/*
This program is to calculate the gcd of two numbers by using Euclidean algorithm
*/
#include <iostream>
#include <vector>

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else 
		gcd(a,a%b);
}
int main()
{ 
	
   int  a, b;
	cin>>a,b;
 
	int gc = gcd(a,b);

	cout<<gc;
  

	return 0;
}
