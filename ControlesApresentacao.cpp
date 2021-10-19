#include <string>
#include <iostream>
#include <stdexcept>
#include "ControlesApresentacao.h"

using namespace std;

// Menu Principal
void CntrApresentacaoControle::executar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar usuario.";
    string texto4 = "3 - Acessar dados sobre peca, sessao ou sala.";
    string texto5 = "4 - Encerrar execucao do sistema.";

    string texto6 = "Selecione um dos servicos : ";
    string texto7 = "1 - Selecionar servicos de participante.";
    string texto8 = "2 - Selecionar servicos relacionados a peca, sessao ou sala.";
    string texto9 = "3 - Encerrar sessao.";

    string texto10 = "Falha na autenticacao. Aperte enter para continuar.";

    string texto11 ="Sucesso no cadastramento. Digite algo.";
    string texto12 ="Falha no cadastramento. Digite algo.";

    int op;
    bool apresentar1 = true;

    while(apresentar1){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;

        switch(op){
            case 1:
                if(cntrApresentacaoAutenticacao->autenticar(&matricula)){
                    bool apresentar2 = true;
                    while(apresentar2){
                        CLR;
                        cout << texto6 << endl;
                        cout << texto7 << endl;
                        cout << texto8 << endl;
                        cout << texto9 << endl;

                        cin >> op;

                        switch(op){
                            case 1:
                                cntrApresentacaoParticipante->executar(&matricula);
                                break;
                            case 2:
                                cntrApresentacaoPSS->executar(&matricula);
                                break;
                            case 3:
                                apresentar2 = false;
                                break;
                        }
                    }
                }
                else{
                    CLR;
                    cout << texto10 << endl;
                    cin.ignore();
                }
                break;
            case 2:
                if (cntrApresentacaoParticipante->cadastrar()){
                    cout << texto11 << endl;
                    cin.ignore();
                    cin.ignore();
                }
                else{
                    cout << texto12 << endl;
                    cin.ignore();
                    cin.ignore();
                }
                break;
            case 3:
                cntrApresentacaoPSS->executar();
                break;
            case 4:
                apresentar1 = false;
                break;
        }
    }
    return;
}


//
//  Autenticação
//


bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){
    string texto1 = "Digite a matricula: ";
    string texto2 = "Digite a senha: ";
    string texto3 = "Dado em formato incorreto. Aperte enter.";

    string dado1;
    string dado2;

    Senha senha;

    while(true){
        CLR;
        cout << texto1 << " ";
        cin >> dado1;
        cout << texto2;
        cin >> dado2;
        try{
            matricula->setValor(dado1);
            senha.setValor(dado2);
            break;
        }
        catch(invalid_argument &exp){
            CLR;
            cout << texto3 << endl;
            cin.ignore();
            cin.ignore();
            return false;
        }
    }
    return (cntr->autenticar(matricula, &senha));
}

//
//  Participante
//


