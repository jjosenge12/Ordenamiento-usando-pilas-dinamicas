#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig;
}tNodo;
typedef tNodo* tPila;

void crearPila(tPila *p);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila *p, unsigned cantBytes);
int ponerEnPila(tPila *p, const void* d,unsigned cantBytes);
int verTope(const tPila *p, void *d,unsigned cantBytes);
int sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);

#endif // PILADINAMICA_H_INCLUDED
