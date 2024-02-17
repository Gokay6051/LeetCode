class Solution {
public:
    bool canJump(vector<int>& nums) {
        int _max = -1;

        for(int i=0; i<nums.size(); ++i){
            _max = max(_max, nums[i]);
            if(_max == 0 && i < nums.size()-1)
                return false;
            --_max;
        }
        return true;
    }
};
/*
[0]
[2,5,0,0,0,0,0]
[2,5,0,0,0,0,0,0]
[2,5,0,0,0,1,0,0]
*/
