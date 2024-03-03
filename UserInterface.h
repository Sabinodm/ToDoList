//
// Created by sabinodm on 11/11/23.
//

#ifndef TODOLIST_USERINTERFACE_H
#define TODOLIST_USERINTERFACE_H
#include <string>
#include "Category.h"

int removeActivityInterface();
std::string activitySetNameInterface();
std::string activitySetDescriptionInterface();
int activitySetDayInterface();
int activitySetMonthInterface();
int activitySetYearInterface();
void printListInterface(const Category &indexOfCategory);

#endif //TODOLIST_USERINTERFACE_H
