class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        int temp;

        for(int i=0; i<s.length()-1; ++i){
            temp = s[i]-s[i+1];
            if(temp < 0)
                temp *= -1;
            res += temp;
        }
        return res;
    }
};
