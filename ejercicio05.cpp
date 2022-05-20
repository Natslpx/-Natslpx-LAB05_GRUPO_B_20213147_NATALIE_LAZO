/*
 *
 */

#include <iostream>
using namespace std;

void concatenar(char *cad1, const char *cad2)
{
    int l = 0; // l = longitud de la cad1
    while(cad1[l++] != 0);
    char *temp = new char[l]; // temp para guardar la cad1 temporalmente
    for(int i=0; i != l; i++)
    {
        temp[i] = cad1[i];
    }
    int i = 0, j = 0; // reescribiendo la cad2 + cad1
    while(cad2[i] != 0)
    {
        cad1[i] = cad2[i];
        i++;
    }
    while(temp[j] != 0)
    {
        cad1[i] = temp[j];
        i++;
        j++;
    }
    cad1[i] = 0;
    delete [] temp;
}

int main()
{
    char cadena[80];
    cout << cadena << endl;
    concatenar(cadena, "especial.");
    cout << cadena << endl;
    concatenar(cadena, "texto ");
    cout << cadena << endl;
    concatenar(cadena, "de ");
    cout << cadena << endl;
    concatenar(cadena, "cadena ");
    cout << cadena << endl;
    concatenar(cadena, "de ");
    cout << cadena << endl;
    concatenar(cadena, "concatenación ");
    cout << cadena << endl;

    return 0;
}
