class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < n - 2; ++i) {
            // Ayn� say�y� tekrarlamamak i�in kontrol
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target-sum) < abs(target-closest)) 
                    closest = sum;
                if (sum<target) 
                    ++left;
                else if(sum>target)
                    --right;
                else 
                    return closest;
            }
        }

        return closest;
    }
};
