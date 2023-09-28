//
// Created by sabinodm on 14/09/23.
//
#include "iostream"
#include "Category.h"
#include "Activity.h"
#include "TxtFile.h"

Category::Category(std::string &name) : categoryName(name) {

}

const std::string & Category::setName(const std::string & chosenName) {
    this->categoryName = chosenName;
    return categoryName;
}

const std::string & Category::getName() {
    return categoryName;
}

void Category::addActivity() {
    Activity newActivity = Activity();
    newActivity.Activity::setName();
    newActivity.Activity::setDescription();
    newActivity.Activity::setDate();
    category.push_back(newActivity);
}

void Category::removeActivity() {
    std::cout << "Inserisci il numero dell'attività da rimuovere" << std::endl;
    std::cout << "Elemento numero:";
    int indexElement;
    std::cin.exceptions(std::ios_base::failbit);
    std::cin >> indexElement;
    if (indexElement >= category.size() || indexElement < 0) {
        throw std::out_of_range("Indice non valido");
    }
    else {
        category.erase(category.begin() + indexElement);
    }
}

void Category::printList() {
    std::cout << "Categoria: " << categoryName << std::endl;
    if (category.empty()) {
        throw std::out_of_range("La categoria è vuota");
    }
    else {
        for (int i = 0; i < category.size(); i++) {
            std::cout << i << " ― ― " << std::endl;
            category[i].Activity::printActivity();
        }
    }
}

void Category::clearList() {
    category.clear();
}

void Category::collectCategory() {
    writeCategory(categoryName);
    for (int i = 0; i < category.size(); i++) {
        category[i].collectActivity();
    }
}

void Category::readCategory(const std::string &name, const std::string &description, int day, int month, int year, bool yesNOdate, Category &newCategory) {
    Activity newActivity = Activity();
    newActivity.readActivity(name, description, day, month, year, yesNOdate);
    newCategory.category.push_back(newActivity);
}
