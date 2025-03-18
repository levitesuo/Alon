#include <iostream>
#include <set>
#include <map>

using namespace std;

int main () {
    long long n, maxU;
    cin >> n;
    cin >> maxU;

    set<pair<long long, long long>> lastPlaces;
    set<long long> seen;
    map<long long, long long> lPDict;

    long long u = 0;
    long long output = 0;
    long long laggingI = -1;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (seen.find(num) != seen.end()){
            auto fpIt = lastPlaces.upper_bound({lPDict[num], num});
            fpIt--;
            lastPlaces.erase(fpIt);
            lastPlaces.insert({i, num});
            lPDict[num] = i;
        } else {
            seen.insert(num);
            lastPlaces.insert({i, num});
            lPDict[num] = i;
            if (u == maxU) {
                laggingI = lastPlaces.begin()->first;
                seen.erase(lastPlaces.begin()->second);
                lastPlaces.erase(lastPlaces.begin());
            } else {
                u += 1;
            }
        }

        output += i - laggingI;

        /*
        cout << "\n";
        cout << "lastPlaces ";
        for (auto it = lastPlaces.begin(); it != lastPlaces.end(); it++){
            cout << "[" << it->first << ", " << it->second << "] ";
        }
        cout << "\n";
        cout << "seen ";
        for (auto it = seen.begin(); it != seen.end(); it++){
            cout << *it << " ";
        }
        cout << "\n";
        cout << "i: " << i << "\tli: " << laggingI << "\n"; 
        cout << "out: " << output << "\tu: " << u << "\n"; 
        */
    }
    cout << output;
}