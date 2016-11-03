#include <iostream>
#include <algorithm>
using namespace std;
int knapsack(int W,int val[],int w[],int n)
{    //Base cases W is the size of knapsack. n is the number of items we have added .
	 // definitely if W == 0 value = 0 or n ==0 value = 0;
     if(W==0||n==0)
     {
     	return 0;
     }
    else if(w[n-1]>W) return knapsack(W,val,w,n-1); //if the given knapsack weight is greater than the whole knapsack size 
     											 //then we will not consider this weight 

    else 
    	return max(val[n-1]+knapsack(W-w[n-1],val,w,n-1),knapsack(W,val,w,n-1));

}
int main()
{
    int val[] = {60,100,120};
    int w[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(int);
    int ans = knapsack(W,val,w,3);
    cout<<ans;

	return 0;
}
