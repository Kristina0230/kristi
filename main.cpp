#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string major;
    float gpa;

    Student(int id, string name, int age, string major, float gpa) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->major = major;
        this->gpa = gpa;
    }
     Student() {}
};

// Генерация случайного студента
Student generateStudent(int id) {
    Student s;
    s.id = id;
    string names[] = {"Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Helen", "Ivy", "Jack"};
    s.name = names[rand() % 10];
    s.age = rand() % 10 + 18; // возраст от 18 до 27
    string majors[] = {"Math", "Physics", "Chemistry", "Biology", "Computer Science", "Engineering"};
    s.major = majors[rand() % 6];
    s.gpa = static_cast<float>(rand() % 400 + 100) / 100; // средний балл от 1.00 до 5.00
    return s;
}

// Запись студентов в файл
void writeStudentsToFile(string filename, vector<Student>& students) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Ошибка открытия файла " << filename << " для записи." << endl;
        exit(1);
    }
    srand(time(0));
    for (int i = 0; i < 50; i++) {
        Student s = generateStudent(i + 1);
        students.push_back(s);
        fout << s.id << ' ' << s.name << ' ' << s.age << ' ' << s.major << ' ' << s.gpa << endl;
    }
    fout.close();
}
vector<Student> readStudentsFromFile(string filename) {
    vector<Student> students;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string field;
            vector<string> fields;
            while (getline(ss, field, ',')) {
                fields.push_back(field);
            }
            int id = stoi(fields[0]);
            string name = fields[1];
            int age = stoi(fields[2]);
            string major = fields[3];
            double gpa = stod(fields[4]);
            students.push_back(Student(id, name, age, major, gpa));
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << endl;
    }

    return students;
}


Student sequentialSearch(string filename, int id) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла " << filename << " для чтения." << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int cur_id;
        ss >> cur_id;
        if (cur_id == id) {
            string name, major;
            int age;
            double gpa;
            ss >> name >> age >> major >> gpa;
            file.close();
            return Student(id, name, age, major, gpa);
        }
    }
    file.close();
    cerr << "Студент с идентификатором " << id << " не найден." << endl;
    exit(1);
}

Student treeSearch(string filename, int id) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла " << filename << " для чтения." << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ' ')) {
            fields.push_back(field);
        }
        int student_id = stoi(fields[0]);
        if (student_id == id) {
            string name = fields[1];
            int age = stoi(fields[2]);
            string major = fields[3];
            double gpa = stod(fields[4]);
            file.close();
            return Student(student_id, name, age, major, gpa);
        }
    }
    file.close();
    cerr << "Студент с идентификатором " << id << " не найден." << endl;
    exit(1);
}


Student binarySearch(vector<Student>& students, int id) {
    int left = 0;
    int right = students.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (students[middle].id == id) {
            return students[middle];
        } else if (students[middle].id < id) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    // Студент с заданным идентификатором не найден
    Student nullStudent;
    nullStudent.id = -1;
    return nullStudent;
}


Student interpolationSearch(string filename, int id) {
    vector<Student> students = readStudentsFromFile(filename);
    int n = students.size();
    int low = 0;
    int high = n - 1;
    while (low <= high && id >= students[low].id && id <= students[high].id) {
        // Рассчитываем позицию по формуле интерполяции
        int pos = low + ((id - students[low].id) * (high - low)) / (students[high].id - students[low].id);
        // Если элемент найден, возвращаем его
        if (students[pos].id == id) {
            return students[pos];
        }
        // Если искомый элемент находится в левой половине, уменьшаем диапазон
        if (students[pos].id > id) {
            high = pos - 1;
        } else {
            // Если искомый элемент находится в правой половине, увеличиваем диапазон
            low = pos + 1;
        }
    }
    // Элемент не найден, возвращаем пустой объект
    Student emptyStudent;
    return emptyStudent;
}


int main() {
       vector<Student> students;
    writeStudentsToFile("students.txt", students);
   
///Метод бинарного поиска
    int id = 10;
    Student student = binarySearch(students, id);

    if (student.id != -1) {
        cout << "Студент найден: " << student.name << endl;
         cout << "ID: " << student.id << endl;
        cout << "Имя: " << student.name << endl;
        cout << "Возраст: " << student.age << endl;
        cout << "Специальность: " << student.major << endl;
        cout << "Средний балл: " << student.gpa << endl;
    } else {
        cerr << "Студент с идентификатором " << id << " не найден." << endl;
      
    }
    
 ///Метод последовательного поиска
        id = 20;
    student = sequentialSearch("students.txt", id);

    if (student.id != -1) {
        cout << "Студент найден: " << student.name << endl;
         cout << "ID: " << student.id << endl;
        cout << "Имя: " << student.name << endl;
        cout << "Возраст: " << student.age << endl;
        cout << "Специальность: " << student.major << endl;
        cout << "Средний балл: " << student.gpa << endl;
    } else {
        cerr << "Студент с идентификатором " << id << " не найден." << endl;
      
    }
    
     ///Метод поиска в неотсортированных массивах древовидно структурированных
        id = 30;
    student = treeSearch("students.txt", id);

    if (student.id != -1) {
        cout << "Студент найден: " << student.name << endl;
         cout << "ID: " << student.id << endl;
        cout << "Имя: " << student.name << endl;
        cout << "Возраст: " << student.age << endl;
        cout << "Специальность: " << student.major << endl;
        cout << "Средний балл: " << student.gpa << endl;
    } else {
        cerr << "Студент с идентификатором " << id << " не найден." << endl;
      
    }
    
    ///Поиск студента с помощью интерполяционного поиска
        id = 40;
    student = interpolationSearch("students.txt", id);

    if (student.id != -1) {
        cout << "Студент найден: " << student.name << endl;
         cout << "ID: " << student.id << endl;
        cout << "Имя: " << student.name << endl;
        cout << "Возраст: " << student.age << endl;
        cout << "Специальность: " << student.major << endl;
        cout << "Средний балл: " << student.gpa << endl;
    } else {
        cerr << "Студент с идентификатором " << id << " не найден." << endl;
      
    }
   
    return 0;
}
