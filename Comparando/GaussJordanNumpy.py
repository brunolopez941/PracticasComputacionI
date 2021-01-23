import numpy as np
import time

def determinante1(A):
    deter1 = (A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1]) - (A[2][0] * A[1][1] * A[0][2] + A[2][1] * A[1][2] * A[0][0] + A[2][2] * A[1][0] * A[0][1]);
    return deter1

def determinante2(A):
    deter2=A[0][0]*A[1][1]-A[0][1]*A[1][0]
    return deter2
    
def tieneSolucion(A):
    if (len(A)==2):
        det = determinante2(A)
    elif(len(A)==3):
        det = determinante1(A)
    else:
        det = 1
    if (det!=0):
        return True
    else:
        return False

def GaussJordan(A):
    for i in range(len(A)):
        for j in range(len(A)):
            if (A[i][i]!=0):
                aux = 0
            else:
                aux = 1
        if (aux==1):
            Aux = [0]
            for i in range(len(A)):
                for j in range(len(A)+1):
                    Aux[i][j]=A[i][j]
            for i in range(len(A)+1):
                for j in range(len(A)+1):
                    A[i][j]=Aux[i+1][j]
        for k in range(len(A)):
            factor = A[k][k]
            j = k
            for j in range(len(A)+1):
                A[k][j]=A[k][j]/factor
            for i in range(len(A)):
                if (i!=k):
                    factor = A[i][k]
                    for j in range(len(A)+1):
                        A[i][j]=A[i][j]-factor*A[k][j]

def solucion(matriz):
    print("Solución: ")
    for i in range(len(matriz)):
        print("x",i," = ",matriz[i][-1])

def llenarMatriz(n):
    m = n + 1
    matriz = np.ndarray(shape=(n,m),dtype=np.float)
    for i in range(n):
        for j in range(m):
            matriz[i][j] = float(input(f"Valor de elemento [{i}][{j}]: "))
    return matriz

n = int(input("Número de ecuaciones: "))
print("")
A = llenarMatriz(n)
inicio = time.time()
if(tieneSolucion(A)==True):
    GaussJordan(A)
    fin = time.time()
    print("")
    solucion(A)
    print("Tiempo de ejecución: ", (fin-inicio)*1000000,"micro segundos")
else:
    print("")
    print("El sistema no tiene solución")