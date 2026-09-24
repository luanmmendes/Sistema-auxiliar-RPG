//Dedicado ao menu
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


void menu(){
    printf("=================================MENU============================\n");
    printf("1-Cadastrar personagem\n2-Consultar personagem por ID\n3-Alterar personagem\n4-Remover personagem\n5-Listar personagens\n6-Administrar inventário\n7-Consultar equipamentos\n8-Equipar item\n9-Desequipar item\n10-Exibir atributos totais\n0-Encerrar\n");
    printf("==================================================================");
    
}
int validaEnumClasse(char* texto){
   if (strcmp(texto,GUERREIRO) == 0)return GUERREIRO;
   if (strcmp(texto,CLERIGO)== 0) return CLERIGO;  
   if(strcmp(texto,LADINO)== 0)return LADINO;  
   if(strcmp(texto,MAGO)== 0) return MAGO;
   else return -1;
  }
int validaEnumRaca(char* texto){  
  if(strcmp(texto, "HUMANO"))return HUMANO;
  if(strcmp(texto,"ELFO"))return ELFO;
  if(strcmp(texto,"ANAO"))return ANAO;
  if(strcmp(texto,"HALFLING"))return HALFLING;
  else return -1;
}
void lerDadosPersonagem(){
  int verificaRaca, verificaClase = 0;
  char texto[50];
  Personagem p;
  int valido = -1;
  printf("ID: ");
  scanf("%d",p.ID);
  printf("Nome: ");
  fgets(texto,sizeof(texto),stdin);
  strcpy(p.nome,texto);
  printf("Raca: ");
  fgets(texto,sizeof(texto),stdin);
  verificaRaca = validaEnumRaca(texto);
  if (verificaRaca == -1)
  {
   while (verificaRaca == -1);
  {
    printf("digite uma raca valida! (USE CAIXA ALTA)");
    char* texto;
    fgets(texto,sizeof(texto),stdin);
    verificaRaca = validaEnumRaca(texto);
  }
  }
  strcpy(p.raca,texto);
  printf("Classe: ");
  fgets(texto, sizeof(texto),stdin);
  verificaClase = validaEnumClasse(texto);
  if (verificaClase == -1)
  {
    while (verificaClase == -1)
    {
        printf("digite uma raca valida! (USE CAIXA ALTA)");
        char* texto;
        fgets(texto,sizeof(texto),stdin);
        verificaRaca = validaEnumRaca(texto);
    } 
  }
  printf("Nivel: ");
  scanf("%d",p.Nivel);
  while (p.Nivel > 20 || p.Nivel < 1)
  { 
    printf("digite um valor valido");
    scanf("%d",&p.Nivel);    
  }
  printf("HP: ");
  scanf("%d",p.HP);
  while (p.HP < 0 || p.HP > 999)
  {
    printf("digite um valor valido!");
    scanf("%d", p.HP);
  }
    
  printf("HP Atual: ");
  scanf("%d",p.HPatual);
  while (p.HPatual < 0 || p.HPatual > p.HP)
  {
    printf("Digite um numero valido!");
    scanf("%d", p.HPatual);
  }
  printf("Ataque: ");
  scanf("%d",p.Ataque);
  while (p.Ataque < 0 || p.Ataque > 30)
  {
    printf("digite um valor valido!");
    scanf("%d",p.Ataque);
  }
  printf("Defesa ");
  scanf("%d",p.Defesa);
  while (p.Defesa < 1 ||p.Defesa >30)
  {
    printf("Digite um valor valido!");
    scanf("%d",p.Defesa);
  }
  
  printf("Iniciativa: ");
  while (p.Iniciativa < -5 || p.Iniciativa > 20)
  {
    printf("digite um valor valido");
    scanf("%d",p.Iniciativa);
  }
  printf("Poder: ");
  scanf("%d",p.Poder);
  while (p.Poder < 0 || p.Poder > 100)
  {
    printf("digite um valor valido!");
    scanf("%d", p.Poder);
  }
  






}
  