#include "inventario.h"
#include <stdio.h>

void inicializarInventario(Inventario *inv)
{
    if (inv != NULL)
    {
        inv->quantidade = 0;
    }
}

int calcularOcupacao(const Inventario *inv)
{
    if (inv == NULL) return 0;
    int soma = 0;
    for (int i = 0; i < inv->quantidade; i++)
    {
        soma += inv->itens[i].espacosGastos;
    }
    return soma;
}

int espacosLivres(const Inventario *inv)
{
    return ESPACOS_MAXIMOS_INVENTARIO - calcularOcupacao(inv);
}

int buscarItemInventario(const Inventario *inv, int id)
{
    if (inv == NULL) return -1;
    for (int i = 0; i < inv->quantidade; i++)
    {
        if (inv->itens[i].ID == id)
        {
            return i;
        }
    }
    return -1;
}

int adicionarItemInventario(Inventario *inv, Item item)
{
    if (inv == NULL) return -1;

    if (inv->quantidade >= CAPACIDADE_INVENTARIO)
    {
        printf("Inventario com capacidade maxima de itens atingida!\n");
        return -2;
    }

    if (buscarItemInventario(inv, item.ID) != -1)
    {
        printf("Ja existe um item com o ID %d no inventario!\n", item.ID);
        return -3;
    }

    int ocupacaoAtual = calcularOcupacao(inv);
    if (ocupacaoAtual + item.espacosGastos > ESPACOS_MAXIMOS_INVENTARIO)
    {
        printf("Espaco insuficiente no inventario! Ocupacao atual: %d/50, Item exige: %d\n",
               ocupacaoAtual, item.espacosGastos);
        return -4;
    }

    inv->itens[inv->quantidade] = item;
    inv->quantidade++;
    printf("Item '%s' adicionado ao inventario com sucesso!\n", item.nome);
    return 0;
}

int removerItemInventario(Inventario *inv, int id, Item *removido)
{
    if (inv == NULL) return -1;

    int pos = buscarItemInventario(inv, id);
    if (pos == -1)
    {
        printf("Item com ID %d nao encontrado no inventario!\n", id);
        return -1;
    }

    if (removido != NULL)
    {
        *removido = inv->itens[pos];
    }

    for (int i = pos; i < inv->quantidade - 1; i++)
    {
        inv->itens[i] = inv->itens[i + 1];
    }
    inv->quantidade--;
    printf("Item removido do inventario com sucesso!\n");
    return 0;
}

void listarInventario(const Inventario *inv)
{
    if (inv == NULL) return;

    int ocupados = calcularOcupacao(inv);
    int livres = espacosLivres(inv);

    printf("\n============= ITENS NO INVENTARIO (%d itens) =============\n", inv->quantidade);
    printf("Espacos ocupados: %d/50 | Espacos livres: %d/50\n", ocupados, livres);

    if (inv->quantidade == 0)
    {
        printf("O inventario esta vazio.\n");
        printf("===========================================================\n");
        return;
    }

    for (int i = 0; i < inv->quantidade; i++)
    {
        printf("[%d] ID: %d | Nome: %s | Espacos: %d | Atq: %+d | Def: %+d | Vida: %+d | Ini: %+d | Poder: %d\n",
               i + 1,
               inv->itens[i].ID,
               inv->itens[i].nome,
               inv->itens[i].espacosGastos,
               inv->itens[i].bonusAtaque,
               inv->itens[i].bonusDefesa,
               inv->itens[i].bonusVida,
               inv->itens[i].bonusIniciativa,
               inv->itens[i].poder);
    }
    printf("===========================================================\n");
}
