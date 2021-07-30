#include <stdexcept>
#include "Dominios.h"

using namespace std;

const regex Codigo::FORMATO {"[A-Z]{2}[0-9]{4}"};
const regex Horario::FORMATO {"([01][0-9]|2[0-3]):(00|15|30|45)"};


//talvez colocar try-catch
Capacidade::Capacidade(int cap){
    setCap(cap);
}



void Capacidade::setCap(int cap){
    //Os números mágicos correspondem às capacidades possíveis
    switch (cap) {
        case 100:
        case 200:
        case 300:
        case 400:
        case 500:
            this->cap = cap;
            break;
        default:
            throw invalid_argument("Capacidade invalida");
    }


}



//talvez colocar try-catch
Codigo::Codigo(string cod){
    setCod(cod);
}



void Codigo::setCod(string cod){
    if (regex_match(cod, FORMATO))
        this->cod = cod;
    else
        throw invalid_argument("Codigo invalido");
}




//talvez colocar try-catch
Horario::Horario(string hor){
    setHor(hor);
}


void Horario::setHor(string hor){
    if (regex_match(hor, FORMATO))
        this->hor = hor;
    else
        throw invalid_argument("Horario invalido");
}
