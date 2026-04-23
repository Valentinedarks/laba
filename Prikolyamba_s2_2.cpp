#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

// Сортування
void bubbleSort(int a[], int n, bool asc)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((asc && a[j] > a[j + 1]) ||
                (!asc && a[j] < a[j + 1]))
                swap(a[j], a[j + 1]);
        }
}

// Масив
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void task2()
{
    cout << "\n[Завдання 2]\n";
    srand(static_cast<unsigned int>(time(0)));

    const int MAX_SIZE = 50;
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    cout << "Розмір масиву: ";
    cin >> n;

    int* a = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++){
    {
        bool isUnique;
        int num;

        do {
            isUnique = true;
            num = rand() % 100;
            for (int j = 0; j < i; j++) {
                if (a[j] == num) {
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);
        a[i] = num;
    }

    cout << "Початковий масив (унікальні числа):\n";
    printArray(a, n);

    int X;
    cout << "Введіть X: ";
    cin >> X;

    for (int i = 0; i < n; i++)
        if (a[i] <= X)
            a[i] = 0;

    cout << "Після обробки (заміна <= X на 0):\n";
    printArray(a, n);

    cout << "Просторова складність: "
         << n * sizeof(int) << " байт\n";

    delete[] a;
}
}


int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    task2();

    return 0;
}