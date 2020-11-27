#include <iostream>
#include <string>

//Incluir clase Grupo y Molecula
#include "Grupo.h"
#include "Molecula.h"

using namespace std;

// Declaraci�n de funciones
Grupo CrearGrupo(int numGrupo);


int main()
{
    //Pedir al usuario el nombre de la mol�cula
    string nombreMolecula;
    cout << "Nombre de la molecula: ";
    cin >> nombreMolecula;

    // Crear una instancia de la clase Mol�cula y pasarle como par�metro al constructor el nombre
    Molecula miMolecula(nombreMolecula);

    // Pedir al usuario el n�mero de grupos que va a tener la mol�cula (tiene que ser mayor a cero)
    int numGrupos;
    do
    {
        cout << "Numero de grupos: ";
        cin >> numGrupos;
    } while (numGrupos <= 0);

    // Crear el n�mero de grupos indicado por el usuario y agregarlos a la mol�cula
    for (int i = 0; i < numGrupos; i++)
        miMolecula.AgregarGrupo(CrearGrupo(i)); // Primero se manda a llamar la creaci�n del grupo, y la instancia regresada se le pasa a la mol�cula

    // Calcular e imprimir el punto isoel�ctrico en pantalla
    cout << "El punto isoelectrico de " << nombreMolecula << " es = " << miMolecula.CalcularPuntoIsoelectrico() << endl;

    // Si todo sali� bien, regresamos el valor cero
    return 0;
}

// Crea una instancia de la clase Grupo con la informaci�n indicada por el usuario
Grupo CrearGrupo(int i)
{
    // Pedir nombre del grupo
    string nombreGrupo;
    float pkGrupo;
    int cargaGrupo;
    cout << "Nombre grupo " << i << ": ";
    cin >> nombreGrupo;

    // Pedir el pk (tiene que ser un valor entre 0 y 14)
    do
    {
        cout << "pK de " << nombreGrupo << ": ";
        cin >> pkGrupo;
    } while (pkGrupo < 0 || pkGrupo > 14);

    // Pedir la carga del grupo
    cout << "Carga de " << nombreGrupo << " a pH mayor a " << pkGrupo << ": ";
    cin >> cargaGrupo;

    // Crear una instancia del grupo con los valores ingresados
    Grupo miGrupo(nombreGrupo, pkGrupo, cargaGrupo);
    return miGrupo; // Regresar la nueva instancia
}