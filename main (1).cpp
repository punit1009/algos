class Solution
{
public:
    void sortArray(vector<int> &nums)
    {
        int a;
        int b;
        int flag1 = 0;
        int flag2 = 0;
        int len = nums.size()-1;
        
        for(int i = 0; i <= len;i++) {
            if(nums[i] == 0 && flag1 == 0) {
                continue;
            }
            else if(nums[i] == 1 && flag1 == 0) {
                a = i;
                flag1 = 1;  
                continue;
            }
            else if(nums[i] == 0 && flag1 == 1) {
                swap(nums[a], nums[i]);  
                i = a;
                if(nums[a] != 1) flag1 = 0;
            }
            else if(nums[i] == 1 && flag1 == 1) {
                continue;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[len--]); 

            }
        }
    }
    
    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }
};