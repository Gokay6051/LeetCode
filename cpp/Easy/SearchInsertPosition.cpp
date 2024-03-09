class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }

    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low == high){
            if(nums[low] == target || nums[low] > target)
                return low;
            return low+1;
        }

        int mid = low + (high-low)/2;

        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target){
            if(mid > 0 && nums[mid-1] < target)
                return mid;
            return binarySearch(nums, target, low, mid);
        }
        else if(nums[mid] < target){
            if(mid < nums.size()-1 && nums[mid+1] > target)
                return mid+1;
            return binarySearch(nums, target, mid+1, high);
        }

        return -1;
    }
};
