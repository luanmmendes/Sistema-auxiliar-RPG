#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

Personagem *iniciarPersonagem(int capacidadeMax)
{
  Personagem *personagem = malloc(capacidadeMax * sizeof(*personagem));
  personagem->Itens[0] = CAPACIDADE_ITENS;
  personagem->ID = 0;
  personagem->nome[0] = 'x';
  personagem->raca = 0;
  personagem->classe = 0;
  personagem->Nivel = 1;
  personagem->HP = 999;
  personagem->HPatual = 999;
  personagem->Ataque = 15;
  personagem->Defesa = 15;
  personagem->Iniciativa = 15;
  personagem->Poder = 10;
  return personagem;
}

Personagem cadastrarPersonagem(Personagem *p)
{
  int verificaRaca, verificaClasse = 0;
  char texto[50];

  printf("ID:");
  scanf("%d", &p->ID);
  if (p->ID < 0)
  {
    printf("o ID deve ser um inteiro positivo valido!\n");
    while (p->ID < 0)
    {
      scanf("%d", &p->ID);
    }
  }
  limpaBuffer();
  printf("Nome:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  strcpy(p->nome, texto);
  printf("Raca:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  verificaRaca = validaEnumRaca(texto);
  if (verificaRaca == -1)
  {
    while (verificaRaca == -1)
    {
      printf("digite uma raca valida! (USE CAIXA ALTA)");
      fgets(texto, sizeof(texto), stdin);
      limpaBarra(texto);
      verificaRaca = validaEnumRaca(texto);
    }
  }
  printf("Classe:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  verificaClasse = validaEnumClasse(texto);
  if (verificaClasse == -1)
  {
    while (verificaClasse != 0) // QUEBRADO
    {
      printf("digite uma classe valida! (USE CAIXA ALTA)");
      fgets(texto, sizeof(texto), stdin);
      verificaRaca = validaEnumRaca(texto);
    }
  }
  printf("Nivel:");
  scanf("%d", &p->Nivel);
  while (p->Nivel > 20 || p->Nivel < 1)
  {
    printf("digite um nivel valido");
    scanf("%d", &p->Nivel);
  }
  printf("HP: ");
  scanf("%d", &p->HP);
  while (p->HP < 0 || p->HP > 999)
  {
    printf("digite um HP valido!");
    scanf("%d", &p->HP);
  }

  printf("HP Atual: ");
  scanf("%d", &p->HPatual);
  while (p->HPatual < 0 || p->HPatual > p->HP)
  {
    printf("Digite um HP atual valido!");
    scanf("%d", &p->HPatual);
  }
  printf("Ataque: ");
  scanf("%d", &p->Ataque);
  while (p->Ataque < 0 || p->Ataque > 30)
  {
    printf("digite um valor valido!");
    scanf("%d", &p->Ataque);
  }
  printf("Defesa ");
  scanf("%d", &p->Defesa);
  while (p->Defesa < 1 || p->Defesa > 30)
  {
    printf("Digite um valor valido!");
    scanf("%d", &p->Defesa);
  }

  printf("Iniciativa: ");
  scanf("%d", &p->Iniciativa);
  while (p->Iniciativa < -5 || p->Iniciativa > 20)
  {
    printf("digite um valor valido");
    scanf("%d", &p->Iniciativa);
  }
  printf("Poder: ");
  scanf("%d", &p->Poder);
  while (p->Poder < 0 || p->Poder > 100)
  {
    printf("digite um valor valido!");
    scanf("%d", &p->Poder);
  }
}

void alterarPersonagem(Personagem *p, int id, int quantidade)
{
  for (int i = 0; i < 20; i++)
  {
    if (p[i].ID == id)
    {
      cadastrarPersonagem(p);
      verificaID(p, quantidade);
    }
    else
    {
      printf("esse ID não existe!\n");
      break;
    }
  }
}

void removerPersonagem(Personagem *p, int *quantidade, int id)
{
  for (int i = 0; i < *quantidade; i++)
  {
    if (p[i].ID == id)
    {
      for (int j = i; j < *quantidade - 1; j++)
      {
        p[j] = p[j + 1];
      }
       (*quantidade)--;
        break;
    }
  }
}

  void verificaID(Personagem * p, int quantidade)
  {
    if (quantidade >= 1)
    {
      for (int i = 1; i < quantidade; i++)
      {
        if (p[quantidade].ID == p[quantidade - 1].ID)
        {
          while (p[quantidade].ID == p[quantidade - 1].ID)
          {
            printf("Não é possível cadastrar personagens com IDs repetidos, digite outro id:\n");
            scanf("%d", &p[quantidade].ID);
          }
        }
      }
    }
  }
