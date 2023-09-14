//
// Created by sabinodm on 14/09/23.
//

#include <iostream>
#include "Activity.h"

Activity::Activity() : name("no  name"), description("no description") {

}

void Activity::setName() {
    std::cout << "Inserisci il nome della nuova attività" << std::endl;
    std::string chosen_name;
    std::cin >> chosen_name;
    this->name = chosen_name;
}

void Activity::setDescription() {
    std::cout << "Inserisci la descrizione della nuova attività" << std::endl;
    std::string chosen_description;
    std::cin >> chosen_description;
    this->description = chosen_description;
}

void Activity::printActivity() {
    std::cout << "Attività: " << name << std::endl;
    std::cout << "Descrizione: " << description << std::endl;
}