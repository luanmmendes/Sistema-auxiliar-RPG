#include "interface.h"
#include "personagem.h"
#include "item.h"

#include <stdlib.h>
#include <stdio.h>
#define CAPACIDADE 20
#define CAPACIDADE_ITENS 50
// comando para rodar o codigo gcc -Wall *.c
int main(void)
{
    // iniciar programa
    // menu();
    int valor, id, menuInventario;
    Personagem *p = iniciarPersonagem(CAPACIDADE);
    int quantidade = 0;
    do
    {
        valor = menu();

        switch (valor)
        {
        case 1:
            if (quantidade >= CAPACIDADE)
            {
                printf("Capacidade maxima de %d personagens atingida!\n", CAPACIDADE);
                break;
            }
            cadastrarPersonagem(&p[quantidade]);
            verificaID(p, quantidade);
            quantidade++;
            printf("Personagem cadastrado com sucesso! Total: %d\n", quantidade);
            break;
        case 2:
            printf("qual o ID do personagem que você deseja buscar? ");
            scanf("%d", &id);
            listaID(p, id);
            break;
        case 3:
            printf("qual o ID do personagem que você deseja alterar? ");
            scanf("%d", &id);
            alterarPersonagem(p, id, quantidade);
            break;
        case 4:
            printf("qual o ID do personagem que você deseja deletar? ");
            scanf("%d", &id);
            removerPersonagem(p, &quantidade, id);
            break;
        case 5:
            listaPersonagens(p, quantidade);
            break;
        case 6:
        {
            printf("Qual o ID do personagem cujo inventario deseja administrar? ");
            scanf("%d", &id);
            int pos = -1;
            for (int k = 0; k < quantidade; k++)
            {
                if (p[k].ID == id) { pos = k; break; }
            }
            if (pos == -1)
            {
                printf("Personagem com ID %d nao encontrado!\n", id);
                break;
            }
            do
            {
                menuInventario = interfaceInventario();
                switch (menuInventario)
                {
                case 1:
                {
                    Item itemTemp;
                    cadastrarItem(&itemTemp);
                    adicionarItemInventario(&p[pos].inventario, itemTemp);
                    break;
                }
                case 2:
                {
                    int idItem;
                    printf("Digite o ID do item que deseja consultar: ");
                    scanf("%d", &idItem);
                    int idx = buscarItemInventario(&p[pos].inventario, idItem);
                    if (idx != -1)
                    {
                        printf("Item encontrado:\n");
                        printf("  [ID: %d] %s | Espacos: %d | Atq: %+d | Def: %+d | Vida: %+d | Ini: %+d | Poder: %d\n",
                               p[pos].inventario.itens[idx].ID,
                               p[pos].inventario.itens[idx].nome,
                               p[pos].inventario.itens[idx].espacosGastos,
                               p[pos].inventario.itens[idx].bonusAtaque,
                               p[pos].inventario.itens[idx].bonusDefesa,
                               p[pos].inventario.itens[idx].bonusVida,
                               p[pos].inventario.itens[idx].bonusIniciativa,
                               p[pos].inventario.itens[idx].poder);
                    }
                    else
                    {
                        printf("Item com ID %d nao encontrado no inventario!\n", idItem);
                    }
                    break;
                }
                case 3:
                {
                    int idItem;
                    printf("Digite o ID do item que deseja remover: ");
                    scanf("%d", &idItem);
                    removerItemInventario(&p[pos].inventario, idItem, NULL);
                    break;
                }
                case 4:
                    listarInventario(&p[pos].inventario);
                    break;
                case 0:
                    printf("Retornando ao menu principal...\n");
                    break;
                default:
                    printf("Digite um numero valido!\n");
                    break;
                }
            } while (menuInventario != 0);
            break;
        }
        case 7:
        {
            printf("Qual o ID do personagem para consultar equipamentos? ");
            scanf("%d", &id);
            int pos = -1;
            for (int k = 0; k < quantidade; k++)
            {
                if (p[k].ID == id) { pos = k; break; }
            }
            if (pos == -1)
            {
                printf("Personagem com ID %d nao encontrado!\n", id);
                break;
            }
            exibeEquipamentosPersonagem(&p[pos]);
            break;
        }
        case 8:
        {
            printf("Qual o ID do personagem que vai equipar o item? ");
            scanf("%d", &id);
            int pos = -1;
            for (int k = 0; k < quantidade; k++)
            {
                if (p[k].ID == id) { pos = k; break; }
            }
            if (pos == -1)
            {
                printf("Personagem com ID %d nao encontrado!\n", id);
                break;
            }
            listarInventario(&p[pos].inventario);
            if (p[pos].inventario.quantidade > 0)
            {
                int idItem;
                printf("Digite o ID do item que deseja equipar: ");
                scanf("%d", &idItem);
                equiparItem(&p[pos], idItem);
            }
            break;
        }
        case 9:
        {
            printf("Qual o ID do personagem que vai desequipar o item? ");
            scanf("%d", &id);
            int pos = -1;
            for (int k = 0; k < quantidade; k++)
            {
                if (p[k].ID == id) { pos = k; break; }
            }
            if (pos == -1)
            {
                printf("Personagem com ID %d nao encontrado!\n", id);
                break;
            }
            exibeEquipamentosPersonagem(&p[pos]);
            int slot;
            printf("Digite o numero do slot que deseja desequipar (1 a 9): ");
            scanf("%d", &slot);
            desequiparItem(&p[pos], slot - 1);
            break;
        }
        case 10:
        {
            printf("Qual o ID do personagem para exibir atributos totais? ");
            scanf("%d", &id);
            int pos = -1;
            for (int k = 0; k < quantidade; k++)
            {
                if (p[k].ID == id) { pos = k; break; }
            }
            if (pos == -1)
            {
                printf("Personagem com ID %d nao encontrado!\n", id);
                break;
            }
            printf("\n============ ATRIBUTOS TOTAIS (ID %d: %s) ============\n", p[pos].ID, p[pos].nome);
            printf("Ataque Total    : %d (Base: %d, Modificador: %+d)\n",
                   calcularAtaqueTotal(&p[pos]), p[pos].Ataque, calcularAtaqueTotal(&p[pos]) - p[pos].Ataque);
            printf("Defesa Total    : %d (Base: %d, Modificador: %+d)\n",
                   calcularDefesaTotal(&p[pos]), p[pos].Defesa, calcularDefesaTotal(&p[pos]) - p[pos].Defesa);
            printf("Iniciativa Total: %d (Base: %d, Modificador: %+d)\n",
                   calcularIniciativaTotal(&p[pos]), p[pos].Iniciativa, calcularIniciativaTotal(&p[pos]) - p[pos].Iniciativa);
            printf("HP Maximo Total : %d (Base: %d, Modificador: %+d) | HP Atual: %d\n",
                   calcularHPTotal(&p[pos]), p[pos].HP, calcularHPTotal(&p[pos]) - p[pos].HP, p[pos].HPatual);
            printf("Poder Total     : %d (Base: %d, Modificador: %+d)\n",
                   calcularPoderTotal(&p[pos]), p[pos].Poder, calcularPoderTotal(&p[pos]) - p[pos].Poder);
            printf("======================================================\n");
            break;
        }
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Digite um número válido!\n");
            break;
        }
    } while (valor != 0);

    free(p);
    return 0;
}
