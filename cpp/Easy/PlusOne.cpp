class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool tenFlag=0;
        int i = digits.size()-1;

        ++digits[i];
        if(digits[i]==10){
            tenFlag = 1;
            digits[i] -= 10;
            --i;
            if(i<0){
                ++i;
                digits.insert(digits.begin(), 1);
                tenFlag = 0;
            }
        }  
        else
            --i;

        for(; i>=0; --i){
            if(tenFlag == 1){
                ++digits[i];
                if(digits[i] == 10){
                    tenFlag = 1;
                    digits[i] %= 10;
                    if(i<=0){
                        ++i;
                        digits.insert(digits.begin(), 1);
                        tenFlag = 0;
                    }
                }
                else
                    tenFlag = 0;
            }
            else
                break;   
        }

        return digits;
    }
};
