#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


class Capacidade {
    //Luiz
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
        string cargo;
    public:
        Cargo(string cargo);
        void setCargo(string cargo);
        string getCargo();
};

inline string Cargo::getCargo(){
    return cargo;
}

class Classificacao {
    //Henrique
    private:
        string classificacao;
    public:
        Classificacao(string classificacao);
        void setClassificacao(string classificacao);
        string getClassificacao();
};

inline string Classificacao::getClassificacao(){
    return classificacao;
}

class Codigo {
    //Luiz
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
    //Luiz
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
        string numeroTelefone;
        static const regex FORMATO;
    public:
        Telefone (string numeroTelefone);
        void setTelefone(string numeroTelefone);
        string getTelefone();
};

class Tipo {
    // Arthur
    private:
        string tipo;
    public:
        Tipo (string tipo);
        void setTipo(string tipo);
        string getTipo();
};

#endif // DOMINIOS_H
