#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

Personagem *iniciarPersonagem(int capacidadeMax)
{
  Personagem *personagem = malloc(capacidadeMax * sizeof(*personagem));
  if (personagem == NULL) return NULL;
  for (int i = 0; i < capacidadeMax; i++)
  {
    personagem[i].ID = 0;
    personagem[i].nome[0] = '\0';
    personagem[i].raca = HUMANO;
    personagem[i].classe = GUERREIRO;
    personagem[i].Nivel = 1;
    personagem[i].HP = 100;
    personagem[i].HPatual = 100;
    personagem[i].Ataque = 10;
    personagem[i].Defesa = 10;
    personagem[i].Iniciativa = 10;
    personagem[i].Poder = 10;
    inicializarInventario(&personagem[i].inventario);
    inicializarEquipamentos(&personagem[i].equipamentos);
  }
  return personagem;
}

Personagem cadastrarPersonagem(Personagem *p)
{
  int verificaRaca, verificaClasse = 0;
  char texto[50];

  printf("ID:");
  scanf("%d", &p->ID);
  if (p->ID < 0)
  {
    printf("o ID deve ser um inteiro positivo valido!\n");
    while (p->ID < 0)
    {
      scanf("%d", &p->ID);
    }
  }
  limpaBuffer();
  printf("Nome:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  strcpy(p->nome, texto);
  printf("Raca:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  verificaRaca = validaEnumRaca(texto);
  if (verificaRaca == -1)
  {
    while (verificaRaca == -1)
    {
      printf("digite uma raca valida! (USE CAIXA ALTA): ");
      fgets(texto, sizeof(texto), stdin);
      limpaBarra(texto);
      verificaRaca = validaEnumRaca(texto);
    }
  }
  p->raca = verificaRaca;
  printf("Classe:");
  fgets(texto, sizeof(texto), stdin);
  limpaBarra(texto);
  verificaClasse = validaEnumClasse(texto);
  if (verificaClasse == -1)
  {
    while (verificaClasse == -1)
    {
      printf("digite uma classe valida! (USE CAIXA ALTA): ");
      fgets(texto, sizeof(texto), stdin);
      limpaBarra(texto);
      verificaClasse = validaEnumClasse(texto);
    }
  }
  p->classe = verificaClasse;
  printf("Nivel:");
  scanf("%d", &p->Nivel);
  while (p->Nivel > 20 || p->Nivel < 1)
  {
    printf("digite um nivel valido");
    scanf("%d", &p->Nivel);
  }
  printf("HP: ");
  scanf("%d", &p->HP);
  while (p->HP < 0 || p->HP > 999)
  {
    printf("digite um HP valido!");
    scanf("%d", &p->HP);
  }

  printf("HP Atual: ");
  scanf("%d", &p->HPatual);
  while (p->HPatual < 0 || p->HPatual > p->HP)
  {
    printf("Digite um HP atual valido!");
    scanf("%d", &p->HPatual);
  }
  printf("Ataque: ");
  scanf("%d", &p->Ataque);
  while (p->Ataque < 0 || p->Ataque > 30)
  {
    printf("digite um valor valido!");
    scanf("%d", &p->Ataque);
  }
  printf("Defesa ");
  scanf("%d", &p->Defesa);
  while (p->Defesa < 1 || p->Defesa > 30)
  {
    printf("Digite um valor valido!");
    scanf("%d", &p->Defesa);
  }

  printf("Iniciativa: ");
  scanf("%d", &p->Iniciativa);
  while (p->Iniciativa < -5 || p->Iniciativa > 20)
  {
    printf("digite um valor valido");
    scanf("%d", &p->Iniciativa);
  }
  printf("Poder: ");
  scanf("%d", &p->Poder);
  while (p->Poder < 0 || p->Poder > 100)
  {
    printf("digite um valor valido!");
    scanf("%d", &p->Poder);
  }
  inicializarInventario(&p->inventario);
  inicializarEquipamentos(&p->equipamentos);
  return *p;
}

void alterarPersonagem(Personagem *p, int id, int quantidade)
{
  int achou = 0;
  for (int i = 0; i < quantidade; i++)
  {
    if (p[i].ID == id)
    {
      achou = 1;
      printf("\n--- Digite os novos dados para o personagem ID %d ---\n", id);
      cadastrarPersonagem(&p[i]);
      p[i].ID = id;
      printf("Personagem ID %d alterado com sucesso!\n", id);
      break;
    }
  }
  if (!achou)
  {
    printf("Personagem com ID %d nao existe!\n", id);
  }
}

void removerPersonagem(Personagem *p, int *quantidade, int id)
{
  int achou = 0;
  for (int i = 0; i < *quantidade; i++)
  {
    if (p[i].ID == id)
    {
      achou = 1;
      for (int j = i; j < *quantidade - 1; j++)
      {
        p[j] = p[j + 1];
      }
      (*quantidade)--;
      printf("Personagem ID %d removido com sucesso!\n", id);
      break;
    }
  }
  if (!achou)
  {
    printf("Personagem com ID %d nao encontrado para remocao!\n", id);
  }
}

int verificaID(Personagem *p, int quantidade, int id)
{
  for (int i = 0; i < quantidade; i++)
  {
    if (p[i].ID == id)
    {
      return 1;
    }
  }
  return 0;
}

const char* nomeSlotEquipado(int slot)
{
  switch (slot)
  {
    case CABECA: return "Cabeca (Elmo)";
    case PEITO: return "Peito (Peitoral)";
    case BRACOS: return "Bracos (Manoplas)";
    case PERNAS: return "Pernas (Calca)";
    case PES: return "Pes (Botas)";
    case MAO_DIREITA: return "Mao Direita";
    case MAO_ESQUERDA: return "Mao Esquerda";
    case ACESSORIO1: return "Acessorio 1";
    case ACESSORIO2: return "Acessorio 2";
    default: return "Desconhecido";
  }
}

void inicializarEquipamentos(Equipamentos *eq)
{
  if (eq == NULL) return;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    eq->ocupado[i] = 0;
  }
  eq->armaDuasMaosEquipada = 0;
}

int itemIDEmUso(Personagem *p, int id)
{
  if (buscarItemInventario(&p->inventario, id) != -1)
  {
    return 1;
  }
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i] && p->equipamentos.itens[i].ID == id)
    {
      return 1;
    }
  }
  return 0;
}

