#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int num = 0;
    	bool flag = 0;
    	
        if((x>2147483647 || x<-2147483648)){
        	return 0;
		}
        
		if(x<0){
			flag = 1;
		}
			 	
        while(x != 0){
        	num += x%10;
        	x /= 10;
        	if(!(num<=214748364 && num>=-214748364)){
        		if(x!=0)
        			return 0;
			}
			else if(num==214748364 || num==-214748364){
				if(flag==1 && x>8){
        			return 0;
				}
        		if(flag==0 && x>7){
					return 0;
				}
			}
			if(x!=0)
        		num *= 10;	
		}
		return num;
    }
};

