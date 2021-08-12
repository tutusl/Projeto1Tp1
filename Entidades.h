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
        void setMatricula(Matricula valor);
        Matricula getMatricula();

        void setNome(Nome valor);
        Nome getNome();

        void setSobrenome(Nome valor);
        Nome getSobrenome();

        void setEmail(Email valor);
        Email getEmail();

        void setTelefone(Telefone valor);
        Telefone getTelefone();

        void setSenha(Senha valor);
        Senha getSenha();

        void setCargo(Cargo valor);
        Cargo getCargo();
};














#endif
