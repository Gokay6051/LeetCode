class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findMax(nums, 0, nums.size()-1);
    }
    
    int findMax(vector<int>& nums, int left, int right){
        if(left==right)
            return nums[left];
        
        int mid = left + (right-left)/2;

        int rightMax = findMax(nums, mid+1, right);
        int leftMax = findMax(nums, left, mid);
        int _crossMax = crossMax(nums, left, right, mid);

        return max({rightMax, leftMax, _crossMax});
    }

    int crossMax(vector<int>& nums, int left, int right, int mid){
        int rightSum = INT_MIN;
        int leftSum = INT_MIN;
        int sum = 0;

        for(int i=mid; i>=left; --i){
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;

        for(int i=mid+1; i<=right; ++i){
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return rightSum + leftSum;
    }
};
