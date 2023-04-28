#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class MultiArray {
public:
    vector<int> dims;
    unordered_map<int, int> data;

    MultiArray(vector<int> d) : dims(d) {
        int total_size = 1;
        for (int i = 0; i < dims.size(); ++i) {
            total_size *= dims[i];
        }
        data.reserve(total_size);
    }

    int get_index(vector<int> indices) {
        int index = indices[0];
        int stride = 1;
        for (int i = 1; i < dims.size(); ++i) {
            stride *= dims[i - 1];
            index += indices[i] * stride;
        }
        return index;
    }

    int get_element_by_aly(int i, int j, int k) {
        int a = get_index({i, j, k});
        int b = get_index({i, k, j});
        int c = get_index({j, i, k});
        int d = get_index({j, k, i});
        int e = get_index({k, i, j});
        int f = get_index({k, j, i});
        return data[a] + data[b] + data[c] + data[d] + data[e] + data[f];
    }

    int get_element_by_row_col(int i, int j, int k) {
        return data[i + j * dims[0] + k * dims[0] * dims[1]];
    }

    int& operator[](vector<int> indices) {
        return data[get_index(indices)];
    }
};

int main() {
    // создаем массив 5x5x5
    vector<int> dims = {5, 5, 5};
    MultiArray arr(dims);
    // заполняем массив случайными числами от 0 до 99
for (int i = 0; i < dims[0]; ++i) {
    for (int j = 0; j < dims[1]; ++j) {
        for (int k = 0; k < dims[2]; ++k) {
            arr[{i, j, k}] = rand() % 100;
        }
    }
}

// тестируем прямой доступ к элементам массива
auto start_time = high_resolution_clock::now();
for (int i = 0; i < dims[0]; ++i) {
    for (int j = 0; j < dims[1]; ++j) {
        for (int k = 0; k < dims[2]; ++k) {
            int val = arr[{i, j, k}];
        }
    }
}
auto end_time = high_resolution_clock::now();
auto elapsed_time = duration_cast<nanoseconds>(end_time - start_time);
cout << "Direct access elapsed time: " << elapsed_time.count() << " ns" << endl;

// тестируем доступ посредством векторов Айлиффа
start_time = high_resolution_clock::now();
for (int i = 0; i < dims[0]; ++i) {
    for (int j = 0; j < dims[1]; ++j) {
        for (int k = 0; k < dims[2]; ++k) {
            int val = arr.get_element_by_aly(i, j, k);
        }
    }
}
end_time = high_resolution_clock::now();
elapsed_time = duration_cast<nanoseconds>(end_time - start_time);
cout << "Access by Alyeff elapsed time: " << elapsed_time.count() << " ns" << endl;

// тестируем метод доступа посредством векторов строки и столбцов
start_time = high_resolution_clock::now();
for (int i = 0; i < dims[0]; ++i) {
    for (int j = 0; j < dims[1]; ++j) {
        for (int k = 0; k < dims[2]; ++k) {
            int val = arr.get_element_by_row_col(i, j, k);
        }
    }
}
end_time = high_resolution_clock::now();
elapsed_time = duration_cast<nanoseconds>(end_time - start_time);
cout << "Access by Row and Col elapsed time: " << elapsed_time.count() << " ns" << endl;

// выводим информацию о размере используемой памяти
size_t memory_usage = sizeof(MultiArray) + arr.dims.size() * sizeof(int) * 4 + arr.data.size() * sizeof(int);
cout << "Memory usage: " << memory_usage << " bytes" << endl;

return 0;
}