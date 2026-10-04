//Dedicado ao menu
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


int menu(){
    int valor;
    printf("=================================MENU============================\n");
    printf("1-Cadastrar personagem\n2-Consultar personagem por ID\n3-Alterar personagem\n4-Remover personagem\n5-Listar personagens\n6-Administrar inventário\n7-Equipar item\n8-Desequipar item\n9-Exibir atributos totais\n10-Exibir Total de Personagens Cadastrados\n0-Encerrar\n");
    printf("==================================================================");
    scanf("%d", &valor);
    return valor;
}
int interfaceInventario(){
  int valor;
    printf("=================================INVENTARIO============================\n");
    printf("1-Cadastrar item\n2-Consultar item por ID\n3-Alterar item\n4-Remover item\n5-Listar itens\n6-Exibir Total de Itens Cadastrados\n0-Encerrar\n");
    printf("==================================================================");
    scanf("%d", &valor);
}
// funções de limpeza:
//scanf sempre vai ler somente os valores brutos do que você digitar, portanto, ele guarda no buffer do teclado o \n necessitando de uma função para limpá-lo e nao carregar o \n para o fgets, que busca tudo que está no buffer do teclado.
//o fgets, por outro lado, como dito acima, ele guarda os valores diretamente numa variavel, de forma que se você digitar por exemplo nome: luan ele vai receber 'l','u','a','n','\n','\0', precisando que troquemos o \n por um \0 podendo travar o app caso contrário,pois como o buffer está vazio, ele espera uma entrada para conseguir limpar

void limpaBuffer(){ // é usado depois de scanf, para limpar o buffer do teclado.
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {;}
}
/// é 
void limpaBarra(char* texto){ //é usado depois de fgets para limpar a variável de '\n's
    int i = strlen(texto);
    if (texto[i-1] == '\n')
    {
      texto[i-1] = '\0';
    }
}
//funções de validação de dados:
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
int validaEnumItem(char* texto){  
  int i = strlen(texto); 
  if (texto[i-1] == '\n')
  {
    texto[i-1] = '\0';
  }
  if(strcmp(texto, "ELMO") == 0)return ELMO;
  if(strcmp(texto,"PEITORAL") == 0)return PEITORAL;
  if(strcmp(texto,"MANOPLAS") == 0)return MANOPLAS;
  if(strcmp(texto,"CALCA") == 0)return CALCA;
  if(strcmp(texto,"BOTAS") == 0)return BOTAS;
  if(strcmp(texto,"ANEL") == 0)return ANEL;
  if(strcmp(texto,"COLAR") == 0)return COLAR;
  if(strcmp(texto,"CINTO") == 0)return CINTO;
  if(strcmp(texto,"ACESSORIO1") == 0)return ACESSORIO1;
  if(strcmp(texto,"ACESSORIO2") == 0)return ACESSORIO2;  
  if(strcmp(texto,"ARMA_UMA_MAO") == 0)return ARMA_UMA_MAO;
  if(strcmp(texto,"ARMA_DUAS_MAOS") == 0 )return ARMA_DUAS_MAOS; 
  else return -1;
}
int validaEnumEquipadoEm(char* texto){  
  int i = strlen(texto); 
  if (texto[i-1] == '\n')
  {
    texto[i-1] = '\0';
  }
  if(strcmp(texto, "CABECA") == 0)return CABECA;
  if(strcmp(texto,"PEITO") == 0)return PEITO;
  if(strcmp(texto,"BRACOS") == 0)return BRACOS;
  if(strcmp(texto,"PERNAS") == 0)return PERNAS;
  if(strcmp(texto, "PES") == 0)return PES;
  if(strcmp(texto,"MAO_DIREITA") == 0)return MAO_DIREITA;
  if(strcmp(texto,"MAO_ESQUERDA") == 0)return MAO_ESQUERDA;
  if(strcmp(texto,"ACESSORIO1") == 0)return ACESSORIO1;
  if(strcmp(texto,"ACESSORIO2") == 0)return ACESSORIO2;
  else return -1;
}
  
//variaveis de print, para deixarmos bonitinho a saida de dados.
void printaEnum(Personagem *p){
  if (p->raca == HUMANO)
  {
    printf("Raça:Humano\n");
  }
  else if (p->raca == ELFO)
  {
    printf("Raça:Elfo\n");
  }
  else if (p->raca == HALFLING)
  {
    printf("Raça:Halfling\n");
  }
  else if(p->raca == ANAO){
    printf("Raça:Anao\n");
  }
}
void printaClasse(Personagem *p){
  if (p->classe == GUERREIRO)
  {
    printf("Classe: Guerreiro\n");
  }
  if (p->classe == MAGO)
  {
    printf("Classe: Mago\n");
  }
  if (p->classe == LADINO )
  {
    printf("Classe:Ladino\n");
  }
  if (p->classe == CLERIGO)
  {
    printf("Classe: Clerigo\n");
  }
}

void listaID(Personagem *p,int ID){
  for (int i = 0; i < 20; i++)
  {
    if (p[i].ID == ID)
    {
        printf("=========================PERSONAGEM %d============================\n",ID);
        printf("Nome:%s\n",p[i].nome);
        //printf("%d",&p->Itens[]);
        printaEnum(p);
        printaClasse(p);
        printf("Nivel %d\n",p->Nivel);
        printf("HP %d\n",p->HP);
        printf("Hpatual %d\n",p->HPatual);
        printf("ataque %d\n",p->Ataque);
        printf("defesa %d\n",p->Defesa);
        printf("iniciativa %d\n",p->Iniciativa);
        printf("poder: %d\n",p->Poder);
        break;
      }
    else if (p[i].ID != ID)
    {
      printf("Nao ha personagem cadastrado com este ID!\n");
      break;
    }
  }
}

void listaPersonagens(Personagem *p,int quantidade){
  for (int i = 0; i < quantidade ; i++)
  {
    printf("=========================PERSONAGEM %d============================\n",i+1);
        printf("Nome:%s\n",p[i].nome);
        //printf("%d",&p->Itens[]);
        printaEnum(p);
        printaClasse(p);
        printf("Nivel %d\n",p->Nivel);
        printf("HP %d\n",p->HP);
        printf("Hpatual %d\n",p->HPatual);
        printf("ataque %d\n",p->Ataque);
        printf("defesa %d\n",p->Defesa);
        printf("iniciativa %d\n",p->Iniciativa);
        printf("poder: %d\n",p->Poder);
        printf("=================================================================\n",i);
  }
  
}