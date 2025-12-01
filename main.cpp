#include <iostream>
#include <vector>
using namespace std;

//global absent_count variable to run program
int absent_count = 0;

// Algorithm 1 - Check if a student fails the lecture for the attendance - original function as given by the instructions
bool fail_lecture(const vector<int>& attendence_records) {
    for (int i = 1; i < attendence_records.size(); ++i) { //Fault int i = 1;
        absent_count += attendence_records[i] == 0; 
    }
    return absent_count >= 3;
}

// Algorithm 2 - Fixed Algorithm 1 code 
bool fail_lecture_fixed(const vector<int>& attendence_records) {
    int absent_count = 0; // If absent_count is not a global variable, then it HAS to be initalized in the function
    for (int i = 0; i < attendence_records.size(); ++i) { //Fault B int i = 1;
        absent_count += attendence_records[i] == 0; 
    }
    return absent_count >= 3;
}

int main() {
    vector<int> attendance_records(10);

    cout << "Enter attendance for 10 lectures (1 = present, 0 = absent):\n";
    for (int i = 0; i < 10; ++i) {
        cin >> attendance_records[i];
    }

    // Run faulty algorithm
    absent_count = 0;  // reset global counter
    bool faulty_result = fail_lecture(attendance_records);

    // Run fixed algorithm
    bool fixed_result = fail_lecture_fixed(attendance_records);

    cout << "\n=== RESULTS ===\n";
    cout << "Faulty Algorithm Result: "
         << (faulty_result ? "FAIL" : "PASS") << endl;

    cout << "Fixed Algorithm Result:  "
         << (fixed_result ? "FAIL" : "PASS") << endl;

    return 0;
}