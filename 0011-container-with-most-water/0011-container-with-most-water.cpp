class Solution {
public:
    int maxArea(vector<int>& height) {
       
        int area=0;
int water=0;
int left=0;
int right=height.size()-1;
        while(left<=right){
            if(height[left]<height[right]){
               water = height[left];
               area = max(area, water*(right-left));
               left++;
            }
            else{
                water = height[right];
               area = max(area, water*(right-left));
               right--;
            }
        }
        return area;
    }
};