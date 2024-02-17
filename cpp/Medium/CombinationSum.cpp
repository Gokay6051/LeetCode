class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findSum(result, candidates, target, 0, current, 0);
        return result;
    }

    void findSum(vector<vector<int>> &result, vector<int>& candidates, int target, int sum, vector<int> current, int i){
        if(sum==target){
            result.push_back(current);
            return;
        }
        if(sum>target)
            return;
        
        while(i<candidates.size()){
            current.push_back(candidates[i]);
            sum += candidates[i];
            findSum(result, candidates, target, sum, current, i);
            current.pop_back();
            sum -= candidates[i];
            ++i;
        }
    }
};
