class Solution {
public:
    string addBinary(string a, string b) {
        int ai = a.length()-1;
        int bi = b.length()-1;
        string solution;
        //1+1 = 10
        bool overFlag = 0;

        while(ai >= 0 && bi >= 0){
            if(a[ai] == '1' && b[bi] == '1'){
                if(overFlag == 1){
                    solution = "1" + solution;
                }
                else{
                    solution = "0" + solution;
                    overFlag = 1;
                }
            }
            else if((a[ai] == '1' && b[bi] == '0') || (a[ai] == '0' && b[bi] == '1')){
                if(overFlag == 1){
                    solution = "0" + solution;
                }
                else{
                    solution = "1" + solution;
                }
            }
            else if(a[ai] == '0' && b[bi] == '0'){
                if(overFlag == 1){
                    solution = "1" + solution;
                    overFlag = 0;
                }
                else{
                    solution = "0" + solution;
                }
            }

            --ai;
            --bi;
            
            if(ai < 0 && bi < 0){
                if(overFlag == 1)
                    solution = "1" + solution;
            }
        }

        while(ai >= 0) {
            if(a[ai] == '1'){
                if(overFlag == 1){
                    solution = "0" + solution;
                }
                else{
                    solution = "1" + solution;
                }
            }
            else if(a[ai] == '0'){
                if(overFlag == 1){
                    solution = "1" + solution;
                    overFlag = 0;
                }
                else{
                    solution = "0" + solution;
                }
            }

            --ai;
            
            if(ai < 0){
                if(overFlag == 1)
                    solution = "1" + solution;
            }
        }

        while(bi >= 0) {
            if(b[bi] == '1'){
                if(overFlag == 1){
                    solution = "0" + solution;
                }
                else{
                    solution = "1" + solution;
                }
            }
            else if(b[bi] == '0'){
                if(overFlag == 1){
                    solution = "1" + solution;
                    overFlag = 0;
                }
                else{
                    solution = "0" + solution;
                }
            }

            --bi;
            
            if(bi < 0){
                if(overFlag == 1)
                    solution = "1" + solution;
            }
        }

        return solution;
    }
};
