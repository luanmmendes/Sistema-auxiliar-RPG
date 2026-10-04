#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"

#define CAPACIDADE_INVENTARIO 50
#define ESPACOS_MAXIMOS_INVENTARIO 50

typedef struct Inventario
{
    Item itens[CAPACIDADE_INVENTARIO];
    int quantidade;
} Inventario;

void inicializarInventario(Inventario *inv);
int calcularOcupacao(const Inventario *inv);
int espacosLivres(const Inventario *inv);
int buscarItemInventario(const Inventario *inv, int id);
int adicionarItemInventario(Inventario *inv, Item item);
int removerItemInventario(Inventario *inv, int id, Item *removido);
void listarInventario(const Inventario *inv);

#endif

