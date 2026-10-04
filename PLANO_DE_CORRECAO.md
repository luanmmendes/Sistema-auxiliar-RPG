# Plano de correção (versão enxuta) — critério: tabela do §10 do PDF

**Regra deste plano:** é obrigatório o que faz algum caso do §10 falhar (ou não poder ser demonstrado) e a regra explícita do §3/§4 de que o ID do item é único no personagem (C4).
**Regra de estilo:** manter o código do autor. Nada de renomear, reestruturar, trocar `scanf`/`limpaBuffer`/`fgets`/`limpaBarra`, remover `malloc`/`iniciarPersonagem`, mover `printf` dos módulos, mexer na `interface.c` além do necessário.

Um patch já pronto e **verificado** está em `correcoes_secao10.patch` (aplica com `patch -p1`, compila sem avisos com `-std=c11 -Wall -Wextra -pedantic` e passa em ASan/UBSan).

---

## 1. Resultado do §10 no código original

| Caso | Resultado |
|---|---|
| Cadastrar duas fichas válidas | ✅ |
| Repetir um ID | ⚠️ **Corrigir** — o programa pede outro ID e cadastra mesmo assim (quantidade sobe); o PDF pede "operação recusada; cadastro permanece inalterado" |
| Buscar ID existente e inexistente | ⚠️ **Corrigir** — após remover o último personagem, buscar o ID removido ainda mostra a ficha (`listaID` varre 20 posições fixas, não `quantidade`) |
| Alterar ficha válida | ✅ |
| PV atuais > PV máximos | ✅ |
| Remover elemento do meio | ✅ |
| 20 posições e a 21ª | ✅ |
| Itens somando exatamente 50 | ✅ |
| Item que levaria a 51 | ✅ |
| Equipar item compatível | ✅ |
| Equipar item incompatível | ⚠️ **Corrigir** — o caso não pode ser demonstrado: o menu 8 só pede o ID do item e o programa escolhe a posição sozinho |
| Desequipar sem capacidade | ✅ |
| Equipar arma de duas mãos | ✅ |
| Calcular atributos totais | ✅ |
| Raça/classe adicional | n/a (extensão opcional) |

Três correções obrigatórias pelo §10 (C1–C3) e uma por regra do PDF (C4). Todo o resto do relatório anterior (malloc, struct de cadastro, enum de retorno, I/O nos módulos, 9 slots, números 20/50, nome vazio, etc.) **não é exercitado pelo §10** e fica fora deste plano (ver seção 4).

---

## 2. Correções obrigatórias (todas verificadas)

### C1 — Repetir ID: recusar e deixar o cadastro inalterado
**Causa:** `main.c` (case 1) chama `cadastrarPersonagem(&p[quantidade])`, que escreve direto no vetor, e só depois `verificaID` pede outro ID.
**Solução (mínima):** cadastrar numa variável temporária; só copiar para o vetor se o ID não existir. `verificaID` passa a apenas **responder** se o ID existe.

`personagem.h`
```c
int verificaID(Personagem *p,int quantidade,int id);
```
`personagem.c` (substitui a `verificaID` antiga)
```c
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
```
`main.c`, case 1 (depois do teste de capacidade)
```c
            {
                Personagem novo = p[quantidade];
                cadastrarPersonagem(&novo);
                if (verificaID(p, quantidade, novo.ID))
                {
                    printf("Ja existe um personagem com o ID %d! Operacao recusada, cadastro inalterado.\n", novo.ID);
                    break;
                }
                p[quantidade] = novo;
                quantidade++;
                printf("Personagem cadastrado com sucesso! Total: %d\n", quantidade);
            }
            break;
```
**Teste:** cadastrar ID 1 ("Ana"), cadastrar ID 1 ("Clone") → mensagem de recusa; listar mostra só "Ana"; total continua 1.

### C2 — Buscar ID inexistente (inclui ID removido)
**Causa:** `listaID` percorre `i < 20`, inclusive posições depois de `quantidade` (restos de remoções e slots vazios com ID 0).
**Solução:** passar `quantidade` e usar como limite.

`interface.h` → `void listaID(Personagem *p,int quantidade,int ID);`
`interface.c` → assinatura `void listaID(Personagem *p, int quantidade, int ID) {` e laço `for (int i = 0; i < quantidade; i++) {`
`main.c`, case 2 → `listaID(p, quantidade, id);`
**Teste:** cadastrar IDs 1 e 2, remover 2, buscar 2 → "Nao ha personagem cadastrado com este ID!". Buscar 1 → ficha de Ana.

### C3 — Equipar item incompatível (tornar o caso demonstrável)
**Causa:** `equiparItem(p, idItem)` escolhe a posição sozinho; não há como tentar uma posição errada. (O código pergunta "Onde o item sera equipado?" no cadastro do item mas ignora a resposta.)
**Solução:** o menu 8 passa a perguntar a posição (mesma numeração 1–9 do menu 9) e `equiparItem` recebe `slot`, recusando antes de mexer em qualquer estrutura se o tipo não combina. O restante da lógica (troca, 2 mãos, espaço) foi mantido.

