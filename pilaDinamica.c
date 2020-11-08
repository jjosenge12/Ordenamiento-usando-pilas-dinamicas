#include "pilaDinamica.h"

void crearPila(tPila *p)
{
    *p=NULL;
}
int pilaVacia(const tPila *p)
{
    return *p==NULL;
}
int pilaLlena(const tPila *p, unsigned cantBytes)
{
    void *pNodo=malloc(sizeof(tNodo));
    void *pNodoInfo=malloc(cantBytes);

    free(pNodo);
    free(pNodoInfo);

    return pNodo==NULL || pNodoInfo==NULL;
}
int ponerEnPila(tPila *p, const void* d,unsigned cantBytes)
{
    tNodo *pNodo;

    pNodo=(tNodo*)malloc(sizeof(tNodo));
    if(pNodo==NULL)
        return 0;
    pNodo->info=malloc(cantBytes);
    if(pNodo->info==NULL)
    {
        free(pNodo);
        return 0;
    }
    memcpy(pNodo->info,d,cantBytes);
    pNodo->tamInfo=cantBytes;

    pNodo->sig=*p;
    *p=pNodo;
    return 1;
}
int verTope(const tPila *p, void *d,unsigned cantBytes)
{
    tNodo *aux=*p;

    if(aux==NULL)
        return 0;

    memcpy(d,aux->info,aux->tamInfo<cantBytes?aux->tamInfo:cantBytes);

    return 1;
}
int sacarDePila(tPila *p, void *d, unsigned cantBytes)
{
    tNodo *aux=*p;

    if(aux==NULL)
        return 0;

    memcpy(d,aux->info,aux->tamInfo<cantBytes?aux->tamInfo:cantBytes);
    *p=aux->sig;

    free(aux->info);
    free(aux);

    return 1;
}
void vaciarPila(tPila *p)
{
    tNodo *aux=*p;
    while(aux!=NULL)
    {
        *p=aux->sig;
        free(aux->info);
        free(aux);
        aux=*p;
    }
}
