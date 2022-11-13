// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <ctime>
#include "tmatrix.h"
//---------------------------------------------------------------------------


void Input_of_Matrix_Auto(TDynamicMatrix<int> &m) {
    //srand(time(0));
    for (int i = 0; i < m.size(); i++) {
        for(int j = 0;j< m.size();j++)
        m[i][j] = rand()%10;
    }
}


void Input_of_Matrix_Byhands(TDynamicMatrix<int>& m) {
    cout << "Введите матрицу";
    cin >> m;
}


void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами"
    << endl;
    int N = 0;
    cout << "Введите размер матрицы N  = " << endl;
    cin >> N;
    TDynamicMatrix<int> a(N), b(N), c(N);
    int i, j;

    cout << "Выберите операцию: 1)Сложение матриц 2)Вычитание матриц 3)Умножение матриц 4)Умножение матрицы на скаляр" << endl;
    int choice;
    cin >> choice;
    int input = 0;
    cout << "Выберите способ ввода матриц: 1)Вручную 2)Автоматически" << endl;
    cin >> input;
 
    switch (choice) {
    case 1: {
        if (input == 1) {
            Input_of_Matrix_Byhands(a);
            Input_of_Matrix_Byhands(b);
        }
        else {
            Input_of_Matrix_Auto(a);
            Input_of_Matrix_Auto(b);
        
        } 
        cout << "Матрица А:\n" << a;
        cout << "Матрица В\n " << b;
        c = a + b;
        cout << "Матрица C\n " << c << endl;
        break;
    }
    case 2: {
        if (input == 1) {
            Input_of_Matrix_Byhands(a);
            Input_of_Matrix_Byhands(b);
        }
        else {
            Input_of_Matrix_Auto(a);
            Input_of_Matrix_Auto(b);
           
        }
        cout << "Матрица А:\n" << a;
        cout << "Матрица В\n " << b;
        c = a - b;
        cout << "Матрица C\n " << c << endl;
        break;
    }
    case 3: {
        if (input == 1) {
            Input_of_Matrix_Byhands(a);
            Input_of_Matrix_Byhands(b);
        }
        else {
            Input_of_Matrix_Auto(a);
            Input_of_Matrix_Auto(b);
           
        }
        cout << "Матрица А:\n" << a;
        cout << "Матрица В\n " << b;
        c = a * b;
        cout << "Матрица C\n " << c << endl;
        break;
    }
    case 4: {
        if (input == 1) {
            Input_of_Matrix_Byhands(a);
        }
        else {
            Input_of_Matrix_Auto(a);
         
        }
        cout << "Матрица А:\n" << a;
        int val = 0;
        cout << "Введите скаляр";
        cin >> val;
        c = a * val;
        cout << "Матрица C\n " << c << endl;
        break;
    }
    default:
        cout << "incorrect input";
    }
}
//---------------------------------------------------------------------------
