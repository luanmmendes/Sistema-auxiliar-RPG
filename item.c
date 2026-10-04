#include "item.h"
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

Item *iniciarItem(int capacidadeMax)
{
    Item *itens = malloc(capacidadeMax * sizeof(itens));
    itens->ID = 0;
    itens->nome[0] = 'x';
    itens->categoria = 0;
    itens->equipado = 0;
    itens->espaçosGastos = 0;
    itens->bonusAtaque = 0;
    itens->bonusDefesa = 0;
    itens->bonusVida = 0;
    itens->bonusIniciativa = 0;
    itens->poder = 0;
}

Item cadastrarItem(Item *itens)
{
    int verificaOndeEquipado, verificaCategoria = 0;
    char texto[50];

    printf("ID:");
    scanf("%d", &itens->ID);
    if (itens->ID < 0)
    {
        printf("o ID deve ser um inteiro positivo valido!\n");
        while (itens->ID < 0)
        {
            scanf("%d", &itens->ID);
        }
    }
    limpaBuffer();
    printf("Nome:");
    fgets(texto, sizeof(texto), stdin);
    limpaBarra(texto);
    strcpy(itens->nome, texto);
    printf("Qual e a categoria do item? (Exemplo: ELMO)\n");
    fgets(texto, sizeof(texto), stdin);
    limpaBarra(texto);
    verificaCategoria = validaEnumItem(texto);
    if (verificaCategoria == -1)
    {
        while (verificaCategoria == -1)
        {
            printf("digite uma categoria valida! (USE CAIXA ALTA)");
            fgets(texto, sizeof(texto), stdin);
            limpaBarra(texto);
            verificaCategoria = validaEnumItem(texto);
        }
    }
    printf("Onde o item sera equipado? (Exemplo: CABECA)\n");
    fgets(texto, sizeof(texto), stdin);
    limpaBarra(texto);
    verificaOndeEquipado = validaEnumEquipadoEm(texto);
    if (verificaOndeEquipado == -1)
    {
        while (verificaOndeEquipado == -1)
        {
            printf("digite uma categoria valida! (USE CAIXA ALTA)");
            fgets(texto, sizeof(texto), stdin);
            limpaBarra(texto);
            verificaOndeEquipado = validaEnumEquipadoEm(texto);
        }
    }

    printf("Bonus de Vida: ");
    scanf("%d", &itens->bonusVida);
    while (itens->bonusVida < 0 || itens->bonusVida > 999) // verificar
    {
        printf("digite um HP valido!");
        scanf("%d", &itens->bonusVida);
    }

    printf("Bonus de Ataque: ");
    scanf("%d", &itens->bonusAtaque);
    while (itens->bonusAtaque < 0 || itens->bonusAtaque > 30)
    {
        printf("digite um valor valido!");
        scanf("%d", &itens->bonusAtaque);
    }
    printf("Bonus de Defesa: ");
    scanf("%d", &itens->bonusDefesa);
    while (itens->bonusDefesa < 1 || itens->bonusDefesa > 30)
    {
        printf("Digite um valor valido!");
        scanf("%d", &itens->bonusDefesa);
    }

    printf("Bonus de Iniciativa: ");
    scanf("%d", &itens->bonusIniciativa);
    while (itens->bonusIniciativa < -5 || itens->bonusIniciativa > 20)
    {
        printf("digite um valor valido");
        scanf("%d", &itens->bonusIniciativa);
    }
    printf("Poder: ");
    scanf("%d", &itens->poder);
    while (itens->poder < 0 || itens->poder > 100)
    {
        printf("digite um valor valido!");
        scanf("%d", &itens->poder);
    }
}