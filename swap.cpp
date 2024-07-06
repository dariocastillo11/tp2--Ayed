#include "SWAP.H"
#include "Arbol.h"

//swap por datos

void swap(int a,int b, arbolPosicional* arbol){
     nodoAVL* an = arbol->getDato(a);
     nodoAVL* bn = arbol->getDato(b);

     string w = bn->dato;
     int wcont = bn->contador;

     bn->dato=an->dato;
     bn->contador=an->contador;

     an->dato=w;
     an->contador=wcont;

};

//swap por punteros
/*
void swap(int a,int b, arbolPosicional* arbol){

     nodoAVL* an = arbol->getDato(a);
     nodoAVL* bn = arbol->getDato(b);
     nodoAVL w = *bn;

     bn->next=an->next;
     if(b-1>1){
     arbol->getDato(b-1)->next=an;
     }

     an->next= w.next;
     if(a-1>1){
     arbol->getDato(a-1)->next=bn;
     }


}
*/