#include <iostream>
#include <set>
#include "limits.h"
using namespace std;

int main() {
    set<pair<long long int, long long int>> movies;
    int n;
    cin >> n;
    long long int s, e;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        movies.insert(make_pair(s, e));
    }

    long long int time = 0;
    long long int bestEnd = LLONG_MAX;
    long long int watched = 1;
    for (auto x = movies.begin(); x != movies.end(); ++x) {
        e = x -> second;
        s = x -> first;
        if (e < bestEnd)
            bestEnd = e;
        if (s >= bestEnd) {
            watched += 1;
            bestEnd = e;
        }
    }
    cout << watched << "\n";

}

/*
Elokuvat ovat järjestetty aloitusajan mukaan.
Aika t on 0
Etsitään elokuva joka alkaa t:n jälkeen
Sitten niistä elokuvista se joka loppuu ekana
Jos löydämme elokuvan alkaa senjälkeen kun paras loppuu haku on valmis.
    Muistetaan tämä paikka. Siitä aloitamme seuraavan haun
aika t = loppuaika

*/