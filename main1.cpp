//lab0
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student {
private:
    string first_name;
    string last_name;
    string faculty;
    int birth_year;
    int enrollment_year;
    string id;

public:
    // Конструкторы
    Student() : birth_year(0), enrollment_year(0) {}
    Student(string first_name, string last_name, string faculty, int birth_year, int enrollment_year, string id) :
        first_name(first_name), last_name(last_name), faculty(faculty), birth_year(birth_year), enrollment_year(enrollment_year), id(id) {}
    Student(const Student& other) :
        first_name(other.first_name), last_name(other.last_name), faculty(other.faculty),
        birth_year(other.birth_year), enrollment_year(other.enrollment_year), id(other.id) {}

    // Методы
    bool operator==(const Student& other) const {
        return id == other.id;
    }
    Student& operator=(const Student& other) {
        first_name = other.first_name;
        last_name = other.last_name;
        faculty = other.faculty;
        birth_year = other.birth_year;
        enrollment_year = other.enrollment_year;
        id = other.id;
        return *this;
    }
    Student* clone() const {
        return new Student(*this);
    }
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.first_name >> s.last_name >> s.faculty >> s.birth_year >> s.enrollment_year >> s.id;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.first_name << " " << s.last_name << " " << s.faculty << " " << s.birth_year << " " << s.enrollment_year << " " << s.id;
        return os;
    }
};

int main() {
    const int SIZE = 50;
    srand(time(0)); // Инициализация генер
    string first_names[10] = {"Emma", "Olivia", "Ava", "Isabella", "Sophia", "Mia", "Charlotte", "Amelia", "Harper", "Evelyn"};
string last_names[10] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Wilson", "Anderson"};

ofstream fout("students.txt");
if (!fout) {
    cerr << "Error opening file\n";
    return 1;
}

for (int i = 0; i < SIZE; i++) {
    string first_name = first_names[rand() % 10];
    string last_name = last_names[rand() % 10];
    string faculty = "Faculty" + to_string((rand() % 3) + 1);
    int birth_year = (rand() % 10) + 1990;
    int enrollment_year = (rand() % 5) + 2015;
    string id = "ID" + to_string(i+1);

    fout << first_name << " "<<last_name << " " << faculty << " " << birth_year << " " << enrollment_year << " " << id << endl;

string first_names[10] = {"Emma", "Olivia", "Ava", "Isabella", "Sophia", "Mia", "Charlotte", "Amelia", "Harper", "Evelyn"};
string last_names[10] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Wilson", "Anderson"};

ofstream fout("students.txt");
if (!fout) {
    cerr << "Error opening file\n";
    return 1;
}

for (int i = 0; i < SIZE; i++) {
    string first_name = first_names[rand() % 10];
    string last_name = last_names[rand() % 10];
    string faculty = "Faculty" + to_string((rand() % 3) + 1);
    int birth_year = (rand() % 10) + 1990;
    int enrollment_year = (rand() % 5) + 2015;
    string id = "ID" + to_string(i+1);

    fout << first_name << " "<<last_name << " " << faculty << " " << birth_year << " " << enrollment_year << " " << id << endl;
}
fout.close();

ifstream fin("students.txt");
if (!fin) {
cerr << "Error opening file\n";
return 1;
}

Student arr[SIZE];
for (int i = 0; i < SIZE; i++) {
fin >> arr[i];
}
fin.close();

for (int i = 0; i < SIZE; i++) {
cout << arr[i] << endl;
}

return 0;
}

}

    return 0;
}
