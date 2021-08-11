#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


////////////////////////////////////////////////

class Dominio {
    //Luiz
    private:
        string valor;
        virtual void validar(string valor) = 0;

    public:
        void setValor(string valor);
        string getValor();

};


inline string Dominio::getValor(){
    return valor;
}





class Capacidade: public Dominio {
    //Luiz
    private:
        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
        void validar(string valor) override;
};




class Cargo: public Dominio {
    //Henrique
    private:
        static const bool PALAVRA_IGUAL = 0;
        void validar(string valor);
};








//class Cargo {
//    //Henrique
//    private:
//        string cargo;
//
//    public:
//        Cargo(string cargo);
//        void setCargo(string cargo);
//        string getCargo();
//};
//
//inline string Cargo::getCargo(){
//    return cargo;
//}


class Classificacao: public Dominio {
    //Henrique
    private:
        static const bool CLASSIFICACAO_IGUAL = 0;
        void validar(string valor) override;
};




//class Classificacao {
//    //Henrique
//    private:
//        string classificacao;
//        void validar(string classificacao);
//        static const bool CLASSIFICACAO_IGUAL = 0;
//    public:
//        Classificacao(string classificacao);
//        void setClassificacao(string classificacao);
//        string getClassificacao();
//};
//
//inline string Classificacao::getClassificacao(){
//    return classificacao;
//}



class Codigo: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};




class Data: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};



class Email: public Dominio {
    //Henrique
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};



//class Email {
//    //Henrique
//    private:
//        string email;
//        void validar(string email);
//        static const regex FORMATO;
//    public:
//        Email(string email);
//        void setEmail(string email);
//        string getEmail();
//};
//
//inline string Email::getEmail(){
//    return email;
//}


class Horario: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Matricula: public Dominio {
    // Henrique
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};




//class Matricula {
//    // Henrique
//    private:
//        string matricula;
//        static const regex FORMATO;
//        void validar(string matricula);
//    public:
//        Matricula(string matricula);
//        void setMatricula(string matricula);
//        string getMatricula();
//};
//
//inline string Matricula::getMatricula(){
//    return matricula;
//}


class Nome: public Dominio {
    // Arthur
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};




//class Nome {
//    // Arthur
//    private:
//        string nome;
//        static const regex FORMATO;
//    public:
//        Nome(string nome);
//        void setNome(string nome);
//        string getNome();
//};



class Senha: public Dominio {
    // Arthur
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


//class Senha {
//    // Arthur
//    private:
//        string senha;
//        static const regex FORMATO;
//    public:
//        Senha (string senha);
//        void setSenha(string senha);
//        string getSenha();
//};


class Telefone: public Dominio {
    // Arthur
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


//class Telefone {
//    // Arthur
//    private:
//        string numeroTelefone;
//        static const regex FORMATO;
//    public:
//        Telefone (string numeroTelefone);
//        void setTelefone(string numeroTelefone);
//        string getTelefone();
//};



class Tipo: public Dominio {
    // Arthur
    private:
        void validar(string valor) override;
};


//class Tipo {
//    // Arthur
//    private:
//        string tipo;
//    public:
//        Tipo (string tipo);
//        void setTipo(string tipo);
//        string getTipo();
//};

#endif // DOMINIOS_H
