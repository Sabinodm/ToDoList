//
// Created by sabinodm on 19/09/23.
//

#include "TimeDateException.h"

// Classe di gestione delle eccezioni riguardanti la data e ora

TimeDateException::TimeDateException(const std::string& err_msg, int err_code) : std::invalid_argument(err_msg)
{
    if(err_code < 0 || err_code > 2)
        this->err_code = UNDEFINED;
    else
        this->err_code = err_code;
}

int TimeDateException::code(){
    return this->err_code;
}