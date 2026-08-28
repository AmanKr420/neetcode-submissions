class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int prodLeft = 1,prodRight=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++)
        {
            ans[i]=prodLeft;
            prodLeft*=nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {

            ans[i] *= prodRight;

            prodRight *= nums[i];
        }

        return ans;
    }
};
