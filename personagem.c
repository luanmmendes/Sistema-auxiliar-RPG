#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

Personagem* iniciarPersonagem(int capacidadeMax){
   Personagem *personagem = malloc(capacidadeMax * sizeof(*personagem));
    personagem->CapacidadeItens[capacidadeMax] = CAPACIDADE_ITENS;
    personagem->ID = 0;
    personagem->nome[capacidadeMax] = 'x';
    personagem->raca = 0;
    personagem->classe = 0;
    personagem->Nivel = 1;
    personagem->HP = 999;
    personagem->HPatual = 999;
    personagem->Ataque =15;
    personagem->Defesa = 15;
    personagem->Iniciativa= 15;
    personagem->Poder = 10;
    return personagem;
}  

Personagem cadastrarPersonagem(Personagem *p){
  int i,verificaRaca,verificaClase = 0;
  char texto[50];
  
  printf("ID: ");
  scanf("%d",&p->ID);
  limpaBuffer(); 
  printf("Nome: ");
  fgets(texto,sizeof(texto),stdin);
  strcpy(p->nome,texto);
  limpaBuffer();
  printf("Raca: ");
  fgets(texto,sizeof(texto),stdin);
  verificaRaca = validaEnumRaca(texto);
  if (verificaRaca == -1)
  {
   while (verificaRaca == -1)
  {
    printf("digite uma raca valida! (USE CAIXA ALTA)");
    fgets(texto,sizeof(texto),stdin);
    i = strlen(texto);
    if (texto[i-1] == '\n')
    {
      texto[i-1] = '\0';
    }
    
    verificaRaca = validaEnumRaca(texto);
  }
  }
  printf("Classe: ");
  fgets(texto, sizeof(texto),stdin);
  limpaBuffer();
  verificaClase = validaEnumClasse(texto);
  if (verificaClase == -1)
  {
    while (verificaClase == -1)
    {
        printf("digite uma raca valida! (USE CAIXA ALTA)");
        fgets(texto,sizeof(texto),stdin);
        verificaRaca = validaEnumRaca(texto);
    } 
  }
  printf("Nivel: ");
  scanf("%d",&p->Nivel);
  while (p->Nivel > 20 || p->Nivel < 1)
  { 
    printf("digite um nivel valido");
    scanf("%d",&p->Nivel);    
  }
  printf("HP: ");
  scanf("%d",&p->HP);
  while (p->HP < 0 || p->HP > 999)
  {
    printf("digite um HP valido!");
    scanf("%d", &p->HP);
  }
    
  printf("HP Atual: ");
  scanf("%d",&p->HPatual);
  while (p->HPatual < 0 || p->HPatual > p->HP)
  {
    printf("Digite um HP atual valido!");
    scanf("%d", &p->HPatual);
  }
  printf("Ataque: ");
  scanf("%d",&p->Ataque);
  while (p->Ataque < 0 || p->Ataque > 30)
  {
    printf("digite um valor valido!");
    scanf("%d",&p->Ataque);
  }
  printf("Defesa ");
  scanf("%d",&p->Defesa);
  while (p->Defesa < 1 ||p->Defesa >30)
  {
    printf("Digite um valor valido!");
    scanf("%d",&p->Defesa);
  }
  
  printf("Iniciativa: ");
  scanf("%d",&p->Iniciativa);
  while (p->Iniciativa < -5 || p->Iniciativa > 20)
  {
    printf("digite um valor valido");
    scanf("%d",&p->Iniciativa);
  }
  printf("Poder: ");
  scanf("%d",&p->Poder);
  while (p->Poder < 0 || p->Poder > 100)
  {
    printf("digite um valor valido!");
    scanf("%d", &p->Poder);
  }
}
  
void verificaID(Personagem *p){
  for (size_t i = 1; i < 20; i++)
  {
    if (p->ID == p[i-1].ID)
    {
      printf("Digite um ID diferente!");
      while (p->ID == p[i-1].ID)
      {
        scanf("%d",&p->ID);
      }
    }
  }    
}

int adicionarLista(Personagem *p,int* capacidadeAtual){
  if (*capacidadeAtual < 0)
  {
    return 1;
  }
  else {
    p++;
    *capacidadeAtual--;
    verificaID(p);
    return 0;
  }z
}
