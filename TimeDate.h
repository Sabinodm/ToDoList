//
// Created by sabinodm on 19/09/23.
//

#ifndef TODOLIST_TIMEDATE_H
#define TODOLIST_TIMEDATE_H

#include <ctime>
#include <sstream>

#include "TimeDateException.h"

class Date
{
private:
    std::tm date;
    void clear();
    void check_date(int day, int month, int year);
    bool is_leap(int year);
public:
    Date();
    ~Date();
    void setDate(int day, int month, int year);
    std::string getDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

};

#endif //TODOLIST_TIMEDATE_H
