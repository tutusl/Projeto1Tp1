#include "Testes.h"
#include <iostream>


TUCapacidade::TUCapacidade()
    : TUD ("100", "50")
{}


TUCargo::TUCargo()
    : TUD ("ator", "Ator")
{}


TUClassificacao::TUClassificacao()
    : TUD ("livre", "fechado")
{}



TUCodigo::TUCodigo()
    : TUD ("AB1234", "aba12sd1")
{}



TUData::TUData()
    : TUD ("23/02/2001", "50/32/1999")
{}



TUEmail::TUEmail()
    : TUD ("email.Valido@unb.br", "email....invalido")
{}



TUHorario::TUHorario()
    : TUD ("22:00", "50:13")
{}



TUMatricula::TUMatricula()
    : TUD ("12345", "50210")
{}



TUNome::TUNome()
    : TUD ("Nominaldo S. Naldo", "..  Nomeaol")
{}



TUSenha::TUSenha()
    : TUD ("Senha@78", "senhaaaaa")
{}



TUTelefone::TUTelefone()
    : TUD ("(61)-123456789", "(10)-000000000")
{}


TUTipo::TUTipo()
    : TUD ("auto", "alto")
{}



const string TUParticipante::VALORES_VALIDOS[] {"12345", "Denilson", "Felix"
    , "deni.felix@gmail.com", "(61)-123456789", "Senha@78", "sonoplasta"};
const string TUPeca::VALORES_VALIDOS[] {"CD5678", "Hamlet", "drama", "14"};
const string TUSessao::VALORES_VALIDOS[] {"EF8765", "23/02/2001", "22:00"};
const string TUSala::VALORES_VALIDOS[] {"GH4321", "Pavilhao J", "100"};


void TUParticipante::testarCenarioSucesso(){
    Matricula matricula;
    matricula.setValor((VALORES_VALIDOS[0]));
    unidade->setMatricula(matricula);
    if (unidade->getMatricula().getValor() != VALORES_VALIDOS[0])
        estado = FALHA;

    Nome nome;
    nome.setValor((VALORES_VALIDOS[1]));
    unidade->setNome(nome);
    if (unidade->getNome().getValor() != VALORES_VALIDOS[1])
        estado = FALHA;

    Nome sobrenome;
    sobrenome.setValor((VALORES_VALIDOS[2]));
    unidade->setSobrenome(sobrenome);
    if (unidade->getSobrenome().getValor() != VALORES_VALIDOS[2])
        estado = FALHA;

    Email email;
    email.setValor((VALORES_VALIDOS[3]));
    unidade->setEmail(email);
    if (unidade->getEmail().getValor() != VALORES_VALIDOS[3])
        estado = FALHA;

    Telefone telefone;
    telefone.setValor((VALORES_VALIDOS[4]));
    unidade->setTelefone(telefone);
    if (unidade->getTelefone().getValor() != VALORES_VALIDOS[4])
        estado = FALHA;

    Senha senha;
    senha.setValor((VALORES_VALIDOS[5]));
    unidade->setSenha(senha);
    if (unidade->getSenha().getValor() != VALORES_VALIDOS[5])
        estado = FALHA;

    Cargo cargo;
    cargo.setValor((VALORES_VALIDOS[6]));
    unidade->setCargo(cargo);
    if (unidade->getCargo().getValor() != VALORES_VALIDOS[6])
        estado = FALHA;
}

void TUPeca::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALORES_VALIDOS[0]);
    unidade->setIdentificador(codigo);
    if (unidade->getIdentificador().getValor() != VALORES_VALIDOS[0])
        estado = FALHA;

    Nome nome;
    nome.setValor((VALORES_VALIDOS[1]));
    unidade->setNome(nome);
    if (unidade->getNome().getValor() != VALORES_VALIDOS[1])
        estado = FALHA;

    Tipo tipo;
    tipo.setValor((VALORES_VALIDOS[2]));
    unidade->setTipo(tipo);
    if (unidade->getTipo().getValor() != VALORES_VALIDOS[2])
        estado = FALHA;
    
    Classificacao classificacao;
    classificacao.setValor((VALORES_VALIDOS[3]));
    unidade->setClassificacao(classificacao);
    if (unidade->getClassificacao().getValor() != VALORES_VALIDOS[3])
        estado = FALHA;
}



void TUSessao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALORES_VALIDOS[0]);
    unidade->setIdentificador(codigo);
    if (unidade->getIdentificador().getValor() != VALORES_VALIDOS[0])
        estado = FALHA;

    Data data;
    data.setValor((VALORES_VALIDOS[1]));
    unidade->setData(data);
    if (unidade->getData().getValor() != VALORES_VALIDOS[1])
        estado = FALHA;

    Horario horario;
    horario.setValor((VALORES_VALIDOS[2]));
    unidade->setHorario(horario);
    if (unidade->getHorario().getValor() != VALORES_VALIDOS[2])
        estado = FALHA;
}


void TUSala::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALORES_VALIDOS[0]);
    unidade->setIdentificador(codigo);
    if (unidade->getIdentificador().getValor() != VALORES_VALIDOS[0])
        estado = FALHA;

    Nome nome;
    nome.setValor((VALORES_VALIDOS[1]));
    unidade->setNome(nome);
    if (unidade->getNome().getValor() != VALORES_VALIDOS[1])
        estado = FALHA;

    Capacidade capacidade;
    capacidade.setValor((VALORES_VALIDOS[2]));
    unidade->setCapacidade(capacidade);
    if (unidade->getCapacidade().getValor() != VALORES_VALIDOS[2])
        estado = FALHA;
}


