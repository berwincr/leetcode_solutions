class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>v;
        int start=0;
        for(int i=1 ; i<=n;i++){
            if(i == target[start]){
                  v.push_back("Push");
                  start++;
            }

            else{
                v.push_back("Push");
                v.push_back("Pop");
            }
            if(start == target.size()){
                break;
            }
        }
        return v;
    }
};