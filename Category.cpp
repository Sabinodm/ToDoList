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

const std::string & Category::getName() const {
    return categoryName;
}

void Category::addActivity(const std::string &chosenName, const std::string &chosenDescription, int chosenDay, int chosenMonth, int chosenYear, bool chosenYesNOdata) {
    Activity newActivity = Activity();
    newActivity.Activity::setName(chosenName);
    newActivity.Activity::setDescription(chosenDescription);
    newActivity.Activity::setDate(chosenDay, chosenMonth, chosenYear);
    newActivity.Activity::setYesNOdata(chosenYesNOdata);
    category.push_back(newActivity);
}

void Category::addActivity(const std::string &chosenName, const std::string &chosenDescription, bool chosenYesNOdata) { //overload in caso di attività senza data
    Activity newActivity = Activity();
    newActivity.Activity::setName(chosenName);
    newActivity.Activity::setDescription(chosenDescription);
    newActivity.Activity::setYesNOdata(chosenYesNOdata);
    category.push_back(newActivity);
}

void Category::removeActivity(int indexElement) {
    if (indexElement >= category.size() || indexElement < 0) {
        throw std::out_of_range("Indice non valido");
    }
    else {
        category.erase(category.begin() + indexElement);
    }
}

void Category::clearList() {
    category.clear();
}

void Category::collectCategory() const{
    std::ofstream fout("file.txt", std::ios_base::app);
    fout << categoryName << std::endl;
    fout.close();
    for (int i = 0; i < category.size(); i++) {
        category[i].collectActivity();
    }
}

void Category::readCategory(const std::string &name, const std::string &description, int day, int month, int year, bool yesNOdate, Category &newCategory) {
    Activity newActivity = Activity();
    newActivity.readActivity(name, description, day, month, year, yesNOdate);
    newCategory.category.push_back(newActivity);
}

int Category::searchActivity(const std::string &searchedName) const {
    int counter = 0;
    for (int i = 0; i < category.size(); i++) {
        bool result = category[i].Activity::getName() == searchedName;
        if (result) {
            std::cout << "Categoria: " << categoryName << std::endl;
            std::cout << i << " ― ― " << std::endl;
            std::cout << "Nome: " << category[i].Activity::getName() << std::endl;
            std::cout << "Descrizione: " << category[i].Activity::getDescription() << std::endl;
            if (category[i].Activity::getYesNOdata()) {
                std::cout << "Data di scadenza: " << category[i].Activity::getDate().getDay() << "/" << category[i].Activity::getDate().getMonth() << "/" << category[i].Activity::getDate().getYear() << std::endl;
            }
            else {
                std::cout << "Nessuna data di scadenza" << std::endl;
            }
            std::cout << std::endl;
            counter++;
        }
    }
    return counter;
}

std::vector<Activity> Category::getVector() const{
    return category;
}

//test

size_t Category::getSize() const{
    return  category.size();
}

std::string Category::getActivityName(int indexElement) const{
    return category[indexElement].Activity::getName();
}

std::string Category::getActivityDescription(int indexElement) const{
    return category[indexElement].Activity::getDescription();
}

Date Category::getActivityDate(int indexElement) const{
    return category[indexElement].Activity::getDate();
}

bool Category::getActivityYesNOdata(int indexElement) const{
    return category[indexElement].Activity::getYesNOdata();
}