#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structs as required by the problem
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    Workshop* workshops;
};

// Function to initialize the Available_Workshops object
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->workshops = new Workshop[n];

    for (int i = 0; i < n; ++i) {
        aw->workshops[i].start_time = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end_time = start_time[i] + duration[i];
    }
    return aw;
}

// Comparison function for sorting workshops by their end time
bool compareWorkshops(const Workshop& a, const Workshop& b) {
    return a.end_time < b.end_time;
}

// Function to calculate the maximum number of workshops
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    if (ptr->n == 0) {
        return 0;
    }

    // Sort the workshops based on their end time
    sort(ptr->workshops, ptr->workshops + ptr->n, compareWorkshops);

    int attended_count = 1;
    int last_finish_time = ptr->workshops[0].end_time;

    for (int i = 1; i < ptr->n; ++i) {
        if (ptr->workshops[i].start_time >= last_finish_time) {
            attended_count++;
            last_finish_time = ptr->workshops[i].end_time;
        }
    }
    return attended_count;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}