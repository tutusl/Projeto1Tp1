#include "Dominios.h"

#ifndef ENTIDADES_H
#define ENTIDADES_H

/// 
/// Classe para entidade participante
///

class Participante {
    //180030353
    private:
        Matricula matricula;
        Nome nome;
        Nome sobrenome;
        Email email;
        Telefone telefone;
        Senha senha;
        Cargo cargo;

    public:

///
/// Armazena matrícula.
/// @param valor Objeto de classe Matrícula
///
        void setMatricula(const Matricula &valor);
///
/// Retorna matrícula.
/// @return valor
///
///
        Matricula getMatricula();
///
/// Armazena nome.
/// @param valor Objeto de classe Nome
///
        void setNome(const Nome &valor);
///
/// Retorna Nome.
/// @return valor
///
        Nome getNome();
///
/// Armazena sobrenome.
/// @param valor Objeto de classe Nome
///
        void setSobrenome(const Nome &valor);
///
/// Retorna sobrenome.
/// @return valor
///
        Nome getSobrenome();
///
/// Armazena email.
/// @param valor Objeto de classe Email
///
        void setEmail(const Email &valor);
///
/// Retorna email.
/// @return valor
///
        Email getEmail();
///
/// Armazena telefone.
/// @param valor Objeto de classe Telefone
///
        void setTelefone(const Telefone &valor);
///
/// Retorna telefone.
/// @return valor
///
        Telefone getTelefone();
///
/// Armazena senha.
/// @param valor Objeto de classe Senha
///
        void setSenha(const Senha &valor);
///
/// Retorna senha.
/// @return valor
///
        Senha getSenha();
///
/// Armazena cargo.
/// @param valor Objeto de classe Cargo
///
        void setCargo(const Cargo &valor);
///
/// Retorna cargo.
/// @return valor
///
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

/// 
/// Classe para entidade Peça
///

class Peca {
    //190046546
    private:
        Codigo identificador;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;

    public:
///
/// Armazena identificador.
/// @param valor Objeto da classe Código.
///
        void setIdentificador(const Codigo &valor);
///
/// Retorna identificador.
/// @return valor
///
        Codigo getIdentificador();
///
/// Armazena nome.
/// @param valor Objeto da classe Nome.
///
        void setNome(const Nome &valor);
///
/// Retorna nome.
/// @return valor
///
        Nome getNome();
///
/// Armazena tipo.
/// @param valor Objeto da classe Tipo.
///
        void setTipo(const Tipo &valor);
///
/// Retorna tipo.
/// @return valor
///
        Tipo getTipo();
///
/// Armazena classificação.
/// @param valor Objeto da classe Classificação.
///
        void setClassificacao(const Classificacao &valor);
///
/// Retorna classificação.
/// @return valor
///
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

/// 
/// Classe para entidade Sessão
///

class Sessao {
    //180030353
    private:
        Codigo identificador;
        Data data;
        Horario horario;

    public:
///
/// Armazena identificador.
/// @param valor Objeto da classe Código.
///
        void setIdentificador(const Codigo &valor);
///
/// Retorna identificador.
/// @return valor
///
        Codigo getIdentificador();
///
/// Armazena data.
/// @param valor Objeto da classe Data.
///
        void setData(const Data &valor);
///
/// Retorna data.
/// @return valor
///
        Data getData();
///
/// Armazena horário.
/// @param valor Objeto da classe Horário.
///
        void setHorario(const Horario &valor);
///
/// Retorna horário.
/// @return valor
///
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
/// 
/// Classe para entidade Sala
///
class Sala {
    //180030353
    private:
        Codigo identificador;
        Nome nome;
        Capacidade capacidade;

    public:
///
/// Armazena identificador.
/// @param valor Objeto da classe Código.
///
        void setIdentificador(const Codigo &valor);
///
/// Retorna identificador.
/// @return valor
///
        Codigo getIdentificador();
///
/// Armazena nome.
/// @param valor Objeto da classe Nome.
///
        void setNome(const Nome &valor);
///
/// Retorna nome.
/// @return valor
///
        Nome getNome();
///
/// Armazena capacidade.
/// @param valor Objeto da classe Capcidade.
///
        void setCapacidade(const Capacidade &valor);
///
/// Retorna capacidade.
/// @return valor
///
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
