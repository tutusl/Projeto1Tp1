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

inline void Participante::setMatricula(const Matricula &valor){
    matricula = valor; 
}

inline Matricula Participante::getMatricula(){
    return matricula; 
}

inline void Participante::setNome(const Nome &valor){
    nome = valor; 
}

inline Nome Participante::getNome(){
    return nome;
}

inline void Participante::setSobrenome(const Nome &valor){
    sobrenome = valor; 
}

inline Nome Participante::getSobrenome(){
    return sobrenome;
}

inline void Participante::setEmail(const Email &valor){
    email = valor; 
}

inline Email Participante::getEmail(){
    return email;
}

inline void Participante::setTelefone(const Telefone &valor){
    telefone = valor; 
}

inline Telefone Participante::getTelefone(){
    return telefone;
}

inline void Participante::setSenha(const Senha &valor){
    senha = valor; 
}

inline Senha Participante::getSenha(){
    return senha;
}

inline void Participante::setCargo(const Cargo &valor){
    cargo = valor; 
}

inline Cargo Participante::getCargo(){
    return cargo;
}

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

inline void Peca::setIdentificador(const Codigo &valor){
    identificador = valor; 
}

inline Codigo Peca::getIdentificador(){
    return identificador;
}

inline void Peca::setNome(const Nome &valor){
    nome = valor; 
}

inline Nome Peca::getNome(){
    return nome;
}

inline void Peca::setTipo(const Tipo &valor){
    tipo = valor; 
}

inline Tipo Peca::getTipo(){
    return tipo;
}

inline void Peca::setClassificacao(const Classificacao &valor){
    classificacao = valor; 
}

inline Classificacao Peca::getClassificacao(){
    return classificacao;
}

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

inline void Sessao::setIdentificador(const Codigo &valor){
    identificador = valor; 
}

inline Codigo Sessao::getIdentificador(){
    return identificador;
}

inline void Sessao::setData(const Data &valor){
    data = valor; 
}

inline Data Sessao::getData(){
    return data;
}

inline void Sessao::setHorario(const Horario &valor){
    horario = valor; 
}

inline Horario Sessao::getHorario(){
    return horario;
}

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
