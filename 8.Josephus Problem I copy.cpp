#include <iostream>
#include <cmath>

using namespace std;

int main () {
    long long n, step, r, last, first;
    cin >> n;
    r = 2;
    step = 2;
    first = 1;
    last = n;

    for ( int i = 0; i < n; i++) {
        if (last <= r){
            if ( r == last ) {
                cout << r;
                last = r - step + step / 2;
                r = first - step;
            } else {
                cout << first;
                r = first;
                first = r + step;
            }
            step = step * 2;
        } else  {
            cout << r;
        }
        r += step;
        cout << ' ';
    }
}