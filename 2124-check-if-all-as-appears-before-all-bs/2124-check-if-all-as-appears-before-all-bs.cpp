class Solution {
public:
    bool checkString(string s) {
      bool found_B = false;

      for(int i=0;i<s.size();i++){
              if(s[i]=='b'){
                found_B=true;
              }
              else if(found_B){
                return false;
              }
      }
      return true;
    }
};