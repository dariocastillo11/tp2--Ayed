#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cctype>
#include "Arbol.h"
#include "SWAP.H"
#include "lista.h"


using namespace std;    


int main (int argc, char *argv[])
{
    std::ifstream file("input.txt");
    char ch;

    arbolAVL* arbol = new arbolAVL;

    if (!file.is_open()) {
        std::cerr << "Error abriendo archivo" << std::endl;
        return EXIT_SUCCESS;
    }
    //add palabras separadas por los chars testeados
    string palabra;
    while (file.get(ch)) {
        ch = tolower(ch);
        if (ch == ' ' || ch == '.' || ch == ',' || ch == ';' || ch == ':' || ch == '?' || ch == '!' || ch == '\n') {
    if (palabra.size() != 0) {
        arbol->addPalabra(palabra);
        palabra = "";
    }
    } else {
        palabra += ch;
    }
    }
    //add ultima palabra
    if(palabra!=""){arbol->addPalabra(palabra);}
    


    //convertir orden del arbol en una lista para hacer print
    Lista<string>* primerPaso = arbol->irdLista();
    cout<<"lista alfabetica: "<<endl<<primerPaso->toPrint("")<<endl;
    

    //arbol posicional binario semi-completo
    arbolPosicional* arbolPos = new arbolPosicional(arbol->czo);
    cout<<"arbol posicional creado"<<endl;


    cout<<"ordenando por seleccion: "<<endl;
    arbol->ordenarSeleccion(arbol->czo,arbolPos);
    Lista<string>* segundoPaso = new Lista<string>;
    

    //convertir orden del arbol en una lista para hacer print
    bool cont = true;
    nodoAVL* actual = arbol->czo;
    while(cont){
        segundoPaso->add(actual->dato+"("+to_string(actual->contador)+")");
        actual=actual->next;
        if(actual==NULL){cont= false;}
    }
    cout<<"lista por cantidad: "<<endl<<segundoPaso->toPrint("")<<endl;



    cout<<endl<<"ordenando con quicksort"<<endl;
    int comparaciones = 0; 
    ordenarQS(1,sizeNodos(arbol->czo),arbolPos,comparaciones);
    cout<<"cantidad de comparaciones QS: "<<comparaciones<<endl;

    //convertir orden del arbol en una lista para hacer print
    Lista<string>* tercerPaso = new Lista<string>;
    cont = true;
    actual = arbol->czo;
    while(cont){
        tercerPaso->add(actual->dato);
        actual=actual->next;
        if(actual==NULL){cont= false;}
    }
    cout<<"lista alfabetica: "<<endl<<tercerPaso->toPrint("");

    //testear si primer y tercer paso son iguales
    if(tercerPaso->toPrint("")==primerPaso->toPrint("")){cout<<endl<<"PRIMER PASO Y TERCER PASO SON IGUALES";}
    else{cout<<endl<<"PRIMER PASO Y TERCER PASO SON DIFERENTES";}



    file.close(); 
   return EXIT_SUCCESS;
};