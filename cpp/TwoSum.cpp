#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> idx;
    	int first;
    	int second;
    	int flag;
    	
    	flag = 0;
    	
    	
        
        for(int i=0; i<nums.size(); ++i){
        	if(flag == 1)
        		break;

        	first = nums[i];
        	second = target - first;
    
        	for(int j=i+1; j<nums.size(); ++j) {
        		if(nums[j] == second) {
                    idx.push_back(i);
    	            idx.push_back(j);
        			flag = 1;
        			break;
				}
			}
        	
		}
        
        
        	
        return idx;
    }
};


