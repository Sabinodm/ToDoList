//
// Created by sabinodm on 14/09/23.
//
#include "iostream"
#include "ActivityList.h"
#include "Activity.h"

ActivityList::ActivityList(std::string name) : list_name(name) {

}

const std::string & ActivityList::setName(std::string & chosen_name) {
    this->list_name = chosen_name;
    return list_name;
}

const std::string & ActivityList::getName() {
    return list_name;
}

void ActivityList::addActivity() {
    Activity newActivity = Activity();
    newActivity.Activity::setName();
    newActivity.Activity::setDescription();
    list.push_back(newActivity);
}

void ActivityList::removeActivity() {
    std::cout << "Inserisci il nome dell'attività da rimuovere" << std::endl;
    std::cout << "Elemento numero:";
    int index_element;
    std::cin >> index_element;
    list.erase(list.begin() + index_element);
}

void ActivityList::printList() {
    std::cout << "Lista: " << list_name << std::endl;
    for (int i = 0; i < list.size(); i++) {
        std::cout << i;
        list[i].Activity::printActivity();
    }
}

void ActivityList::clearList() {
    list.clear();
}
