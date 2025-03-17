#include <iostream>
#include <set>

using namespace std;

set<string> f (string s) {
    set<string> out;
    if (s.size() == 1) {
        out.insert(s);
        return out;
    }
    for (int i = 0; i < s.size(); i++) {
        string iter = s;
        iter.erase(i, 1);
        set<string> substrings = f(iter);
        set<string>::iterator x;
        for (x = substrings.begin(); x != substrings.end(); ++x) {
            out.insert(s[i] + *x);
        }
    }
    return out;
}

int main () {
    string s;
    cin >> s;
    //s = "abc";
    set<string> permutations = f(s);
    set<string>::iterator x;
    cout << permutations.size() << "\n";
    for (x = permutations.begin(); x != permutations.end(); x++) {
        cout << *x + "\n";
    }
}

/*
Funktio joka palauttaa setin missä on kaikki mahdolliset stringit.
Funktio on rekursiivinen.
Funktio hakee vaikka kaikki stringit jotka alkavat merkillä a
Jne

*/