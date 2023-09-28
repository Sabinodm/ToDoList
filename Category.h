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
    explicit Category(std::string &name);
    ~Category() = default;
    const std::string & setName(const std::string & chosenName);
    const  std::string & getName();
    void addActivity();
    void removeActivity();
    void printList();
    void clearList();
    void collectCategory();
    void readCategory(const std::string &name, const std::string &description, int day, int month, int year, bool yesNOdate, Category &newCategory);


private:
    std::string categoryName;
    std::vector<Activity> category;
};

#endif //TODOLIST_CATEGORY_H