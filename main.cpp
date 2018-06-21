/* 
 * File:   main.cpp
 * Author: zack
 *
 * Created on March 6, 2018, 10:40 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "makeChange.h"
#include "NegativeValueException.h"

using namespace std;
#define currencyTypes 8

const static Currency currency[currencyTypes] = {
    {20.00, "Twenty", "Twenties"},
    {10.00, "Ten", "Tens"},
    {5.00, "Five", "Fives"},
    {2.00, "Toonie", "Toonies"},
    {1.00, "Loonie", "Loonies"},
    {0.25, "Quarter", "Quarters"},
    {0.10, "Dime", "Dimes"},
    {0.05, "Nickel", "Nickels"}
};

/*
 * 
 */
int main() {
    double total = -1, tendered = -1, changeDue;

    while (true) {
        try {
            total = getMoneyValue("Enter the amount of the purchase: ");
            break;
        } catch (exception& e) {
            cout << e.what() << "\n";
        }
    }

    while (tendered < 0) {
        try {
            tendered = getMoneyValue("Enter the amount tendered: ");
        } catch (exception& e) {
            cout << e.what() << "\n";
        }
    }

    if (tendered < total) {
        cout << "Not enough money tendered. Try again.\n";
        tendered = getMoneyValue("      Enter the amount tendered: ");
    }

    changeDue = tendered - total;

    std::cout << std::fixed;
    std::cout << std::cout.precision(2);
    std::cout << "Change due is " << changeDue << "\n";

    changeDue = round(changeDue / 0.05) * 0.05;
    std::cout << "Rounded to the nearest nickel " << changeDue << "\n";

    ChangeValue changeValue;
    for (int i = 0; i < currencyTypes; i++) {
        changeValue = makeChange(changeDue, currency[i].value);
        int num = changeValue.numberChangeItems;
        if (num == 1) {
            cout << num << " ";
            cout << currency[i].name << "\n";
        } else if (num > 1) {
            cout << num << " ";
            cout << currency[i].pluralName << "\n";
        }
        changeDue = changeValue.balance;
    }

    return (EXIT_SUCCESS);
}

double getMoneyValue(string prompt) throw (NegativeValueException) {
    double response;

    //enter amount
    cout << prompt;
    cin >> response;
    if (response < 0.0) {
        NegativeValueException nve;
        throw nve;
    }
    return response;
}

ChangeValue makeChange(double balance, double denominationValue) {
    int numOfChangeItems;
    numOfChangeItems = balance / denominationValue;
    balance = balance - numOfChangeItems * denominationValue;
    ChangeValue cv;
    cv.numberChangeItems = numOfChangeItems;
    cv.balance = balance;
    return cv;

}