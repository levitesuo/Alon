#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main () {
    int n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return 0;
    }

    long long t = sum / 2;

    long long nums[t+1]{0};

    nums[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = t; j >= i; j--){
            nums[j] = (nums[j-i] + nums[j]) % 1000000007;
        }
    }
    cout << (nums[t] * 500000004) % 1000000007;
}