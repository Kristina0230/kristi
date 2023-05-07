//lab3 динамические структуры
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>


using namespace std;

struct Student {
    string name;
    string surname;
    string faculty;
    int birth_year;
    int graduation_year;
    int id;
};


Student read_student(const string& line) {
    Student s;
    istringstream iss(line);
    iss >> s.name >> s.surname >> s.faculty >> s.birth_year >> s.graduation_year >> s.id;
    return s;
}



void print_student(const Student& s) {
    cout << "Name: " << s.name << endl;
     cout << "Surname: " << s.surname << endl;
    cout << "Faculty: " << s.faculty << endl;
    cout << "Birth year: " << s.birth_year << endl;
    cout << "Graduation year: " << s.graduation_year << endl;
    cout << "ID: " << s.id << endl;
    cout << endl;
}


void read_students(stack<Student>& students, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            students.push(read_student(line));
        }
        file.close();
    }
    else {
        cout << "Невозможно открыть файл" << endl;
    }
}


void print_students(const stack<Student>& students) {
    stack<Student> copy = students;
    while (!copy.empty()) {
        print_student(copy.top());
        copy.pop();
    }
}

Student* find_student(stack<Student>& students, int id) {
    stack<Student> copy = students;
    while (!copy.empty()) {
        if (copy.top().id == id) {
            return &copy.top();
        }
        copy.pop();
    }
    return nullptr;
}

void remove_student(stack<Student>& students, int id) {
    stack<Student> temp;
    while (!students.empty()) {
        if (students.top().id != id) {
            temp.push(students.top());
        }
        students.pop();
    }
    while (!temp.empty()) {
        students.push(temp.top());
        temp.pop();
    }
}


void add_student(stack<Student>& students, const Student& new_student) {
    students.push(new_student);
}

int main() {
    stack<Student> students;

    read_students(students, "students.txt");

    print_students(students);

int id = 1;
Student* s = find_student(students, id);
if (s != nullptr) {
    cout << "Студент с ID" << id << " найден:" << endl;
    print_student(*s);
}
else {
    cout << "Студент с ID " << id << " не найден " << endl;
}

int id_to_remove = 4;
remove_student(students, id_to_remove);
cout << "Студент с ID " << id_to_remove << " удален" << endl;

Student new_student = {"John", "Doe", "Computer Science", 1994, 2026, 51};
add_student(students, new_student);
cout << "Добавлен новый студент:" << endl;
print_student(students.top());

return 0;
}
