/*input
4
12
*/
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else 
		gcd(a,a%b);
}

int main()
{
   int a,b;
   cin>>a>>b;

     int lcm = a*b/gcd(a,b);

     cout<<lcm;


	return 0;
}
