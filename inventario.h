#ifndef INVENTARIO_H
#define INVENTARIO_H


typedef struct
{
    int ID;
    char nome[50];
    int espacos[50];
    int bonusAtaque;
    int bonusDefesa;
    int bonusVida;
    int bonusIniciativa;
    int poder;

}inventario;


#endif
