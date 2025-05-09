//
// Created by Joey Tamondong on 5/6/25.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Train type definitions
enum TrainType { TYPE_A, TYPE_B, TYPE_AB };

// struct: holds station name and type
struct TransitStation {
    string stationName;
    TrainType stationType;

    TransitStation(const string &name, TrainType type) {
        stationName = name;
        stationType = type;
    }
};

// Function to convert enum to string
string trainTypeToString(TrainType t) {
    switch (t) {
        case TYPE_A: return "A";
        case TYPE_B: return "B";
        case TYPE_AB: return "A/B";
        default: return "Unknown";
    }
}

// Print schedule with filters
void showSchedule(const vector<TransitStation>& routeMap, const string& header, int filter, bool includeRandom = false) {
    cout << "\n=== " << header << " ===\n";
    for (size_t i = 0; i < routeMap.size(); ++i) {
        const TransitStation& station = routeMap[i];
        bool printIt = false;

        if (filter == TYPE_AB && station.stationType == TYPE_AB)
            printIt = true;
        else if (filter == TYPE_A && (station.stationType == TYPE_A || station.stationType == TYPE_AB))
            printIt = true;
        else if (filter == TYPE_B && (station.stationType == TYPE_B || station.stationType == TYPE_AB))
            printIt = true;
        else if (filter == -1)
            printIt = true;

        if (printIt) {
            cout << "* " << station.stationName << " [" << trainTypeToString(station.stationType) << "]";
            if (includeRandom) {
                int embarks = rand() % 100;
                int disembarks = rand() % 100;
                cout << " | On: " << embarks << ", Off: " << disembarks;
            }
            cout << "\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness


    vector<TransitStation> NWMetroRoute;
    NWMetroRoute.push_back(TransitStation("Main Terminal", TYPE_AB));
    NWMetroRoute.push_back(TransitStation("Cleveland Avenue", TYPE_A));
    NWMetroRoute.push_back(TransitStation("Illinois Street", TYPE_B));
    NWMetroRoute.push_back(TransitStation("Harper Plaza Station", TYPE_AB));
    NWMetroRoute.push_back(TransitStation("Avondale Avenue", TYPE_B));
    NWMetroRoute.push_back(TransitStation("Sedgwick Street", TYPE_B));
    NWMetroRoute.push_back(TransitStation("Shopping District", TYPE_A));
    NWMetroRoute.push_back(TransitStation("Jefferson Port", TYPE_AB));
    NWMetroRoute.push_back(TransitStation("Lake Avenue", TYPE_A));
    NWMetroRoute.push_back(TransitStation("Reagan Junction", TYPE_B));
    NWMetroRoute.push_back(TransitStation("Northwest Terminal", TYPE_AB));

    int userPick;
    cout << "=== MRTS Schedule Display ===\n";
    cout << "[1] A Train Stops Only\n";
    cout << "[2] B Train Stops Only\n";
    cout << "[3] A/B Train Stops Only\n";
    cout << "[4] All Stops\n";
    cout << "Pick yo vibe (1-4): ";
    cin >> userPick;

    switch (userPick) {
        case 1:
            showSchedule(NWMetroRoute, "A Train Route", TYPE_A, true);
            break;
        case 2:
            showSchedule(NWMetroRoute, "B Train Route", TYPE_B, true);
            break;
        case 3:
            showSchedule(NWMetroRoute, "A/B Train Route", TYPE_AB, true);
            break;
        case 4:
            showSchedule(NWMetroRoute, "Full Route (All Stops)", -1, true);
            break;
        default:
            cout << "ayo, pick a valid option.\n";
    }

    return 0;
}