	using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int same;
        same = nums[0];
        vector<int> removed;
        removed.push_back(same);

        for(int i=1; i<nums.size(); ++i){
            if(same != nums[i]){
                same = nums[i];
                removed.push_back(same);
            }
        }

        nums = removed;
        return nums.size();
    }
};
