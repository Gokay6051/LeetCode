class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int rowMin = 0;
        int rowMax = matrix.size()-1;
        int colMin = 0;
        int colMax = matrix[0].size()-1;

        while(rowMin<=rowMax && colMin<=colMax){
            for(int i=colMin; i<=colMax; ++i){
                vec.push_back(matrix[rowMin][i]);
            }
            ++rowMin;
            if(rowMin>rowMax)
                break;

            for(int i=rowMin; i<=rowMax; ++i){
                vec.push_back(matrix[i][colMax]);
            }
            --colMax;
            if(colMin>colMax)
                break;

            for(int i=colMax; i>=colMin; --i){
                vec.push_back(matrix[rowMax][i]);
            }
            --rowMax;
            if(rowMin>rowMax)
                break;

            for(int i=rowMax; i>=rowMin; --i){
                vec.push_back(matrix[i][colMin]);
            }
            ++colMin;
            if(colMin>colMax)
                break;
        }

        return vec;
    }
};
