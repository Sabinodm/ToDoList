#include <iostream>
#include <vector>
#include <limits>
#include "Category.h"
#include "TxtFile.h"

int listSelector(std::vector<Category> &index) {
    int categoryNumber;
    std::cout << "Scegli la categoria dall'elenco:" << std::endl;
    for (int i = 0; i < index.size(); i++) {
        std::cout << i << " ― ― ";
        std::cout << index[i].getName() << std::endl;
    }

    if (index.empty()) {
        throw std::out_of_range("Non ci sono categorie! \nCrea una categoria prima di procedere!");
    }
    else {
        std::cout << "Categoria numero:";
        std::cin.exceptions(std::ios_base::failbit);
        std::cin >> categoryNumber;
    }

    if (categoryNumber >= index.size() || categoryNumber < 0) {
        throw std::out_of_range("Categoria non esistente");
    } else {
        return categoryNumber;
    }
}

int main() {
    std::vector<Category> indexOfCategory;
    int a;
    try {
        checkFile("file.txt", indexOfCategory);
    }catch (TimeDateException &ex) {
        std::cout << "Errore nella lettura del file"  << std::endl;
        std::cout << std::endl;
    }

    do {
        std::cout << "Scegli l'operazione dall'elenco " << std::endl;
        std::cout << "0-- Salva ed esci dal programma " << std::endl;
        std::cout << "1-- Creare una nuova categoria " << std::endl;
        std::cout << "2-- Aggiungere una nuova attività " << std::endl;
        std::cout << "3-- Stampare le attività di una categoria " << std::endl;
        std::cout << "4-- Rimuovere un' attività da una categoria " << std::endl;
        std::cout << "5-- Svuotare una categoria " << std::endl;
        std::cout << "6-- Eliminare una categoria ed il suo contenuto " << std::endl;
        std::cout << "7-- Eliminare tutte le categorie ed il loro contenuto " << std::endl;
        try {
            std::cin.exceptions(std::ios_base::failbit);
            std::cin >> a;
        }catch (std::ios_base::failure &fail) {
            std::cout << "Valore inserito non valido" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            a = -1; //case default
        }
        std::string categoryName;

        switch (a) {
            case 0:
                saveFile(indexOfCategory);
                std::cout << "Arrivederci" << std::endl;
            break;

            case 1 :  //creazione categoria
                std::cout << "Inserisci nome nuova categoria" << std::endl;
                std::cin >> categoryName;
                indexOfCategory.push_back(Category(categoryName));
                indexOfCategory[indexOfCategory.size() - 1].setName(categoryName);
            break;

            case 2: //aggiunta attività
                try {
                    int categoryNumber = listSelector(indexOfCategory);
                    indexOfCategory[categoryNumber].addActivity();
                }catch (std::out_of_range &e ){
                    std::cout << e.what() << std::endl;
                }catch (std::ios_base::failure &fail) {
                    std::cout << "Valore inserito non valido" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            break;

            case 3: //stampa categoria
                try {
                    int categoryNumber = listSelector(indexOfCategory);
                    indexOfCategory[categoryNumber].printList();
                }catch (std::out_of_range &e ){
                    std::cout << e.what() << std::endl;
                }catch (std::ios_base::failure &fail) {
                    std::cout << "Valore inserito non valido" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            break;

            case 4: //rimozione attività da una categoria
                try {
                    int categoryNumber = listSelector(indexOfCategory);
                    indexOfCategory[categoryNumber].printList();
                    indexOfCategory[categoryNumber].removeActivity();
                    std::cout << "Attività rimossa" << std::endl;
                }catch (std::out_of_range &e ){
                    std::cout << e.what() << std::endl;
                }catch (std::ios_base::failure &fail) {
                    std::cout << "Valore inserito non valido" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            break;

            case 5: //svuotamento categoria
                try {
                    int categoryNumber = listSelector(indexOfCategory);
                    indexOfCategory[categoryNumber].clearList();
                    std::cout << "Categoria svuotata" << std::endl;
                }catch (std::out_of_range &e ){
                    std::cout << e.what() << std::endl;
                }catch (std::ios_base::failure &fail) {
                    std::cout << "Valore inserito non valido" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case 6: //eliminazione categoria
                try {
                    int categoryNumber = listSelector(indexOfCategory);
                    indexOfCategory.erase(indexOfCategory.begin() + categoryNumber);
                    std::cout << "Categoria eliminata" << std::endl;
                }catch (std::out_of_range &e ){
                    std::cout << e.what() << std::endl;
                }catch (std::ios_base::failure &fail) {
                    std::cout << "Valore inserito non valido" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            break;

            case 7: //eliminazione tutte le categorie
                indexOfCategory.clear();
                std::cout << "Tutte le categorie sono state eliminate" << std::endl;
                break;

            default:
                std::cout << "operazione non valida" << std::endl;
                break;
        }
        std::cout << std::endl;
    } while (a != 0);
}