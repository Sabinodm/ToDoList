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
    void setName(const std::string &chosenName);
    void setDescription(const std::string &chosenDescription);
    void setDate(int chosenDay, int chosenMonth, int chosenYear);
    void printActivity() const;
    void collectActivity() const;
    void readActivity(const std::string &readName, const std::string &readDescription, int readDay, int readMonth, int readYear, bool readYesNOdate);
    void setYesNOdata(bool chosenYesNOdata);

    //test
    std::string getName() const;
    std::string getDescription() const;
    Date getDate() const;
    bool getYesNOdata() const;




private:
    std::string name;
    std::string description;
    Date date;
    bool YesNOdata;


};



#endif //TODOLIST_ACTIVITY_H