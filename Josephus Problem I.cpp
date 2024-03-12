#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    vector<long long int> v;
    long long int n;
    cin >> n;
    for (int i = 0; i <= 18; i ++) {
        if (n >= pow(2, i)) {
            cout << 2 * (n - pow(2, i - 1));
            return -1;
        }
    }

}