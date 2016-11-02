/*input
3
16
32
96
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
	int n,lcm;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
      int first = a[0],second;

     for(int i=1;i<n;i++)
     {  
     	 second = a[i];

     	 lcm = first*second/gcd(first,second);
     	 first = lcm;
     }
     cout<<lcm;

    



	return 0;
}
