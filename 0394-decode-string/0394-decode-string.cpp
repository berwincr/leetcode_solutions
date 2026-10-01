class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string current = "";
        int num = 0;

        for(int i = 0; i < s.size(); i++) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                numStack.push(num);
                strStack.push(current);

                num = 0;
                current = "";
            }

            else if(s[i] == ']') {
                int repeat = numStack.top();
                numStack.pop();

                string previous = strStack.top();
                strStack.pop();

                string temp = "";

                for(int j = 0; j < repeat; j++) {
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current += s[i];
            }
        }

        return current;
    }
};