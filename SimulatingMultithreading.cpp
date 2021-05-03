// SimulatingMultithreading.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <thread>

using namespace std;

// Имитация сложного процесса, который выполняется 10 секунд
int Sum(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "----------\t" << "Sum Started\t----------" << endl;
    this_thread::sleep_for(chrono::milliseconds(8000));
    cout << "----------\t" << "Sum Proccesing: a + b = " << a + b << "\t----------" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "----------\t" << "Sum Stopped\t----------" << endl;

    return a + b;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int result; // результат выполнения Sum()

    thread th([&result]() { result = Sum(2, 8); }); // получить результат Sum можно только используя анонимное лямбда-выражение

    for (size_t i = 0; true; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join(); // вызовDoWork в новом потоке, не блокирующем поток с main

    return 0;
}