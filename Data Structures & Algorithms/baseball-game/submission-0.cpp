class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> scores;

        for (string op : operations) {

            if (op != "C" && op != "D" && op != "+") {
                scores.push_back(stoi(op));
            }
            else if (op == "C") {
                scores.pop_back();
            }
            else if (op == "D") {
                scores.push_back(2 * scores.back());
            }

            else if (op == "+") {
                int n = scores.size();
                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
        }

        int points = 0;

        for (int score : scores) {
            points += score;
        }

        return points;
    }
};