`personagem.h`
```c
int slotCompativel(enum tipoItem categoria, int slot);
int equiparItem(Personagem *p, int idItem, int slot);
```
`personagem.c` — nova função antes de `equiparItem`:
```c
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
```
`personagem.c` — em `equiparItem`: nova assinatura `int equiparItem(Personagem *p, int idItem, int slot)`; logo após `int slotDestino = -1;` inserir:
```c
  if (!slotCompativel(item.categoria, slot))
  {
    printf("Item '%s' incompativel com a posicao %s! Nada foi alterado.\n", item.nome, nomeSlotEquipado(slot));
    return -1;
  }
```
e trocar a escolha automática por `slotDestino = slot;` nos casos `ANEL/COLAR/CINTO` e `ARMA_UMA_MAO` (mantendo no `ARMA_UMA_MAO` o teste de conflito com arma de 2 mãos que já existe). `ARMA_DUAS_MAOS` continua ocupando as duas mãos.
`main.c`, case 8 — depois de ler `idItem`:
```c
                exibeEquipamentosPersonagem(&p[pos]);
                int slotEquipar;
                printf("Digite o numero da posicao onde deseja equipar (1 a 9): ");
                scanf("%d", &slotEquipar);
                equiparItem(&p[pos], idItem, slotEquipar - 1);
```
**Teste:** item ELMO no inventário; equipar na posição 6 (Mão Direita) → recusa, item continua no inventário (1 item); equipar na posição 1 → sai do inventário e aparece em "Cabeca (Elmo)".

### C4 — ID de item único no personagem (inventário **e** equipados)
**Causa:** `adicionarItemInventario` só confere os itens do inventário. Com o item ID 5 equipado, é possível cadastrar outro ID 5 no inventário; ao desequipar, a inserção falha por ID duplicado, mas `desequiparItem` não confere o retorno e libera o slot: o item equipado **some**. O PDF (§3) define o ID do item como "único no personagem".
**Solução:** função que olha inventário e slots equipados, usada antes de adicionar. Assim o duplicado nunca entra e o desequipar nunca encontra conflito.

`personagem.h`
```c
int itemIDEmUso(Personagem *p, int id);
```
`personagem.c` — nova função antes de `slotCompativel`:
```c
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
```
`main.c`, submenu de inventário, case 1:
```c
                    cadastrarItem(&itemTemp);
                    if (itemIDEmUso(&p[pos], itemTemp.ID))
                    {
                        printf("Ja existe um item com o ID %d neste personagem (inventario ou equipado)! Operacao recusada.\n", itemTemp.ID);
                        break;
                    }
                    adicionarItemInventario(&p[pos].inventario, itemTemp);
                    break;
```
**Teste:** equipar item ID 5 (Espada); cadastrar outro ID 5 → recusado; desequipar a Espada → volta ao inventário. Com arma de 2 mãos equipada (ocupa 2 slots), o ID dela também fica protegido.

---

## 3. Verificação feita (cópia do projeto com as 3 correções)

Compilação sem avisos com as flags do enunciado; ASan/UBSan sem relatórios; todos os casos do §10 passam:

| Caso | Situação após patch |
|---|---|
| Repetir ID | ✅ recusa e cadastro inalterado |
| Buscar existente / inexistente (incl. removido) | ✅ |
| Equipar incompatível (ELMO → Mão Direita) | ✅ recusado, item não se perde |
| Equipar compatível; Anel em Acessório 2; 1 mão na esquerda | ✅ |
| 2 mãos + 1 mão → conflito; desequipar sem capacidade | ✅ |
| 21º personagem; 50/50 e 51; remover do meio; alterar; PV atual > máximo | ✅ (inalterados) |
| Totais só com equipados (Def 10 + 3 = 13) | ✅ |
| C4: ID repetido com item equipado (normal e 2 mãos) recusado; desequipar devolve o item; ID repetido no inventário continua recusado; ID distinto aceito | ✅ |

---

## 4. Fora do §10 — NÃO alterar (a menos que o grupo decida)

Itens encontrados na análise que **nenhum caso do §10 exercita**. Ficam como "opcionais/qualidade", sem pressa:

| Item | Observação |
|---|---|
| `malloc` / sem struct `CadastroPersonagens` / retornos em `enum` / I/O dentro dos módulos / 9 slots / números 20 e 50 espalhados | Desvios do texto do PDF (§2, §4, §7, §8), mas não reprovam nenhum caso da tabela |
| `alterarPersonagem` reinicia inventário e equipamentos | Decisão de projeto; o PDF é ambíguo. Sugestão: registrar no README que é intencional |
| ID 0 aceito (`< 0` em vez de `<= 0`), nome vazio, PV máximo 0 | Não aparecem no §10; correção de 1 linha cada se quiserem |
| `ACESSORIO1/2` aceitos como "categoria" (linhas 95–96 de `interface.c`; `ACESSORIO2` vira `ARMA_UMA_MAO`) | Apagar essas 2 linhas resolve |
| Entrada não numérica / EOF travam ou ignoram validação | Só aparece em uso fora do roteiro de testes |
| README com identificação de 1 pessoa e `{` solto; binário `personagens` e `.vscode/` no zip | Higiene da entrega |

---

## 5. Instruções para a IA que for aplicar

1. Aplicar `correcoes_secao10.patch` (ou reproduzir manualmente C1–C4, **sem** alterar nomes, indentação ou estilo existentes).
2. Não adicionar arquivos novos, não refatorar, não tocar em nada da seção 4.
3. Compilar: `gcc -std=c11 -Wall -Wextra -pedantic main.c personagem.c inventario.c item.c interface.c -o personagens` (0 avisos).
4. Executar manualmente os testes descritos em C1, C2, C3 e C4 e conferir os demais casos da tabela do §10.
