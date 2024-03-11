#include <iostream>
#include <set>

using namespace std;

int main () {
    set<long long int> numbers;
    int n;
    cin >> n;
    long long int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (numbers.count(x))
            numbers.insert(x*2);
        else
            numbers.insert(x);
    }
    x = 0;
    while (true) {
        x += 1;
        
    }
}