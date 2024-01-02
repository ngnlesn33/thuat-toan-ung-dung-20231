#include <bits/stdc++.h>

using namespace std;

time_t convertToTimeT(string &time);

vector<tuple<string, string, string, string, int>>
firstAndLastTrip(vector<tuple<string, string, string, string, int>> &, const string &);

void sortDataByDateTime(vector<tuple<string, string, string, string, int>> &);

vector<pair<time_t, time_t>> tripsTime(vector<tuple<string, string, string, string, int>> &);

void readData(vector<tuple<string, string, string, string, int>> &);

int TOTAL_QTY(vector<tuple<string, string, string, string, int>> &);

int QTY_CUSTOMER(vector<tuple<string, string, string, string, int>> &, const string &);

int
QTY_MAX_PERIOD(vector<tuple<string, string, string, string, int>> &, string, const string &, string, const string &);

set<string> TOTAL_TRIPS(vector<tuple<string, string, string, string, int>> &);

int TRAVEL_TIME_TRIP(vector<tuple<string, string, string, string, int>> &, const string &);

int dfs(int idx, vector<pair<time_t, time_t>> &trips, vector<pair<time_t, time_t>> &current_set);

int MAX_CONFLICT_TRIPS(vector<tuple<string, string, string, string, int>> &);

void readQuery(vector<tuple<string, string, string, string, int>> &);

int main() {
    vector<tuple<string, string, string, string, int>> data;
    readData(data);
    sortDataByDateTime(data);
    readQuery(data);
    return 0;
}

void readData(vector<tuple<string, string, string, string, int>> &data) {
    string tripCode, customerCode, date, time;
    int qty;
    while (cin >> tripCode && tripCode != "***") {
        cin >> customerCode >> date >> time >> qty;
        data.emplace_back(tripCode, customerCode, date, time, qty);
    }
}

// Total qty with format TOTAL_QTY until *** and return total qty of all data
int TOTAL_QTY(vector<tuple<string, string, string, string, int>> &data) {
    int totalQty = 0;
    for (const auto &trip: data) {
        auto qty = get<4>(trip);
        totalQty += qty;
    }
    return totalQty;
}

// Total qty with format QTY_CUSTOMER <customer_code> until *** and return total qty of customer with customer_code
int QTY_CUSTOMER(vector<tuple<string, string, string, string, int>> &data, const string &customerCode) {
    int totalQtyCustomer = 0;
    for (const auto &trip: data) {
        auto currentCustomerCode = get<1>(trip);
        auto qty = get<4>(trip);
        if (customerCode == currentCustomerCode) {
            totalQtyCustomer += qty;
        }
    }
    return totalQtyCustomer;
}

// Return max qty in period from from_date from_time to to_date to_time
int QTY_MAX_PERIOD(vector<tuple<string, string, string, string, int>> &data, string from_date, const string &from_time,
                   string to_date, const string &to_time) {
    int maxQty = 0;
    string tStrFrom = from_date.append(" ").append(from_time);
    string tStrTo = to_date.append(" ").append(to_time);
    time_t from = convertToTimeT(tStrFrom);
    time_t to = convertToTimeT(tStrTo);
    for (const auto &trip: data) {
        auto date = get<2>(trip);
        auto time = get<3>(trip);
        auto qty = get<4>(trip);
        string tStr = date.append(" ").append(time);
        time_t t = convertToTimeT(tStr);
        if (t >= from && t <= to) {
            maxQty = max(maxQty, qty);
        }
    }
    return maxQty;
}

// Return number of all trips with different trip code
set<string> TOTAL_TRIPS(vector<tuple<string, string, string, string, int>> &data) {
    set<string> tripCodes;
    for (const auto &trip: data) {
        string tripCode;
        tripCode = get<0>(trip);
        tripCodes.insert(tripCode);
    }
    return tripCodes;
}

// Sort data by date and time
void sortDataByDateTime(vector<tuple<string, string, string, string, int>> &data) {
    // sort data by date and time of trip code and then by qty.
    sort(data.begin(), data.end(),
         [](const tuple<string, string, string, string, int> &a, const tuple<string, string, string, string, int> &b) {
             auto dateA = get<2>(a);
             auto timeA = get<3>(a);
             auto qtyA = get<4>(a);

             auto dateB = get<2>(b);
             auto timeB = get<3>(b);
             auto qtyB = get<4>(b);

             time_t tA = convertToTimeT(dateA.append(" ").append(timeA));
             time_t tB = convertToTimeT(dateB.append(" ").append(timeB));

             return (tA != tB) ? (tA < tB) : (qtyA < qtyB);
         });
}

// Convert to time_t object
time_t convertToTimeT(string &time) {
    tm tm = {};
    istringstream ss(time);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
    time_t t = mktime(&tm);
    return t;
}

