#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include "main.h"
#include "pilaDinamica.h"

void crearLoteDePrueba();
int ordenarArchivoBin(FILE *pf,unsigned tam, int(*comparar)(void *arg1, void *arg2));
int actualizarArchivoConPila(FILE *pf,unsigned tam, tPila *pilaOrdenada);
int comparaStrings(void *arg1, void *arg2);
void mostrarArchivo(FILE *pf);
#endif // FUNCIONES_H_INCLUDED
