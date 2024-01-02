#include <bits/stdc++.h>

using namespace std;

time_t convertToTimeT(string &time);

//// Convert time from hh:mm:ss format to hour, minute, second
//void convertHourMinuteSecond(int &hour, int &minute, int &second, string &time) {
//    hour = stoi(time.substr(0, 2));
//    minute = stoi(time.substr(3, 2));
//    second = stoi(time.substr(6, 2));
//}
//
//// Convert YYYY-MM-DD format to year, month, day
//void convertYearMonthDay(int &year, int &month, int &day, string &date) {
//    year = stoi(date.substr(0, 4));
//    month = stoi(date.substr(5, 2));
//    day = stoi(date.substr(8, 2));
//}
//
//// read date until "*" and store in vector
//void readDate(vector<string> &dates) {
//    string date;
//    while (cin >> date && date != "*") {
//        dates.push_back(date);
//    }
//}

// Data input with <trip_code> <customer_code> <date> <time> qty format. Read until "***" and store in vector of tuple
// (trip_code, customer_code, date, qty) and return the vector of tuple

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
    for (const auto &res: data) {
        string tripCode, customerCode, date, time;
        int qty;
        tie(tripCode, customerCode, date, time, qty) = res;
        totalQty += qty;
    }
    return totalQty;
}

// Total qty with format QTY_CUSTOMER <customer_code> until *** and return total qty of customer with customer_code
int QTY_CUSTOMER(vector<tuple<string, string, string, string, int>> &data, const string &customerCode) {
    int totalQtyCustomer = 0;
    for (const auto &res: data) {
        string tripCode, currentCustomerCode, date, time;
        int qty;
        tie(tripCode, currentCustomerCode, date, time, qty) = res;
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
    for (const auto &res: data) {
        string tripCode, customerCode, date, time;
        int qty;
        tie(tripCode, customerCode, date, time, qty) = res;
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
    for (const auto &res: data) {
        string tripCode, customerCode, date, time;
        int qty;
        tie(tripCode, customerCode, date, time, qty) = res;
        tripCodes.insert(tripCode);
    }
    return tripCodes;
}

// Sort data by date and time
void sortDataByDateTime(vector<tuple<string, string, string, string, int>> &data) {
    sort(data.begin(), data.end(),
         [](const tuple<string, string, string, string, int> &a, const tuple<string, string, string, string, int> &b) {
             string tripCodeA, customerCodeA, dateA, timeA;
             int qtyA;
             tie(tripCodeA, customerCodeA, dateA, timeA, qtyA) = a;
             string tripCodeB, customerCodeB, dateB, timeB;
             int qtyB;
             tie(tripCodeB, customerCodeB, dateB, timeB, qtyB) = b;
             time_t tA = convertToTimeT(dateA.append(" ").append(timeA));
             time_t tB = convertToTimeT(dateB.append(" ").append(timeB));
             if (tA != tB) {
                 return tA < tB;
             }
             return qtyA < qtyB;
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

// Return total time of trip with <trip_code>. Total time is time from first customer to last customer. The time insert in data is not sorted by time and date, so we need to sort it first by date and time of trip code and then calculate total time of trip code by subtracting time of first customer and last customer of trip code and return total time of trip code in minutes (round up) with format TRAVEL_TIME_TRIP <trip_code> until ***.
int TRAVEL_TIME_TRIP(vector<tuple<string, string, string, string, int>> &data, const string &tripCode) {
    int totalTravelTime = 0;
    vector<tuple<string, string, string, string, int>> tripData;
    for (const auto &res: data) {
        string currentTripCode, customerCode, date, time;
        int qty;
        tie(currentTripCode, customerCode, date, time, qty) = res;
        if (currentTripCode == tripCode) {
            tripData.push_back(res);
        }
    }
    //    sortDataByDateTime(tripData);
    string tripCodeFirst, customerCodeFirst, dateFirst, timeFirst;
    int qtyFirst;
    tie(tripCodeFirst, customerCodeFirst, dateFirst, timeFirst, qtyFirst) = tripData[0];
    string tripCodeLast, customerCodeLast, dateLast, timeLast;
    int qtyLast;
    tie(tripCodeLast, customerCodeLast, dateLast, timeLast, qtyLast) = tripData[tripData.size() - 1];
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
        // loop from the beginning of the data to find the first trip of the trip code and then break the loop.
        for (const auto &i: data) {
            string tripCode, customerCode, date, time;
            int qty;
            tie(tripCode, customerCode, date, time, qty) = i;
            if (tripCode == trip) {
                startTrip = date.append(" ").append(time);
                break;
            }
        }
        // loop from the end of the data to find the last trip of the trip code and then break the loop.
        for (int i = data.size() - 1; i >= 0; i--) {
            string tripCode, customerCode, date, time;
            int qty;
            tie(tripCode, customerCode, date, time, qty) = data[i];
            if (tripCode == trip) {
                endTrip = date.append(" ").append(time);
                break;
            }
        }
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

int main() {
    // vector<string> dates;
    // readDate(dates);
    vector<tuple<string, string, string, string, int>> data;
    readData(data);
    sortDataByDateTime(data);
//    readQuery(data);
    // print data
    for (const auto &res: data) {
        string tripCode, customerCode, date, time;
        int qty;
        tie(tripCode, customerCode, date, time, qty) = res;
        cout << tripCode << " " << customerCode << " " << date << " " << time << " " << qty << endl;
    }
    return 0;
}