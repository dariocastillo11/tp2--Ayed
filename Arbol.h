#ifndef Arbol
#define Arbol
#include "lista.h"
#include "lista.h"

using namespace std;

class nodoAVL;
class arbolAVL;
class nodoPosicional;
class arbolPosicional;

class nodoAVL {
public:
       nodoAVL(){
            dato = "";
            contador = 0; 
            FB= 0;
            izq = NULL;
            der = NULL;
            next = NULL;
            };
       string dato;
       int contador;
       int FB; 
       nodoAVL *izq, *der;
       nodoAVL *next;
};

int sizeNodos (nodoAVL* nodo);

class arbolAVL {
    void Insert(string x, bool &aumento, nodoAVL* &A);
    void rotarLL(nodoAVL* &A);
    void rotarRR(nodoAVL* &A);
    void rotarLRalter(nodoAVL* &A);
    void rotarRLalter(nodoAVL* &A);
    Lista<string>* irdLista(nodoAVL* &A, Lista<string>* l){
        if(A!=NULL){
            irdLista(A->izq,l);
            l->add(A->dato);
            irdLista(A->der,l);
        return l;
        }
    };
    void ird(nodoAVL* &A);
    
public:
    nodoAVL* raiz;
    nodoAVL* czo;
    arbolAVL(){raiz=NULL;czo=NULL;};
    ~arbolAVL(){};
    Lista<string>* irdLista(){return irdLista(raiz,new Lista<string>());};
    void ordenarSeleccion(nodoAVL* &A, arbolPosicional* arbol);
    void addPalabra(string x);
    int size (){sizeNodos(raiz);};
    
};


class nodoPosicional {
public:
       nodoPosicional(){};
       int posicion;
       nodoAVL *nodo = NULL;
       nodoPosicional *izq, *der;
};

class arbolPosicional {
    int capas;
    nodoPosicional* raiz;
    void insert(nodoAVL* dato, int pos);
    
public:
    arbolPosicional(nodoAVL* raiz);
    ~arbolPosicional(){};
    nodoAVL* getDato(int i);
   
};
int ordenarQS(int primero, int ultimo, arbolPosicional* arbol, int &comparaciones);

#endif