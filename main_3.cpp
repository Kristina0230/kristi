#include <iostream>
#include <fstream>
#include <stack>
#include <string>

struct Student {
    std::string name;
    std::string surname;
    int age;
    float gpa;
    std::string id;
};

// Функция для вывода информации о студенте на экран
void printStudent(const Student& s) {
    std::cout << s.name << " " << s.surname << ", " << s.age << " years old, "
              << "GPA: " << s.gpa << ", ID: " << s.id << std::endl;
}

int main() {
    // Открываем файл с данными студентов
    std::ifstream fin("students.txt");

    // Создаем пустой стек студентов
    std::stack<Student> students;

    // Читаем данные из файла и добавляем их в стек
    std::string name, surname, id;
    int age;
    float gpa;
    while (fin >> name >> surname >> age >> gpa >> id) {
        Student s = {name, surname, age, gpa, id};
        students.push(s);
    }

    // Выводим информацию о каждом студенте в стеке
    std::cout << "Students in the stack:" << std::endl;
    while (!students.empty()) {
        Student s = students.top();
        printStudent(s);
        students.pop();
    }

    // Добавляем нового студента в стек
    Student newStudent = {"John", "Doe", 20, 3.5, "ID12345"};
    students.push(newStudent);

    // Ищем студента по ID
    std::string searchID = "ID16619";
    std::stack<Student> tempStack; // временный стек для хранения студентов
    bool found = false;
    while (!students.empty()) {
        Student s = students.top();
        students.pop();
        if (s.id == searchID) {
            std::cout << "Student found:" << std::endl;
            printStudent(s);
            found = true;
            break;
        }
        else {
            tempStack.push(s);
        }
    }
    // Возвращаем студентов из временного стека в исходный стек
    while (!tempStack.empty()) {
        students.push(tempStack.top());
        tempStack.pop();
    }
    if (!found) {
        std::cout << "Student with ID " << searchID << " not found." << std::endl;
    }

    // Удаляем студента с заданным ID
    std::string deleteID = "ID12777";
    found = false;
    while (!students.empty()) {
        Student s = students.top();
        students.pop();
        if (s.id == deleteID) {
            std::cout << "Student deleted:" << std::endl;
            printStudent(s);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << deleteID << " not found." << std::endl;
    }

    return 0;
}

