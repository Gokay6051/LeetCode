#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        prefix = strs[0];
        
        for(int i=1; i<strs.size(); ++i){
        	if(prefix.length() > strs[i].length())
            		prefix.erase(prefix.length() - (prefix.length() - strs[i].length()));
            		
            for(int j=0; j<prefix.length(); ++j){
                if(j<prefix.length()){
                    if(prefix[j] != strs[i][j]){
                        prefix.erase(j, prefix.length());
                        break;
                    }
                }
                else
                    break;  
            }
        }
        return prefix;
    }
};
