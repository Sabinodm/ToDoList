//
// Created by sabinodm on 14/09/23.
//

#include <iostream>
#include <limits>
#include "Activity.h"
#include "TxtFile.h"

Activity::Activity() : name("no  name"), description("no description"), YesNOdata(false) {

}

void Activity::setName() {
    std::cout << "Inserisci il nome della nuova attività" << std::endl;
    std::string chosenName;
    std::cin >> chosenName;
    this->name = chosenName;
}

void Activity::setDescription() {
    std::cout << "Inserisci una descrizione per la nuova attività" << std::endl;
    std::string chosenDescription;
    std::cin >> chosenDescription;
    this->description = chosenDescription;
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
            int chosenDay;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosenDay;

            std::cout << "Mese: ";
            int chosenMonth;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosenMonth;

            std::cout << "Anno: ";
            int chosenYear;
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> chosenYear;

            date.setDate(chosenDay, chosenMonth, chosenYear);
            d = true;

            }catch (TimeDateException &ex) {
                std::cout  << ex.what() << std::endl;
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

void Activity::collectActivity() {
    writeActivity(name, description, date, YesNOdata);
}

void Activity::readActivity(const std::string &readName, const std::string &readDescription, int readDay, int readMonth, int readYear, bool readYesNOdate) {
    this->name = readName;
    this->description = readDescription;
    this->date.setDate(readDay, readMonth, readYear);
    this->YesNOdata = readYesNOdate;
}
