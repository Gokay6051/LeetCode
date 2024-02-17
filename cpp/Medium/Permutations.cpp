class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> newPermute;
        vector<bool> used(nums.size(), false);

        backTrack(newPermute, nums, current, used);

        return newPermute;
    }

    void backTrack(vector<vector<int>>& newPermute, vector<int>& nums, vector<int> current, vector<bool> used){
        if(current.size() == nums.size()){
            newPermute.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                used[i] = true;
                current.push_back(nums[i]);
                backTrack(newPermute, nums, current, used);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
