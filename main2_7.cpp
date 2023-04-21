//lab0
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_STUDENTS = 50;
// Класс Студент "Student"
class Student {
public:
    string name;// имя студента
    int id;// уникальный идентификатор студента
    int age;// возраст студента
    string major;// специальность студента
    float gpa;// средний балл студента
// Конструктор по умолчанию
    Student() {
        name = "";
        id = 0;
        age = 0;
        major = "";
        gpa = 0.0;
    }

 // Конструктор копирования
    Student(const Student& other) {
        name = other.name;
        id = other.id;
        age = other.age;
        major = other.major;
        gpa = other.gpa;
    }
// Клонирование объекта
    Student* clone() {
        return new Student(*this);
    }
 // Перегрузка оператора ==
    bool operator==(const Student& other) const {
        return (id == other.id);
    }
 // Перегрузка оператора >> для ввода данных студента
    friend istream& operator>>(istream& in, Student& s) {
        in >> s.name >> s.id >> s.age >> s.major >> s.gpa;
        return in;
    }
// Перегрузка оператора << для вывода данных студента
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.name << " " << s.id << " " << s.age << " " << s.major << " " << s.gpa << endl;
        return out;
    }
};
// Генерация случайных данных для массива студентов
void generateData(Student arr[]) {
    // массив имен и специальностей для студентов
    string names[] = {"John", "Emily", "Michael", "Sophia", "Jacob", "Emma", "William", "Olivia", "Daniel", "Ava", "Ethan", "Mia", "James", "Isabella", "Alexander", "Abigail", "Benjamin", "Charlotte", "Lucas", "Harper", "Mason", "Amelia", "Evelyn", "Liam", "Aria", "Noah", "Luna", "Logan", "Chloe", "Caleb", "Lily", "Elijah", "Madison", "Aiden", "Ella", "Luke", "Nora", "Jackson", "Hannah", "Levi", "Layla", "Isaac", "Sofia", "Samuel", "Mila", "Owen", "Elizabeth", "Henry", "Scarlett", "Wyatt", "Victoria"};
    string majors[] = {"Computer Science", "Engineering", "Mathematics", "Business", "Psychology", "Biology", "Chemistry", "English", "History", "Art"};
// используем текущее время как зерно для генератора случайных чисел
    srand(time(NULL));
    // заполняем массив студентов случайными значениями
    for (int i = 0; i < NUM_STUDENTS; i++) {
        arr[i].name = names[rand() % 50];
        arr[i].id = rand() % 1000 + 1;
        arr[i].age = rand() % 10 + 18;
        arr[i].major = majors[rand() % 10];
        arr[i].gpa = (float)(rand() % 400 + 100) / 100;
    }
}

void printFromFile() {
    // открываем файл для чтения
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }
// читаем информацию о студентах из файла и выводим на экран
    Student student;
    while (inFile >> student.name >> student.id >> student.age >> student.major >> student.gpa) {
        cout << "Name: " << student.name << endl;
        cout << "ID: " << student.id << endl;
        cout << "Age: " << student.age << endl;
        cout << "Major: " << student.major << endl;
        cout << "GPA: " << student.gpa << endl;
        cout << endl;
    }
// закрываем файл
    inFile.close();
}

int main() {
    // создаем массив студентов и заполняем случайными значениями
    Student students[NUM_STUDENTS];
    generateData(students);
    // выводим информацию о студентах из файла на экран
    printFromFile();
    return 0;
}