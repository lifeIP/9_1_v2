#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;

struct flights
{
    char last_name[50];
    char first_name[50];
    char patronymic_of_the_passenger[50];
    char airline[50];
    int flight_No;
    char departure_airport[50];
    char destination_airport[50];
    int date_d;
    int date_m;
    int date_y;
    int time_h;
    int time_m;
};

void print_menu();
int load(const char* file, flights* fly);
void print(flights* fli, int count);
void find_(flights* fli, int count);
void setData(const char* fileName, int size);

int main()
{
    setlocale(LC_ALL, "RUS");
   
    flights fli[15];
    int count = 0;
    while (true)
    {
        print_menu();
        char ch = _getch();
        switch (ch)
        {
        case '1':
            count = load("fly.txt", fli);
            if (count < 0)
            {
                return 0;
            }
            break;
        case '2':
            print(fli, count);
            break;
        case '3':
            find_(fli, count);
            break;
        case '4':
            cout << "Введите кол-во пассажиров: " << endl;
            int co;
            cin >> co;
            setData("fly.txt", co);
            break;
        case '0':
            return 0;
            break;
        default:
            cout << "Введена неизвестная команда" << endl;
        }
        cout << "Нажмите любую клавишу...." << endl;
        _getch();
    }

}
void print_menu()
{
    cout << endl;
    cout << "1 - загрузка данных" << endl;
    cout << "2 - вывод всех данных пассажиров" << endl;
    cout << "3 - вывод пассажиров рейса" << endl;
    cout << "4 - добавить пассажиров" << endl;
    cout << "0 - выход" << endl;
    cout << "Выберите действие: ";
}

int load(const char* file, flights* fly)
{
    ifstream f;
    f.open(file);
    if (!f.is_open())
    {
        cout << "Не удалось открыть файл " << file << endl;
        return -1;
    }

    char buff[100];
    f.getline(buff, 99);
    int count = atoi(buff);

    for (int i = 0; i < count; i++)
    {
        if (f.eof())
        {
            cout << "В файле недостаточно данных!" << endl;
            f.close();
            return -1;
        }
        f.getline(fly[i].airline, 31);//char
        
        char date_d[10] = {};
        f.getline(date_d, 31);
        fly[i].date_d = atoi(date_d);//int
        
        char date_m[10] = {};
        f.getline(date_m, 31);//int
        fly[i].date_m = atoi(date_m);
        
        char date_y[10] = {};
        f.getline(date_y, 31);
        fly[i].date_y = atoi(date_y);//int
        
        f.getline(fly[i].departure_airport, 31); //char
        f.getline(fly[i].destination_airport, 31); // char
        f.getline(fly[i].first_name, 31); //char
    
        char numb[10] = {};
        f.getline(numb, 31);
        fly[i].flight_No = atoi(numb);//int
    
        f.getline(fly[i].last_name, 31);//char
        f.getline(fly[i].patronymic_of_the_passenger, 31);//char
        
        char time_h[10] = {};
        f.getline(time_h, 31);
        fly[i].time_h = atoi(time_h);//float

        char time_m[10] = {};
        f.getline(time_m, 31);
        fly[i].time_m = atoi(time_m);
    
    }
    f.close();
    return count;
}
void print(flights* fli, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Пассажир " << i + 1 << endl;
        cout << "Ф.И.О. " << fli[i].last_name <<" " << fli[i].first_name <<" " << fli[i].patronymic_of_the_passenger << endl;
        cout << "Авиакомпания " << fli[i].airline << endl;
        cout << "Дата рейса " << fli[i].date_d << "." << fli[i].date_m << "." << fli[i].date_y << endl;
        cout << "Номер рейса " << fli[i].flight_No << endl;
        cout << "Из " << fli[i].departure_airport << endl;
        cout << "В " << fli[i].destination_airport << endl;
        cout << "Время " << (fli[i].time_h) <<":" << (fli[i].time_m)<< endl;
        cout << endl;
    }
}

void find_(flights* fli, int count)
{
    cout << "Введите номер рейса: ";
    char reis[32];
    cin >> reis;
    for (int i = 0; i < count; i++)
    {
        char s[10];
        _itoa(fli[i].flight_No, s, 10);
        if (strcmp(reis, s) == 0)
        {
            cout << "Пассажир " << i + 1 << endl;
            cout << "Ф.И.О. " << fli[i].last_name << " " << fli[i].first_name << " " << fli[i].patronymic_of_the_passenger << endl;
            cout << "Авиакомпания " << fli[i].airline << endl;
            cout << "Дата рейса " << fli[i].date_d << "." << fli[i].date_m << "." << fli[i].date_y << endl;
            cout << "Номер рейса " << fli[i].flight_No << endl;
            cout << "Из " << fli[i].departure_airport << endl;
            cout << "В " << fli[i].destination_airport << endl;
            cout << "Время " << (fli[i].time_h) << ":" << (fli[i].time_m) << endl;
            cout << endl;
        }
    }
}

void setData(const char* fileName, int size) {
    flights* dataBase = new flights[size];
    std::ofstream file;
    file.open(fileName, std::ios::app);
    if (file.is_open()) {
        std::cout << "Enter passenger details" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "Enter last name: " << std::endl;
            std::cin >> dataBase[i].last_name;
            std::cout << "Enter first_name: " << std::endl;
            std::cin >> dataBase[i].first_name;
            std::cout << "Enter patronymic_of_the_passenger: " << std::endl;
            std::cin >> dataBase[i].patronymic_of_the_passenger;
            std::cout << "Enter airline: " << std::endl;
            std::cin >> dataBase[i].airline;
            std::cout << "Enter flight_No: " << std::endl;
            std::cin >> dataBase[i].flight_No;
            std::cout << "Enter departure_airport: " << std::endl;
            std::cin >> dataBase[i].departure_airport;
            std::cout << "Enter destination_airport: " << std::endl;
            std::cin >> dataBase[i].destination_airport;
            std::cout << "Enter day: " << std::endl;
            std::cin >> dataBase[i].date_d;
            for (; dataBase[i].date_d > 30;) {
                std::cout << "Enter month: " << std::endl;
                std::cin >> dataBase[i].date_d;
            }
            std::cin >> dataBase[i].date_m;
            for (; dataBase[i].date_m > 12;) {
                std::cout << "Enter year: " << std::endl;
                std::cin >> dataBase[i].date_m;
            }
            std::cin >> dataBase[i].date_y;
            std::cout << "Enter time: " << std::endl;
            std::cin >> dataBase[i].time_h;
            std::cin >> dataBase[i].time_m;

            file << dataBase[i].airline << std::endl
                << dataBase[i].date_d << std::endl
                << dataBase[i].date_m << std::endl
                << dataBase[i].date_y << std::endl
                << dataBase[i].departure_airport << std::endl
                << dataBase[i].destination_airport << std::endl
                << dataBase[i].first_name << std::endl
                << dataBase[i].flight_No << std::endl
                << dataBase[i].last_name << std::endl
                << dataBase[i].patronymic_of_the_passenger << std::endl
                << dataBase[i].time_h << std::endl
                << dataBase[i].time_m << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Fatal error! Try again.." << std::endl;
    }
    delete[]dataBase;
}