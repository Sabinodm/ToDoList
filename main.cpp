#include <iostream>
#include <vector>
#include "Category.h"

int listSelector(std::vector<Category> &index) {
    int list_number;
    std::cout << "Scegli  la categoria dall'elenco:" << std::endl;
    for (int i = 0; i < index.size(); i++) {
        std::cout << i << " ― ― ";
        std::cout << index[i].getName() << std::endl;
        std::cout << "Categoria numero:";
        std::cin >> list_number;
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

        std::cin >> a;
        std::string list_name;
        int list_number;

        switch (a) {
            case 0:
                std::cout << "Arrivederci" << std::endl;
                break;

            case 1 :  //creazione categoria
                std::cout << "Inserisci nome nuova categoria" << std::endl;
                std::cin >> list_name;
                indexOfCategory.push_back(Category(list_name));
                indexOfCategory[indexOfCategory.size() - 1].setName(list_name);
                break;

            case 2: //aggiunta attività
                list_number = listSelector(indexOfCategory);
                indexOfCategory[list_number].addActivity();
                break;

            case 3: //stampa categoria
                list_number = listSelector(indexOfCategory);
                indexOfCategory[list_number].printList();
                break;

            case 4: //rimozione attività da una categoria
                list_number = listSelector(indexOfCategory);
                indexOfCategory[list_number].printList();
                indexOfCategory[list_number].removeActivity();
                std::cout << "Attività rimossa" << std::endl;
                break;

            case 5: //svuotamento categoria
                list_number = listSelector(indexOfCategory);
                indexOfCategory[list_number].clearList();
                std::cout << "Categoria svuotata" << std::endl;
                break;

            case 6: //eliminazione categoria
                list_number = listSelector(indexOfCategory);
                indexOfCategory.erase(indexOfCategory.begin() + list_number);
                std::cout << "Categoria eliminata" << std::endl;
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