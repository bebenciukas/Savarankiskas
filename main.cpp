#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

struct Student {
    string name;
    string surname;
    deque<int> grades;
    int examGrade;
    double finalGrade; };

//*** Galutinio vidurkio suskaiciavimas ***
double calculateFinalGrade(const deque<int>& grades, int examGrade) {
    double sum = 0;
    for (int grade : grades) {sum += grade;}
    double average = sum / grades.size();
    return 0.4 * average + 0.6 * examGrade;}

int main() {
  
    //*** Failo pasirinkimas ***
    string filename;
    cout << "Iveskite failo pilna pavadinima: ";
    cin >> filename;
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Nepavyko atidaryti tokio failo: " << filename << endl;
        return 1;
    }

    //*** Pradedamas matuoti laikas ***
    auto start = chrono::high_resolution_clock::now();
    string line;
    deque<Student> students;
    getline(inputFile, line);

    auto FailuNuskStart = chrono::high_resolution_clock::now();

    while (getline(inputFile, line)) {
        istringstream iss(line);
        Student student;
        iss >> student.name >> student.surname;

        int grade;
        while (iss >> grade) {
            student.grades.push_back(grade);
        }
        student.examGrade = grade;
        student.finalGrade = calculateFinalGrade(student.grades, student.examGrade);
        students.push_back(student);
    }

    auto FailuNuskEnd = chrono::high_resolution_clock::now();

    //*** Studentu sarasas isrikiuojamas pagal vidurki ***
    auto IsskirstStart = chrono::high_resolution_clock::now();
    sort(students.begin(), students.end(),
    [](const Student& a, const Student& b) {return a.finalGrade < b.finalGrade;});
    auto IsskirstEnd = chrono::high_resolution_clock::now();

    //*** Irasymo i failus ir naujo failo kūrimo laiko matavimo pradzia ***
    ofstream prasciokaiFile("prasciokai.txt");
    ofstream pirmunaiFile("pirmunai.txt");

    if (!prasciokaiFile.is_open() || !pirmunaiFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    auto IrasymStart = chrono::high_resolution_clock::now();
    for (const Student& student : students) {
    if (student.finalGrade < 5.0) { prasciokaiFile << student.name << " " << student.surname << " " << fixed << setprecision(2) << student.finalGrade << "\n";}
    else { pirmunaiFile << student.name << " " << student.surname << " " << fixed << setprecision(2) << student.finalGrade << "\n";}
    }
    auto IrasymEnd = chrono::high_resolution_clock::now();

    //*** Uždarymas ***
    prasciokaiFile.close();
    pirmunaiFile.close();
    inputFile.close();

    auto end = chrono::high_resolution_clock::now();

    //*** Laiko atvaizdavimas sekundziu pavidalu ***
    auto BendraTrukme = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
    auto DuomNusk = chrono::duration_cast<chrono::milliseconds>(FailuNuskEnd - FailuNuskStart).count() / 1000.0;
    auto Isskirstymas = chrono::duration_cast<chrono::milliseconds>(IsskirstEnd - IsskirstStart).count() / 1000.0;
    auto Irasymas = chrono::duration_cast<chrono::milliseconds>(IrasymEnd - IrasymStart).count() / 1000.0;

    //*** Rezultatai ***
    cout << "Bendra trukme: " << fixed << setprecision(5) << BendraTrukme << " s\n";
    cout << "Duomenu nuskaitymas is failo: " << fixed << setprecision(5) << DuomNusk << " s\n";
    cout << "Isskirstymas uztruko: " << fixed << setprecision(5) << Isskirstymas << " s\n";
    cout << "Failu irasymas uztruko: " << fixed << setprecision(5) << Irasymas << " s\n";

    return 0;
}
