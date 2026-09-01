class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.contains(needle)){
                int idx=haystack.find(needle);
                return idx;
        }
       return -1;
    }
};