int slotCompativel(enum tipoItem categoria, int slot)
{
  switch (categoria)
  {
    case ELMO: return slot == CABECA;
    case PEITORAL: return slot == PEITO;
    case MANOPLAS: return slot == BRACOS;
    case CALCA: return slot == PERNAS;
    case BOTAS: return slot == PES;
    case ANEL:
    case COLAR:
    case CINTO: return slot == ACESSORIO1 || slot == ACESSORIO2;
    case ARMA_UMA_MAO:
    case ARMA_DUAS_MAOS: return slot == MAO_DIREITA || slot == MAO_ESQUERDA;
    default: return 0;
  }
}

int equiparItem(Personagem *p, int idItem, int slot)
{
  if (p == NULL) return -1;

  int pos = buscarItemInventario(&p->inventario, idItem);
  if (pos == -1)
  {
    printf("Item com ID %d nao encontrado no inventario do personagem!\n", idItem);
    return -1;
  }

  Item item = p->inventario.itens[pos];
  int slotDestino = -1;

  if (!slotCompativel(item.categoria, slot))
  {
    printf("Item '%s' incompativel com a posicao %s! Nada foi alterado.\n", item.nome, nomeSlotEquipado(slot));
    return -1;
  }

  switch (item.categoria)
  {
    case ELMO: slotDestino = CABECA; break;
    case PEITORAL: slotDestino = PEITO; break;
    case MANOPLAS: slotDestino = BRACOS; break;
    case CALCA: slotDestino = PERNAS; break;
    case BOTAS: slotDestino = PES; break;
    case ANEL:
    case COLAR:
    case CINTO:
      slotDestino = slot;
      break;
    case ARMA_UMA_MAO:
      if (p->equipamentos.armaDuasMaosEquipada)
      {
        printf("Conflito: Ha uma arma de duas maos equipada! Desequipe-a primeiro.\n");
        return -1;
      }
      slotDestino = slot;
      break;
    case ARMA_DUAS_MAOS:
    {
      int espacosNecessarios = (p->equipamentos.ocupado[MAO_DIREITA] ? p->equipamentos.itens[MAO_DIREITA].espacosGastos : 0) +
                               ((p->equipamentos.ocupado[MAO_ESQUERDA] && !p->equipamentos.armaDuasMaosEquipada) ? p->equipamentos.itens[MAO_ESQUERDA].espacosGastos : 0);
      int ocupacaoAtual = calcularOcupacao(&p->inventario);
      if (ocupacaoAtual - item.espacosGastos + espacosNecessarios > 50)
      {
        printf("Sem espaco no inventario para desequipar as armas atuais e equipar a arma de 2 maos!\n");
        return -1;
      }
      removerItemInventario(&p->inventario, item.ID, NULL);
      if (p->equipamentos.ocupado[MAO_DIREITA])
      {
        adicionarItemInventario(&p->inventario, p->equipamentos.itens[MAO_DIREITA]);
      }
      if (p->equipamentos.ocupado[MAO_ESQUERDA] && !p->equipamentos.armaDuasMaosEquipada)
      {
        adicionarItemInventario(&p->inventario, p->equipamentos.itens[MAO_ESQUERDA]);
      }
      p->equipamentos.itens[MAO_DIREITA] = item;
      p->equipamentos.ocupado[MAO_DIREITA] = 1;
      p->equipamentos.itens[MAO_ESQUERDA] = item;
      p->equipamentos.ocupado[MAO_ESQUERDA] = 1;
      p->equipamentos.armaDuasMaosEquipada = 1;
      printf("Arma de duas maos '%s' equipada com sucesso em ambas as maos!\n", item.nome);
      return 0;
    }
    default:
      printf("Tipo de item incompativel com qualquer posicao de equipamento!\n");
      return -1;
  }

  if (p->equipamentos.ocupado[slotDestino])
  {
    Item antigo = p->equipamentos.itens[slotDestino];
    int ocupacaoAtual = calcularOcupacao(&p->inventario);
    if (ocupacaoAtual - item.espacosGastos + antigo.espacosGastos > 50)
    {
      printf("Espaco insuficiente no inventario para realizar a troca de itens!\n");
      return -1;
    }
    removerItemInventario(&p->inventario, item.ID, NULL);
    adicionarItemInventario(&p->inventario, antigo);
    p->equipamentos.itens[slotDestino] = item;
    p->equipamentos.ocupado[slotDestino] = 1;
    printf("Item '%s' equipado em %s (item '%s' retornou ao inventario).\n",
           item.nome, nomeSlotEquipado(slotDestino), antigo.nome);
    return 0;
  }
  else
  {
    removerItemInventario(&p->inventario, item.ID, NULL);
    p->equipamentos.itens[slotDestino] = item;
    p->equipamentos.ocupado[slotDestino] = 1;
    printf("Item '%s' equipado em %s com sucesso!\n", item.nome, nomeSlotEquipado(slotDestino));
    return 0;
  }
}

