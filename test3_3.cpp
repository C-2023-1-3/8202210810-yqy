#include <iostream>
#include "mytemperature.h"
using namespace std;

//摄氏温度到华氏温度
double celsius_to_fah(double cel) {
    return cel * 9 / 5 + 32;
}

//华氏温度到摄氏温度
double fahrenheit_to_cels(double fah) {
    return (fah - 32) * 5 / 9;
}

int main() {
    cout << "Celsius    Fahrenheit   |   Fahrenheit       Celsius" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (double cel = 40.0, fah = 105.0; cel >= 31.0; cel--, fah -= 3) {
        cout << fixed;
        cout.precision(1);
        if(celsius_to_fah(cel) >= 100)
            cout << cel << "       " << celsius_to_fah(cel) << "        |   " << fah << "             " << fahrenheit_to_cels(fah) << endl;
        else
            cout << cel << "       " << celsius_to_fah(cel) << "         |   " << fah << "             " << fahrenheit_to_cels(fah) << endl;
    }
    return 0;
}