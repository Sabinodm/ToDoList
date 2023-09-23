//
// Created by sabinodm on 19/09/23.
//

#ifndef TODOLIST_TIMEDATEEXCEPTION_H
#define TODOLIST_TIMEDATEEXCEPTION_H

#include <stdexcept>
#include <string>

// Classe di gestione delle eccezioni riguardanti la data e ora

class TimeDateException : public std::invalid_argument
{
private:
    int err_code;

public:
    // codici di errore
    enum codes
    {
        UNDEFINED, // errore non definito
        INVALID_FORMAT // formato della data non valido
    };

    TimeDateException(const std::string& err_msg, int err_code = 0);
    int code();
};

#endif //TODOLIST_TIMEDATEEXCEPTION_H
