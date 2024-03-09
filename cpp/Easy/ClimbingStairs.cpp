class Solution {
public:
    int climbStairs(int n) {
        int pre = 1;
        int current = 1;

        if(n == 1)
            return 1;
        
        for(int i=1; i<n; ++i){
            int temp = pre;
            pre = current;
            current += temp;
        }

        return current;
    }
};
/*
//first solution, time limit problem
class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        return findStep(n, 0, count, 0);
    }
    //oneTwo: one or two, count: how many different way, total: sum of one or two steps
    int findStep(int n, int oneTwo, int& count, int total){
        total += oneTwo;
        cout << total << " " << count << endl;
        if(total>n)
            return 0;
        if(total == n){
            count ++;
            return count;
        }
        
        findStep(n, 1, count, total);
        findStep(n, 2, count, total);

        return count;
    }
};
*/
