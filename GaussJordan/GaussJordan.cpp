#include <iostream>
#include <array>

// A�adir std para f�cil llamado de funciones
using namespace std;

//// Declaraci�n de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz& miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz& miMatriz);

template <typename matriz>
void GaussJordan(matriz& miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz& miMatriz);


int main()
{
    // Definimos el n�mero de variables de nuestro sistema
    const int variables = 3;
    // El n�mero de columnas ser� el n�mero de variables m�s su soluci�n para cada ecuaci�n
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el m�todo de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la soluci�n de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con �xito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ning�n valor.
*/
template <typename matriz>
void LlenarMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ning�n valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la soluci�n para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ning�n valor.
*/

template <typename matriz>
void ImprimirSolucion(matriz& miMatriz)
{
    cout << endl;
    cout << "Soluci\242n:" << endl;
    for (int i = 0; i < 3; i++){
        cout << "x" << i << " = " << miMatriz[i][3] << endl;
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la soluci�n del algoritmo.
No regresa ning�n valor.
*/
template <typename matriz>
void GaussJordan(matriz& miMatriz)
{
    const int n = 3;
    float factor,det;
    int aux = 0;
    det = (miMatriz[0][0] * miMatriz[1][1] * miMatriz[2][2] + miMatriz[0][1] * miMatriz[1][2] * miMatriz[2][0] + miMatriz[0][2] * miMatriz[1][0] * miMatriz[2][1]) - (miMatriz[2][0] * miMatriz[1][1] * miMatriz[0][2] + miMatriz[2][1] * miMatriz[1][2] * miMatriz[0][0] + miMatriz[2][2] * miMatriz[1][0] * miMatriz[0][1]);
    if (det == 0) {
        cout << "Su sistema no tiene soluci\242n" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (miMatriz[i][i] != 0)
            {
                aux = 0;
            }
            else
            {
                aux = 1;
            }
        }
    }
    if (aux = 1)
    {
        array <array<float, 4>, 3> Aux = { 0 };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                Aux[i][j] = miMatriz[i][j];
            }
        }
        for (int j = 0; j < n + 1; j++)
        {
            miMatriz[0][j] = Aux[1][j];
            miMatriz[1][j] = Aux[2][j];
            miMatriz[2][j] = Aux[0][j];
        }
    }
    for (int k = 0; k < n; k++) {
        factor = miMatriz[k][k];
        for (int j = k; j < n + 1; j++) {
            miMatriz[k][j] = miMatriz[k][j] / factor;
        }
        for (int i = 0; i < n; i++) {
            if (i != k) {
                factor = miMatriz[i][k];
                for (int j = 0; j < n + 1; j++) {
                    miMatriz[i][j] = miMatriz[i][j] - factor * miMatriz[k][j];
                }
            }
        }
    }
}