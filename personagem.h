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

typedef struct gerenciamentoPersona
{
    Personagem* lista;
    Personagem* info;
    int capacidadeAtual;
}gerenciamentoPersona;


void validaEnum();
Personagem* iniciarPersonagem();
Personagem cadastrarPersonagem(Personagem* personagem);
gerenciamentoPersona* IniciarLista(int capacidadeAtual);
int adicionarLista(gerenciamentoPersona *lista , Personagem *p,int capacidadeAtual);





#endif