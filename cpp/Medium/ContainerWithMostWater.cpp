class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxArea = 0;

        while (low < high) {
            int h = min(height[low], height[high]);
            int w = high - low;
            int area = h * w;

            maxArea = max(maxArea, area);

            if (height[low] < height[high]) {
                ++low;
            } else {
                --high;
            }
        }

        return maxArea;
    }
};

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int hVal;
        int lVal;
        int max;
        
        if(height[low] > height[high])
            max = height[high]*high;
        else
            max = height[low]*high;

        while(low<high){
        	cout << max;
            if(height[low] > height[high]){
            	--high; 
            	cout << " " << height[high] << endl;
			}
            else{
            	++low;
				cout << " " << height[low] << endl;
			}
            if(height[high] < height[low])
            	hVal = height[high]*(high-low);	
			else
				hVal = height[low]*(high-low);
            if(hVal > max)
                max = hVal;
        }
        return max;
    }
};
*/
