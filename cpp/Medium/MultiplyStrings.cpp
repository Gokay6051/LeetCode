class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> solution(n1 + n2, 0);

        for(int i=n1-1; i>=0; --i){
            for(int j=n2-1; j>=0; --j){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int total = solution[i+j+1] + mul;

                solution[i+j] += total / 10;
                solution[i+j+1] = total % 10;
            }
        }

        string solutionStr;
        for(int num : solution){
            solutionStr.push_back(num + '0');
        }

        // Erase the first element if it's zero
        if (solutionStr[0] == '0') {
            solutionStr.erase(solutionStr.begin());
        }
        return solutionStr;
    }
};
