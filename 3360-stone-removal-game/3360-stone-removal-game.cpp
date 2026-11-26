class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;
        bool alice = true;

        while(n >= i) {
            n -= i;
            i--;
            alice = !alice;
        }

        return !alice;
    }
};