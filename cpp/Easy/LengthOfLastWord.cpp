class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length()-1;

        while(s[i] == ' ' && i >= 0)
            --i;
        
        for(; i>=0; --i){
            if(s[i] == ' ')
                break;
            ++len;
        }
        return len;
    }
};
