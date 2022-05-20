/* Asignar valores a dos variables enteras.
 * Intercambie estos valores almacenados usando solo punteros a enteros
 */
#include <iostream>
using namespace std;

void intercambiar(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int val1, val2;
    cout << "val1? "; cin >> val1;
    cout << "val2? "; cin >> val2;
    intercambiar(&val1, &val2);
    cout << "Después del intercambio:" << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;
    return 0;
}
