class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        findSum(result, candidates, target, 0, current, 0);
        return result;
    }

    void findSum(vector<vector<int>> &result, const vector<int>& candidates, int target, int sum, vector<int>& current, int start) {
        if (sum == target) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) // Aynı sayıyı tekrar kullanmayı önler
                continue;

            current.push_back(candidates[i]);
            findSum(result, candidates, target, sum + candidates[i], current, i + 1); // i+1'den devam eder, tekrar etmeyi önler
            current.pop_back();
        }
    }
};
