#include <iostream>
#include <string>

//Incluir clase Grupo y Molecula
#include "Grupo.h"
#include "Molecula.h"

using namespace std;

// Declaración de funciones
Grupo CrearGrupo(int numGrupo);


int main()
{
    //Pedir al usuario el nombre de la molécula
    string nombreMolecula;
    cout << "Nombre de la molecula: ";
    cin >> nombreMolecula;

    // Crear una instancia de la clase Molécula y pasarle como parámetro al constructor el nombre
    Molecula miMolecula(nombreMolecula);

    // Pedir al usuario el número de grupos que va a tener la molécula (tiene que ser mayor a cero)
    int numGrupos;
    do
    {
        cout << "Numero de grupos: ";
        cin >> numGrupos;
    } while (numGrupos <= 0);

    // Crear el número de grupos indicado por el usuario y agregarlos a la molécula
    for (int i = 0; i < numGrupos; i++)
        miMolecula.AgregarGrupo(CrearGrupo(i)); // Primero se manda a llamar la creación del grupo, y la instancia regresada se le pasa a la molécula

    // Calcular e imprimir el punto isoeléctrico en pantalla
    cout << "El punto isoelectrico de " << nombreMolecula << " es = " << miMolecula.CalcularPuntoIsoelectrico() << endl;

    // Si todo salió bien, regresamos el valor cero
    return 0;
}

// Crea una instancia de la clase Grupo con la información indicada por el usuario
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