/* 2. Cree dos vectores con valores flotantes y asígnele valores aleatorios,
para esto deberá de asignar memoria a cada vector. Calcule el producto punto
de vectores y muestre por pantalla. Una vez finalizado este proceso, retire
la memoria asignada a los punteros. Repita este proceso de asignación y
retiro de memoria dentro de un for de 1 000 000 veces. */

#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

const int INTmin = 2; // valores para la dimension del vector
const int INTmax = 5;

const int DOUBLEmin = -10; // valores para los flotantes aleatorios
const int DOUBLEmax = 10;

const int NREP = 1000000; // numero de repeticiones
//const int NREP = 10; // numero de repeticiones

int main()
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> random_double(DOUBLEmin, DOUBLEmax);
    srand(time(NULL));

    double *vector1 = NULL, *vector2 = NULL, producto;
    cout << setprecision(3) ; // numero de decimales
    for(int i = 0; i != NREP; i++)
    {
        int dim = INTmin + rand() % (INTmax - INTmin + 1); // dimension del vector
        vector1 = new double[dim];
        vector2 = new double[dim];
        for(int j = 0; j != dim; j++) // generacion del vector
        {
            vector1[j] = random_double(eng);
            vector2[j] = random_double(eng);
        }
        producto = 0; // producto punto
        for(int j = 0; j != dim; j++)
        {
            producto += vector1[j] * vector2[j];
        }
        cout << i+1 << ": [" ; // salida por pantalla
        for(int j = 0; j != dim - 1; j++)
        {
            cout << vector1[j] << "," ;
        }
        cout << vector1[dim-1] << "].[";
        for(int j = 0; j != dim - 1; j++)
        {
            cout << vector2[j] << "," ;
        }
        cout << vector2[dim-1] << "] = " << producto << endl;
        delete [] vector1;
        delete [] vector2;
        vector1 = NULL;
        vector2 = NULL;
    }
    return 0;
}
