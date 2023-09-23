//
// Created by sabinodm on 14/09/23.
//

#include <iostream>
#include <limits>
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
    std::cout << "Inserisci una descrizione per la nuova attività" << std::endl;
    std::string chosen_description;
    std::cin >> chosen_description;
    this->description = chosen_description;
}

void Activity::setDate() {
    std::cout << "Vuoi inserire una data di scadenza per la nuova attività? (S/N)" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "S" || answer == "s") {
        YesNOdata = true;
        std::cout << "Inserisci la data di scadenza per la nuova attività" << std::endl;
        for (bool d = false; !d;) {
            std::cout << "Giorno: ";
            try {
            int chosen_day;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosen_day;

            std::cout << "Mese: ";
            int chosen_month;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosen_month;

            std::cout << "Anno: ";
            int chosen_year;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosen_year;

            date.setDate(chosen_day, chosen_month, chosen_year);
            d = true;

            }catch (TimeDateException &ex) {
                std::cout << "[" << ex.code() << "] " << ex.what() << std::endl;
            }catch (std::ios_base::failure &fail) {
                std::cout << "Valore inserito non valido" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
        }
    }
    else if (answer == "N" || answer == "n") {
        YesNOdata = false;
    }
    else {
        std::cout << "Risposta non valida" << std::endl;
        std::cout << "Nessuna data è stata inserita" << std::endl;
       YesNOdata = false;
    }
}

void Activity::printActivity() {
    std::cout << "Attività: " << name << std::endl;
    std::cout << "Descrizione: " << description << std::endl;
    if (!YesNOdata) {
        std::cout << "Data di scadenza: Nessuna data inserita" << std::endl;
    }
    else {
        std::cout << "Data di scadenza: " << date.getDate() << std::endl;
    }
}