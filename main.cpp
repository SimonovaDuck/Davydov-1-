// Лабораторная работа №1
// Симметричная криптография. Простые шифры.
// Вариант №4, Маршрутная перестановка.
// Давыдов Андрей, КИ20-07Б

#include <iostream>

using namespace std;

int main() {
        
    char IN_DATA[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++)
            IN_DATA[i][j] = '~';
    }
    
    cout << " Лабораторная работа №1\n Симметричная криптография. Простые шифры.\n Вариант №4, Маршрутная перестановка.\n Давыдов Андрей, КИ20-07Б\n\n Введите сообщение длинной до 100 символов (пробелы программа не замечает, кириллицу не принимает). Для остановки ввода введите символ ~ .\n";
    
    char Z = '.';
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (Z != '~'){
                cin >> IN_DATA[i][j];
                Z = IN_DATA[i][j];
            }
        }
    }
    
    cout << "\n";
    cout << "Проверка ВВЕДЕННЫХ:\n";
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++)
            cout << IN_DATA[i][j] << " ";
        cout << "\n";
    }
    
    cout << "\n";
    cout << " Введенное сообщение:\n";
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (IN_DATA[i][j] != '~')
                cout << IN_DATA[i][j];
        }
    }
    cout << "\n";
    
    char OUT_DATA[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++)
            OUT_DATA[i][j] = '~';
    }
    
    int x=0, y=0;
    for (int i=9; i>=0; i--){
        for (int j=9; j>=0; j--){
            if (IN_DATA[j][i] != '~'){
                OUT_DATA[x][y] = IN_DATA[j][i];
                if (y == 9){
                    y = 0;
                    x++;
                }
                else y++;
            }
        }
    }
    
    
    cout << "\n";
    cout << " Шифротекст:\n";
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (OUT_DATA[i][j] != '~')
                cout << OUT_DATA[i][j];
        }
    }
    cout << "\n";
    
    // Дешифровка
    
    char OUT_2_DATA[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++)
            OUT_2_DATA[i][j] = '~';
    }
    
    x = 0;
    y = 0;
    for (int i=9; i>=0; i--){
        for (int j=9; j>=0; j--){
            if (OUT_DATA[i][j] != '~'){
                if (OUT_DATA[x][y] != '~'){
                    OUT_2_DATA[x][y] = OUT_DATA[i][j];
                    if (OUT_DATA[x+1][y] != '~')
                        x++;
                    else{
                        x = 0;
                        y++;
                    }
                }
            }
        }
    }
    
    
    cout << "\n";
    cout << " Дешифратор:\n";
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (OUT_2_DATA[i][j] != '~')
                cout << OUT_2_DATA[i][j];
        }
    }
    cout << "\n";

    cout << "\n";
    return 0;
}
