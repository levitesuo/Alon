#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int n;
    cin >> n;
    string out1 = n % 4 == 0 || n % 4 == 3 ? "YES" : "NO";
    cout << out1;
    if (out1 == "NO")
        return 0;
    string row1 = "";
    string row2 = "";
    int count1 = 0;
    int count2 = 0;
    loop:
        row1 += to_string(n) += " ";
        count1 += 1;
        n -= 1;
        if (n == 0)
            goto end;
        row2 += to_string(n) += " ";
        count2 += 1;
        n -= 1;
        if (n == 0)
            goto end;
        row2 += to_string(n) += " ";
        count2 += 1;
        n -= 1;
        if (n == 0)
            goto end;
        row1 += to_string(n) += " ";
        count1 += 1;
        n -= 1;
        if (n == 0)
            goto end;
    goto loop;
    end:
    cout << "\n" << count1 << "\n" << row1 << "\n" << count2 << "\n" << row2;
}
