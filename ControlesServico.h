#ifndef CONTROLES_SERVICO_H
#define CONTROLES_SERVICO_H

#include <string>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"



class CntrServicoAutenticacao: public IServicoAutenticacao {
    public:
        bool autenticar(Matricula* matricula, Senha* senha) override;

};


class CntrServicoParticipante: public IServicoParticipante {
    public:
        bool descadastrar(Matricula *matricula) override;
        bool alterar(Participante *participante) override;
        bool cadastrar(Participante *participante) override;
        bool cadastrarEmPeca(Matricula *matricula, string peca) override;
};


class CntrServicoPeca: public IServicoPeca {
    public:
        bool incluir(Peca *peca) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Peca *peca) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};


class CntrServicoSessao: public IServicoSessao {
    public:
        bool incluir(Sessao *sessao, string peca, string sala) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Sessao *sessao) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};


class CntrServicoSala: public IServicoSala {
    public:
        bool incluir(Sala *sala) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Sala *sala) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};

#endif // CONTROLES_SERVICO_H
