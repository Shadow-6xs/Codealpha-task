#include <iostream>
#include <map>
#include <string>
#include <iomanip> // For setting precision

using namespace std;

// Function to convert letter grades to grade points
double getGradePoint(const string& grade) {
    map<string, double> gradeToPoint = {
        {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0},
        {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    // Check if the grade exists in the map
    if (gradeToPoint.find(grade) != gradeToPoint.end()) {
        return gradeToPoint[grade];
    }
    else {
        cout << "Invalid grade entered: " << grade << ". Assuming grade point as 0.0" << endl;
        return 0.0;
    }
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    double totalPoints = 0.0; // To store the sum of (Grade Point * Credit Hours)
    double totalCredits = 0.0; // To store the total credit hours

    for (int i = 1; i <= numSubjects; ++i) {
        string grade;
        double credits;

        cout << "Enter grade for subject " << i << " (e.g., A, B+, C-): ";
        cin >> grade;

        cout << "Enter credit hours for subject " << i << ": ";
        cin >> credits;

        // Get the grade point for the entered grade
        double gradePoint = getGradePoint(grade);

        // Update totals
        totalPoints += gradePoint * credits;
        totalCredits += credits;
    }

    // Calculate CGPA
    if (totalCredits > 0) {
        double cgpa = totalPoints / totalCredits;
        cout << fixed << setprecision(2); // Set output to 2 decimal places
        cout << "Your CGPA is: " << cgpa << endl;
    }
    else {
        cout << "Total credit hours cannot be zero. Unable to calculate CGPA." << endl;
    }

    return 0;
}