// Return first and last trip of trip code
vector<tuple<string, string, string, string, int>>
firstAndLastTrip(vector<tuple<string, string, string, string, int>> &data,
                 const string &tripCode) {
    vector<tuple<string, string, string, string, int>> tripData;
    // find first and last customer of trip code
    string currentTripCode;
    for (int i = 0; i <= data.size() - 1; i++) {
        currentTripCode = get<0>(data[i]);
        if (currentTripCode == tripCode) {
            tripData.push_back(data[i]);
            break;
        }
    }
    for (int i = data.size() - 1; i >= 0; i--) {
        currentTripCode = get<0>(data[i]);
        if (currentTripCode == tripCode) {
            tripData.push_back(data[i]);
            break;
        }
    }
    return tripData;
}

// Return total time of trip with <trip_code>. Total time is time from first customer to last customer. The time insert in data is not sorted by time and date, so we need to sort it first by date and time of trip code and then calculate total time of trip code by subtracting time of first customer and last customer of trip code and return total time of trip code in minutes (round up) with format TRAVEL_TIME_TRIP <trip_code> until ***.
int TRAVEL_TIME_TRIP(vector<tuple<string, string, string, string, int>> &data, const string &tripCode) {
    vector<tuple<string, string, string, string, int>> tripData = firstAndLastTrip(data, tripCode);
    // Get the date and time of first and last customer of trip code
    auto dateFirst = get<2>(tripData[0]);
    auto timeFirst = get<3>(tripData[0]);
    auto dateLast = get<2>(tripData[1]);
    auto timeLast = get<3>(tripData[1]);
    string tStrFirst = dateFirst + " " + timeFirst;
    string tStrLast = dateLast + " " + timeLast;
    time_t tFirst = convertToTimeT(tStrFirst);
    time_t tLast = convertToTimeT(tStrLast);
    int totalSecond = difftime(tLast, tFirst);
    return totalSecond;
}

// Return all the trip time pair
vector<pair<time_t, time_t>> tripsTime(vector<tuple<string, string, string, string, int>> &data) {
    vector<pair<time_t, time_t>> trips;
    string startTrip, endTrip;
    for (const auto &trip: TOTAL_TRIPS(data)) {
        vector<tuple<string, string, string, string, int>> tripData = firstAndLastTrip(data, trip);
        startTrip = get<2>(tripData[0]) + " " + get<3>(tripData[0]);
        endTrip = get<2>(tripData[1]) + " " + get<3>(tripData[1]);
        // add the pair of start trip and end trip to the vector
        trips.emplace_back(convertToTimeT(startTrip), convertToTimeT(endTrip));
    }
    return trips;
}

// Function to perform depth-first search
int dfs(int idx, vector<pair<time_t, time_t>> &trips, vector<pair<time_t, time_t>> &current_set) {
    // If we have checked all trips, return the size of the current set
    if (idx == trips.size()) {
        return current_set.size();
    }
    int taken = 0;
    bool overlap = true;
    // Check if the current trip overlaps with all trips in the current set
    for (auto &trip: current_set) {
        time_t startTrip1 = trips[idx].first;
        time_t endTrip1 = trips[idx].second;
        time_t startTrip2 = trip.first;
        time_t endTrip2 = trip.second;
        if (startTrip1 > endTrip2 || endTrip1 < startTrip2) {
            overlap = false;
            break;
        }
    }
    // If the current trip overlaps with all trips in the current set, add it to the set and recurse
    if (overlap) {
        current_set.push_back(trips[idx]);
        taken = dfs(idx + 1, trips, current_set);
        current_set.pop_back(); // Remove the current trip from the set after exploring
    }
    // Recurse without adding the current trip to the set
    int not_taken = dfs(idx + 1, trips, current_set);
    // Return the maximum of taken and not_taken
    return max(taken, not_taken);
}

// Function to find the maximum number of overlapping trips
int MAX_CONFLICT_TRIPS(vector<tuple<string, string, string, string, int>> &data) {
    vector<pair<time_t, time_t>> trips = tripsTime(data);
    vector<pair<time_t, time_t>> current_set; // Initialize the current set as empty
    // Start the depth-first search
    return dfs(0, trips, current_set);
}

// read query with format TOTAL_QTY until *** and return total qty of all data
void readQuery(vector<tuple<string, string, string, string, int>> &data) {
    string query;
    while (cin >> query && query != "***") {
        if (query == "TOTAL_QTY") {
            cout << TOTAL_QTY(data) << endl;
        }
        if (query == "QTY_CUSTOMER") {
            string customerCode;
            cin >> customerCode;
            cout << QTY_CUSTOMER(data, customerCode) << endl;
        }
        if (query == "QTY_MAX_PERIOD") {
            string from_date, from_time, to_date, to_time;
            cin >> from_date >> from_time >> to_date >> to_time;
            cout << QTY_MAX_PERIOD(data, from_date, from_time, to_date, to_time) << endl;
        }
        if (query == "TOTAL_TRIPS") {
            cout << TOTAL_TRIPS(data).size() << endl;
        }
        if (query == "TRAVEL_TIME_TRIP") {
            string tripCode;
            cin >> tripCode;
            cout << TRAVEL_TIME_TRIP(data, tripCode) << endl;
        }
        if (query == "MAX_CONFLICT_TRIPS") {
            cout << MAX_CONFLICT_TRIPS(data) << endl;
        }
    }
}
