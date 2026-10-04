#ifndef ITEM_H
#define ITEM_H

enum tipoItem{
    ELMO,
    PEITORAL, 
    MANOPLAS ,
    CALCA, 
    BOTAS, 
    ANEL, 
    COLAR,
    CINTO,
    ARMA_UMA_MAO,
    ARMA_DUAS_MAOS
};
enum equipadoEm{
    CABECA,
    PEITO,
    BRACOS,
    PERNAS, 
    PES,
    MAO_DIREITA,
    MAO_ESQUERDA,
    ACESSORIO1,
    ACESSORIO2,
};

typedef struct Item
{
    int ID;
    char nome[50];
    enum tipoItem categoria;
    enum equipadoEm equipado;
    int espaçosGastos;
    int bonusAtaque;
    int bonusDefesa;
    int bonusVida;
    int bonusIniciativa;
    int poder;


}Item;
Item* iniciarItem(int capacidadeMax);
Item cadastrarItem(Item *itens);


#endif