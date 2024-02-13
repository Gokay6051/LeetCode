class Solution {
public:
    string intToRoman(int num) {
        string roman;
        //iterator
        int i=1;
        int val;
        
        while(num>0){
            val = (num % 10)*i;

            if(val>=1000){
                addRoman(roman, val, 1000, 5000, 3000, 1000);
            }
            else if(val>=500){
                addRoman(roman, val, 500, 1000, 800, 100);
            }
            else if(val>=100){
                addRoman(roman, val, 100, 500, 300, 100);
            }
            else if(val>=50){
                addRoman(roman, val, 50, 100, 80, 10);
            }
            else if(val>=10){
                addRoman(roman, val, 10, 50, 30, 10);
            }
            else if(val>=5){
                addRoman(roman, val, 5, 10, 8, 1);
            }
            else if(val>=1){
                addRoman(roman, val, 1, 5, 3, 1);
            }

            num /= 10;
            i *= 10;

            
        }
        return roman;
    }
    //a=main number, b=upper number
    void addRoman(string& roman, int val, int a, int b, int c, int d){
        unordered_map<int, string> hash_Table;

        hash_Table[1] = "I";
        hash_Table[5] = "V";
        hash_Table[10] = "X";
        hash_Table[50] = "L";
        hash_Table[100] = "C";
        hash_Table[500] = "D";
        hash_Table[1000] = "M";

        if(val>c){  
            roman = hash_Table[b] + roman;
            while(val<b){
                roman = hash_Table[d] + roman;
                val += d;
            }       
        }
        else if(val>a){
            while(val>a){
                roman = hash_Table[d] + roman;
                val -= d;
            }       
            roman = hash_Table[a] + roman;
        }
        else{
            while(val>0){      
                roman = hash_Table[a] + roman;
                val -= a;
            }
        }
    }
};



//Best solution at LeetCode
/*
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
*/
