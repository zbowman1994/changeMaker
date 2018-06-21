/* 
 * File:   NegativeValueException.h
 * Author: c0374314
 *
 * Created on March 6, 2018, 10:42 AM
 */

#ifndef NEGATIVEVALUEEXCEPTION_H
#define NEGATIVEVALUEEXCEPTION_H

class NegativeValueException: public std::exception {
    public:
  virtual const char* what() const throw()  {
    return "Negative values are not allowed";
  }
};

#endif /* NEGATIVEVALUEEXCEPTION_H */

