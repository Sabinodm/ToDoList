//
// Created by sabinodm on 14/09/23.
//

#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <string>
#include "Activity.h"
#include <vector>

class ActivityList {
public:
    explicit ActivityList(std::string name);
    ~ActivityList() = default;
    const std::string & setName(std::string & chosen_name);
    const  std::string & getName();
    void addActivity();
    void removeActivity();
    void printList();
    void clearList();

private:
    std::string list_name;
    std::vector<Activity> list;
};

#endif //TODOLIST_ACTIVITYLIST_H