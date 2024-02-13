class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	
        vector<vector<int>> newMatrix(n, vector<int>(n, 0));
        
        for(int j=0; j<n; ++j){
        	for(int i=n-1; i>=0; --i){
        		newMatrix[j][n-1-i] = matrix[i][j];
			}
		}
		
		matrix = newMatrix;
    }
};
