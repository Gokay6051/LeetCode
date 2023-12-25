class Solution {
public:
    int romanToInt(string s) {
        int sum;
        sum=0;
        int num1;
        int num2;

        for(int i=0; i<s.length(); ++i) {
            if(i!=s.length()) {
                num1 = convert(s[i]);
                num2 = convert(s[i+1]);

                if(num2>num1) {
                    sum += num2 - num1;
                    ++i;
                }
                else{
                    sum += num1;
                }
            }
            else {
                num1 = convert(s[i]);
                sum += num1;
            }
        }

        return sum;
    }

    int convert(char ch) {
        int num1;
        switch(ch){
                case 'I':
                    num1= 1;  
                    break;
                case 'V':
                    num1= 5;
                    break;
                case 'X':
                    num1= 10;
                    break;
                case 'L':
                    num1= 50;
                    break;
                case 'C':
                    num1= 100;
                    break;
                case 'D':
                    num1= 500;
                    break;
                case 'M':
                    num1= 1000;
                    break;
            }
        return num1;
    }
};
