class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> current;

        current.push_back(1);
        pascal.push_back(current);
        current.clear();

        for(int i=1; i<numRows; ++i){
            current.push_back(1);
            for(int j=1; j<i; ++j){
                current.push_back(pascal[i-1][j] + pascal[i-1][j-1]);
            }
            current.push_back(1);
            pascal.push_back(current);

            current.clear();
        }
        return pascal;
    }
};
