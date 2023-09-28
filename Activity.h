//
// Created by sabinodm on 14/09/23.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <string>
#include "TimeDate.h"


class Activity {
public:
    explicit Activity();
    ~Activity() = default;
    void setName();
    void setDescription();
    void setDate();
    void printActivity();
    void collectActivity();
    void readActivity(const std::string &readName, const std::string &readDescription, int readDay, int readMonth, int readYear, bool readYesNOdate);

private:
    std::string name;
    std::string description;
    Date date;
    bool YesNOdata;

};



#endif //TODOLIST_ACTIVITY_H