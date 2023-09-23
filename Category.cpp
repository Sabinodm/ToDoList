//
// Created by sabinodm on 14/09/23.
//
#include "iostream"
#include "Category.h"
#include "Activity.h"

Category::Category(std::string name) : category_name(name) {

}

const std::string & Category::setName(std::string & chosen_name) {
    this->category_name = chosen_name;
    return category_name;
}

const std::string & Category::getName() {
    return category_name;
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
    int index_element;
    std::cin.exceptions(std::ios_base::failbit);
    std::cin >> index_element;
    if (index_element >= category.size() || index_element < 0) {
        throw std::out_of_range("Indice non valido");
    }
    else {
        category.erase(category.begin() + index_element);
    }
}

void Category::printList() {
    std::cout << "Categoria: " << category_name << std::endl;
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
