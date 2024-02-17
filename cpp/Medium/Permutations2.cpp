class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> newPermute;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());

        backTrack(newPermute, nums, current, used);

        return newPermute;
    }

    void backTrack(vector<vector<int>>& newPermute, vector<int>& nums, vector<int> current, vector<bool> used){
        /*for(int k=0; k<current.size(); ++k){
            cout << current[k] << " ";
        }
        cout << endl;*/

        if(current.size() == nums.size()){
            newPermute.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) // Skip if it's used or a duplicate but the previous duplicate isn't used
                continue;
            
                used[i] = true;
                current.push_back(nums[i]);
                backTrack(newPermute, nums, current, used);
                current.pop_back();
                used[i] = false;    
        }
    }
};
