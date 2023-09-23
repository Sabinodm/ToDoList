//
// Created by sabinodm on 19/09/23.
//

#include "TimeDate.h"

Date::Date()
{
    clear();
}

Date::~Date(){}

void Date::setDate(int day, int month, int year)
{
    try
    {
        check_date(day, month, year);
        clear();
        this->date.tm_mday = day;
        this->date.tm_mon = month-1;
        this->date.tm_year = year-1900;
    }
    catch(TimeDateException& ex)
    {
        throw ex;
    }

}

std::string Date::getDate() const
{
    std::ostringstream ss;
    ss << this->getDay() << "/" << this->getMonth() << "/" << this->getYear();
    return ss.str();
}

int Date::getDay() const
{
    return this->date.tm_mday;
}

int Date::getMonth() const
{
    return this->date.tm_mon+1;
}

int Date::getYear() const
{
    return this->date.tm_year+1900;
}

void Date::clear()
{
    this->date.tm_sec = 0;
    this->date.tm_min = 0;
    this->date.tm_hour = 1;
    this->date.tm_mday = 1;
    this->date.tm_mon = 0;
    this->date.tm_year = 0;
}

bool Date::is_leap(int year)
{
    if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
        return true;
    else
        return false;
}

void Date::check_date(int day, int month, int year)
{
    // Controlli base

    if(day < 1)
        throw TimeDateException("Day can't be < 1", TimeDateException::INVALID_FORMAT);
    else if (day > 31)
        throw TimeDateException("Day can't be > 31", TimeDateException::INVALID_FORMAT);

    if(month < 1)
        throw TimeDateException("Month can't be < 1", TimeDateException::INVALID_FORMAT);
    else if(month > 12)
        throw TimeDateException("Month can't be > 12", TimeDateException::INVALID_FORMAT);

    if(year < 1900)
        throw TimeDateException("Year can't be < 1900", TimeDateException::INVALID_FORMAT);

    // Controlli coerenza <day, month> e year

    if( (month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::ostringstream ss;
        ss << "<day, month> = <" << day << ", " << month << "> is not valid. Day must be in [1,30]";
        throw TimeDateException(ss.str(), TimeDateException::INVALID_FORMAT );
    }
    else if( month == 2 && is_leap(year) && day > 29)
    {
        std::ostringstream ss;
        ss << "<day, month> = <" << day << ", " << month << "> (leap) is not valid. Day must be in [1,29]";
        throw TimeDateException(ss.str(), TimeDateException::INVALID_FORMAT );
    }
    else if( month == 2 && !is_leap(year) && day > 28)
    {
        std::ostringstream ss;
        ss << "<day, month> = <" << day << ", " << month << "> (not leap) is not valid. Day must be in [1,28]";
        throw TimeDateException(ss.str(), TimeDateException::INVALID_FORMAT );
    }
}
