class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.length(); ++i){
            if(haystack[i]==needle[0]){
                int flag = isSubString(haystack, needle, i);
                if(flag != -1)
                    return flag;
            }
            if((haystack.length() - i) < needle.length())
                return -1;
        }

        return -1;
    }

    int isSubString(string &haystack, string &needle, int i){
        int idx = i;

        for(int j=0; j<needle.length(); ++j){
            if(needle[j] != haystack[i] || i>=haystack.length())
                return -1;

            ++i;
        }
        return idx;
    }
};
