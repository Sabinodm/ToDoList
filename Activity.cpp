//
// Created by sabinodm on 14/09/23.
//

#include <iostream>
#include "Activity.h"
#include "TxtFile.h"

Activity::Activity() : name("no  name"), description("no description"), YesNOdata(false) {

}

void Activity::setName(const std::string &chosenName) {
    this->name = chosenName;
}

void Activity::setDescription(const std::string &chosenDescription) {
    this->description = chosenDescription;
}

void Activity::setDate(int chosenDay, int chosenMonth, int chosenYear) {
        try {
            this->date.setDate(chosenDay, chosenMonth, chosenYear);
        }catch (TimeDateException &ex) {
            std::cout  << ex.what() << std::endl;
            std::cout << "È stata inserita la data di default '1/1/1990'" << std::endl;
    }
}

void Activity::setYesNOdata(bool chosenYesNOdata) {
    this->YesNOdata = chosenYesNOdata;
}

void Activity::collectActivity() const {
    std::ofstream fout("file.txt", std::ios_base::app);
    fout << name << std::endl;
    fout << description << std::endl;
    fout << date.getDay() << std::endl << date.getMonth() << std::endl << date.getYear() << std::endl;
    fout << YesNOdata << std::endl;
    fout.close();

}

void Activity::readActivity(const std::string &readName, const std::string &readDescription, int readDay, int readMonth, int readYear, bool readYesNOdate) {
    this->name = readName;
    this->description = readDescription;
    this->date.setDate(readDay, readMonth, readYear);
    this->YesNOdata = readYesNOdate;
}

//test
std::string Activity::getName() const {
    return name;
}

std::string Activity::getDescription() const {
    return description;
}

Date Activity::getDate() const {
    return date;
}

bool Activity::getYesNOdata() const {
    return YesNOdata;
}