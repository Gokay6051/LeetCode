class Solution {
public:
    int maxLength(vector<string>& arr) {
        return findMax(arr, 0, 0, "");
    }

    bool hasDuplicateCharacters(const string& str) {
        bool charSet[256] = {false}; // 256 elemanl� bir dizi (ASCII karakter seti)

        for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
            // Karakterin ASCII de�eri
            int asciiValue = static_cast<int>(*it);

            // Dizi i�indeki ilgili indeksi kontrol et
            if (charSet[asciiValue]) {
                return true; // E�er dizi zaten true ise, ayn� karakter var demektir
            }

            // Dizi i�indeki ilgili indeksi true yap
            charSet[asciiValue] = true;
        }

        // Hi�bir karakter tekrar etmiyorsa
        return false;
    }

    int findMax(vector<string>& arr, int idx, int max, string str){
        if(idx>=arr.size())
            return max;
            
        if(str=="" && !hasDuplicateCharacters(arr[idx]))
            str = arr[idx];
        
        int _idx = idx;
        if(!hasDuplicateCharacters(str)){
            if(str.length() > max)
                max = str.length();
                
            while(_idx+1<arr.size()){
                if(!hasDuplicateCharacters(str+arr[++_idx])){
                    max = findMax(arr, _idx, max, str+arr[_idx]);
                }
            }
        }
        max = findMax(arr, idx+1, max, "");
        return max;
    }
};
