class Solution {
public:
    string reverseVowels(string s) {

        vector<char>v;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
               if(ch=='a' || ch=='e' || ch =='i' || ch=='o' || ch=='u'||
               ch=='A' || ch=='E' || ch =='I' || ch=='O' || ch=='U'){
                        v.push_back(ch);
               }
        }
        int k=0;

        for(int i=s.size()-1 ;i>=0;i--){
            char ch = s[i];
            if( ch=='a' || ch=='e' || ch =='i' || ch=='o' || ch=='u'|| ch=='A' || ch=='E' || ch =='I' || ch=='O' || ch=='U' ){
                s[i]= v[k];
                k++;
            }
        }
        return s;
    }
};