class Solution {
public:
    int compress(vector<char>& chars) {
         int n = chars.size();
    int read = 0;
    int write = 0;

    while (read < n) {
        char ch = chars[read];
        int count = 0;

        while (read < n && chars[read] == ch) {
            read++;
            count++;
        }

        chars[write++] = ch;

        if (count > 1) {
            string s = to_string(count);

            for (char c : s) {
                chars[write++] = c;
            }
        }
    }
    return write;
}
};