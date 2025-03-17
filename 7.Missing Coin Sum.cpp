#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<long long int> numbers;
    int n;
    cin >> n;
    long long int y;
    for (int i = 0; i < n; i ++) {
        cin >> y;
        numbers.push_back(y);
    }
    sort(numbers.begin(), numbers.end());
    auto firstElement = numbers.begin();
    if (1 != *firstElement) {
        cout << 1;
        return 0;
    }
    numbers.erase(firstElement);
    long long int interval = 1;
    long long int lastNum = 1;
    for (auto x = numbers.begin(); x != numbers.end(); x++) {
        if (lastNum + interval < *x) {
            //cout << "Ended at: " << *x << "     lastNum: " << lastNum << "     interval: " << interval << "\n";
            cout << lastNum + interval;
            return 0;
        }
        interval += lastNum;
        lastNum = *x;
        //cout << "lastNum: " << lastNum << "     interval: " << interval << "\n";
    }
    cout << lastNum + interval;
}
