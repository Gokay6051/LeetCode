#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	long int numcpy, num;
    	numcpy=x;
    	num=0;
    	
        if(x<0)
        	return false;
        
			
    	while(numcpy>0){
    		num += numcpy%10;
    		num *= 10;
    		numcpy /= 10;
		}
		num /= 10;
		
		if(num == x)
			return true;
		
		return false;
    }
};

