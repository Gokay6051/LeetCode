class Solution {
public:
    string convert(string s, int numRows) {
        string newS;
        //upper or lower flag
        int flag;
        for(int i=0; i<numRows; ++i){
            flag = 0;
            for(int j=i; j<s.length();){
                if(i==0 || i==numRows-1){
                    newS += s[j];
                    //cout << i << j  << s[j]<<"1 ";
                    if(numRows==1)
                        j += 1;
                    else
                        j += 2*(numRows-1);
                }
                else if(flag == 0){
                    newS += s[j];
                    //cout << i << j  << s[j]<< "2 ";
                    if(numRows-i-1 == 1)
                        j += 2;
                    else
                        j += 2*(numRows-i-1);
                    flag = 1;
                }
                else{
                    newS += s[j];
                    //cout << i << j << s[j]<<"3 " ;
                    if(i==1)
                        j += 2;
                    else
                        j += 2*(i);

                    flag = 0;
                }
            }
        }

        return newS;
    }
};
