//lab0
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_STUDENTS = 50;

class Student {
public:
    string name;
    int id;
    int age;
    string major;
    float gpa;

    Student() {
        name = "";
        id = 0;
        age = 0;
        major = "";
        gpa = 0.0;
    }

    Student(const Student& other) {
        name = other.name;
        id = other.id;
        age = other.age;
        major = other.major;
        gpa = other.gpa;
    }

    Student* clone() {
        return new Student(*this);
    }

    bool operator==(const Student& other) const {
        return (id == other.id);
    }

    friend istream& operator>>(istream& in, Student& s) {
        in >> s.name >> s.id >> s.age >> s.major >> s.gpa;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.name << " " << s.id << " " << s.age << " " << s.major << " " << s.gpa << endl;
        return out;
    }
};

void generateData(Student arr[]) {
    string names[] = {"John", "Emily", "Michael", "Sophia", "Jacob", "Emma", "William", "Olivia", "Daniel", "Ava", "Ethan", "Mia", "James", "Isabella", "Alexander", "Abigail", "Benjamin", "Charlotte", "Lucas", "Harper", "Mason", "Amelia", "Evelyn", "Liam", "Aria", "Noah", "Luna", "Logan", "Chloe", "Caleb", "Lily", "Elijah", "Madison", "Aiden", "Ella", "Luke", "Nora", "Jackson", "Hannah", "Levi", "Layla", "Isaac", "Sofia", "Samuel", "Mila", "Owen", "Elizabeth", "Henry", "Scarlett", "Wyatt", "Victoria"};
    string majors[] = {"Computer Science", "Engineering", "Mathematics", "Business", "Psychology", "Biology", "Chemistry", "English", "History", "Art"};

    srand(time(NULL));
    for (int i = 0; i < NUM_STUDENTS; i++) {
        arr[i].name = names[rand() % 50];
        arr[i].id = rand() % 1000 + 1;
        arr[i].age = rand() % 10 + 18;
        arr[i].major = majors[rand() % 10];
        arr[i].gpa = (float)(rand() % 400 + 100) / 100;
    }
}

void printFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    while (inFile >> student.name >> student.id >> student.age >> student.major >> student.gpa) {
        cout << "Name: " << student.name << endl;
        cout << "ID: " << student.id << endl;
        cout << "Age: " << student.age << endl;
        cout << "Major: " << student.major << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }

    inFile.close();
}

int main() {
    Student students[NUM_STUDENTS];
    generateData(students);
    printFromFile();
    return 0;
}
