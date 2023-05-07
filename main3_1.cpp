//lab3 бинарное дерево
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    string major;
    int year_start;
    int year_end;
    int id;
    Student* left;
    Student* right;
};


Student* createNode(int id, string name, string major, int year_start, int year_end) {
    Student* node = new Student;
    node->name = name;
    node->major = major;
    node->year_start = year_start;
    node->year_end = year_end;
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Student* insertNode(Student* root, int id, string name, string major, int year_start, int year_end) {
    if (root == NULL) {
        root = createNode(id, name, major, year_start, year_end);
        return root;
    }
    if (id < root->id) {
        root->left = insertNode(root->left, id, name, major, year_start, year_end);
    }
    else {
        root->right = insertNode(root->right, id, name, major, year_start, year_end);
    }
    return root;
}

Student* deleteNode(Student* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    }
    else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    }
    else {
 
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
     
        else if (root->left == NULL) {
            Student* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Student* temp = root;
            root = root->left;
            delete temp;
     
        else {
            Student* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->id = temp->id;
            root->name = temp->name;
            root->major = temp->major;
            root->year_start = temp->year_start;
            root->year_end = temp->year_end;
            root->right = deleteNode(root->right, temp->id);
        }
    }
    return root;
}

Student* findNode(Student* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (root->id == id) {
        return root;
    }
    if (id < root->id) {
        return findNode(root->left, id);
    }
    else {
        return findNode(root->right, id);
}
}


void printInOrder(Student* root) {
if (root != NULL) {
printInOrder(root->left);
cout << "ID: " << root->id << endl;
cout << "Name: " << root->name << endl;
cout << "Major: " << root->major << endl;
cout << "Year Start: " << root->year_start << endl;
cout << "Year End: " << root->year_end << endl << endl;
printInOrder(root->right);
}
}

int main() {

Student* root = NULL;

root = insertNode(root, 1, "Alice", "Computer Science", 2017, 2021);
root = insertNode(root, 2, "Bob", "Mathematics", 2018, 2022);
root = insertNode(root, 3, "Charlie", "Physics", 2019, 2023);
root = insertNode(root, 4, "David", "Chemistry", 2020, 2024);
root = insertNode(root, 5, "Eve", "Biology", 2021, 2025);

cout << "Все узлы по порядку:" << endl;
printInOrder(root);


int idToFind = 3;
Student* foundNode = findNode(root, idToFind);
if (foundNode != NULL) {
    cout << "Node with ID " << idToFind << " found:" << endl;
    cout << "Name: " << foundNode->name << endl;
    cout << "Major: " << foundNode->major << endl;
    cout << "Year Start: " << foundNode->year_start << endl;
    cout << "Year End: " << foundNode->year_end << endl;
}
else {
    cout << "Node with ID " << idToFind << " not found." << endl;
}

int idToDelete = 2;
root = deleteNode(root, idToDelete);

cout << endl << "Все узлы после удаления узла с идентификатором " << idToDelete << ":" << endl;
printInOrder(root);

return 0;
}
