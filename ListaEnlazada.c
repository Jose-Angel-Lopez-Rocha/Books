#include<stdio.h>
#include<stdlib.h>

struct Nodo
{
	int val;
	struct Nodo*sig;
};
struct Nodo*crearNodo(int x)
{
	struct Nodo*nuevoNodo=(struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->val=x;
	nuevoNodo->sig=NULL;
	return nuevoNodo;	
}

void insertarDatoInicio(struct Nodo** cabeza, int x) 
{
    struct Nodo* nuevoNodo = crearNodo(x);
    nuevoNodo->sig = *cabeza;
    *cabeza = nuevoNodo;
}

void insertarDatoFin(struct Nodo**cabeza, int x)
{
	struct Nodo*nuevoNodo=crearNodo(x);
	if(*cabeza==NULL)
	{
		*cabeza=nuevoNodo;
		return;
	}
	struct Nodo*tempo=*cabeza;
	while(tempo->sig!=NULL){
		tempo=tempo->sig;
	}
	tempo->sig=nuevoNodo;
}
void Borrar(struct Nodo** cabeza, int x) {
struct Nodo* tempo = *cabeza;
struct Nodo* prev = NULL;
while (tempo != NULL && tempo->val != x)
	{
        prev = tempo;
        tempo = tempo->sig;
    }
    if (tempo == NULL)
	{
        printf("Numero no encontrado\n");
        return;
    }
    
    if (prev == NULL) 
	{
        *cabeza = tempo->sig;
    }else 
	{
        prev->sig = tempo->sig;
    }
    free(tempo);
}
void imprimirLista(struct Nodo* nodo) 
{
    while (nodo != NULL) {
        printf("%d -> ", nodo->val);
        nodo = nodo->sig;
    }
    printf("NULL\n");
}
struct Nodo*buscarNodo(struct Nodo*nodo,int x)
{
    while (nodo!=NULL)
    if(x==nodo->val)
    {
        return nodo;
    }
    {
    printf("%d->",nodo->val);
    nodo=nodo->sig;
    }
    printf("Nodo no encontrado\n");
    return NULL;
}

int main() 
{
    struct Nodo*cabeza=NULL;
    int opc;
    do{
    printf("Humano ingresa la opcion: \n");
    printf("1) Insertar dato inicio: \n 2) Insertar dato fin: \n 3) Borrar: \n 4) Imprimir lista: \n 5) Buscar nodo:\n 6) Salir\n" );
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
    int x;
    printf("Ingresa el numero:");
    scanf("%d",&x);
    insertarDatoInicio(&cabeza,x);
    break;
    case 2:
    int y;
    printf("Humano ingresa el numero:");
    scanf("%d",&y);
    insertarDatoFin(&cabeza,y);
    break;
    case 3:
    int z;
    printf("Humano ingresa el numero:");
    scanf("%d",&z);
    Borrar(&cabeza,z);
    break;
    case 4:
    imprimirLista(cabeza);
    break;
    case 5:
    int w;
    printf("Ingresa el valor: ");
    scanf("%d",&w);
    buscarNodo(cabeza,w);
    break;
    case 6:
    printf("Adios humano!");
    break;
    default: 
    printf("Opcion invalida ingresala de nuevo");
    }
    } while (opc!=6);
    return 0;
}