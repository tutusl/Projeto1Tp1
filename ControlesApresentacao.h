#ifndef CONTROLES_APRESENTACAO_H
#define CONTROLES_APRESENTACAO_H

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"

#ifdef _WIN32   // OS Windows
#define CLR system("CLS")
#elif __linux__  // OS Linux
#define CLR system("clear")
#endif

class CntrApresentacaoControle {
    private:
        Matricula matricula;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoParticipante *cntrApresentacaoParticipante;
        IApresentacaoPSS *cntrApresentacaoPSS;

    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {cntrApresentacaoAutenticacao = cntr;};
        void setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr) {cntrApresentacaoParticipante = cntr;};
        void setCntrApresentacaoPSS(IApresentacaoPSS *cntr) {cntrApresentacaoPSS = cntr;};
};



class CntrApresentacaoAutenticacao: public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao *cntr;

    public:
        bool autenticar(Matricula *matricula) override;
        void setCntrServicoAutenticacao(IServicoAutenticacao *cntr) override {this->cntr = cntr;};

};


class CntrApresentacaoParticipante: public IApresentacaoParticipante {
    private:
        IServicoParticipante *cntr;

    public:
        bool editar(Matricula *matricula);
        bool cadastrar() override;
        void executar(Matricula *matricula) override;
        void setCntrServicoParticipante(IServicoParticipante *cntr) override {this->cntr = cntr;};
};


class CntrApresentacaoPSS: public IApresentacaoPSS {
    private:
        void editar();
        bool editarPeca();
        bool editarSessao();
        bool editarSala();

        void incluir();
        bool incluirPeca();
        bool incluirSessao();
        bool incluirSala();

        void excluir();

        void visualizar();

        IServicoPeca *cntrPeca;
        IServicoSessao *cntrSessao;
        IServicoSala *cntrSala;

    public:
        void executar(Matricula *matricula) override;
        void executar() override;
        void setCntrServicoPeca(IServicoPeca *cntrPeca) override {this->cntrPeca = cntrPeca;};
        void setCntrServicoSessao(IServicoSessao *cntrSessao) override {this->cntrSessao = cntrSessao;};
        void setCntrServicoSala(IServicoSala *cntrSala) override {this->cntrSala = cntrSala;};
};


#endif // CONTROLES_APRESENTACAO_H
