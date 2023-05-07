//lab0
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
   
    Student() {
        name = "";
        surname = "";
        age = 0;
        avg_grade = 0.0;
        student_id = "";
    }

    Student(const string& n, const string& s, int a, double g, const string& id) {
        name = n;
        surname = s;
        age = a;
        avg_grade = g;
        student_id = id;
    }

    Student(const Student& other) {
        name = other.name;
        surname = other.surname;
        age = other.age;
        avg_grade = other.avg_grade;
        student_id = other.student_id;
    }

    // Операторы
    Student& operator=(const Student& other) {
        name = other.name;
        surname = other.surname;
        age = other.age;
        avg_grade = other.avg_grade;
        student_id = other.student_id;
        return *this;
    }

    bool operator==(const Student& other) const {
        return student_id == other.student_id;
    }

    // Методы чтения/записи из потока
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.name >> s.surname >> s.age >> s.avg_grade >> s.student_id;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " " << s.surname << " " << s.age << " " << s.avg_grade << " " << s.student_id;
        return os;
    }

private:
    string name;
    string surname;
    int age;
    double avg_grade;
    string student_id;
};

int main() {
   
    ofstream outfile("students.txt");
    for (int i = 0; i < 50; i++) {
        string name = "Name" + to_string(i+1);
        string surname = "Surname" + to_string(i+1);
        int age = 18 + rand() % 10;
        double avg_grade = 3.0 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(5.0-3.0)));
        string student_id = "ID" + to_string(rand() % 10000 + 10000);
        outfile << Student(name, surname, age, avg_grade, student_id) << endl;
    }
    outfile.close();

   
    ifstream infile("students.txt");
    vector<Student> students;
    Student s;
    while (infile >> s) {
        students.push_back(s);
    }
    infile.close();

    
    for (const auto& student : students) {
        cout << student << endl;
    }

    return 0;
}
