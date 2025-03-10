/*

The Longest Bitonic Subarray (LBS) problem is to find a contiguous subarray of a given sequence in which the subarray’s elements are first sorted in increasing order, then in decreasing order, and the subarray is as long as possible.

Input : [3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4]
Output: [4, 5, 9, 10, 8, 5, 3]

In case the multiple bitonic subarrays of maximum length exists, the solution can return any one of them.

Input : [-5, -1, 0, 2, 1, 6, 5, 4, 2]
Output: [-5, -1, 0, 2, 1] or [1, 6, 5, 4, 2]

*/

class Solution
{
public:
	vector<int> findBitonicSubarray(vector<int> const &nums)
	{
		// Write your code here...
		int inc = 0;
		int dec = 0;
		int start=0;
		int end=0;
		int count =1;
		
		vector<int>result;
		int max =0;
		int maxstart;
		
		if(nums.size()<3){
			return nums;
		}
		
		for(int i = 0; i < nums.size()-1;i++){
				if(nums[i] < nums[i+1] ){
					if(dec==1){
						count=1;
						dec=0;
					}
					if(count==1){
						start =i;
						end =0;
					}
					
					end =  start;
					end++;
					inc = 1;
					count++;
					if(max<count){
						max=count;
						maxstart = start;
					}
					
				}
				else if(nums[i] > nums[i+1] && inc ==1){
					end++;
					count++;
					if(max<count){
						max=count;
						maxstart = start;
					}
					dec=1;
				}
				else if(nums[i] > nums[i+1] && inc==0){
					if(count==1){
						start =i;
						end=0;
					}
					end =  start;
					end++;
					count++;
					if(max<count){
						max=count;
						maxstart=start;
					}
					dec =1;
				}else{
					start = i;
					count = 1;
                	inc = 0;
                	dec = 0;
                	if(max<count){
						max=count;
						maxstart=start;
					}

				}

		}
		
		for(int i =0; i<max;i++){
			result.push_back(nums[maxstart+i]);
		}
		
		return result;

	}
};
