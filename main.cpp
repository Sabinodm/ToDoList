#include <iostream>
#include <vector>
#include "ActivityList.h"

int listSelector(std::vector<ActivityList> &index) {
    int list_number;
    std::cout << "scegli  la lista dall'elenco:" << std::endl;
    for (int i = 0; i < index.size(); i++) {
        std::cout << i << " ― ― ";
        std::cout << index[i].getName() << std::endl;
        std::cout << "Lista numero:";
        std::cin >> list_number;
    }
}

int main() {
    std::vector<ActivityList> indexOfActivityLists;
    int a;
    do {
        std::cout << "Scegli l'operazione dall'elenco " << std::endl;
        std::cout << "0-- Esci dal programma " << std::endl;
        std::cout << "1-- Creare una nuova lista " << std::endl;
        std::cout << "2-- Aggiungere un nuovo elemento " << std::endl;
        std::cout << "3-- Stampare gli elementi di una lista " << std::endl;
        std::cout << "4-- Rimuovere un elemento da una lista " << std::endl;
        std::cout << "5-- Svuotare una lista " << std::endl;

        std::cin >> a;
        std::string list_name;
        int list_number;

        switch (a) {
            case 0:
                std::cout << "Arrivederci" << std::endl;
                break;

            case 1 :  //creazione lista
                std::cout << "inserisci nome nuova lista" << std::endl;
                std::cin >> list_name;
                indexOfActivityLists.push_back(ActivityList(list_name));
                indexOfActivityLists[indexOfActivityLists.size() - 1].setName(list_name);
                break;

            case 2: //aggiunta elemento
                list_number = listSelector(indexOfActivityLists);
                indexOfActivityLists[list_number].addActivity();
                break;

            case 3: //stampa lista
                list_number = listSelector(indexOfActivityLists);
                indexOfActivityLists[list_number].printList();
                break;

            case 4: //rimozione elemento da una lista
                list_number = listSelector(indexOfActivityLists);
                indexOfActivityLists[list_number].printList();
                indexOfActivityLists[list_number].removeActivity();
                std::cout << "Elemento rimosso" << std::endl;
                break;

            case 5: //svuotamento lista
                list_number = listSelector(indexOfActivityLists);
                indexOfActivityLists[list_number].clearList();
                std::cout << "Lista svuotata" << std::endl;
                break;
        }
    } while (a != 0);
}