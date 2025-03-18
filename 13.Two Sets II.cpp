#include <iostream>
#include <cmath>

using namespace std;

int main () {
    long long n, bigN;
    cin >> n;
    float c = (n * 0.5 * n + 0.5 * n)/2;

    if ( round(c) == c) bigN = c;
    else return bigN = c;

    long long values[bigN + 1]{0};

    cout << bigN;

    values[1] = 1;
    values[2] = 1;
    for ( int i = 2; i < bigN; i++ ){
        values[i] = values[i-1] + values[i-2];
    } 
    cout << values[bigN];
}