class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> stringStack;

        string current = "";
        int num = 0;

        for (char c : s) {

            // Build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Start a new encoded section
            else if (c == '[') {
                numStack.push(num);
                stringStack.push(current);

                num = 0;
                current = "";
            }

            // Finish the current encoded section
            else if (c == ']') {

                int repeat = numStack.top();
                numStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            // Normal character
            else {
                current += c;
            }
        }

        return current;
    }
};