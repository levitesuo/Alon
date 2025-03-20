#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    long long pathCost;
    int a;
    int b;
};

int main()
{
    int n;
    int m = 1e9;
    cin >> n;
    vector<int> numbers(n);
    vector<vector<Node>> arr(n, vector<Node>(n, {-3000000000, -1, -1}));
    vector<long long> p(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int myTurn = (n + 1) % 2;

    /* making a web of possibilities*/
    for (int i = 0; i < n; i++)
    {
        int a = i;
        int b = i;
        long long points = 0;
        for (int j = 0; j < n; j++)
        {
            int c;

            if (b == n - 1 || (numbers[a] > numbers[b] && a > 0))
            {
                c = numbers[a];
            }
            else
            {
                c = numbers[b];
            }

            cout << "c: " << c << " i: " << i << " j: " << j << " mt: " << (j % 2 == myTurn) << "\n";
            cout << "p: " << points << " a: " << a << " n[a]: " << numbers[a] << " b: " << b << " n[b]: " << numbers[b] << "\n\n";
            if (j % 2 == myTurn)
                points += c;

            if (arr[i - a][i - b].pathCost < points)
            {
                arr[i - a][i - b] = {points, a, b};
            }

            if (b == n - 1 || (numbers[a] > numbers[b] && a > 0))
            {
                a -= 1;
            }
            else
            {
                b += 1;
            }
        }
    }

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
        {
            Node node = *jt;
            cout << setw(5) << "[" << node.pathCost % 1000 << "|" << setw(2) << node.a << ", " << setw(2) << node.b << "]";
        }
        cout << endl;
    }

    /* calculating the result */
    long long out = 0;
    int a = 0;
    int b = n - 1;
    for (int j = 0; j < n; j++)
    {

        if (arr[a][b].a != a)
        {
            if (j % 2 == myTurn)
                out += numbers[b];
            cout << a << " " << b << " " << numbers[b] << " " << out << "\n";
        }
        else
        {
            if (j % 2 == myTurn)
                out += numbers[b];
            cout << a << " " << b << " " << numbers[a] << " " << out << "\n";
        }
        if (a < 0 || b < 0 || a >= n || b >= n)
            break; // Extra safety check

        int tempA = arr[a][b].a;
        int tempB = arr[a][b].b;

        a = tempA;
        b = tempB;
    }

    cout << out;
}