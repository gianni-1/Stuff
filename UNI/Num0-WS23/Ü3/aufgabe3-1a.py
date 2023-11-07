import numpy as np

def forward_substitution(L, b):
    n = len(b)      #Anzahl an elemente b
    y = np.zeros_like(b, dtype=np.double)   #Vektor b nur mit nullen anstelle der Werte
    
    for i in range(n):
        #Sumnme der Produkte aus L und y für die aktuellen bekannten y-Werte
        #berechnet das Skalarprodukt der ersten i-Elemente der i-ten Zeile von L mit den ersten
        #i-Elementen von y
        sum_Ly = np.dot(L[i, :i], y[:i])
        #Berechnung der i-ten Komponente von y
        y[i] = (b[i] - sum_Ly) / L[i, i]
        
    return y

#Beispiel für die Verwendung der Funktion
#L ist eine untere Dreiecksmatrix mit Einsen auf der Diagonale
L = np.array([[1, 0, 0],
              [2, 1, 0],
              [3, 4, 1]])

b= np.array([5, 6, 7])

y = forward_substitution(L, b)
print(y)