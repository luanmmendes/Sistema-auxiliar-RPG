#ifndef INTERFACE_H
#define INTERFACE_H
#include "personagem.h"
int menu();
int validaEnumRaca();
int validaEnumClasse();
void limpaBuffer();
void limpaBarra(char* texto);
void listaID(Personagem *p,int ID);
void listaPersonagens(Personagem *p,int quantidade);
void printaEnum(Personagem *p);
void printaRaca(Personagem *p);
#endif