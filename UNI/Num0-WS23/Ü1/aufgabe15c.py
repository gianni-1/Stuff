import numpy as np

#erstellen die Matrix A

A = np.array([[1,2], [-1,0.5]])    # einzelne repräsentieren Zeilen 


#die Ergebnisse speichern wie nun in eigenen Variablen 
p1norm = np.linalg.norm(A, 1)
pinfinitynorm = np.linalg.norm(A, np.inf)

#Wir geben die Ergebnisse aus 
print("Die p = 1 Norm der Matrix A: ", p1norm)
print("Die p = infinity Norm der Matrix A: ", pinfinitynorm)
