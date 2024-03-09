class Solution {
public:
    int addDigits(int num) {
        int temp = 0;

        while(num >= 10){
            while(num > 0){
                temp += num % 10;
                num /= 10;
            }
            num = temp;
            temp = 0;
        }

        return num;
    }
};
