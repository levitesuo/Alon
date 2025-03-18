#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    long nCustomers;
    cin >> nCustomers;

    multiset<pair<long, int>> arrivals, departures;
    
    for (int i = 0; i < nCustomers; i++ ) {
        long arr, dep;
        cin >> arr >> dep;
        arrivals.insert({arr, i});
        departures.insert({dep, i});
    }

    long maxRooms = 0;
    long rooms = 0;

    vector<int> roomList(maxRooms, -1);
    vector<long> questList(arrivals.size());

    priority_queue <int, vector<int>, greater<int>> freeRooms; 

    auto dit = departures.begin();
    for ( auto ait = arrivals.begin(); ait != arrivals.end(); ait++ ){
        while (dit->first < ait->first) {
            freeRooms.push(questList[dit->second]);
            
            rooms -= 1;
            dit++;
        }

        rooms += 1;
        if (rooms > maxRooms) {
            maxRooms = rooms;
            freeRooms.push(maxRooms);
        }
        
        questList[ait->second] = freeRooms.top(); 
        freeRooms.pop();
    }

    cout << maxRooms << "\n";

    for ( auto it = questList.begin(); it != questList.end(); it++) {
        cout << *it << " ";
    }
}