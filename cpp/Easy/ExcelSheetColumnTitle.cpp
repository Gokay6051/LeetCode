class Solution {
public:
    string convertToTitle(int columnNumber) {
        string slt;
        while(columnNumber > 0){
            int num = (columnNumber % 26) + 64;
            if(num == 64)
                num += 26;
            slt = (char)num + slt;
            columnNumber -= num-64;
            columnNumber /= 26;
        }
        return slt;
    }
};
