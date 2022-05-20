/*6. Utilizando punteros a funciones, implemente las funciones:
a. void sumar (int a, int b);
b. void restar (int a, int b);
c. void multiplicar (int a, int b);
d. void dividir (int a, int b);
Cree un vector de punteros a funciones e implemente un programa que
permita la invocación de cada función, pero a través del puntero.*/

#include <iostream>
#include <vector>
using namespace std;

void sumar(int a, int b)
{
    cout << a << " + " << b << " = " << a+b << endl;
}

void restar(int a, int b)
{
    cout << a << " - " << b << " = " << a-b << endl;
}

void multiplicar(int a, int b)
{
    cout << a << " * " << b << " = " << a*b << endl;
}

void dividir(int a, int b)
{
    cout << a << " / " << b << " = " << a/b << endl;
}

int main()
{
    vector<void (*)(int, int)> funciones = {sumar, restar, multiplicar, dividir};
    int a, b;

    cout << "a.Escriba un número: "; cin >> a;
    cout << "b.Escriba un número: "; cin >> b;

    for(auto i = 0; i < funciones.size(); i++)
    {
        (*funciones[i])(a, b);
    }
    return 0;
}
