import numpy as np

def LR_full_pivot_corrected_v2(A):
    n = len(A)
    p = list(range(n))  # Permutationsvektor für Zeilen
    q = list(range(n))  # Permutationsvektor für Spalten
    A = A.copy()  # Erstellen einer Kopie von A
    L = np.eye(n)  # Initialisierung von L als Einheitsmatrix

    for k in range(n):
        # Vollpivotisierung: Suche nach dem maximalen Element
        i1, i2 = np.unravel_index(np.argmax(np.abs(A[k:, k:])), A[k:, k:].shape)
        i1 += k
        i2 += k

        # Zeilenvertauschung in A und L
        A[[k, i1]] = A[[i1, k]]
        L[[k, i1], :k] = L[[i1, k], :k]  # Vertauschen der Zeilen in L, aber nur bis zur k-ten Spalte
        p[k], p[i1] = p[i1], p[k]

        # Spaltenvertauschung
        A[:, [k, i2]] = A[:, [i2, k]]
        q[k], q[i2] = q[i2], q[k]

        # Gauss-Elimination
        for i in range(k+1, n):
            L[i, k] = A[i, k] / A[k, k]  # Speichern des Multiplikators in L
            for j in range(k+1, n):
                A[i, j] -= L[i, k] * A[k, j]
            A[i, k] = 0  # Setzen der unteren Dreieckselemente auf 0, da sie in L gespeichert sind

    return L, A, p, q

# Testen der erneut korrigierten Funktion mit der Beispielmatrix A
A = np.array([[2, 5, 4],
              [3, 0, 4],
              [1, 4, 2]])

L_corrected_v2, R_corrected_v2, p_corrected_v2, q_corrected_v2 = LR_full_pivot_corrected_v2(A)

print(L_corrected_v2)
print(R_corrected_v2)
print(p_corrected_v2)
print(q_corrected_v2)

