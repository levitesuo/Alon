#include <iostream>
 
using namespace std;
 
void f (long long int n) {
    string out = to_string(n);
    while (n != 1) {
        out += " ";
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
        out += to_string(n);
    }
    cout << out;
}
 
int main() {
    long long int x;
    cin >> x;
    f(x);
}