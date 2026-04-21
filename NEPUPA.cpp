#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
T findMin(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
class ArrayProcessor {
private:
    T arr1[100], arr2[100];
    int size;

public:
    void input(int n) {
        size = n;
        cout << "Введи перший масив:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr1[i];
        }

        cout << "Введи другий масив:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr2[i];
        }
    }

    void print() {
        cout << "Масив 1: ";
        for (int i = 0; i < size; i++) {
            cout << arr1[i] << " ";
        }
        cout << endl;

        cout << "Масив 2: ";
        for (int i = 0; i < size; i++) {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    int compare() {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr1[i] == arr2[i]) {
                count++;
            }
        }
        return count;
    }
};

class Student {
private:
    string surname;
    int age;
    float average;

public:
    Student() {
        surname = "";
        age = 0;
        average = 0;
    }

    Student(string s, int a, float avg) {
        surname = s;
        age = a;
        average = avg;
    }

    void input() {
        cout << "Введи прізвище: ";
        cin >> surname;
        cout << "Введи вік: ";
        cin >> age;
        cout << "Введи середній бал: ";
        cin >> average;
    }

    void print() {
        cout << surname << " | Вік: " << age << " | Середній: " << average << endl;
    }

    float getAvg() {
        return average;
    }

    int getAge() {
        return age;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int a[] = {5, 2, 8, 1, 9};
    float b[] = {2.5, 0.5, 7.1};
    char c[] = {'z', 'a', 'k'};

    cout << "Мінімальний int: " << findMin(a, 5) << endl;
    cout << "Мінімальний float: " << findMin(b, 3) << endl;
    cout << "Манімальний char: " << findMin(c, 3) << endl;

    ArrayProcessor<int> obj1;
    obj1.input(3);
    obj1.print();
    cout << "Збіги: " << obj1.compare() << endl;

    int n;
    cout << "Кількість студентів: ";
    cin >> n;

    Student students[100];

    for (int i = 0; i < n; i++) {
        students[i].input();
    }

    int bestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].getAvg() > students[bestIndex].getAvg()) {
            bestIndex = i;
        }
    }

    cout << "\nЛегенда:\n";
    students[bestIndex].print();

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getAge() > 20) {
            count++;
        }
    }

    cout << "Студенти яким за 20: " << count << endl;

    cout << "\nУсі студенти:\n";

    Student* it = students;
    Student* end = students + n;

    for (; it != end; it++) {
        it->print();
    }

    float sum = 0;

    for (Student* it2 = students; it2 != students + n; it2++) {
        sum += it2->getAvg();
    }

    cout << "Середній серед усіх: " << sum / n << endl;

    return 0;
}