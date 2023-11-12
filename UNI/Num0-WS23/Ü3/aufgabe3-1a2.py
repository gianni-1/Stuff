import numpy as np

def backward_substitution(R, y):
    n = len(y)
    x = np.zeros_like(y)

    for i in range(n-1, -1, -1):      #Schleife für die xi Werte die von hinten nach vorne berechnet werden 
        if R[i, i] == 0:              #Determinante gleich null
            raise ValueError("Die Matrix R ist singulär. ")
        x[i] = y[i]
        for j in range(i+1, n):       #Schleife um die Rij mal xj von y abzuziehen
            x[i] -= R[i, j] * x[j]
        x[i] = x[i] / R[i, i]
    return x 

#Test der Funktionen 
R = np.array([[2, 3],
              [0, 1]], dtype=float)

y = np.array([5,2], dtype= float)

#Erwartete Lösung [-0,5, 2]

#Berechnete Lösung 
x_calculated = backward_substitution(R, y)
print(x_calculated)