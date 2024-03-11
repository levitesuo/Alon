#include <iostream>
using namespace std;

int main () {
    int n, x, runs;
    cin >> n;
    runs = 0;
    bool seenBool [n + 1] = { false };
    for ( int i = 0; i < n; i ++) {
        cin >> x;
        if  (seenBool[x - 1] == false)
            runs = runs + 1;
        seenBool[x] = true;
    }
    cout << runs;
}