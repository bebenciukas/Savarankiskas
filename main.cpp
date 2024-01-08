#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

struct Student {
    string name;
    string surname;
    vector<int> Ivert;
    int Egz;
    double Pazim; };


double Galutinis(const vector<int>& Ivert, int Egz) {
    double sum = 0;
    for (int grade : Ivert) {sum += grade;}
    double Vid = sum / Ivert.size();
    return 0.4 * Vid + 0.6 * Egz;}

void STRAT(vector<Student>& students, vector<Student>& prasciok) {
auto partitionIt = stable_partition(students.begin(), students.end(),
[](const Student& student) { return student.Pazim < 5.0; });
    move(partitionIt, students.end(), back_inserter(prasciok));

    // Erase poor students from the original container
    students.erase(partitionIt, students.end());
}
int main() {
    // Read data from file and create vector container
  string filename;
    cout << "Iveskite failo pilna pavadinima: ";
    cin >> filename;
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Nepavyko atidaryti tokio failo: " << filename << endl;
        return 1;
    }

    string line;
    vector<Student> studentsVector;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Student student;
        iss >> student.name >> student.surname;
       int grade;
        while (iss >> grade) {student.Ivert.push_back(grade);}
        student.Egz = grade;
        student.Pazim = Galutinis(student.Ivert, student.Egz);
        studentsVector.push_back(student);
    }

    auto start = chrono::high_resolution_clock::now();

    vector<Student> Prasciokai;
    STRAT(studentsVector,  Prasciokai);
    auto end = chrono::high_resolution_clock::now();
    auto BendraTrukme = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
    cout << fixed << setprecision(5) << BendraTrukme << " s\n";

    return 0;
}
