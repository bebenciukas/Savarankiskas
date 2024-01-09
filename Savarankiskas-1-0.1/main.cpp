#include <iostream>
#include <vector>
#include <fstream> 
#include <limits>
#include "student.h"

using namespace std;

//*** Rusiavimas vykdomas atsizvelgiant i pirmaja pavardes raide ***
bool compareBySurnameInitial(const Student& a, const Student& b) {
    return a.getSurname()[0] < b.getSurname()[0];
}
int main() {
  //*** paprastas UI | Do while loop, kad programa neuzsidarytu pasirinkus neegzistuojanti punkta ***
  char Pasirinkimas;
  do {
      cout << "Pasirinkite:\n";
      cout << "------------------------\n";
      cout << "1. Ivesti duomenis ranka\n";
      cout << "2. Nuskaityti duomenis is failo\n";
      cout << "3. Sugeneruoti atsitiktinius (random) pazymius\n";
      cout << "1|2|3: ";
      cin >> Pasirinkimas;

      if (Pasirinkimas != '1' && Pasirinkimas != '2' && Pasirinkimas != '3') {
          cout << "\nPasirinkote neimanoma varianta.\n";
      }
  } while (Pasirinkimas != '1' && Pasirinkimas != '2' && Pasirinkimas != '3');

      //*** Random pazymiu ivedimas ***  
      if (Pasirinkimas == '3') {
        Student student;
        string name, surname;
        cout << "Iveskite varda: ";
        cin >> name;
        student.setName(name);
        cout << "Iveskite pavarde: ";
        cin >> surname;
        student.setSurname(surname);
        student.RANDOMGEN();
        cout << "\nAtsitiktinai sugeneruotu pazymiu vidurkis ir mediana:\n";
        cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas";
        cout << setw(12) << "Galutinis(Vid.)" << setw(12) << " Galutinis(Med.)\n";
        cout << "----------------------------------------------------\n";
        student.Rez();
    }

    //*** Nuskaitymo is kursiokai.txt failo pasirinkimas ***
      if (Pasirinkimas == '2') {
        string filename;
        cout << "Iveskite failo pilna pavadinima: ";
        cin >> filename;
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Nepavyko atidaryti tokio failo: " << filename << endl;
            return 1;
        }
        //** pirmosios eilutes |headerio| praleidimas **
        string header;
        getline(inputFile, header);
        
        //** Isvesti duomenys **
        cout << "\nIs failo nuskaityti ir surusiuoti duomenys:" << endl;
        cout << "\nPavarde     Vardas      Galutinis(Vid.) Galutinis(Med.)\n";
        cout << "------------------------------------------------------\n";


        //** Nuskaitymas ir ivedimas **
        vector<Student> students; 
        string surname, name;
        int hw1, hw2, hw3, hw4, hw5, exam;
        while (inputFile >> surname >> name >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
            Student student;
            student.setName(surname);
            student.setSurname(name);
            student.addHomeworkGrade(hw1);
            student.addHomeworkGrade(hw2);
            student.addHomeworkGrade(hw3);
            student.addHomeworkGrade(hw4);
            student.addHomeworkGrade(hw5);
            student.setExamGrade(exam);

            students.push_back(student);
        }

        //*** Sortingas pagal pavardes pirmaji iniciala ***
        sort(students.begin(), students.end(), compareBySurnameInitial);
        for (const auto& student : students) { student.Rez();  }
        
        inputFile.close();
    }
  
    //*** Duomenys ivedami ranka ***
  
    if(Pasirinkimas =='1') {
        Student student;
        string name, surname;
        cout << "Iveskite varda: ";
        cin >> name;
        student.setName(name);

        cout << "Iveskite pavarde: ";
        cin >> surname;
        student.setSurname(surname);

        //** Namu darbu ivedimas **
        vector<int> homeworkGrades;
        cout << "Iveskite namu darbu pazymius atskirtus tarpu (nebaikite ivedimo tarpu): ";
        while (true) {
            int grade;
            if (!(cin >> grade)) {
              
            //** kad nereiketu rasyti atitinkamo simbolio nutraukimui, nuskaito Enter **
              
                if (cin.eof()) { break;  }
                cout << "Neteisingas ivedimas. Iveskite pazymi 10-baleje sistemoje." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;  }

            if (grade < 0 || grade > 10) {
                cout << "Neteisingas ivedimas. Iveskite pazymi 10-baleje sistemoje." << endl;   continue;  }
            homeworkGrades.push_back(grade);
            if (cin.peek() == '\n') {   break;    }
        }

        for (int grade : homeworkGrades) {
            student.addHomeworkGrade(grade);
        }

        //** Egzamino pazymio ivedimas **
        int examGrade;
        cout << "Iveskite egzamino ivertinima: ";
        cin >> examGrade;

        if (examGrade < 0 || examGrade > 10) {
            cout << "Iveskite pazymi 10-baleje sistemoje" << endl;
            return 1;
        }

        student.setExamGrade(examGrade);

        //** Isvedimas **
        cout << "\nPavarde     Vardas      Galutinis(Vid.) Galutinis(Med.)\n";
        cout << "------------------------------------------------------\n";
        student.Rez();
    } 
  
  
    return 0; 
}