bool CntrApresentacaoParticipante::cadastrar(){
    string texto1 ="Preencha os seguintes campos:";
    string texto2 ="Matricula       : ";
    string texto3 ="Email           : ";
    string texto4 ="Nome            : ";
    string texto5 ="Sobrenome       : ";
    string texto6 ="Senha           : ";
    string texto7 ="Telefone        : ";
    string texto8 ="Cargo           : ";
    string texto9 ="Dados em formato incorreto. Digite algo.";


    string dado1, dado2, dado3, dado4, dado5, dado6, dado7;

    Participante participante;
    Matricula matricula;
    Email email;
    Nome nome;
    Nome sobrenome;
    Senha senha;
    Telefone telefone;
    Cargo cargo;

    CLR;

    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;
    cout << texto5;
    cin >> dado4;
    cout << texto6;
    cin >> dado5;
    cout << texto7;
    cin >> dado6;
    cout << texto8;
    cin >> dado7;

    //  Talvez precise de cin.ignore()

    try{
        matricula.setValor(dado1);
        email.setValor(dado2);
        nome.setValor(dado3);
        sobrenome.setValor(dado4);
        senha.setValor(dado5);
        telefone.setValor(dado6);
        cargo.setValor(dado7);
    }
    catch(invalid_argument &exp){
        cout << texto9 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    participante.setMatricula(matricula);
    participante.setEmail(email);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setSenha(senha);
    participante.setTelefone(telefone);
    participante.setCargo(cargo);

    return (cntr->cadastrar(&participante));

}


void CntrApresentacaoParticipante::executar(Matricula *matricula){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Descadastrar usuario.";
    string texto3 = "2 - Alterar dados.";
    string texto4 = "3 - Cadastrar em peca.";
    string texto5 = "4 - Voltar ao inicio.";

    string texto6 = "Usuario descadastrado com sucesso.";
    string texto7 = "Falha em descadastrar o usuario.";
    string texto8 = "Usuario alterado com sucesso";
    string texto9 = "Falha em alterar o usuario.";
    string texto10 = "Codigo da peca: ";
    string texto11 = "Cadastrado em peca com sucesso";
    string texto12 = "Falha em cadastrar em peca";

    int op;
    bool apresentar = true;

    while(apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        string peca;
        cin >> op;

        switch(op){
            case 1:
                if(cntr->descadastrar(matricula))
                    cout << texto6 << endl;
                else
                    cout << texto7 << endl;
                cin.ignore();
                cin.ignore();
                apresentar = false;
                break;
            case 2:
                if(editar(matricula))
                    cout << texto8 << endl;
                else
                    cout << texto9 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                CLR;

                cout << texto10;
                cin >> peca;

                if(cntr->cadastrarEmPeca(matricula, peca))
                    cout << texto11 << endl;
                else
                    cout << texto12 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
    return;
}

bool CntrApresentacaoParticipante::editar(Matricula *matricula){
    string texto1 ="Preencha os seguintes campos:";
    string texto2 ="Email           : ";
    string texto3 ="Nome            : ";
    string texto4 ="Sobrenome       : ";
    string texto5 ="Senha           : ";
    string texto6 ="Telefone        : ";
    string texto7 ="Cargo           : ";
    string texto8 ="Dados em formato incorreto. Digite algo.";

    string dado1, dado2, dado3, dado4, dado5, dado6;

    Participante participante;
    Email email;
    Nome nome;
    Nome sobrenome;
    Senha senha;
    Telefone telefone;
    Cargo cargo;

    CLR;

    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;
    cout << texto5;
    cin >> dado4;
    cout << texto6;
    cin >> dado5;
    cout << texto7;
    cin >> dado6;


    try{
        email.setValor(dado1);
        nome.setValor(dado2);
        sobrenome.setValor(dado3);
        senha.setValor(dado4);
        telefone.setValor(dado5);
        cargo.setValor(dado6);
    }
    catch(invalid_argument &exp){
        cout << texto8 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    participante.setMatricula(*matricula);
    participante.setEmail(email);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setSenha(senha);
    participante.setTelefone(telefone);
    participante.setCargo(cargo);

    return (cntr->alterar(&participante));
}

//
//  PSS
//

void CntrApresentacaoPSS::executar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Listar pecas.";
    string texto3 = "2 - Listar sessoes.";
    string texto4 = "3 - Listar salas.";
    string texto5 = "4 - Voltar.";

    int op;
    bool apresentar = true;

    while(apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;

        switch(op){
            case 1:
                cout << cntrPeca->listar() << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                cout << cntrSessao->listar() << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                cout << cntrSala->listar() << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}

bool CntrApresentacaoPSS::editarPeca(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Nome           : ";
    string texto3 = "Tipo           : ";
    string texto4 = "Classificação  : ";
    string texto5 = "Dados em formato incorreto. Digite algo.";
    string texto6 = "Identifique o codigo da peca que deseja mudar: ";

    string dado1, dado2, dado3, dado4;

    Peca peca;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
    Codigo codigo;

    CLR;

    cout << texto6 << endl;
    cin >> dado4;
    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;

    try{
        nome.setValor(dado1);
        tipo.setValor(dado2);
        classificacao.setValor(dado3);
        codigo.setValor(dado4);
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);
    peca.setIdentificador(codigo);

    return (cntrPeca->editar(&peca));

}

bool CntrApresentacaoPSS::editarSessao(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Data           : ";
    string texto3 = "Hora           : ";
    string texto4 = "Dados em formato incorreto. Aperte Enter.";
    string texto5 = "Identifique o codigo da sessao que deseja mudar: ";

    string dado1, dado2, dado3;

    Sessao sessao;
    Data data;
    Horario hora;
    Codigo codigo;

    CLR;

    cout<< texto5 << endl;
    cin >> dado3;
    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;


    try{
        data.setValor(dado1);
        hora.setValor(dado2);
        codigo.setValor(dado3);
    }
    catch(invalid_argument &exp){
        cout << texto4 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    sessao.setData(data);
    sessao.setHorario(hora);
    sessao.setIdentificador(codigo);

    return (cntrSessao->editar(&sessao));

}

bool CntrApresentacaoPSS::editarSala(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Nome          : ";
    string texto3 = "Capacidade    : ";
    string texto4 = "Dados em formato incorreto. Digite algo.";
    string texto5 = "Identifique o codigo da sala que deseja mudar: ";

    string dado1, dado2, dado3;

    Sala sala;
    Nome nome;
    Capacidade capacidade;
    Codigo codigo;

    CLR;

    cout<< texto5 << endl;
    cin >> dado3;
    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;


    try{
        nome.setValor(dado1);
        capacidade.setValor(dado2);
        codigo.setValor(dado3);
    }
    catch(invalid_argument &exp){
        cout << texto4 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    sala.setNome(nome);
    sala.setCapacidade(capacidade);
    sala.setIdentificador(codigo);

    return cntrSala->editar(&sala);

}

void CntrApresentacaoPSS::editar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Editar peca";
    string texto3 = "2 - Editar sessao";
    string texto4 = "3 - Editar sala";
    string texto5 = "4 - Voltar.";
    string texto6 = "Peca editada com sucesso.";
    string texto7 = "Sessao editada com sucesso.";
    string texto8 = "Sala editada com sucesso.";
    string texto9 = "Falha em editar peca.";
    string texto10 = "Falha em editar sessao.";
    string texto11 = "Falha em editar sala.";


    string codigo;
    int op;
    bool apresentar = true;

    while (apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;
        switch(op){
            case 1:
                if(editarPeca())
                    cout << texto6 << endl;
                else
                    cout << texto9 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                if(editarSessao())
                    cout << texto7 << endl;
                else
                    cout << texto10 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                if(editarSala())
                    cout << texto8 << endl;
                else
                    cout << texto11 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }

}

bool CntrApresentacaoPSS::incluirPeca(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto6 = "Codigo       : ";
    string texto2 = "Nome         : ";
    string texto3 = "Tipo         : ";
    string texto4 = "Classificacao: ";
    string texto5 = "Dados em formato incorreto. Digite algo.";

    string dado1, dado2, dado3, dado4;

    Peca peca;
    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    CLR;

    cout << texto1 << endl;
    cout << texto6;
    cin >> dado4;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;

    try{
        codigo.setValor(dado4);
        nome.setValor(dado1);
        tipo.setValor(dado2);
        classificacao.setValor(dado3);
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    peca.setIdentificador(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    return (cntrPeca->incluir(&peca));
}

bool CntrApresentacaoPSS::incluirSessao(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto7 = "Codigo       : ";
    string texto2 = "Data         : ";
    string texto3 = "Hora         : ";
    string texto4 = "Dados em formato incorreto. Digite algo.";
    string texto5 = "Codigo da peca associada: ";
    string texto6 = "Codigo da sala associada: ";

    string dado1, dado2, dado3, peca, sala;

    Sessao sessao;
    Codigo codigo;
    Data data;
    Horario hora;

    CLR;

    cout << texto1 << endl;
    cout << texto7;
    cin >> dado3;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto5;
    cin >> peca;
    cout << texto6;
    cin >> sala;


    try{
        codigo.setValor(dado3);
        data.setValor(dado1);
        hora.setValor(dado2);
    }
    catch(invalid_argument &exp){
        cout << texto4 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    sessao.setIdentificador(codigo);
    sessao.setData(data);
    sessao.setHorario(hora);


    return (cntrSessao->incluir(&sessao, peca, sala));
}

bool CntrApresentacaoPSS::incluirSala(){
    string texto1 = "Preencha os seguintes campos: ";
    string texto5 = "Codigo       : ";
    string texto2 = "Nome         : ";
    string texto3 = "Capacidade   : ";
    string texto4 = "Dados em formato incorreto. Digite algo.";

    string dado1, dado2, dado3;

    Sala sala;
    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    CLR;

    cout << texto1 << endl;
    cout << texto5;
    cin >> dado3;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;


    try{
        codigo.setValor(dado3);
        nome.setValor(dado1);
        capacidade.setValor(dado2);
    }
    catch(invalid_argument &exp){
        cout << texto4 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    sala.setIdentificador(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);


    return (cntrSala->incluir(&sala));

}

void CntrApresentacaoPSS::incluir(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Incluir peca";
    string texto3 = "2 - Incluir sessao";
    string texto4 = "3 - Incluir sala";
    string texto5 = "4 - Voltar.";
    string texto6 = "Peca incluida com sucesso.";
    string texto7 = "Sessao incluida com sucesso.";
    string texto8 = "Sala incluida com sucesso.";
    string texto9 = "Falha em incluir peca.";
    string texto10 = "Falha em incluir sessao.";
    string texto11 = "Falha em incluir sala.";

    int op;
    bool apresentar = true;

    while (apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;
        switch(op){
            case 1:
                if(incluirPeca())
                    cout << texto6 << endl;
                else
                    cout << texto9 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                if(incluirSessao())
                    cout << texto7 << endl;
                else
                    cout << texto10 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                if(incluirSala())
                    cout << texto8 << endl;
                else
                    cout << texto11 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }

}


void CntrApresentacaoPSS::excluir(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Excluir peca";
    string texto3 = "2 - Excluir sessao";
    string texto4 = "3 - Excluir sala";
    string texto5 = "4 - Voltar.";
    string texto6 = "Digite o código da peca que deseja excluir: ";
    string texto7 = "Digite o código da sessao que deseja excluir: ";
    string texto8 = "Digite o código da sala que deseja excluir: ";
    string texto9 = "Peca excluida com sucesso.";
    string texto10 = "Sessao excluida com sucesso.";
    string texto11 = "Sala excluida com sucesso.";
    string texto12 = "Falha em excluir peca.";
    string texto13 = "Falha em excluir sessao.";
    string texto14 = "Falha em excluir sala.";

    string cod;
    Codigo codigo;
    int op;
    bool apresentar = true;

    while (apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;
        switch(op){
            case 1:
                cout << texto6 << endl;
                cin >> cod;
                codigo.setValor(cod);
                if(cntrPeca->excluir(&codigo))
                    cout << texto9 << endl;
                else
                    cout << texto12 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                cout << texto7 << endl;
                cin >> cod;
                codigo.setValor(cod);
                if(cntrSessao->excluir(&codigo))
                    cout << texto10 << endl;
                else
                    cout << texto13 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                cout << texto8 << endl;
                cin >> cod;
                codigo.setValor(cod);
                if(cntrSala->excluir(&codigo))
                    cout << texto11 << endl;
                else
                    cout << texto14 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoPSS::visualizar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar peca";
    string texto3 = "2 - Visualizar sessao";
    string texto4 = "3 - Visualizar sala";
    string texto5 = "4 - Voltar.";
    string texto6 = "Digite o código da peca que deseja visualizar: ";
    string texto7 = "Digite o código da sessao que deseja visualizar: ";
    string texto8 = "Digite o código da sala que deseja visualizar: ";

    string cod;
    Codigo codigo;
    int op;
    bool apresentar = true;

    while(apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cin >> op;
        switch(op){
            case 1:
                cout << texto6 << endl;
                cin >> cod;
                codigo.setValor(cod);
                cout << cntrPeca->visualizar(&codigo) << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                cout << texto7 << endl;
                cin >> cod;
                codigo.setValor(cod);
                cout << cntrSessao->visualizar(&codigo) << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                cout << texto8 << endl;
                cin >> cod;
                codigo.setValor(cod);
                cout << cntrSala->visualizar(&codigo) << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoPSS::executar(Matricula *matricula){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Incluir peca, sessao ou sala.";
    string texto3 = "2 - Excluir peca, sessao ou sala.";
    string texto4 = "3 - Editar peca, sessao ou sala.";
    string texto5 = "4 - Visualizar peca, sessao ou sala.";
    string texto6 = "5 - Listar pecas, sessoes ou salas.";
    string texto7 = "6 - Voltar.";

    int op;
    bool apresentar = true;

    while(apresentar){
        CLR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        cin >> op;

        switch(op){
            case 1:
                incluir();
                cin.ignore();
                break;
            case 2:
                excluir();
                cin.ignore();
                break;
            case 3:
                editar();
                cin.ignore();
                break;
            case 4:
                visualizar();
                cin.ignore();
                break;
            case 5:
                executar();
                cin.ignore();
                break;
            case 6:
                apresentar = false;
                break;
        }
    }

}
