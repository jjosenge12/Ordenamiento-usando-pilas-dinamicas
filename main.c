#include"main.h"
int main()
{
    FILE *pf;

    crearLoteDePrueba();
    pf=fopen("arch.dat","r+b");
    if(pf==NULL)
    {
        printf("No se pudo abrir archivo");
        return 1;
    }
    switch(ordenarArchivoBin(pf,4,comparaStrings))
    {
    case -1 :
        puts("Error sacando de pila");
        return -1;
    case -2 :
        puts("Error poniendo en pila");
        return -2;
    case -3 :
        puts ("Error viendo tope");
        return -3;
    }
    mostrarArchivo(pf);
    fclose(pf);
    return 0;
}
