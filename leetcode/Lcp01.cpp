#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    static int game(vector<int>& guess, vector<int>& answer) {

        int count = 0;
        for (int i = 0; i < 3; ++i) {
            if (guess[i] == answer[i]) count++;
        }

        return count;
    }
};

int main () {

    vector<int> guess;
    vector<int> answer;

    guess.push_back(1);
    guess.push_back(3);
    guess.push_back(3);

    answer.push_back(2);
    answer.push_back(3);
    answer.push_back(1);
    int res = Solution::game(guess, answer);
    cout << res << endl;
    return 0;
}
