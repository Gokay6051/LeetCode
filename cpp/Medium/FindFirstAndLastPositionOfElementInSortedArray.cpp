class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        cout << endl << target << endl;
        return findRange(nums, target, 0, nums.size()-1);
    }

    vector<int> findRange(vector<int>& nums, int target, int low, int high){
        vector<int> vec;
        int mid=(high+low)/2;
        if(mid==low)
            ++mid;

        //sonuc yoksa -1 döndür
        if(((low==high || low==high-1) && nums[low] != target && nums[high] != target) || high==-1){
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }

        //sonuca varýldýysa return et
        if(nums[low] == target && nums[high]==target){
            if(low==0 && high==nums.size()-1){
                vec.push_back(low);
                vec.push_back(high);
                return vec;
            }
            else if(low==0){
                if(nums[high+1]!=target){
                    vec.push_back(low);
                    vec.push_back(high);
                    return vec;
                }
            }
            else if(high==nums.size()-1){
                if(nums[low-1]!=target){
                    vec.push_back(low);
                    vec.push_back(high);
                    return vec;
                }    
            }
            else if(nums[high+1]!=target && nums[low-1]!=target){
            	vec.push_back(low);
                vec.push_back(high);
                return vec;
			}
        }

        //duruma göre parametreleri güncelle ve recurcion fonksiyonu çaðýr
        if(nums[mid]>target) {
            if(mid==high)
                --mid;
            return findRange(nums, target, low, mid);
        } 
            
        if(nums[mid]<target)
            return findRange(nums, target, mid, high);
        if(nums[low] != target){
        	if(low+1>=mid)
        		++low;
        	else
        		low = (mid+low)/2;
		}
        else if(nums[low] == target){
            if(low==0){}
            else if(nums[low-1]!=target){}
            else if(nums[low-1]==target)
                --low;
        }
        if(nums[high] != target)
            high = (high+mid)/2;
        else if(nums[high] == target){
            if(high==nums.size()-1){}
            else if(nums[high+1] != target){}
            else if(nums[high+1] == target)
                ++high;
        }

        return findRange(nums, target, low, high);
    }
};
