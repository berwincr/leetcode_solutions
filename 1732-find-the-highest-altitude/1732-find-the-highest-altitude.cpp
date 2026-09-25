class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    int high=0;
    
int n = gain.size();

     int gainSum[n];
     gainSum[0]=gain[0];
        for(int i=1;i<gain.size();i++){
            
             gainSum[i] = gainSum[i-1]+gain[i];
        }

        for(int i=0;i<n;i++){
              if(gainSum[i]>high){
                high = gainSum[i];
              }
        }
     return high;   
    }
};