#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numCourses;
    float grade, credit;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "===== GPA & CGPA Calculator =====\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    float grades[numCourses];
    float credits[numCourses];

    // Input grades and credits
    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade Point: ";
        cin >> grades[i];

        cout << "Enter Credit Hours: ";
        cin >> credits[i];

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n\n===== Course Details =====\n";
    cout << left << setw(10) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits"
         << setw(15) << "Grade Points" << endl;

    for (int i = 0; i < numCourses; i++)
    {
        cout << left << setw(10) << i + 1
             << setw(15) << grades[i]
             << setw(15) << credits[i]
             << setw(15) << grades[i] * credits[i]
             << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA       : " << fixed << setprecision(2) << GPA;

    // CGPA Calculation
    int semesters;
    cout << "\n\nEnter total number of semesters: ";
    cin >> semesters;

    float overallGradePoints = 0;
    float overallCredits = 0;

    for (int i = 1; i <= semesters; i++)
    {
        float semGPA, semCredits;

        if (i == 1)
        {
            semGPA = GPA;
            semCredits = totalCredits;
        }
        else
        {
            cout << "\nSemester " << i << endl;
            cout << "Enter GPA: ";
            cin >> semGPA;

            cout << "Enter Total Credits: ";
            cin >> semCredits;
        }

        overallGradePoints += semGPA * semCredits;
        overallCredits += semCredits;
    }

    float CGPA = overallGradePoints / overallCredits;

    cout << "\n================================";
    cout << "\nFinal CGPA : " << fixed << setprecision(2) << CGPA;
    cout << "\n================================" << endl;

    return 0;
}