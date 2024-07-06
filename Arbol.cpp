#include <iostream>
#include "Arbol.h"
#include "SWAP.H"
#include <math.h>
#include <vector>
#include <bitset>


using namespace std;


void arbolAVL::addPalabra(string x)
{    
        if(x!=""){
        bool aumento;
        aumento=false;
        Insert(x,aumento,raiz);
}
};

int sizeNodos(nodoAVL* nodo){
        if (nodo == NULL){return 0;}
        else{
                return(sizeNodos(nodo->next)+1);
        }
};

void arbolAVL::Insert(string x,bool &aumento, nodoAVL* &A){
        if (A == NULL){
                A = new nodoAVL;
                A->dato = x;
                A->FB = 0;
                A->izq = NULL;
                A->der = NULL;
                aumento = true;
                A->contador = 1;
                if(czo!=NULL){
                        A->next = czo;
                }
                czo = A;
                
        }
        /*
        addLista()
        //acá enlaces al principio de la lista

        */
        else{
                if (x < A->dato){                       
                        Insert(x, aumento, A->izq);                     
                        if (aumento){
                                switch (A->FB){
                                        case -1:{
                                                A->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                        case 0:{
                                                A->FB = 1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                if (A->izq->FB == 1){ //1 necesita LL, si es -1 necesita LR
                                                        rotarLL(A);
                                                }else{
                                                        rotarLRalter(A);
                                                }
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol izquierdo
                else if( x == A->dato){
                    A->contador++;
                }
                else{
                        Insert(x, aumento, A->der);            
                        if (aumento){
                                switch (A->FB){
                                        case -1:{
                                                if (A->der->FB == 1){ //1 necesita RL, si es -1 necesita RR
                                                        rotarRLalter(A);
                                                }else{
                                                        rotarRR(A);
                                                }
                                                aumento = false;                                                
                                                break;
                                        }
                                        case 0:{
                                                A->FB = -1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                A->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol derecho
        }//fin A!=NULL
};


void arbolAVL::ordenarSeleccion(nodoAVL* &A, arbolPosicional* arbol){
    int max;
    int c;
    int size = sizeNodos(A);

    for (int i = 1; i<=size; i++) {
        max =i;
        for (int j = i+1; j<=size; j++) {
                c++;
            
            if (arbol->getDato(j)->contador > arbol->getDato(max)->contador) {
                max = j;
            }
        }
        if (max!=i) {
            //cout<<"se swapea:"<<arbol->getDato(i)->dato<<" con: "<<arbol->getDato(max)->dato<<endl;
            swap(i, max, arbol);
        }
    }
    printf("\n cantidad de comparaciones C= %d ",c);
};

 

void arbolAVL::rotarLL(nodoAVL* &A){ 
        nodoAVL* aux = A->izq->der;
        A->izq->der = A;
        A->izq->FB = 0; 
        nodoAVL* aux2 = A->izq;
        A->izq = aux;
        A->FB = 0;
        A = aux2;
};
void arbolAVL::rotarRR(nodoAVL* &A){ 
        nodoAVL* aux = A->der->izq;
        A->der->izq = A;
        A->der->FB = 0; 
        nodoAVL* aux2 = A->der;
        A->der = aux;
        A->FB = 0;
        A = aux2;
};
 
void arbolAVL::rotarLRalter(nodoAVL* &A){ 
        rotarRR(A->izq);
        rotarLL(A);
};
 
void arbolAVL::rotarRLalter(nodoAVL* &A){ 
        rotarLL(A->der);
        rotarRR(A);
};

void arbolAVL::ird(nodoAVL* &A)
{
    if (A != NULL) {
        ird(A->izq);
        ird(A->der);
    }
};


arbolPosicional::arbolPosicional(nodoAVL* czo){
        int size = sizeNodos(czo);
        int cuenta=0;
        capas = ceil(log2(size));
        vector<nodoPosicional*> pasoAnterior(1, new nodoPosicional);
        raiz = pasoAnterior[0];
        for(int i = 1; i<=capas;i++){
                vector<nodoPosicional*> paso;
                for(int j = 0 ; j<pasoAnterior.size();j++){
                        pasoAnterior[j]->izq= new nodoPosicional;
                        pasoAnterior[j]->der= new nodoPosicional;
                        cuenta+=2;
                        paso.push_back(pasoAnterior[j]->izq);
                        paso.push_back(pasoAnterior[j]->der);
                }
                pasoAnterior = paso;
        }
        bool cont=true;
        nodoAVL* nodo = czo;
        int pos= 1;
        while(cont){
                this->insert(nodo,pos);
                pos++;
                if(nodo->next==NULL){cont=false;}
                else{nodo=nodo->next;}
        };      
};

void arbolPosicional::insert(nodoAVL* dato, int pos){
        if(dato->dato!=""){
        bitset<16> bin = bitset<16>(pos-1);
        nodoPosicional* actual = raiz;
        for(int i = capas-1;i>=0;i--){
                if(bin[i]){actual=actual->der;}
                else{actual=actual->izq;}
        }
        actual->nodo = dato;

        }
};

nodoAVL* arbolPosicional::getDato( int pos){
        bitset<16> bin = bitset<16>(pos-1);
        nodoPosicional* actual = raiz;
        for(int i = capas-1;i>=0;i--){
                if(bin[i]){actual=actual->der;}
                else{actual=actual->izq;}
        }
        return actual->nodo;
};

int partition( int start, int end, arbolPosicional* arbol, int &cc)        
{
    string pivot = arbol->getDato(start)->dato;
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        cc++;
        if (arbol->getDato(i)->dato <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(pivotIndex, start, arbol);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arbol->getDato(i)->dato <= pivot) {
            cc++;
            i++;
        }
        while (arbol->getDato(j)->dato > pivot) {
            cc++;
            j--;
        }
        cc++;
        if (i < pivotIndex && j > pivotIndex) {
            swap(i++, j--,arbol);
        }
    }
 
    return pivotIndex;
};
 
int ordenarQS(int start, int end, arbolPosicional* arbol, int &cc)
{
    if (start >= end)
        return 0;
 
    int p = partition(start, end, arbol, cc);
 
    ordenarQS(start, p - 1, arbol, cc);
 
    ordenarQS(p + 1, end, arbol, cc);


};
