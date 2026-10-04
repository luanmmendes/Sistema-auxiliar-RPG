#ifndef INTERFACE_H
#define INTERFACE_H
#include "personagem.h"
#include "item.h"
int menu();
int validaEnumRaca(char* texto);
int validaEnumClasse(char* texto);
int validaEnumItem(char* texto);
int validaEnumEquipadoEm(char* texto);
void limpaBuffer();
void limpaBarra(char* texto);
void listaID(Personagem *p,int quantidade,int ID);
void listaPersonagens(Personagem *p,int quantidade);
void printaEnum(Personagem *p);
void printaRaca(Personagem *p);
void printaClasse(Personagem *p);
void exibeEquipamentosPersonagem(const Personagem *p);
int interfaceInventario();
#endif