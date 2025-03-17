#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main () {
    long long nTickets, nCustomers;
    cin >> nTickets;
    cin >> nCustomers;
    indexed_set tickets;
    for ( int i = 0; i < nTickets; i++ ) {
        long long ticketPrice;
        cin >> ticketPrice;
        tickets.insert(-1 * ticketPrice);
    }
    cout << "size: " << tickets.size() << "\n";
    for ( int i = 0; i < nCustomers; i ++) {
        long long customerPrice;
        cin >> customerPrice;
        auto pricePlace = tickets.order_of_key( -1 * customerPrice);
        auto price = tickets.find_by_order(pricePlace);
        if (*price == 0) {
            cout << -1 << "\n";
        } else {
            cout << -1 * *price << "\n";
            tickets.erase(*price);
        }
        cout << tickets.size() << "\n";
    }

}