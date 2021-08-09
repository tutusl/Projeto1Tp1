#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


////////////////////////////////////////////////
template <typename T>
class Dominio {
    //Luiz
    private:
        T valor;
        virtual void validar(T valor) = 0;

    public:
        void setValor(T valor);
        T getValor();

};

template <typename T>
inline T Dominio<T>::getValor(){
    return valor;
}

template <typename T>
inline void Dominio<T>::setValor(T valor){
    validar(valor);
    this->valor = valor;
}



class Capacidade: public Dominio<int> {
    //Luiz
    private:
        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
        void validar(int valor) override;
};



class Codigo: public Dominio<string> {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


//////////////////////////////////////////





//class Capacidade {
//    //Luiz
//    private:
//        int cap;
//        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
//
//    public:
//        Capacidade(int cap);
//        void setCap(int cap);
//        int getCap();
//};
//
//inline int Capacidade::getCap(){
//    return cap;
//}







class Cargo {
    //Henrique
    private:
        string cargo;
        void validar(string cargo);
        static const bool PALAVRA_IGUAL = 0;
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
        void validar(string classificacao);
        static const bool CLASSIFICACAO_IGUAL = 0;
    public:
        Classificacao(string classificacao);
        void setClassificacao(string classificacao);
        string getClassificacao();
};

inline string Classificacao::getClassificacao(){
    return classificacao;
}



//class Codigo {
//    //Luiz
//    private:
//        string cod;
//        static const regex FORMATO;
//
//    public:
//        Codigo(string cod);
//        void setCod(string cod);
//        string getCod();
//};
//
//inline string Codigo::getCod(){
//    return cod;
//}




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
        string email;
        void validar(string email);
        static const regex FORMATO;
    public:
        Email(string email);
        void setEmail(string email);
        string getEmail();
};

inline string Email::getEmail(){
    return email;
}


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
        string matricula;
        static const regex FORMATO;
        void validar(string matricula);
    public:
        Matricula(string matricula);
        void setMatricula(string matricula);
        string getMatricula();
};

inline string Matricula::getMatricula(){
    return matricula;
}

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
