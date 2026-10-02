#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#define CAPACIDADE_ITENS 50
#include <string.h>

enum Raca{
    HUMANO,
    ELFO,
    ANAO,
    HALFLING

};
enum Classe {
    GUERREIRO,
    LADINO,
    MAGO,
    CLERIGO,  

};

typedef struct Personagem
{  
    int CapacidadeItens[CAPACIDADE_ITENS];
    int ID;
    char nome[50];    
    enum Raca raca;
    enum Classe classe;
    int Nivel;
    int HP;
    int HPatual;
    int Ataque;
    int Defesa;
    int Iniciativa;
    int Poder;

}Personagem;



void validaEnum();
void verificaID(Personagem *p);
Personagem* iniciarPersonagem();
Personagem cadastrarPersonagem(Personagem* personagem);
int adicionarLista(Personagem* p, int* capacidadeAtual);

typedef struct gerenciamentoPersona
{
    Personagem* personagens;
    int capacidadeAtual;
}gerenciamentoPersona;



#endif