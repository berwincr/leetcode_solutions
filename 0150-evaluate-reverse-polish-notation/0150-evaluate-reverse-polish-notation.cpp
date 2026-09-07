class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;

        int i = 0;

        while (i < tokens.size()) {

            string token = tokens[i];

           
            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                s.push(stoi(token));
            }

        
            else {

                int operand2 = s.top();
                s.pop();

                int operand1 = s.top();
                s.pop();

                int ans;

                if (token == "+") {
                    ans = operand1 + operand2;
                }
                else if (token == "-") {
                    ans = operand1 - operand2;
                }
                else if (token == "*") {
                    ans = operand1 * operand2;
                }
                else {
                    ans = operand1 / operand2;
                }

                s.push(ans);
            }

            i++;
        }

        return s.top();
    }
};