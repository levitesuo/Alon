#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    long long int o;
    cin >> n;
    o = 0;
    cin >> x;
    if (n == 1) 
        goto end;
    for (int i = 1; i < n; i ++) {
        cin >> y;
        if (y < x)
            o += (x - y);
        else
            x = y;
        //cout << "O: " + to_string(o) + "    X: " + to_string(x) +  "    Y: " + to_string(y)+"\n";
    }
    end:
    cout << o;
}