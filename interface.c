//Dedicado ao menu
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


void menu(){
    printf("=================================MENU============================\n");
    printf("1-Cadastrar personagem\n2-Consultar personagem por ID\n3-Alterar personagem\n4-Remover personagem\n5-Listar personagens\n6-Administrar inventário\n7-Consultar equipamentos\n8-Equipar item\n9-Desequipar item\n10-Exibir atributos totais\n0-Encerrar\n");
    printf("==================================================================");
    
}
void limpaBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {;}
}
int validaEnumClasse(char* texto){
  int i = strlen(texto); 
  if (texto[i-1] == '\n')
  {
    texto[i-1] = '\0';
  } 
   if (strcmp(texto,"GUERREIRO") == 0)return GUERREIRO;
   if (strcmp(texto,"CLERIGO")== 0) return CLERIGO;  
   if(strcmp(texto,"LADINO")== 0)return LADINO;  
   if(strcmp(texto,"MAGO")== 0) return MAGO;
   else return -1;
  }
int validaEnumRaca(char* texto){  
  int i = strlen(texto); 
  if (texto[i-1] == '\n')
  {
    texto[i-1] = '\0';
  }
  
  if(strcmp(texto, "HUMANO") == 0)return HUMANO;
  if(strcmp(texto,"ELFO") == 0)return ELFO;
  if(strcmp(texto,"ANAO") == 0)return ANAO;
  if(strcmp(texto,"HALFLING") == 0)return HALFLING;
  else return -1;
}
