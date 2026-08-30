class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        long long num = 0;
        bool positive = true;

    
        while (i < s.size() && s[i] == ' ') {
            i++;
        }


        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                positive = false;
            }
            i++;
        }

        
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

        
            if (positive && num > INT_MAX) {
                return INT_MAX;
            }

            if (!positive && -num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

    
        return positive ? num : -num;
  }
};