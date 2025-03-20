#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <stdlib.h>

using namespace std;

int main () {
    int a, b, s, l;
    cin >> a >> b;

    vector<vector<int>> res(a + 1, vector<int>(b + 1, 1e9));


    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if ( i == j ) res[i][j] = 0;
            else {
                for (int k = 1; k < i; k++) {
                    res[i][j] = min(res[i-k][j] + res[k][j]+1, res[i][j]);
                }
                for (int k = 1; k < j; k++) {
                    res[i][j] = min(res[i][j-k] + res[i][k] + 1, res[i][j]);
                }
            }
        }
    }
    /*
    for (auto it = res.begin(); it != res.end(); it++){
        for (auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout << setw(3) <<  *jt;
        }
        cout << "\n";
    }
    */

    cout << res[a][b];
}