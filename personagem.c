#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

void iniciarPersonagem(int capacidade){
   Personagem *personagem = malloc(capacidade * sizeof(*personagem));
    personagem->Capacidade = capacidade--;
    //personagem->nome[50] = "xxx";
    personagem->raca = "HUMANO";
    personagem->classe = "MAGO";
    personagem->Nivel = 1;
    personagem->HP = 999;
    personagem->HPatual = 999;
    personagem->Ataque =15;
    personagem->Defesa = 15;
    personagem->Iniciativa= 15;
    personagem->Poder = 10;
    return *personagem;
}

  
  
  printf("");

  printf("");

  printf("");

  printf("");

  printf("");
 
  
  
  

  

  

  
}


cadastrarPersonagem(Personagem *personagem,char nome[50],enum Raca,enum Classe,int nivel,int hp,int hpatual,int ataque,int defesa,int iniciativa,int poder){
  
  
  
  if (personagem == NULL)
  {
    return perror; 
  }
  
  printf("digite um ID Válido");
  scanf("%d",ID,personagem->ID);
  if ();
  {
    /* code */
  }
  
  
  
  

}