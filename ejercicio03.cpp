/* 3. Construya una lista enlazada simple utilizando solo punteros. Añada
las funciones de insertar y eliminar un elemento. En la función insertar
se debe asegurar que los números insertados estén en orden creciente.
Simule el proceso con 10000 números aleatorios sin que el programa falle.
 */

#include <iostream>
#include <random>
using namespace std;

const int NREP = 10000;
//const int NREP = 10;

struct Nodo
{
    int elemento;
    Nodo *siguiente;
};

Nodo *raiz = NULL; // raiz de la lista enlazada, ambito global

void insertar_elemento(int e)
{
    Nodo *nuevo = new Nodo;
    nuevo->elemento = e;
    nuevo->siguiente = NULL;
    if(raiz == NULL)
    {
        raiz = nuevo;
    }
    else if(nuevo->elemento <= raiz->elemento)
    {
        nuevo->siguiente = raiz;
        raiz = nuevo;
    }
    else
    {
        Nodo *p = raiz;
        while(p->siguiente != NULL)
        {
            if(nuevo->elemento <= p->siguiente->elemento)
            {
                break;
            }
            p = p->siguiente;
        }
        nuevo->siguiente = p->siguiente;
        p->siguiente = nuevo;
    }
}

void eliminar_elemento(int e)
{
    if(raiz == NULL)
    {
        cout << "lista vacia, nada para eliminar" << endl;
    }
    else if(e == raiz->elemento)
    {
        Nodo *borrar = raiz;
        raiz = raiz->siguiente;
        delete borrar;
    }
    else
    {
        Nodo *p = raiz;
        while(p->siguiente != NULL)
        {
            if(e == p->siguiente->elemento)
            {
                Nodo *borrar = p->siguiente;
                p->siguiente = borrar->siguiente;
                delete borrar;
                break;
            }
            p = p->siguiente;
        }
        if(p != NULL)
        {
            cout << "el elemento no esta en la lista" << endl;
        }
    }
}

void imprimir_lista()
{
    Nodo *p = raiz;
    cout << "[";
    while(raiz != NULL && p->siguiente != NULL)
    {
        cout << p->elemento << ", ";
        p = p->siguiente;
    }
    if(p != NULL)
    {
        cout << p->elemento;
    }
    cout << "] ";
}

void limpiar_lista()
{
    while(raiz != NULL)
    {
        Nodo *borrar = raiz;
        raiz = raiz->siguiente;
        delete borrar;
    }
}

int main()
{
    srand(time(NULL));
    cout << "inserciones: " << endl;
    for(int i = 0; i != 20; i++)
    {
        int e = rand() % 20;
        insertar_elemento(e);
        cout << e << ": ";
        imprimir_lista();
        cout << endl;
    }
    cout << "eliminaciones: " << endl;
    for(int i = 0; i != 10; i++)
    {
        int e = rand() % 20;
        eliminar_elemento(e);
        cout << e << ": ";
        imprimir_lista();
        cout << endl;
    }

    limpiar_lista();
    cout << "\nlista inicial" << endl;
    imprimir_lista();
    for(int i = 0; i != NREP; i++)
    {
        insertar_elemento(rand()%100000);
    }
    cout << "\nlista final" << endl;
    imprimir_lista();
    cout << endl;

    limpiar_lista();
    return 0;

}
