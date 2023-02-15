#include <iostream>
#include <windows.h>


using namespace std;

void enter(double* a[], int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";			//Вывод матрицы 			
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    double tmp, d;
    cout << "Введите размерность матрицы:\n";
    cout << "n = ";
    cin >> n;
    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    cout << "Введите Матрицу:\n";                  //Заполнение матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[ " << i << "," << j << "]= ";
            cin >> a[i][j];
        }
    }
    cout << "Ваша матрица:\n";                       
    enter(a, n);
    for (int k = 0; k < n - 1; k++) {               //Приводим к ступенчатому виду
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
        enter(a, n);
    }


    cout << "\nМатрица в треугольном виде:\n\n";
    cout.precision(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(8);
            cout << fixed << a[i][j] << " ";
        }
        cout << "\n";
    }

    d = 1;
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    cout << fixed << "\nОпределитель матрицы = " << d << "\n";
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    system("pause");
    return 0;
}
