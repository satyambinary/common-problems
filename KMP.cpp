/*input
aabaabaaa
aaadffggaabaabaaabbbb
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void knuth_morrish_pratt(string text,string pattern,vector <int> F)
{
	int m = F.size() - 1;
	int n = text.size();
	cout<<" ";
	/* for(int i=1;i<=m;i++)
    {
    	cout<<F[i];
    }*/
    int i = 0, j = 0;
    for( ; ;)
    {
    	if(j==n) break;

    	if(text[j] == pattern[i])
    	{
    		i++;
    		j++;
    		if(i==m) {
    			cout<<"Match found at "<<j-m;
    				}
    	}

    	else if(i>0) i = F[i];

    	else j++;

    }
}
void failure_function(string text,string pattern)
{ 
	int m = pattern.size();
	
	vector <int> F(m+1);
    F[0] = F[1] = 0;
    F[1] = 0;
 		int j;

    for(int i=2; i<=m ; i++)
        {
        	j = F[i-1];

        	while(true)
        	{
        		if(pattern[j]==pattern[i-1])
        		
        			{ F[i] = j + 1 ;
        			  break;
        			}
        		
        		 if(j==0) { F[i] = 0 ; break; }

        		j = F[j];


        	}
    }
   /* for(int i=1;i<=m;i++)
    {
    	cout<<F[i];
    }*/
    knuth_morrish_pratt(text,pattern,F);


}

int main()
{ 
	string pattern,text;
	cin>>pattern;
	cin>>text;
	// cout<<pattern;

	failure_function(text,pattern);


	return 0;
}
