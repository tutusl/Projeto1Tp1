#include "Testes.h"




TUCapacidade::TUCapacidade()
    : TU ("100", "50")
{}


TUCargo::TUCargo()
    : TU ("ator", "Ator")
{}


TUClassificacao::TUClassificacao()
    : TU ("livre", "fechado")
{}



TUCodigo::TUCodigo()
    : TU ("AB1234", "aba12sd1")
{}



TUData::TUData()
    : TU ("23/02/2001", "50/32/1999")
{}



TUEmail::TUEmail()
    : TU ("email.Valido@unb.br", "email....invalido")
{}



TUHorario::TUHorario()
    : TU ("22:00", "50:13")
{}



TUMatricula::TUMatricula()
    : TU ("12345", "50210")
{}



TUNome::TUNome()
    : TU ("Nominaldo S. Naldo", "..  Nomeaol")
{}



TUSenha::TUSenha()
    : TU ("Senha@78", "senhaaaaa")
{}



TUTelefone::TUTelefone()
    : TU ("(61)-123456789", "(10)-000000000")
{}


TUTipo::TUTipo()
    : TU ("auto", "alto")
{}
