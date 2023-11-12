//
// Created by sabinodm on 11/11/23.
//
#include "UserInterface.h"
#include <iostream>
#include <limits>

int removeActivityInterface(){
    std::cout << "Inserisci il numero dell'attività da rimuovere" << std::endl;
    std::cout << "Elemento numero:";
    int indexElement;
    std::cin.exceptions(std::ios_base::failbit);
    std::cin >> indexElement;
    return indexElement;
}

std::string activitySetNameInterface(){
    std::cout << "Inserisci il nome della nuova attività" << std::endl;
    std::string chosenName;
    std::cin >> chosenName;
    return chosenName;
}

std::string activitySetDescriptionInterface(){
    std::cout << "Inserisci una descrizione per la nuova attività" << std::endl;
    std::string chosenDescription;
    std::cin >> chosenDescription;
    return chosenDescription;
}

int activitySetDayInterface(){
        try {
            std::cout << "Giorno: ";
            int chosenDay;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosenDay;
            return chosenDay;
        }catch (std::ios_base::failure &fail) {
            std::cout << "Valore inserito non valido" << std::endl;
            std::cout << "È stato inserito il giorno di default '1'" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 1;
        }
    }

int activitySetMonthInterface(){
    try {
        std::cout << "Mese: ";
        int chosenMonth;
        std::cin.exceptions(std::ios_base::failbit);
        std::cin >> chosenMonth;
        return chosenMonth;
    }catch (std::ios_base::failure &fail) {
        std::cout << "Valore inserito non valido" << std::endl;
        std::cout << "È stato inserito il mese di default '1'" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
}

int activitySetYearInterface() {
    try {
        std::cout << "Anno: ";
        int chosenYear;
        std::cin.exceptions(std::ios_base::failbit);
        std::cin >> chosenYear;
        return chosenYear;
    }catch (std::ios_base::failure &fail) {
        std::cout << "Valore inserito non valido" << std::endl;
        std::cout << "È stato inserito l'anno di default '1990'" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1990;
    }
}