int desequiparItem(Personagem *p, int slot)
{
  if (p == NULL || slot < 0 || slot >= QTD_SLOTS_EQUIPAMENTO)
  {
    printf("Slot invalido!\n");
    return -1;
  }
  if (!p->equipamentos.ocupado[slot])
  {
    printf("Nao ha item equipado no slot %s!\n", nomeSlotEquipado(slot));
    return -1;
  }

  if (p->equipamentos.armaDuasMaosEquipada && (slot == MAO_DIREITA || slot == MAO_ESQUERDA))
  {
    Item arma = p->equipamentos.itens[MAO_DIREITA];
    if (calcularOcupacao(&p->inventario) + arma.espacosGastos > 50)
    {
      printf("Sem espaco no inventario para desequipar a arma de duas maos! Item permanece equipado.\n");
      return -1;
    }
    adicionarItemInventario(&p->inventario, arma);
    p->equipamentos.ocupado[MAO_DIREITA] = 0;
    p->equipamentos.ocupado[MAO_ESQUERDA] = 0;
    p->equipamentos.armaDuasMaosEquipada = 0;
    printf("Arma de duas maos '%s' desequipada e guardada no inventario!\n", arma.nome);
    return 0;
  }

  Item item = p->equipamentos.itens[slot];
  if (calcularOcupacao(&p->inventario) + item.espacosGastos > 50)
  {
    printf("Sem espaco no inventario para desequipar o item! Item permanece equipado.\n");
    return -1;
  }
  adicionarItemInventario(&p->inventario, item);
  p->equipamentos.ocupado[slot] = 0;
  printf("Item '%s' desequipado de %s e guardado no inventario!\n", item.nome, nomeSlotEquipado(slot));
  return 0;
}

int calcularAtaqueTotal(const Personagem *p)
{
  int total = p->Ataque;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i])
    {
      if (p->equipamentos.armaDuasMaosEquipada && i == MAO_ESQUERDA) continue;
      total += p->equipamentos.itens[i].bonusAtaque;
    }
  }
  return total;
}

int calcularDefesaTotal(const Personagem *p)
{
  int total = p->Defesa;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i])
    {
      if (p->equipamentos.armaDuasMaosEquipada && i == MAO_ESQUERDA) continue;
      total += p->equipamentos.itens[i].bonusDefesa;
    }
  }
  return total;
}

int calcularIniciativaTotal(const Personagem *p)
{
  int total = p->Iniciativa;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i])
    {
      if (p->equipamentos.armaDuasMaosEquipada && i == MAO_ESQUERDA) continue;
      total += p->equipamentos.itens[i].bonusIniciativa;
    }
  }
  return total;
}

int calcularHPTotal(const Personagem *p)
{
  int total = p->HP;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i])
    {
      if (p->equipamentos.armaDuasMaosEquipada && i == MAO_ESQUERDA) continue;
      total += p->equipamentos.itens[i].bonusVida;
    }
  }
  return total;
}

int calcularPoderTotal(const Personagem *p)
{
  int total = p->Poder;
  for (int i = 0; i < QTD_SLOTS_EQUIPAMENTO; i++)
  {
    if (p->equipamentos.ocupado[i])
    {
      if (p->equipamentos.armaDuasMaosEquipada && i == MAO_ESQUERDA) continue;
      total += p->equipamentos.itens[i].poder;
    }
  }
  return total;
}
