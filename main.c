#include "interface.h"
#include "personagem.h"
#include "item.c"

#include <stdlib.h>
#include <stdio.h>

//comando para rodar o codigo gcc -Wall *.c 
int main(int argc, char const *argv[])
{
    //iniciar programa
    menu();
    int valor;
    scanf("%d", &valor);
    switch (valor)
    {
    case 1:
        /* code */
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
