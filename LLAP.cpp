/* Given a set of numbers we have to find the longest subsequence which is in AP

We can solve this problem in O(n^3) by using a simple approach.
We will consider every pair as first two number of AP and we will check out other numbers in sorted set.

for example:
   set[] = {1, 7, 10, 15, 27, 29}
   
   take {1,7} as first pair.
   a = 1;   // first element
   a1 = 7;   //second element
   d = a1 -a = 6;  //common difference
   
   now a2 = a1 + d;
       a2 = 7 + 6 = 13;
       now search for 13 in the sequence {10,15,27,29} 
       it is not present so the ans = 2;
       
       if sequence would have {1,7,10,13,17,19,20}
       we would get 13 in the sequence so ans++;
       now a3 = a2+6 = 19;
       now 19 is present so ans++;
       now a4 = a3+6 = 25. not present and list finished ans = 4 till now.
       
       now check this for each pair for which we required 3 loops .
       
       
      2nd APPROACH - DYNAMIC PROGRAMMING 
      
      CHECK FOR THE DESCRIPTION ----> http://www.geeksforgeeks.org/length-of-the-longest-arithmatic-progression-in-a-sorted-array/
     
 */
       #include <iostream>
#include <vector>
using namespace std;

int solve_longest_ap(vector <int> &v , int length)
{
	// vector < vector<int> > L (length, vector<int>(length ,-1)) ;
    int N,M;
   int llap = 2;
      N = M = length;
	 vector< vector<int> > L(N, vector<int>(M, 0)); 
	
	for(int i=0; i < length; i++)
	  L[i][length-1] = 2;
		
		for(int j = length - 2 ; j >= 1 ; j--)
		{  
			int i = j - 1 ;
			int k = j + 1 ;
			

			while(i>=0 & k<length)
			{   
				if(v[i]+v[k]<2*v[j])
				{
					k++;
				}
				else if (v[i]+v[k]>2*v[j])
				{
					L[i][j] = 2;
					i--;
				}
				else if((v[i]+v[k])==2*v[j])
				{    
					L[i][j] = L[j][k] + 1;
                    llap = max(llap,L[i][j]);
					i--; 
				 k++;
				}

            }

            while(i>=0)
            {   
            	L[i][j] = 2;
            	i--;
            }

		}



	return llap;
}
int main()
{   
	int arr[] = {2, 4, 6, 8, 10 , 13 , 14 ,16 , 18};

	vector <int> v (arr, arr+sizeof arr / sizeof arr[0]);

	int length = sizeof arr/ sizeof arr[0];

    int longest_ap = solve_longest_ap(v ,length);

    cout<<longest_ap;

	return 0;
}
   
   
