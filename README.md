# Sistema Auxiliar de Mestre de RPG (em C)

Projeto desenvolvido para a disciplina de **Algoritmos e Estruturas de Dados 2** (4º Período).

**Feito por:**
- Luan Da Cruz Mendes
- Henrique Rodrigues Ferreira

---

## Sobre o Projeto

O programa tem como intuito implementar um sistema auxiliar para mestres de RPG de mesa diretamente no terminal. Com ele, o mestre consegue cadastrar, consultar, alterar e remover personagens de forma prática, além de administrar o inventário de cada um, equipando itens que concedem bônus de vida, ataque, defesa, iniciativa e poder em tempo real.

O projeto foi construído com foco em boas práticas de programação em C : ponteiros, modularização de código em arquivos `.c` e `.h`, tratamento de buffers do teclado e compilação sem warnings.

---

## Funcionalidades

### Gerenciamento de Personagens
- **Cadastro Completo**: Nome, Raça (Humano, Elfo, Anão, etc.), Classe (Guerreiro, Mago, Ladino, etc.), Nível, HP (Máximo e Atual), Ataque, Defesa, Iniciativa e Poder.
- **Validação de ID**: Não permite o cadastro de personagens com IDs duplicados.
- **Consulta por ID**: Visualização rápida e detalhada da ficha de um personagem específico.
- **Alteração de Atributos**: Modificação de valores da ficha sem perder os itens e equipamentos.
- **Remoção de Personagem**: Exclusão segura do personagem com reorganização automática do vetor de registros.
- **Listagem Geral**: Visão panorâmica de todos os aventureiros cadastrados e suas estatísticas.

### Sistema de Inventário e Mochila
- **Capacidade e Volume**: Cada personagem possui um inventário com limite de até **50 espaços**. Cada item cadastrado ocupa uma quantidade específica de espaços (`espacosGastos`), simulando o peso/volume real na mochila.
- **Cadastro e Consulta de Itens**: Adição de itens no inventário com verificação para evitar IDs duplicados no mesmo personagem.
- **Remoção de Itens**: Descarte de itens da mochila com liberação imediata dos espaços ocupados.
- **Listagem com Ocupação**: Exibição dos itens guardados e do total de espaços ocupados vs disponíveis.

### Sistema de Equipamentos e Bônus
- **9 Slots de Equipamento**: Cabeça, Tronco, Pernas, Pés, Mão Direita, Mão Esquerda, Amuleto, Anel 1 e Anel 2.
- **Verificação de Compatibilidade**: O sistema só permite equipar um item no slot condizente com a sua categoria (ex: espada nas mãos, capacete na cabeça).
- **Atributos Totais e Bônus em Tempo Real**: Cálculo dinâmico dos atributos do personagem (Atributo Base + Modificadores dos Itens Equipados), exibindo claramente o bônus concedido por cada peça em batalha.

---

## Estrutura e Modularidade

Por questões de modularidade e organização do código, criamos arquivos dedicados exclusivamente à interface (`interface.c` e `interface.h`). Assim, chamamos apenas a função `menu()` no `main.c`. 

- `main.c`: Ponto de entrada do programa, controle do menu interativo e ciclo de vida dos dados.
- `interface.c` / `interface.h`: Menus interativos no terminal, formatações de saída, validações de enums e rotinas para limpeza de buffers (`limpaBuffer` para limpar o `\n` do `stdin` deixado pelo `scanf` e `limpaBarra` para strings lidas com `fgets`).
- `personagem.c` / `personagem.h`: Definição das estruturas `Personagem` e `Equipamentos`, alocação na Heap, operações de CRUD e cálculo dos atributos totais com bônus.
- `inventario.c` / `inventario.h`: Gerenciamento da struct `Inventario`, controle da mochila de 50 espaços e cálculo da soma dos espaços ocupados.
- `item.c` / `item.h`: Definição da struct `Item` e funções de entrada/cadastro de novos itens.
- `Makefile`: Script para compilação automatizada com flags rigorosas (`-std=c11 -Wall -Wextra -pedantic -g`).

---

## Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado (suporte a C11).
- Utilitário Make (opcional, mas recomendado).
- Sistema Linux / terminal Bash.

### Opção 1: Usando o Makefile (Recomendado)

Para compilar o projeto:
```bash
make
```

Para rodar o programa logo em seguida:
```bash
make run
```

Para limpar os arquivos objetos (`.o`) e o executável:
```bash
make clean
```

### Opção 2: Compilação Manual via GCC

Caso não queira usar o Make, você pode compilar todos os arquivos diretamente:
```bash
gcc -std=c11 -Wall -Wextra -pedantic -g main.c personagem.c interface.c inventario.c item.c -o personagens
./personagens
```
