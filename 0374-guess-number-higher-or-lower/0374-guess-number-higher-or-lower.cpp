/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
 int pick;
        while(left<=right){
             pick = left + (right - left)/2;

            int num = guess(pick);

            if(num==0){
                return pick;
            }
            else if(num==1){
                left=pick+1;
            }
            else{
                right = pick-1;
            }


        }
        return -1;
    }
};