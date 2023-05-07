//lab0
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_RECORDS = 50;

class Student {
public:
    // конструкторы
    Student();
    Student(const Student& other);

    // операторы
    Student& operator=(const Student& other);
    bool operator==(const Student& other) const;

    // методы чтения/записи в поток
    friend istream& operator>>(istream& is, Student& student);
    friend ostream& operator<<(ostream& os, const Student& student);

private:
    string firstName;
    string lastName;
    string faculty;
    int birthYear;
    int enrollmentYear;
    int id;

    static const string FIRST_NAMES[];
    static const string LAST_NAMES[];
    static const string FACULTIES[];
    static const int MIN_BIRTH_YEAR = 1990;
    static const int MAX_BIRTH_YEAR = 2005;
    static const int MIN_ENROLLMENT_YEAR = 2010;
    static const int MAX_ENROLLMENT_YEAR = 2021;
    static int nextId;
};

// инициализация статических полей
const string Student::FIRST_NAMES[] = {"John", "Jane", "Bob", "Alice", "Mike", "Sarah", "Jack", "Emily", "Tom", "Mary"};
const string Student::LAST_NAMES[] = {"Smith", "Johnson", "Brown", "Jones", "Garcia", "Wilson", "Miller", "Davis", "Taylor", "Lee"};
const string Student::FACULTIES[] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Engineering", "Medicine", "Law", "Economics", "History"};
int Student::nextId = 1;

// конструктор по умолчанию
Student::Student() {
    // генерация случайных значений для полей
    firstName = FIRST_NAMES[rand() % 10];
    lastName = LAST_NAMES[rand() % 10];
    faculty = FACULTIES[rand() % 10];
    birthYear = rand() % (MAX_BIRTH_YEAR - MIN_BIRTH_YEAR + 1) + MIN_BIRTH_YEAR;
    enrollmentYear = rand() % (MAX_ENROLLMENT_YEAR - MIN_ENROLLMENT_YEAR + 1) + MIN_ENROLLMENT_YEAR;
    id = nextId++;
}

// конструктор копирования
Student::Student(const Student& other) {
    firstName = other.firstName;
    lastName = other.lastName;
    faculty = other.faculty;
    birthYear = other.birthYear;
    enrollmentYear = other.enrollmentYear;
    id = other.id;
}

// оператор копирования
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        faculty = other.faculty;
        birthYear = other.birthYear;
        enrollmentYear = other.enrollmentYear;
        id = other.id;
    }
    return *this;
}

// оператор сравнения
bool Student::operator==(const Student& other) const {
return id == other.id;
}

// метод чтения из потока
istream& operator>>(istream& is, Student& student) {
is >> student.firstName >> student.lastName >> student.faculty >> student.birthYear >> student.enrollmentYear >> student.id;
return is;
}

// метод записи в поток
ostream& operator<<(ostream& os, const Student& student) {
os << student.firstName << " " << student.lastName << " " << student.faculty << " " << student.birthYear << " " << student.enrollmentYear << " " << student.id;
return os;
}

int main() {
srand(time(0));
// создание и запись записей в файл
ofstream file("students.txt");
for (int i = 0; i < NUM_RECORDS; i++) {
Student student;
file << student << endl;
}
file.close();
// чтение из файла и вывод на экран
ifstream infile("students.txt");
Student students[NUM_RECORDS];
for (int i = 0; i < NUM_RECORDS; i++) {
    infile >> students[i];
    cout << students[i] << endl;
}
infile.close();

return 0;
}
