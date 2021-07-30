#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


class Capacidade {
    private:
        int cap;

    public:
        Capacidade(int cap);
        void setCap(int cap);
        int getCap();
};

inline int Capacidade::getCap(){
    return cap;
}

class Cargo {
    private:
    public:
};

class Classificacao {
    private:
    public:
};

class Codigo {
    private:
        string cod;
        static const regex FORMATO;

    public:
        Codigo(string cod);
        void setCod(string cod);
        string getCod();
};

inline string Codigo::getCod(){
    return cod;
}




class Data {
    private:
        string dat;
        static const regex FORMATO;

    public:
        Data(string dat);
        void setDat(string dat);
        string getDat();
};



inline string Data::getDat(){
    return dat;
}

class Email {
    private:
    public:
};


class Horario {
    private:
        string hor;
        static const regex FORMATO;

    public:
        Horario(string hor);
        void setHor(string hor);
        string getHor();
};

inline string Horario::getHor(){
    return hor;
}

class Matricula {
    private:
    public:
};

class Nome {
    private:
    public:
};

class Senha {
    private:
    public:
};

class Telefone {
    private:
    public:
};

class Tipo {
    private:
    public:
};






#endif // DOMINIOS_H
