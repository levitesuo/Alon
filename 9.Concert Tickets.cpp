#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<long> tickets;

    int nTickets, nCustomers;
    cin >> nTickets >> nCustomers;

    for (int i = 0; i < nTickets; ++i) {
        long ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (int i = 0; i < nCustomers; ++i) {
        long customer;
        cin >> customer;
        auto it = tickets.upper_bound(customer);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}