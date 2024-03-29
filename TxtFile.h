//
// Created by sabinodm on 23/09/23.
//

#ifndef TODOLIST_TXTFILE_H
#define TODOLIST_TXTFILE_H
#include <fstream>
#include "Activity.h"
#include "Category.h"

void checkFile(const std::string &file, std::vector<Category> &index);
void readFile(std::ifstream &fin, std::vector<Category> &index);
void saveFile(std::vector<Category> &index, const std::string &file);
void writeLabel();
bool readLabel(const std::string &label);




#endif //TODOLIST_TXTFILE_H
