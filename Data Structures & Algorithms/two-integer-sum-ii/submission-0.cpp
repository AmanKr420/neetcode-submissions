class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int left=0;
        int right=numbers.size()-1;
        while(left<right)
        {
            if(numbers[left]+numbers[right]==target)
                break;
            if(numbers[left]+numbers[right]>target)
                right--;
            if(numbers[left]+numbers[right]<target)
                left++;
        }
        ans[0]=left+1;
        ans[1]=right+1;
        return ans;
    }
};
