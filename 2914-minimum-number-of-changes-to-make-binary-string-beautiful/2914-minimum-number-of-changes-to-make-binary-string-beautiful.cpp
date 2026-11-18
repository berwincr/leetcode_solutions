class Solution {
public:
    int minChanges(string s) {
        int n =s.size();
        int changes=0;
char prev = s[0];
int cnt=1;
        for(int i=1;i<n;i++){
            if(cnt!=0){
            if(prev==s[i]){
                 cnt=0;
            }
            else{
                cnt=0;
                changes++;
            }
            }

           else{
             prev=s[i];
             cnt=1;
           }

        }
        return changes;
    }
};