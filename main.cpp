#include <iostream>
#include <vector>
#include <limits>
#include "Category.h"

int listSelector(std::vector<Category> &index) {
    int category_number;
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
        std::cin >> category_number;
    }

    if (category_number >= index.size() || category_number < 0) {
        throw std::out_of_range("Categoria non esistente");
    } else {
        return category_number;
    }
}

int main() {
    std::vector<Category> indexOfCategory;
    int a;
    do {
        std::cout << "Scegli l'operazione dall'elenco " << std::endl;
        std::cout << "0-- Esci dal programma " << std::endl;
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
        std::string category_name;

        switch (a) {
            case 0:
                std::cout << "Arrivederci" << std::endl;
            break;

            case 1 :  //creazione categoria
                std::cout << "Inserisci nome nuova categoria" << std::endl;
                std::cin >> category_name;
                indexOfCategory.push_back(Category(category_name));
                indexOfCategory[indexOfCategory.size() - 1].setName(category_name);
            break;

            case 2: //aggiunta attività
                try {
                    int category_number = listSelector(indexOfCategory);
                    indexOfCategory[category_number].addActivity();
                    //TODO exception per time
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
                    int category_number = listSelector(indexOfCategory);
                    indexOfCategory[category_number].printList();
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
                    int category_number = listSelector(indexOfCategory);
                    indexOfCategory[category_number].printList();
                    indexOfCategory[category_number].removeActivity();
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
                    int category_number = listSelector(indexOfCategory);
                    indexOfCategory[category_number].clearList();
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
                    int category_number = listSelector(indexOfCategory);
                    indexOfCategory.erase(indexOfCategory.begin() + category_number);
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
    } while (a != 0);
}