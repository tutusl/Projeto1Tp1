#include "Dominios.h"

#ifndef ENTIDADES_H
#define ENTIDADES_H




class Participante {
    private:
        Matricula matricula;
        Nome nome;
        Nome sobrenome;
        Email email;
        Telefone telefone;
        Senha senha;
        Cargo cargo;

    public:
        void setMatricula(const Matricula &valor);
        Matricula getMatricula();

        void setNome(const Nome &valor);
        Nome getNome();

        void setSobrenome(const Nome &valor);
        Nome getSobrenome();

        void setEmail(const Email &valor);
        Email getEmail();

        void setTelefone(const Telefone &valor);
        Telefone getTelefone();

        void setSenha(const Senha &valor);
        Senha getSenha();

        void setCargo(const Cargo &valor);
        Cargo getCargo();
};


class Peca {
    private:
        Codigo identificador;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;

    public:
        void setIdentificador(const Codigo &valor);
        Codigo getIdentificador();

        void setNome(const Nome &valor);
        Nome getNome();

        void setTipo(const Tipo &valor);
        Tipo getTipo();

        void setClassificacao(const Classificacao &valor);
        Classificacao getClassificacao();
};


class Sessao {
    private:
        Codigo identificador;
        Data data;
        Horario horario;

    public:
        void setIdentificador(const Codigo &valor);
        Codigo getIdentificador();

        void setData(const Data &valor);
        Data getData();

        void setHorario(const Horario &valor);
        Horario getHorario();
};


class Sala {
    private:
        Codigo identificador;
        Nome nome;
        Capacidade capacidade;

    public:
        void setIdentificador(const Codigo &valor);
        Codigo getIdentificador();

        void setNome(const Nome &valor);
        Nome getNome();

        void setCapacidade(const Capacidade &valor);
        Capacidade getCapacidade();
};


inline void Sala::setIdentificador(const Codigo &valor){
    identificador = valor;
}

inline Codigo Sala::getIdentificador(){
    return identificador;
}


inline void Sala::setNome(const Nome &valor){
    nome = valor;
}

inline Nome Sala::getNome(){
    return nome;
}


inline void Sala::setCapacidade(const Capacidade &valor){
    capacidade = valor;
}

inline Capacidade Sala::getCapacidade(){
    return capacidade;
}
#endif
