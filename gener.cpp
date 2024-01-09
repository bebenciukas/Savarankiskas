#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateStudentFile(const string& fileName, int numRecords) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }
    outFile << setw(10) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        outFile << setw(8) << "ND" + to_string(i);
    }
    outFile << setw(8) << "Egz." << endl;

    for (int i = 1; i <= numRecords; ++i) {
        outFile << setw(10) << "Vardas" + to_string(i)
            << setw(20) << "Pavarde" + to_string(i);

        for (int j = 0; j < 15; ++j) {
            outFile << setw(8) << generateRandomNumber(1, 10);
        }

        outFile <<setw(8) << generateRandomNumber(1, 10) << endl;
    }

    outFile.close();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    generateStudentFile("studentai1000.txt", 1000);
    generateStudentFile("studentai10000.txt", 10000);
    generateStudentFile("studentai100000.txt", 100000);
    generateStudentFile("studentai1000000.txt", 1000000);
    generateStudentFile("studentai10000000.txt", 10000000);

    cout << "Studentu failai sukurti sekmingai!" <<endl;

    return 0;
}
