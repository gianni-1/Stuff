import numpy as np

def LR(A):
    n = A.shape[0] #shape gibt ein Tupel für die Dimension wieder 
                   #mit 0 indexen wir die Anzahl der Reihen 
    L = np.eye(n)  #Erstellen eine Einheitsmatrix für L 
    R = A.copy()   #Koopieren von A nach R für die Zerlegung 

    for i in range(n):
        for j in range(i+1, n):
            L[j, i] = R[j, i] / R[i, i] #Berechnen des Multiplikators
            R[j, i:] = R[j, i:] - L[j, i] * R[i, i:] #Aktualisiern die Werte von R
     
    # Setzen der unteren Dreieckselemente von R auf 0 
    for i in range(1, n):
        for j in range(i):
            R[i, j] = 0.0

    return L, R

#Testen der Funktion 
A = np.array([[4, 3],
              [6, 3]], dtype=float)
L, R = LR(A)
print("L:\n", L)
print("R:\n", R)

#Überprüfen, ob LR tatsächlich A ergibt
print("L*R:\n", np.dot(L, R))