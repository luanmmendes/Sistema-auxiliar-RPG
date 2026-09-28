#include "interface.h"
#include "personagem.h"
#include "item.c"

#include <stdlib.h>
#include <stdio.h>
#define CAPACIDADE 20
//comando para rodar o codigo gcc -Wall *.c 
int main(int argc, char const *argv[])
{   
    //iniciar programa
    menu();
    int valor;
    int capacidadeAtual = CAPACIDADE;
    scanf("%d", &valor);
    switch (valor)
    {
    case 1:
        Personagem *p = iniciarPersonagem(CAPACIDADE);    
        cadastrarPersonagem(p);
        iniciarLista(p,capacidadeAtual-1);
        p++;

        printf("ID: %d\n",p->ID);
        printf("Nome: %s\n",p->nome);
        printf("%d",&p->CapacidadeItens);
        printf("Raca: %d\n",p->raca);
        // printf("Classe %d",&p.classe);
        // printf("Nivel %d\n",&p.Nivel);
        // printf("HP %d\n",&p.HP);
        // printf("Hpatual %d\n",&p.HPatual);
        // printf("ataque %d\n",&p.Ataque);
        // printf("defesa %d\n",&p.Defesa);
        // printf("iniciativa %d\n",&p.Iniciativa);
        // printf("poder: %d\n",&p.Poder);
        
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;    
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
    /* code */
        break;
    case 9:
        /* code */
        break;
    case 10:
        /* code */
        break;
    
    
    default:
        printf("digite um número válido!");
        break;
    }

    return 0;
}
