#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


///
/// Classe base para todos os domínios.
///
///
///

class Dominio {
    //Luiz
    private:
        string valor;
        virtual void validar(string valor) = 0;

    public:

///
/// Destrutor virtual para evitar comportamento indefinido.
///

        virtual ~Dominio(){};

///
/// Armazena valor.
/// @param valor Valor do domínio representado em string.
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna valor.
/// @return valor
///
///

        string getValor();

};


inline string Dominio::getValor(){
    return valor;
}


///
/// Classe para representar capacidade.
/// Regras de formato:
/// - Capacidade é válida se for igual a 100, 200, 300, 400 ou 500.
///

class Capacidade: public Dominio {
    //Luiz
    private:
        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
        void validar(string valor) override;
};


///
/// Classe para representar cargo.
/// Regras de formato:
/// - Cargo é válido se for igual a ator, cenógrafo, figurinista, maquiador, sonoplasta ou iluminador.
///

class Cargo: public Dominio {
    //Henrique
    private:
//        static const bool PALAVRA_IGUAL = 0;
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


///
/// Classe para representar classificação.
/// Regras de formato:
/// - Classificação é válida se for igual a livre, 10, 12, 14, 16 ou 18.
///

class Classificacao: public Dominio {
    //Henrique
    private:
//        static const bool CLASSIFICACAO_IGUAL = 0;
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


///
/// Classe para representar código.
/// Regras de formato:
/// - Código é válido se for igual a LLDDDD.
/// - L é letra maiúscula.
/// - D é dígito.
///

class Codigo: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


///
/// Classe para representar data.
/// Regras de formato:
/// - Data é válida se for igual a DD/MM/AAAA.
/// - DD de 01 a 31.
/// - MM de 01 a 12.
/// - AAAA de 2000 a 9999.
/// - Leva em consideração anos bissextos.
///

class Data: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


///
/// Classe para representar email.
/// Regras de formato:
/// - Email é válido se for igual a parte-local@domínio.
/// - parte-local é composta por até 64 caracteres.
/// - domínio é composto por até 255 caracteres.
/// - Caractere pode ser letra maiúscula, letra minúscula, dígito, um dos caracteres: ! # $ % & ' * + - / = ? ^ _ ` { | } ~ ou ponto.
/// - Ponto não pode ser o primeiro ou último caractere, e não pode ocorrer em sequência.
///

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


///
/// Classe para representar horário.
/// Regras de formato:
/// - Horário é válido se for igual a HH:MM.
/// - HH de 00 a 23.
/// - MM é 00, 15, 30 ou 45.
///

class Horario: public Dominio {
    //Luiz
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Matrícula.
/// Regras de formato:
/// - Matrícula é válida se for igual a XXXXX.
/// - X é dígito.
/// - Não podem existir dígitos duplicados.
///

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


///
/// Classe para representar Nome.
/// Regras de formato:
/// - Nome é válido se for de 5 a 20 caracteres.
/// - Cada caractere é letra, ponto ou espaço em branco.
/// - Ponto é precedido por letra.
/// - Não há espaços em branco em sequência.
/// - Primeira letra de cada termo é letra maiúscula.
///

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


///
/// Classe para representar Senha.
/// Regras de formato:
/// - Senha é válida se for igual a XXXXXXXX.
/// - X é letra, dígito ou um dos caracteres especiais ! @ # $ % & ?.
/// - Não pode existir caractere repetido.
/// - Existe pelo menos uma letra (maiúscula ou minúscula), um dígito e um caractere especial.
///

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
