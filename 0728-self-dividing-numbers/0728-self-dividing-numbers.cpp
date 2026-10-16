class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>v;

        for(int i=left;i<=right;i++){
            bool flag=true;
            int dig = i;
            while(dig!=0){
                int n = dig%10;
                if(n==0){
                    flag =false;
                    break;
                    
                }
                if(i%n!=0){
                    flag = false;
                   break;
                   
                }
                dig /=10;
            }
            if(flag){
                v.push_back(i);
            }
        }
        return v;
    }
};