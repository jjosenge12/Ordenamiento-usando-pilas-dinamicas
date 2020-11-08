#include"funciones.h"
void crearLoteDePrueba()
{
    FILE *pf;
    char vec[][4]= {"BEB","FGH","BDE","FAA","DGJ","FCE","HHI","GFI","JGC","CGE","EAF"};
    int i;

    pf=fopen("arch.dat","wb");
    if(pf==NULL)
    {
        printf("Error creando archivo");
        return;
    }

    for(i=0; i<11; i++)
    {
        fwrite(vec[i],sizeof(vec)/11,1,pf);
    }
    fclose(pf);
}

int ordenarArchivoBin(FILE *pf,unsigned tam, int(*comparar)(void *arg1, void *arg2))
{
    tPila pilaOrdenada,pilaAuxiliar;
    void *regArch = malloc(tam);
    void *regOrd = malloc(tam);

    crearPila(&pilaOrdenada);
    crearPila(&pilaAuxiliar);

    rewind(pf);
    fread(regArch,sizeof(tam),1,pf);
    if(!ponerEnPila(&pilaOrdenada,regArch,tam)) ///pongo el primer registro de pilaOrdenada
        return -2;

    while(!feof(pf))
    {
        fread(regArch,sizeof(tam),1,pf);

        if(!verTope(&pilaOrdenada,regOrd,tam))
            return -3;
        if(comparar(regArch,regOrd)<0 && !pilaVacia(&pilaOrdenada))/*TODO ESTE PROCESO SOLO OCURRE SI RegArch es menor a RegOrd,
                                                                    sino lo pone directamente en la pilaOrdenada*/
        {
            while(comparar(regArch,regOrd)<0 && !pilaVacia(&pilaOrdenada))
            {
                if(!sacarDePila(&pilaOrdenada,regOrd,tam))
                    return -1;
                if(!ponerEnPila(&pilaAuxiliar,regOrd,tam))///saco el registro de pilaOrdenada y lo pongo en pilaAuxiliar
                    return -2;

                if(!pilaVacia(&pilaOrdenada))
                    if(!verTope(&pilaOrdenada,regOrd,tam))
                        return -3;

            }
            ponerEnPila(&pilaOrdenada,regArch,tam);

            while(!pilaVacia(&pilaAuxiliar))///Vacio toda la pila auxiliar sacando sus elementos y poniendolos en pila ordenada
            {
                if(!sacarDePila(&pilaAuxiliar,regOrd,tam))
                    return -1;
                if(!ponerEnPila(&pilaOrdenada,regOrd,tam))
                    return -2;
            }
        }
        else ///Si no es menor lo pongo en la pila
            if(!ponerEnPila(&pilaOrdenada,regArch,tam))
                return -2;

    }
    actualizarArchivoConPila(pf,tam,&pilaOrdenada);
    return 1;
}

int actualizarArchivoConPila(FILE *pf,unsigned tam,tPila *pilaOrdenada)
{
    void *aux = malloc(tam);

    rewind(pf);
    fseek(pf,0L,SEEK_CUR);
    while(!pilaVacia(pilaOrdenada))
    {
        if(!sacarDePila(pilaOrdenada,aux,tam))
            return -1;
        fwrite(aux,tam,1,pf);
    }
    return 1;
}

int comparaStrings(void *arg1, void *arg2)
{
    return strcmp((char*)arg1,(char*)arg2);
}

void mostrarArchivo(FILE *pf)
{
    char aux[4];

    rewind(pf);
    fread(&aux,sizeof(aux),1,pf);
    while(!feof(pf))
    {
        printf("%s\t",aux);
        fread(&aux,sizeof(aux),1,pf);
    }
}
