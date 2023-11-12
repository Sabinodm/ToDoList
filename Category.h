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
    void addActivity(const std::string &chosenName, const std::string &chosenDescription, int chosenDay, int chosenMonth, int chosenYear, bool chosenYesNOdata);
    void addActivity(const std::string &chosenName, const std::string &chosenDescription, bool chosenYesNOdata); //overload in caso di attività senza data
    void removeActivity(int indexElement);
    void printList();
    void clearList();
    void collectCategory();
    void readCategory(const std::string &name, const std::string &description, int day, int month, int year, bool yesNOdate, Category &newCategory);

    //test
    size_t getSizes();
    std::string getActivityName(int indexElement);
    std::string getActivityDescription(int indexElement);
    Date getActivityDate(int indexElement);
    bool getActivityYesNOdata(int indexElement);

private:
    std::string categoryName;
    std::vector<Activity> category;
};

#endif //TODOLIST_CATEGORY_H