/* 
 * File:   makeChange.h
 * Author: c0374314
 *
 * Created on March 6, 2018, 11:05 AM
 */

#ifndef MAKECHANGE_H
#define MAKECHANGE_H
#include <cstring>
#include "NegativeValueException.h"

using namespace std;

typedef struct {
    double value;
    string name;
    string pluralName;
} Currency;

typedef struct {
    double numberChangeItems;
    double balance;
} ChangeValue;

ChangeValue makeChange(double balance, double denominationValue);

double getMoneyValue(string prompt) throw (NegativeValueException);
#endif /* MAKECHANGE_H */

