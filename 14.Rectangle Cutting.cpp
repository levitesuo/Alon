#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <stdlib.h>

using namespace std;

int rec(int a, int b) {
    if ( a == b) return 0;
    int best = 1000;
    int ll = max(a, b);
    int ss = min(a, b);
    for (int i = 1; i <= ll; i++) {
        int res = rec(ll - i, ss) + rec(i, ss) + 1;
        if  (res < best) best = res;
    }
    return best;
}

int main () {
    int a, b, s, l;
    cin >> a >> b;
    l = max(a, b);
    s = min(a, b);
    if (l == s) {
        cout << 0;
        return 0;
    }

    int p = 50;

    vector<vector<int>> res(p, vector<int>(p, 0));

    for (int i = 0; i < p; i++) {
        res[i][0] = i;
        res[0][i] = i;
    }


    for (int i = 1; i < p; i++) {
        for (int j = 1; j < p; j++) {
            if ( i < j ) {
                res[i][j] = res[i][j-i] + 1;
            } else if (j < i) {
                res[i][j] = res[i-j][j] + 1;
            } 
        }
    }
    
    for (auto it = res.begin(); it != res.end(); it++){
        for (auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout << setw(3) <<  *jt;
        }
        cout << "\n";
    }
    

    cout << rec(a, b);
}