class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = 46340;
        int mid;
        int midSqrt;

        if(x>=46340*46340)
            return high;
            
        while(low < high){
            mid = low + (high-low)/2;
            midSqrt = mid*mid;

            if(midSqrt == x){
                return mid;
            }
            if(midSqrt < x){
                if(mid<46340 && (mid+1)*(mid+1)>x)
                    return mid;
                low = mid+1;
            }
            else {
                if(mid>0 && (mid-1)*(mid-1)<x)
                    return mid-1;
                high = mid;
            }
            
        }

        return -1;
    }
};
