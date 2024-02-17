class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> solution;

        sort(intervals.begin(), intervals.end());

        // Ýlk aralýðý çözüme ekle
        solution.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= solution.back()[1]) {
                // Aralýklar birleþtirilebilir
                solution.back()[1] = max(solution.back()[1], intervals[i][1]);
            } else {
                // Yeni bir aralýk baþlat
                solution.push_back(intervals[i]);
            }
        }

        return solution;
    }
};

//YARIM KALMIS COZUM
/*class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        bool flag = false;
        vector<vector<int>> solution;
        int _max;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<intervals.size(); ++i){
            if(intervals[i][1] < _max)
                continue;

            int j = i+1;
            for(; j<intervals.size(); ++j){
                if(intervals[j-1][1] < intervals[j][0])
                    break;
                flag = true;
            }
            --j;

            if(flag == true){
                if(intervals[i][1] < intervals[j][1]){
                    solution.push_back({intervals[i][0], intervals[j][1]});
                    _max = intervals[j][1];
                }
                else{
                    solution.push_back({intervals[i][0], intervals[i][1]});
                    _max = intervals[i][1];
                }
                i = j;
            }
            else{
                solution.push_back({intervals[i][0], intervals[i][1]});
                _max = intervals[i][1];
            }

            flag = false;
        }
        
        return solution;
    }
};
*/
