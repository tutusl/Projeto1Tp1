#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "ControlesApresentacao.h"
#include "ControlesServico.h"

using namespace std;



int main()
{
    CntrApresentacaoControle *CAC;
    IApresentacaoAutenticacao *CAA;
    IApresentacaoParticipante *CAP;
    IApresentacaoPSS *CAPSS;

    IServicoAutenticacao *CSA;
    IServicoParticipante *CSPA;
    IServicoPeca *CSPE;
    IServicoSessao *CSSE;
    IServicoSala *CSSA;

    CAC = new CntrApresentacaoControle();
    CAA = new CntrApresentacaoAutenticacao();
    CAP = new CntrApresentacaoParticipante();
    CAPSS = new CntrApresentacaoPSS();

    CSA = new CntrServicoAutenticacao();
    CSPA = new CntrServicoParticipante();
    CSPE = new CntrServicoPeca();
    CSSE = new CntrServicoSessao();
    CSSA = new CntrServicoSala();

    CAC->setCntrApresentacaoAutenticacao(CAA);
    CAC->setCntrApresentacaoParticipante(CAP);
    CAC->setCntrApresentacaoPSS(CAPSS);

    CAA->setCntrServicoAutenticacao(CSA);
    CAP->setCntrServicoParticipante(CSPA);
    CAPSS->setCntrServicoPeca(CSPE);
    CAPSS->setCntrServicoSessao(CSSE);
    CAPSS->setCntrServicoSala(CSSA);

    CAC->executar();

    return 0;
}


