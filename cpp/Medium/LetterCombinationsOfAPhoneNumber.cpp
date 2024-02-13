class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> solution;
        unordered_map<int, string> hash_Table = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };

        if (digits.empty()) 
            return solution;

        string current = ""; 
        DFS(solution, hash_Table, digits, 0, current); 
        return solution;
    }

    void DFS(vector<string> &solution, unordered_map<int, string> &hash_Table, string &digits, int i, string &current) {
        if(i==digits.size()){
            solution.push_back(current);
            return;
        }

        int digit = digits[i] - '0';
        string letters = hash_Table[digit];

        for(char letter: letters) {
            current.push_back(letter);
            DFS(solution, hash_Table, digits, i+1, current);
            current.pop_back();
        }
    }
};
