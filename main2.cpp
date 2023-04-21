///lab2
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

// Функция, которая генерирует данные для студентов
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

// Функция для сортировки пузырьком
void bubbleSort(Student arr[], int n) {
int comparisons = 0;
int swaps = 0;
clock_t startTime = clock();

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        comparisons++;
        if (arr[j].id > arr[j + 1].id) {
            swaps++;
            swap(arr[j], arr[j + 1]);
        }
    }
}

clock_t endTime = clock();
double timeElapsed = double(endTime - startTime) / CLOCKS_PER_SEC;

cout << "Bubble Sort:" << endl;
cout << "Theoretical Complexity: O(n^2)" << endl;
cout << "Number of Comparisons: " << comparisons << endl;
cout << "Number of Swaps: " << swaps << endl;
cout << "Execution Time: " << timeElapsed << " seconds" << endl;
}

// Функция для сортировки выбором
void selectionSort(Student arr[], int n) {
int comparisons = 0;
int swaps = 0;
clock_t startTime = clock();

for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        comparisons++;
        if (arr[j].id < arr[minIndex].id) {
            minIndex = j;
        }
    }
    if (minIndex != i) {
        swaps++;
        swap(arr[i], arr[minIndex]);
    }
}

clock_t endTime = clock();
double timeElapsed = double(endTime - startTime) / CLOCKS_PER_SEC;

cout << "Selection Sort:" << endl;
cout << "Theoretical Complexity: O(n^2)" << endl;
cout << "Number of Comparisons: " << comparisons << endl;
cout << "Number of Swaps: " << swaps << endl;
cout << "Execution Time: " << timeElapsed << " seconds" << endl;
}

// Функция для сортировки вставками
void insertionSort(Student arr[], int n) {
int comparisons = 0;
int swaps = 0;
clock_t startTime = clock();

for (int i = 1; i < n; i++) {
    Student key = arr[i];
    int j = i - 1;

    comparisons++;
    while (j >= 0 && arr[j].id > key.id) {
        swaps++;
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

clock_t endTime = clock();
double timeElapsed = double(endTime - startTime) / CLOCKS_PER_SEC;

cout << "Insertion Sort:" << endl;
cout << "Theoretical Complexity: O(n^2)" << endl;
cout << "Number of Comparisons: " << comparisons << endl;
cout << "Number of Swaps: " << swaps << endl;
cout << "Execution Time: " << timeElapsed << " seconds" << endl;
}

int main() {
Student students[NUM_STUDENTS];
generateData(students);
bubbleSort(students, NUM_STUDENTS);
cout << endl;

selectionSort(students, NUM_STUDENTS);
cout << endl;

insertionSort(students, NUM_STUDENTS);

return 0;
}
