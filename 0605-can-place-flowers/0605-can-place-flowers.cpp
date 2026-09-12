class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(n==0) return true;
       int cnt =0;
       bool canPlace = false;
       int m = flowerbed.size();

        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
            bool leftEmpty =  (i==0 || flowerbed[i-1]==0);
            bool rightEmpty = (i== m-1 || flowerbed[i+1]==0);
            

            if(leftEmpty&&rightEmpty){
                cnt++;
                flowerbed[i]=1;
            }
            }
    }
    if(cnt>=n){
        return true;
    }
    return false;
    }

};