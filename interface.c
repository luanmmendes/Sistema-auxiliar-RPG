//Dedicado ao menu
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


int menu(){
    int valor;
    printf("\n================================= MENU ============================\n");
    printf("1 - Cadastrar personagem\n");
    printf("2 - Consultar personagem por ID\n");
    printf("3 - Alterar personagem\n");
    printf("4 - Remover personagem\n");
    printf("5 - Listar personagens\n");
    printf("6 - Administrar inventário\n");
    printf("7 - Consultar equipamentos\n");
    printf("8 - Equipar item\n");
    printf("9 - Desequipar item\n");
    printf("10 - Exibir atributos totais\n");
    printf("0 - Encerrar\n");
    printf("===================================================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &valor);
    return valor;
}
int interfaceInventario(){
    int valor;
    printf("\n=========================== INVENTARIO ===========================\n");
    printf("1 - Cadastrar item no inventario\n");
    printf("2 - Consultar item por ID\n");
    printf("3 - Remover item do inventario\n");
    printf("4 - Listar itens e ocupacao\n");
    printf("0 - Voltar ao menu principal\n");
    printf("==================================================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &valor);
    return valor;
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

void listaID(Personagem *p, int ID) {
  int achou = 0;
  for (int i = 0; i < 20; i++) {
    if (p[i].ID == ID) {
      achou = 1;
      printf("\n========================= PERSONAGEM ID %d ============================\n", ID);
      printf("Nome: %s\n", p[i].nome);
      printaEnum(&p[i]);
      printaClasse(&p[i]);
      printf("Nivel: %d\n", p[i].Nivel);
      printf("HP: %d (Atual: %d) | Total c/ Equip: %d\n", p[i].HP, p[i].HPatual, calcularHPTotal(&p[i]));
      printf("Ataque: %d | Total c/ Equip: %d\n", p[i].Ataque, calcularAtaqueTotal(&p[i]));
      printf("Defesa: %d | Total c/ Equip: %d\n", p[i].Defesa, calcularDefesaTotal(&p[i]));
      printf("Iniciativa: %d | Total c/ Equip: %d\n", p[i].Iniciativa, calcularIniciativaTotal(&p[i]));
      printf("Poder: %d | Total c/ Equip: %d\n", p[i].Poder, calcularPoderTotal(&p[i]));
      printf("Espacos Ocupados no Inventario: %d/50\n", calcularOcupacao(&p[i].inventario));
      printf("=======================================================================\n");
      break;
    }
  }
  if (!achou) {
    printf("Nao ha personagem cadastrado com este ID!\n");
  }
}

void listaPersonagens(Personagem *p, int quantidade) {
  if (quantidade == 0) {
    printf("Nenhum personagem cadastrado no momento.\n");
    return;
  }
  for (int i = 0; i < quantidade; i++) {
    printf("\n========================= PERSONAGEM %d (ID %d) ============================\n", i + 1, p[i].ID);
    printf("Nome: %s\n", p[i].nome);
    printaEnum(&p[i]);
    printaClasse(&p[i]);
    printf("Nivel: %d\n", p[i].Nivel);
    printf("HP: %d/%d (Total: %d)\n", p[i].HPatual, p[i].HP, calcularHPTotal(&p[i]));
    printf("Ataque: %d (Total: %d) | Defesa: %d (Total: %d)\n",
           p[i].Ataque, calcularAtaqueTotal(&p[i]), p[i].Defesa, calcularDefesaTotal(&p[i]));
    printf("Iniciativa: %d (Total: %d) | Poder: %d (Total: %d)\n",
           p[i].Iniciativa, calcularIniciativaTotal(&p[i]), p[i].Poder, calcularPoderTotal(&p[i]));
    printf("Inventario: %d/50 espacos ocupados (%d itens)\n",
           calcularOcupacao(&p[i].inventario), p[i].inventario.quantidade);
    printf("===========================================================================\n");
  }
}

void exibeEquipamentosPersonagem(const Personagem *p) {
  if (p == NULL) return;
  printf("\n============= EQUIPAMENTOS DO PERSONAGEM (ID %d) =============\n", p->ID);
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++) {
    printf("[%d] %-18s: ", i + 1, nomeSlotEquipado(i));
    if (p->equipamentos.ocupado[i]) {
      printf("%s [ID: %d, Atq: %+d, Def: %+d, Vida: %+d, Ini: %+d, Poder: %d]\n",
             p->equipamentos.itens[i].nome,
             p->equipamentos.itens[i].ID,
             p->equipamentos.itens[i].bonusAtaque,
             p->equipamentos.itens[i].bonusDefesa,
             p->equipamentos.itens[i].bonusVida,
             p->equipamentos.itens[i].bonusIniciativa,
             p->equipamentos.itens[i].poder);
    } else {
      printf("(vazio)\n");
    }
  }
  if (p->equipamentos.armaDuasMaosEquipada) {
    printf("* Nota: Arma de duas maos bloqueia ambas as maos.\n");
  }
  printf("==============================================================\n");
}