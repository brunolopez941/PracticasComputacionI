# Comparando algoritmo Gauss Jordan en C++ y en Python (Numpy)
### Bruno Arturo López Pacheco

Se implementó el algoritmo de eliminación Gauss Jordan en C++ y en Python, usando arreglos de python y arreglos de Numpy. 

- Diferencia al inicializar la matriz (Python y Numpy):

La principal diferencia es la facilidad de inicializar la matriz original,
ya que podemos definir la matriz en Numpy usando una matriz en ceros, diciendo el tamaño (nxm) de la matriz.

```
matriz = np.ndarray(shape=(n,m),dtype=np.float)
    for i in range(n):
        for j in range(m):
            matriz[i][j] = float(input(f"Valor de elemento [{i}][{j}]: "))
```
- Diferencia de tamaño de arreglo (C++ y Python)

La diferencia más notable es la capacidad de Python para realizar arreglos de dimensión variable, pues el arreglo del método de C++ tenemos que modificar el código 
para que soporte otro tamaño. Esto se puede simplificar en Python y en Numpy. Creo que se puede arreglar esto en C++ cambiando el tipo de arreglo, pero evidentemente, 
se necesita más trabajo en código para arreglarlo, algo que es muy fácil de solucionar en Python.
```
// Inicializamos la matriz que vamos a ocupar (C++)
    const int variables = 3;
    const int columnas = variables + 1;
    array <array<float, columnas>, variables> miMatriz = { 0 };
```

#### Diferencias de tiempo en los 3 algoritmos:

* Tiempo en C++ : 18 microsegundos
  
* Tiempo en Python: 998.735 microsegundos
  
* Tiempo en Numpy: 998.258 microsegundos
