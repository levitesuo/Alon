#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    long long pathScore;
    int left;
    int right;
};

int main()
{
    int n;

    cin >> n;

    int MyTurn = n % 2;

    vector<int> numbers(n, 0);
    vector<vector<Node>> arr(n, vector<Node>(n, {-9000000, -1, -1}));

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    for (int sPos = 0; sPos < n; sPos++)
    {
        int left = sPos;
        int right = sPos;
        int score = 0;
        if (MyTurn == 1)
            score = numbers[sPos];

        cout << "\nscore: " << score << " start: " << sPos << "\n";

        for (int turn = 0; turn < n; turn++)
        {
            int tempLeft = left;
            int tempRight = right;

            if (left > 0 && numbers[left - 1] > numbers[right])
            { /* move left */
                left -= 1;
                if (turn % 2 == MyTurn)
                    score += numbers[left];
            }
            else if (right < n - 1 && numbers[right + 1] > numbers[left])
            { /* move right */
                right += 1;
                if (turn % 2 == MyTurn)
                    score += numbers[right];
            }
            else if (left > 0)
            { /* move left */
                left -= 1;
                if (turn % 2 == MyTurn)
                    score += numbers[left];
            }
            else if (right < n - 1)
            { /* move right */
                right += 1;
                if (turn % 2 == MyTurn)
                    score += numbers[right];
            }

            cout << " turn: "
                 << turn
                 << " temp: "
                 << tempLeft
                 << ","
                 << tempRight
                 << "| move: "
                 << left
                 << ","
                 << right
                 << "| score: "
                 << score
                 << "] \n";

            if (arr[left][right].pathScore < score)
            {
                int seen = (arr[left][right].left != -1);
                arr[left][right].pathScore = score;
                arr[left][right].left = tempLeft;
                arr[left][right].right = tempRight;

                if (seen)
                    break;
            }
        }
    }

    cout << "\n \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j].pathScore != -9000000)
            {
                cout << "["
                     << arr[i][j].pathScore
                     << "|"
                     << i
                     << ","
                     << j
                     << "|"
                     << arr[i][j].left
                     << ","
                     << arr[i][j].right
                     << "] ";
            }
        }
        cout << "\n";
    }

    int left = 0;
    int right = n - 1;
    long long out = 0;

    for (int i = 0; i < n; i++)
    {
        int tempLeft = left;
        int tempRight = right;

        if (arr[left][right].left != left)
        {
            if (MyTurn == (i + 1) % 2)
                out += numbers[arr[left][right].left];
            left += 1;
        }
        else
        {
            if (MyTurn == (i + 1) % 2)
                out += numbers[arr[left][right].right];
            right -= 1;
        }
    }
    cout << out;
    return 0;
}