class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        for(int j = 0;j<=m-n;j++){
            for (int i = 0; i < n; i++) {
                if (needle[i] != haystack[j + i]) {
                    break;
                }
                if(i==n-1){
                    return j;
                }
            }
        }
        return -1;
    }
};