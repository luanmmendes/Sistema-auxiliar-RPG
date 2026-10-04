#include "interface.h"
#include "personagem.h"
#include "item.c"

#include <stdlib.h>
#include <stdio.h>
#define CAPACIDADE 20
// comando para rodar o codigo gcc -Wall *.c
int main(int argc, char const *argv[])
{
    // iniciar programa
    // menu();
    int valor, id;
    Personagem *p = iniciarPersonagem(CAPACIDADE);
    int quantidade = 0;
    do
    {
        valor = menu();

        switch (valor)
        {

        case 1:
            verificaID(p, quantidade);
            cadastrarPersonagem(&p[quantidade]);
            quantidade++;
            break;
        case 2:
            printf("qual o ID do personagem que você deseja buscar?");
            scanf("%d", &id);
            listaID(p, id);
            break;
        case 3:
            printf("qual o ID do personagem que você deseja alterar?");
            scanf("%d", &id);
            alterarPersonagem(p, id, quantidade);
            break;
        case 4:
        printf("qual o ID do personagem que você deseja deletar?");
        scanf("%d",&id);
        removerPersonagem(p,&quantidade,id);
            break;
        case 5:
            listaPersonagens(p, quantidade);
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
        case 11:
            printf("Há %d personagens cadastrados",quantidade);
            break;

        default:
            printf("digite um número válido!");
            break;
        }
    } while (valor != 0);

    return 0;
}
