class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int startIndex = 0;
        int maxLength = 0;
        char currentChar;

        for(int i=0; i<s.length(); ++i) {
            currentChar = s[i];

            if(charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= startIndex)
                startIndex = charIndex[currentChar] + 1;

            charIndex[currentChar] = i;

            maxLength = max(maxLength, i - startIndex + 1);
        }

        return maxLength;
    }
};
