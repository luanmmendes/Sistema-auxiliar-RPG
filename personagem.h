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
    int Itens[CAPACIDADE_ITENS];
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



void verificaID(Personagem *p,int quantidade);
Personagem* iniciarPersonagem(int capacidadeMax);
Personagem cadastrarPersonagem(Personagem* personagem);
void alterarPersonagem(Personagem* personagem,int id,int quantidade);
void removerPersonagem(Personagem*p,int *quantidade,int id);
typedef struct gerenciamentoPersona
{
    Personagem* personagens;
    int capacidadeAtual;
}gerenciamentoPersona;



#endif