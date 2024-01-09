#include "student.h"
#include <numeric>
#include <algorithm> 
#include <iomanip>

using namespace std;
Student::Student() : examGrade(0) {}
Student::~Student() {}

Student::Student(const Student& other) {
    this->name = other.name;
    this->surname = other.surname;
    this->homeworkGrades = other.homeworkGrades;
    this->examGrade = other.examGrade;
}
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        this->name = other.name;
        this->surname = other.surname;
        this->homeworkGrades = other.homeworkGrades;
        this->examGrade = other.examGrade;
    }
    return *this;
}

void Student::setName(const string& newName) {name = newName;}
void Student::setSurname(const string& newSurname) {surname = newSurname;}
void Student::addHomeworkGrade(int grade) {if (grade >= 0 && grade <= 10) {homeworkGrades.push_back(grade);}}
void Student::setExamGrade(int grade) {if (grade >= 0 && grade <= 10) {examGrade = grade;}}
double Student::calculateFinalGrade() const {if (homeworkGrades.empty()) {return 0.6 * examGrade; }
double average = calculateAverage();
return 0.4 * average + 0.6 * examGrade;
}

double Student::calculateAverage() const {if (homeworkGrades.empty()) {return 0.0; }
    double total = static_cast<double>(accumulate(homeworkGrades.begin(), homeworkGrades.end(), 0));
    return total / homeworkGrades.size();
}

double Student::calculateMedian() const {if (homeworkGrades.empty()) {return 0.0; }
    vector<int> sortedGrades = homeworkGrades;
    sort(sortedGrades.begin(), sortedGrades.end());
    size_t size = sortedGrades.size();
    if (size % 2 == 0) { return (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0; } 
    else {return sortedGrades[size / 2]; }
}


void Student::Rez() const {
    cout << left << setw(12) << surname << setw(12) << name;
    cout << fixed << setprecision(2);
    cout << setw(12) << calculateFinalGrade() << setw(12) << calculateMedian() << endl;
}
void Student::RANDOMGEN() {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 5; ++i) {addHomeworkGrade(rand() % 11); }
    setExamGrade(rand() % 11); }
