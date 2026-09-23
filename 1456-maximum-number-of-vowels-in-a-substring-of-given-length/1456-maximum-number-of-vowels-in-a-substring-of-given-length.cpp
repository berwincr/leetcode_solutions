class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxcnt=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                        maxcnt++;
            }

        }

        int windowcnt = maxcnt;
            for(int j=k;j<n;j++){
                     if(s[j-k]=='a' || s[j-k]=='e' || s[j-k]=='i' || s[j-k]=='o' || s[j-k]=='u'){
                        windowcnt--;
                     }
                     if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                             windowcnt++;
                     }
                     maxcnt = max(windowcnt,maxcnt);
            }
        
        return maxcnt;
    }
};