//
// Created by sabinodm on 14/09/23.
//

#ifndef TODOLIST_CATEGORY_H
#define TODOLIST_CATEGORY_H
#include <string>
#include "Activity.h"
#include <vector>

class Category {
public:
    explicit Category(std::string name);
    ~Category() = default;
    const std::string & setName(std::string & chosen_name);
    const  std::string & getName();
    void addActivity();
    void removeActivity();
    void printList();
    void clearList();

private:
    std::string category_name;
    std::vector<Activity> category;
};

#endif //TODOLIST_CATEGORY_H