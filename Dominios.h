#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


///
/// Classe base para todos os domínios.
///
///
///

class Dominio {
    //200023314
    private:
        string valor;
        virtual void validar(string valor) = 0;

    public:

///
/// Destrutor virtual para evitar comportamento indefinido.
///

        virtual ~Dominio(){};

///
/// Armazena valor.
/// @param valor Valor do domínio representado em string.
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna valor.
/// @return valor
///
///

        string getValor();

};


inline string Dominio::getValor(){
    return valor;
}


///
/// Classe para representar capacidade.
/// Regras de formato:
/// - Capacidade é válida se for igual a 100, 200, 300, 400 ou 500.
///

class Capacidade: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
//        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
        void validar(string valor) override;
};


///
/// Classe para representar cargo.
/// Regras de formato:
/// - Cargo é válido se for igual a ator, cenógrafo, figurinista, maquiador, sonoplasta ou iluminador.
///

class Cargo: public Dominio {
    //190046546
    private:
        void validar(string valor);
};

///
/// Classe para representar classificação.
/// Regras de formato:
/// - Classificação é válida se for igual a livre, 10, 12, 14, 16 ou 18.
///

class Classificacao: public Dominio {
    //190046546
    private:
        void validar(string valor) override;
};

///
/// Classe para representar código.
/// Regras de formato:
/// - Código é válido se for igual a LLDDDD.
/// - L é letra maiúscula.
/// - D é dígito.
///

class Codigo: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar data.
/// Regras de formato:
/// - Data é válida se for igual a DD/MM/AAAA.
/// - DD de 01 a 31.
/// - MM de 01 a 12.
/// - AAAA de 2000 a 9999.
/// - Leva em consideração anos bissextos.
///

class Data: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


///
/// Classe para representar email.
/// Regras de formato:
/// - Email é válido se for igual a parte-local@domínio.
/// - parte-local é composta por até 64 caracteres.
/// - domínio é composto por até 255 caracteres.
/// - Caractere pode ser letra maiúscula, letra minúscula, dígito, um dos caracteres: ! # $ % & ' * + - / = ? ^ _ ` { | } ~ ou ponto.
/// - Ponto não pode ser o primeiro ou último caractere, e não pode ocorrer em sequência.
///

class Email: public Dominio {
    //190046546
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar horário.
/// Regras de formato:
/// - Horário é válido se for igual a HH:MM.
/// - HH de 00 a 23.
/// - MM é 00, 15, 30 ou 45.
///

class Horario: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Matrícula.
/// Regras de formato:
/// - Matrícula é válida se for igual a XXXXX.
/// - X é dígito.
/// - Não podem existir dígitos duplicados.
///

class Matricula: public Dominio {
    // 190046546
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Nome.
/// Regras de formato:
/// - Nome é válido se for de 5 a 20 caracteres.
/// - Cada caractere é letra, ponto ou espaço em branco.
/// - Ponto é precedido por letra.
/// - Não há espaços em branco em sequência.
/// - Primeira letra de cada termo é letra maiúscula.
///

class Nome: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Senha.
/// Regras de formato:
/// - Senha é válida se for igual a XXXXXXXX.
/// - X é letra, dígito ou um dos caracteres especiais ! @ # $ % & ?.
/// - Não pode existir caractere repetido.
/// - Existe pelo menos uma letra (maiúscula ou minúscula), um dígito e um caractere especial.
///

class Senha: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Telefone.
/// Regras de formato:
/// - Telefone é válido se for igual a (XX)-YYYYYYYYY.
/// - XX é um dos seguintes códigos 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 
/// 34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 
/// 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99.
/// - Cada Y é dígito (0-9)
/// - Não existe número de telefone 000000000.
///

class Telefone: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Tipo.
/// Regras de formato:
/// - Tipo é válido se for igual a auto, comédia, drama, farsa, melodrama, monólogo, musical, ópera, revista.

class Tipo: public Dominio {
    //180030353
    private:
        void validar(string valor) override;
};

#endif // DOMINIOS_H
