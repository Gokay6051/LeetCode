class Solution {
public:
    int maxLength(vector<string>& arr) {
        return findMax(arr, 0, 0, "");
    }

    bool hasDuplicateCharacters(const string& str) {
        bool charSet[256] = {false}; // 256 elemanlý bir dizi (ASCII karakter seti)

        for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
            // Karakterin ASCII deðeri
            int asciiValue = static_cast<int>(*it);

            // Dizi içindeki ilgili indeksi kontrol et
            if (charSet[asciiValue]) {
                return true; // Eðer dizi zaten true ise, ayný karakter var demektir
            }

            // Dizi içindeki ilgili indeksi true yap
            charSet[asciiValue] = true;
        }

        // Hiçbir karakter tekrar etmiyorsa
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
