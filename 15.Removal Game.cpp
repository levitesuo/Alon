#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int a, b;
    a = 0;
    b = n-1;

    int turn = b % 2;

    int out = 0;
    while (a != b){
        int choise;
        if (numbers[a + 1] - numbers[a] > numbers[b - 1] - numbers[b]){
            if (turn = (b - a)%2) {
                out += numbers[b];
                cout << numbers[b] << "\n";
            }
            b -= 1;
        } else {
            if (turn = (b - a)%2) {
                out += numbers[a];
                cout << numbers[a] << "\n";
            }
            a += 1;
        }
    }
    cout << out;

}