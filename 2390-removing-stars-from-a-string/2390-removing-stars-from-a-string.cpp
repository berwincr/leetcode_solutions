class Solution {
public:
    string removeStars(string s) {
        stack<int>ss;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!ss.empty()){
                    ss.pop();
                }
            }
            else{
                ss.push(s[i]);
            }
        }

string newstring;
        while(!ss.empty()){
            newstring +=ss.top();
            ss.pop();
        }
        reverse(newstring.begin(),newstring.end());
        s=newstring;
        return s;
    }
};