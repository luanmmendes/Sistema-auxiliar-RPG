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

#include "inventario.h"
#include "item.h"

#define QTD_SLOTS_EQUIPAMENTO 9

typedef struct Equipamentos
{
    Item itens[QTD_SLOTS_EQUIPAMENTO];
    int ocupado[QTD_SLOTS_EQUIPAMENTO];
    int armaDuasMaosEquipada;
} Equipamentos;

typedef struct Personagem
{  
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
    Inventario inventario;
    Equipamentos equipamentos;

}Personagem;

int verificaID(Personagem *p,int quantidade,int id);
Personagem* iniciarPersonagem(int capacidadeMax);
Personagem cadastrarPersonagem(Personagem* personagem);
void alterarPersonagem(Personagem* personagem,int id,int quantidade);
void removerPersonagem(Personagem*p,int *quantidade,int id);

void inicializarEquipamentos(Equipamentos *eq);
int itemIDEmUso(Personagem *p, int id);
int slotCompativel(enum tipoItem categoria, int slot);
int equiparItem(Personagem *p, int idItem, int slot);
int desequiparItem(Personagem *p, int slot);
int calcularAtaqueTotal(const Personagem *p);
int calcularDefesaTotal(const Personagem *p);
int calcularIniciativaTotal(const Personagem *p);
int calcularHPTotal(const Personagem *p);
int calcularPoderTotal(const Personagem *p);
const char* nomeSlotEquipado(int slot);

typedef struct gerenciamentoPersona
{
    Personagem* personagens;
    int capacidadeAtual;
}gerenciamentoPersona;

#endif