class Solution {
public:
    int hIndex(vector<int>& citations) {
       
int h_index=0;
       
        int n = citations.size();

sort(citations.begin(), citations.end());
        for(int i=0;i<n;i++){
            h_index = n-i;
            
            if(citations[i]>=h_index){
                return h_index;

            }
        }
        return 0;
    }
};