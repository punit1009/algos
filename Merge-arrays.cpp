#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> merge(vector<int>& X, vector<int>& Y)
    {   
    	int i =0;
    	int j = 0;
    	int t = X.size();
    	int k = Y.size();
        while(t>0 && k>0){
        	if(X[i]==0 ){
        		X[i]=Y[j++];
        		t--;
        		k--;
        	}
        	
        	i++;
        }
             sort(X.begin(), X.end());
             return X;
    }
};
