/*4. Construya una lista enlazada que almacene tanto números como cadenas
de texto utilizando punteros. Incluya una función de búsqueda de muestre
 un dato almacenado además del tipo de dato que se encuentra almacenado
(int, float, char, ...)*/

#include <iostream>
#include <stdio.h>
using namespace std;

enum Tipo : int { INT, CHAR, PCHAR, DOUBLE, FLOAT};

struct Nodo
{
    void *puntero;
    Tipo tipo;
    Nodo *siguiente;
};

typedef Nodo *pNodo; // alias a puntero de Nodo

pNodo primero = NULL;
pNodo ultimo = NULL;

void insertar_elemento(void *p,Tipo t)
{
    pNodo nuevo = new Nodo;
    nuevo->puntero = p;
    nuevo->tipo = t;
    nuevo->siguiente = NULL;
    if(primero == NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

void imprimir_lista()
{
    pNodo p = primero;
    cout << "[";
    while(p != ultimo)
    {
        switch(p->tipo)
        {
            case INT:
                cout << "int: " << *(int*)(p->puntero) << ", ";
                break;
            case CHAR:
                cout << "char: \'" << *(char*)(p->puntero) << "\', ";
                break;
            case PCHAR:
                cout << "char*: \"" << (char*)(p->puntero) << "\", ";
                break;
            case DOUBLE:
                cout << "double: " << *(double*)(p->puntero) << ", ";
                break;
            case FLOAT:
                cout << "float: " << *(float*)(p->puntero) << "f, ";
        }
        p = p->siguiente;
    }
    if(p != NULL)
    {
        switch(p->tipo)
        {
            case INT:
                cout << "int: " << *(int*)(p->puntero) << "";
                break;
            case CHAR:
                cout << "char: \'" << *(char*)(p->puntero) << "\'";
                break;
            case PCHAR:
                cout << "char*: \"" << (char*)(p->puntero) << "\"";
                break;
            case DOUBLE:
                cout << "double: " << *(double*)(p->puntero) << "";
                break;
            case FLOAT:
                cout << "float: " << *(float*)(p->puntero) << "f";
        }
    }
    cout << "] ";
}

void limpiar_lista()
{
    while(primero != NULL)
    {
        Nodo *borrar = primero;
        primero = primero->siguiente;
        switch(borrar->tipo)
        {
            case INT:
                delete (int*)(borrar->puntero);
                break;
            case CHAR:
                delete (char*)(borrar->puntero);
                break;
            case PCHAR:
                delete [] (char*)(borrar->puntero);
                break;
            case DOUBLE:
                delete (double*)(borrar->puntero);
                break;
            case FLOAT:
                delete (float*)(borrar->puntero);
        }
        delete borrar;
    }
    ultimo = primero;
}

int main()
{
    void *puntero = NULL;
    int opcion = 0;
    while(opcion != 6)
    {
        cout << "MENU" << endl;
        cout << "0 - ingresar un entero (int)" << endl;
        cout << "1 - ingresar un caracter (char)" << endl;
        cout << "2 - ingresar un cadena (char*)" << endl;
        cout << "3 - ingresar un numero flotante largo (double)" << endl;
        cout << "4 - ingresar un numero flotante (float)" << endl;
        cout << "5 - imprimir lista" << endl;
        cout << "6 - salir" << endl;
        cout << "Ingrese opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 0:
                puntero = new int;
                cout << "ingrese un numero entero: "; cin >> *(int*)puntero;
                insertar_elemento(puntero, INT);
                break;
            case 1:
                puntero = new char;
                cout << "ingrese un caracter: "; cin >> *(char*)puntero;
                insertar_elemento(puntero, CHAR);
                break;
            case 2:
                puntero = new char[80];
                cout << "ingrese una cadena: ";
                cin.ignore();
                cin.getline((char*)puntero, 80);
                insertar_elemento(puntero, PCHAR);
                break;
            case 3:
                puntero = new double;
                cout << "ingrese un numero flotante largo: "; cin >> *(double*)puntero;
                insertar_elemento(puntero, DOUBLE);
                break;
            case 4:
                puntero = new float;
                cout << "ingrese un numero flotante: "; cin >> *(float*)puntero;
                insertar_elemento(puntero, FLOAT);
                break;
            case 5:
                cout << endl << "lista: ";
                imprimir_lista();
                cout << endl << endl;
                break;
            case 6:
                break;
            default:
                cout << endl << "opcion no valida" << endl;
        }
    }

    limpiar_lista();
    return 0;

}
