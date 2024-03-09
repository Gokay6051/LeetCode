class Solution {
public:
    int titleToNumber(string columnTitle) {
        int slt = 0;
        for(int i=columnTitle.length()-1; i>=0; --i){
            slt += pow(26,columnTitle.length()-i-1) * (columnTitle[i] - 64);
        }
        return slt;
    }
};
