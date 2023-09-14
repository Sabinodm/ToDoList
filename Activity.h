//
// Created by sabinodm on 14/09/23.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <string>

class Activity {
public:
    explicit Activity();
    ~Activity() = default;
    void setName();
    void setDescription();
    void printActivity();

private:
    std::string name;
    std::string description;


};



#endif //TODOLIST_ACTIVITY_H