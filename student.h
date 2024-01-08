#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student {
public:
    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    void setName(const string& newName);
    void setSurname(const string& newSurname);
    void addHomeworkGrade(int grade);
    void setExamGrade(int grade);
    double calculateFinalGrade() const;
    double calculateAverage() const;
    double calculateMedian() const;
    void Rez() const;
    void RANDOMGEN();
    string getSurname() const {return surname; }

private:
    string name;
    string surname;
    vector<int> homeworkGrades;
    int examGrade;
};

#endif // STUDENT_H
