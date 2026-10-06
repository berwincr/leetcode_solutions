class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return true;
int open=0;
int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
            open++;
            }
            else{
              if(open>0){
                open--;
              }
              else{
                ans++;
              }
            }
        }

    
        return ans+open;
        
    }
};