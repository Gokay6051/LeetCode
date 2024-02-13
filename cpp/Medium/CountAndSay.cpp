class Solution {
public:
    string countAndSay(int n) {
        string solution="1";
        createString(solution, n-1);
        return solution;
    }

    void createString(string &solution, int count){
        if(count == 0)
            return;

        string newStr;
      
        int i=0;
        while(i<solution.length()){
            int n=1;
            while(i+1<solution.length() && solution[i] == solution[i+1]){
                ++n;
                ++i;
            }
            newStr += to_string(n) + solution[i];
            ++i;
        }
        solution=newStr;
        createString(solution, count-1);
    }
};
