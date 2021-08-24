#include <stdexcept>
#include "Dominios.h"

using namespace std;

const regex Capacidade::FORMATO {"[1-5]00"};
const regex Codigo::FORMATO {"[A-Z]{2}[0-9]{4}"};
const regex Horario::FORMATO {"([0-1][0-9]|2[0-3]):(00|15|30|45)"};
const regex Matricula::FORMATO {"[0-9]{5}"};
const regex Data::FORMATO {"(0[1-9]|[1-2][0-9]|3[0-1])\\/(0[1-9]|1[0-2])\\/([2-9][0-9]{3})"};
const regex Email::FORMATO {"[A-Za-z0-9!#$%&'*+\\-\\/=?^_`{|}~.]{1,64}[@][A-Za-z0-9!#$%&'*+\\-\\/=?^_`{|}~.]{1,255}"};
const regex Nome::FORMATO {"([A-Z]\\.?([A-Za-z]+\\.?|[A-Za-z]*)\\s?)+"};
const regex Senha::FORMATO {"(?=.*\\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[!@#$%&?])([^\\s]){8}"};
const regex Telefone::FORMATO {"\\(([14689][1-9]|2[12478]|3[2-578]|5[13-5]|7[13-579])\\)\\-(?!0{9})[\\d]{9}"};


void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Capacidade::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Capacidade invalida");
}

void Cargo::validar(string valor){
    if(!(valor == "ator" || valor == "figurinista" || valor == "cenografo"
    || valor == "maquiador" || valor == "sonoplasta" || valor == "iluminador"))
        throw invalid_argument("Cargo invalido (O cargo deve ser digitado sem acentos e em minusculo)");
}

void Classificacao::validar(string valor){
    if(!(valor == "livre" || valor == "10" || valor == "12" || valor == "14" || valor == "16" || valor == "18"))
        throw invalid_argument("A classificacao inserida nao faz parte das classificacoes indicadas");
}

void Codigo::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Codigo invalido");
}

void Data::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Data invalida.");

    constexpr int MESES_C_30_DIAS[4] = {4, 6, 9, 11};
    bool valida = true;
    int dia, mes, ano;
    dia = stoi(valor.substr(0, 2));
    mes = stoi(valor.substr(3, 2));
    ano = stoi(valor.substr(6, 4));
    bool ano_bissexto = (ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0);

    if (mes == 2 && (dia > 29 || (!ano_bissexto && dia == 29)))
        valida &= false;

    if (dia == 31){
        switch (mes){
            case MESES_C_30_DIAS[0]:
            case MESES_C_30_DIAS[1]:
            case MESES_C_30_DIAS[2]:
            case MESES_C_30_DIAS[3]:
                valida &= false;
                break;
            default:
                break;
        }
    }

    if (!valida)
        throw invalid_argument("Data invalida.");
}

void Email::validar(string valor){
    if(!regex_match(valor, FORMATO))
        throw invalid_argument("Formato invalido");

    const int TAMANHO_EMAIL = valor.length();
    int i;

    for(i = 0; i < TAMANHO_EMAIL - 1; i++){
        if(valor[i] == '.' && valor[i + 1] == '.')
            throw invalid_argument("Caractere '.' usado em sequencia");
    }

    char caractere;

    if ((valor[0] == '.')||(valor[TAMANHO_EMAIL - 1] == '.'))
        throw invalid_argument("Caractere '.' iniciando e-mail");

    i = 0;
    do{
        caractere = valor[i];
        i++;
    } while(caractere != '@');

    if(valor[i - 2] == '.' || valor[i] == '.')    //checa se o ponto estiver antes ou depois do arroba
        throw invalid_argument("Caractere '.' em posicao invalida");
}

void Horario::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Horario invalido");
}

void Matricula::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Somente sao validos digitos(0-9) no formato XXXXX");

    int i, j;

    for(i = 0; i < static_cast<int>(valor.length()) - 1; i++){
        for(j = i + 1; j < static_cast<int>(valor.length()); j++){
            if (valor[i] == valor[j])
                throw invalid_argument("Digito duplicado");
        }
    }
}

void Nome::validar(string valor)
{
    if (valor.size() < 5)
        throw length_error("Nome invalido (nome muito pequeno)");
    if (valor.size() > 20)
        throw length_error("Nome invalido (nome muito grande)");
    if (!regex_match(valor, FORMATO))
            throw invalid_argument("Nome invalido (formato nao suportado)");
}

void Senha::validar(string valor)
{
    bool charRepetido = false;

    for (int i=0; i < static_cast<int>(valor.size()); i++)
    {
        for (int j=0; j < static_cast<int>(valor.size())-i-1; j++)
        {
            if (valor[i] == valor[i+j+1])
                charRepetido = true;
        }
    }

    if (!(charRepetido == false && regex_match(valor, FORMATO)))
        throw invalid_argument("Senha invalida");
}

void Telefone::validar(string valor)
{
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Numero de telefone invalido");
}

void Tipo::validar(string valor){
    if(!(valor == "auto" || valor == "comedia" || valor == "drama" || valor == "farsa"
    || valor == "melodrama" || valor == "monologo" || valor == "musical" || valor == "opera"
    || valor == "revista" ))
        throw invalid_argument("Tipo invalido (O tipo deve ser digitado sem acentos e em minusculo)");
}