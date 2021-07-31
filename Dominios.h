#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


class Capacidade {
    private:
        int cap;
        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};

    public:
        Capacidade(int cap);
        void setCap(int cap);
        int getCap();
};

inline int Capacidade::getCap(){
    return cap;
}

class Cargo {
    //Henrique
    private:
        string car;
    public:
        Cargo(string car);
        void setCar(string car);
        string getCar();
};

inline string Cargo::getCar(){
    return car;
}

class Classificacao {
    //Henrique
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
    //Luiz
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
    //Henrique
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
    // Henrique
    private:
    public:
};

class Nome {
    // Arthur
    private:
        string nome;
        static const regex FORMATO;
    public:
        Nome(string nome);
        void setNome(string nome);
        string getNome();
};

class Senha {
    // Arthur
    private:
        string senha;
        static const regex FORMATO;
    public:
        Senha (string senha);
        void setSenha(string senha);
        string getSenha();
};

class Telefone {
    // Arthur
    private:
    public:
};

class Tipo {
    // Arthur
    private:
    public:
};






#endif // DOMINIOS_H
