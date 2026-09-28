class Solution {
public:
    int maxDepth(string s) {
        
        int cnt =0;
        int max_cnt =0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }

            max_cnt = max(cnt , max_cnt);
        }
        return max_cnt;
    }
};