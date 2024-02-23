//
// Created by sabinodm on 23/09/23.
//

#include "TxtFile.h"
#include "Category.h"
#include "Activity.h"
#include <fstream>
#include <iostream>
#include <vector>

void checkFile(const std::string &file, std::vector<Category> &index) {
    std::ifstream fin;
    fin.open(file);

    if (fin.is_open()) { //il file esiste
        std::string firstLine;
        std::getline(fin, firstLine);
        std::cout << firstLine << std::endl;
        std::string line;
        std::getline(fin, line);
        readFile(fin, index);
        std::cout << "Caricamento completato" << std::endl;
        fin.close();
        std::cout << std::endl;
    }

    else { //il file non esiste
        std::ofstream fout(file);
        fout << "Il file è in caricamento" << std::endl;
        fout.close();
    }
}

void writeLabel() {
    std::ofstream fout("file.txt", std::ios_base::app);
    fout << "newCategoryLabel" <<std::endl;
    fout.close();
}

bool readLabel(const std::string &label) {
    if (label == "newCategoryLabel") {
        return true;
    }
    else {
        return false;
    }
}


void readFile(std::ifstream &fin, std::vector<Category> &index) {
    while (!fin.eof()) {
    std::string line;
    std::getline(fin, line);
    Category newCategory = Category(line);
        for (bool result= false; !result;) {
          std::string name;
          std::string description;
          std::string waste;
          int day;
          int month;
          int year;
          bool YesNOdate;
          std::getline(fin, name);
          if (readLabel(name)) {
              result = true;
          }
          else if (fin.eof()) {
              result = true;
          }
          else {
              std::getline(fin, description);
              fin >> day;
              fin >> month;
              fin >> year;
              fin >> YesNOdate;
              newCategory.readCategory(name, description, day, month, year, YesNOdate, newCategory);
              std::getline(fin, waste);
              result = false;
          }
        }
        index.push_back(newCategory);
    }
}

void saveFile(std::vector<Category> &index, const std::string& fileName) {
    std::ofstream fout(fileName);
    fout << "Il file è in caricamento" << std::endl;
    fout.close();
    for (int i = 0; i < index.size(); i++) {
        writeLabel();
        index[i].collectCategory();
    }
    std::cout << "File salvato" << std::endl;
}