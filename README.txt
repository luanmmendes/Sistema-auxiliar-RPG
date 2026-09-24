Feito por: Luan Da Cruz Mendes
Por questões de modularidade, achei interessante criar dois arquivos dedicados somente a interface, assim, podemos só chamar uma função menu no main, deixando mais legível o código e não necessitando de uma grande parede de código logo no começo do programa.

código para rodar o programa:
gcc -std=c11 -Wall -Wextra -pedantic \
main.c personagem.c inventario.c item.c interface.c -o personagens 