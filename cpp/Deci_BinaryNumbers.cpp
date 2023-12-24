#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string str) {
        int max = 0;
        int num;

        for(int i=0; i<str.length(); ++i) {
            num = str[i] - '0';

            if(num>max)
                max = num;
            
            if(max == 9)
                break;
        }
			
        return max;
    }
};



int main() {
	Solution obj;
	string str;
	getline(cin, str);
	obj.minPartitions(str);

	return 0;
}
