#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

struct User {
    string username;
    string password;
};

struct Bus {
    string busNumber;
    string origin;
    string destination;
    int departureHour;
    int departureMinute;
    int seatsAvailable;
};

class BusSystem {
    vector<User> users;
    vector<Bus> buses;
    vector<string> stops;
    vector<vector<int>> graph;
    map<string, vector<string>> bookings;
    string loggedInUser;

public:
    void registerUser() {
        string uname, pass;
        cout << "Enter new username: ";
        cin >> uname;
        cout << "Enter new password: ";
        cin >> pass;
        for (auto& u : users) {
            if (u.username == uname) {
                cout << "Username already exists.\n";
                return;
            }
        }
        users.push_back({uname, pass});
        cout << "Registration successful.\n";
    }

    bool loginUser() {
        string uname, pass;
        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pass;
        for (auto& u : users) {
            if (u.username == uname && u.password == pass) {
                loggedInUser = uname;
                cout << "Login successful.\n";
                return true;
            }
        }
        cout << "Invalid credentials.\n";
        return false;
    }

    void addBus(Bus bus) {
        buses.push_back(bus);
    }

    void setupStops(vector<string> s) {
        stops = s;
        graph = vector<vector<int>>(s.size(), vector<int>(s.size(), 0));
    }

    void addRoute(string from, string to, int dist) {
        int i = getIndex(from), j = getIndex(to);
        if (i != -1 && j != -1) {
            graph[i][j] = dist;
            graph[j][i] = dist;
        }
    }

    void displayBuses() {
        for (auto& b : buses) {
            cout << "Bus No: " << b.busNumber << ", From: " << b.origin
                 << ", To: " << b.destination << ", Departure: "
                 << b.departureHour << ":" << b.departureMinute
                 << ", Seats: " << b.seatsAvailable << endl;
        }
    }

    void selectionSortByDeparture() {
        int n = buses.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (timeCompare(buses[j], buses[minIdx]))
                    minIdx = j;
            }
            swap(buses[i], buses[minIdx]);
        }
    }

    bool timeCompare(Bus& a, Bus& b) {
        if (a.departureHour != b.departureHour)
            return a.departureHour < b.departureHour;
        return a.departureMinute < b.departureMinute;
    }

    void searchBus(string busNumber) {
        selectionSortByNumber();
        int index = binarySearch(busNumber);
        if (index == -1)
            cout << "Bus not found.\n";
        else {
            Bus& b = buses[index];
            cout << "Found - Bus No: " << b.busNumber << ", From: " << b.origin
                 << ", To: " << b.destination << ", Departure: "
                 << b.departureHour << ":" << b.departureMinute
                 << ", Seats: " << b.seatsAvailable << endl;
        }
    }

    void selectionSortByNumber() {
        int n = buses.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (buses[j].busNumber < buses[minIdx].busNumber)
                    minIdx = j;
            }
            swap(buses[i], buses[minIdx]);
        }
    }

    int binarySearch(string busNumber) {
        int l = 0, r = buses.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (buses[m].busNumber == busNumber)
                return m;
            else if (buses[m].busNumber < busNumber)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    void dijkstra(string start, string end) {
        int n = stops.size();
        vector<int> dist(n, numeric_limits<int>::max());
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        int src = getIndex(start), dst = getIndex(end);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        if (dist[dst] == numeric_limits<int>::max()) {
            cout << "No route found.\n";
            return;
        }
        vector<string> path;
        for (int at = dst; at != -1; at = parent[at])
            path.push_back(stops[at]);
        reverse(path.begin(), path.end());
        cout << "Shortest path (" << dist[dst] << " km): ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }

    int getIndex(string name) {
        for (int i = 0; i < stops.size(); ++i)
            if (stops[i] == name) return i;
        return -1;
    }

    void bookTicket(string busNumber) {
        int idx = binarySearch(busNumber);
        if (idx == -1 || buses[idx].seatsAvailable <= 0) {
            cout << "Bus not available.\n";
            return;
        }
        buses[idx].seatsAvailable--;
        bookings[loggedInUser].push_back(busNumber);
        cout << "Ticket booked successfully.\n";
    }

    void viewMyBookings() {
        if (bookings[loggedInUser].empty()) {
            cout << "No bookings found.\n";
            return;
        }
        cout << "Your Booked Buses:\n";
        for (auto& b : bookings[loggedInUser]) {
            cout << b << endl;
        }
    }
};

int main() {

    cout << "\n============================================================\n";
    cout << "     ____  _                 _       _     _                \n";
    cout << "    |  _ \\| | ___   ___ __ _| |_ ___| |__ (_)_ __   ___     \n";
    cout << "    | |_) | |/ _ \\ / __/ _` | __/ __| '_ \\| | '_ \\ / _ \\ \n";
    cout << "    |  __/| | (_) | (_| (_| | || (__| | | | | | | | (_) |    \n";
    cout << "    |_|   |_|\\___/ \\___\\__,_|\\__\\___|_| |_|_|_| |_|\\___/ \n";
    cout << "                                                            \n";

    cout << "\n===========================================================\n";
    cout << "         WELCOME TO METRO BUS SYSTEM         \n";
    cout << "=============================================\n";
    cout << "     Efficient | Reliable | Convenient       \n";
    cout << "---------------------------------------------\n";
    cout << "  Book your journey across Delhi NCR with us!\n";
    cout << "=============================================\n\n";
    
    BusSystem system;
    system.setupStops({"Delhi", "Noida", "Meerut", "Rewari", "Ghaziabad"});

    system.addRoute("Delhi", "Noida", 5);
    system.addRoute("Noida", "Meerut", 7);
    system.addRoute("Meerut", "Rewari", 4);
    system.addRoute("Rewari", "Ghaziabad", 6);
    system.addRoute("Delhi", "Meerut", 10);
    system.addRoute("Noida", "Rewari", 8);
    
    system.addBus({"B101", "Delhi", "Noida", 9, 30, 10});
    system.addBus({"B102", "Noida", "Meerut", 10, 15, 8});
    system.addBus({"B103", "Meerut", "Rewari", 11, 45, 12});
    system.addBus({"B104", "Delhi", "Rewari", 12, 20, 6});
    system.addBus({"B105", "Rewari", "Ghaziabad", 14, 0, 7});

  
    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            system.registerUser();
        } else if (choice == 2) {
            if (!system.loginUser()) continue;
            int opt;
            while (true) {
                cout << "\n--- User Dashboard ---\n";
                cout << "1. View Buses\n2. Search Bus\n3. Sort by Departure\n";
                cout << "4. Book Ticket\n5. View Bookings\n6. Shortest Route\n7. Logout\nChoose: ";
                cin >> opt;
                if (opt == 1) system.displayBuses();
                else if (opt == 2) {
                    string bno; cout << "Enter Bus Number: "; cin >> bno;
                    system.searchBus(bno);
                }
                else if (opt == 3) {
                    system.selectionSortByDeparture();
                    system.displayBuses();
                }
                else if (opt == 4) {
                    string bno; cout << "Enter Bus Number to Book: "; cin >> bno;
                    system.bookTicket(bno);
                }
                else if (opt == 5) system.viewMyBookings();
                else if (opt == 6) {
                    string src, dst;
                    cout << "From: "; cin >> src;
                    cout << "To: "; cin >> dst;
                    system.dijkstra(src, dst);
                }
                else if (opt == 7) break;
                else cout << "Invalid option.\n";
            }
        } else if (choice == 3) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
 