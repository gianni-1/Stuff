import numpy as np

def LR_partial_pivot(A):
    A = np.array(A, dtype=float)  
    n = A.shape[0]   
    p = np.arange(n)  # Permutationsvektor

    for k in range(n-1):
        # Pivotisierung: Suche das Maximum im aktuellen Spaltenabschnitt
        max_row = np.argmax(np.abs(A[k:, k])) + k
        # Vertausche die Zeilen in A und im Permutationsvektor
        A[[k, max_row], :] = A[[max_row, k], :]
        p[[k, max_row]] = p[[max_row, k]]

        # Gauss-Elimination
        for i in range(k+1, n):
            if A[k, k] == 0:
                continue  # Vermeide Division durch Null
            A[i, k] /= A[k, k]  # Speichere den Multiplikator in L
            A[i, k+1:] -= A[i, k] * A[k, k+1:]

    return A, p

def extract_LR(LR):
    n = len(LR)
    L = np.zeros((n, n))
    R = np.zeros((n, n))

    for i in range (n):
        L[i, i] = 1 
        for j in range(n):
            if i > j:
                L[i, j] = LR[i, j]
            else : 
                R[i, j] = LR[i, j]
    return L, R

# Beispielmatrix A
A = np.array([[2, 5, 4],
              [3, 0, 4],
              [1, 4, 2]])

# LR-Zerlegung mit Spaltenpivotisierung
LR, p = LR_partial_pivot(A)

#extrahieren L und R
L, R = extract_LR(LR)


# Überprüfen die Ergebnisse
print("LR-Zerlegung mit Spaltenpivotisierung: ")
print(LR)
print("Permutationsvektor:")
print(p)
print(L)
print(R)
