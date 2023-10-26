import numpy as np
def backward(n, I_30, dtype):
    I_values = [I_30]
    
    #Berechnung der Glieder der Rekursionsfolge rückwärts
    for k in range(30, 30-n, -1):       #Schleife die runter zählt
        I_prev = (np.exp(1, dtype = np.float32) - I_values[-1]) / k
        I_values.append(I_prev)
        
    return I_values
        
#Testen der Funktion mit den gegebenen Werten 
n = 15
results_I_30_1 = backward(n, 1, np.float32)
results_I_30_1000 = backward(n, 1000, np.float32)

print("Ergebnisse für I_30 = 1: ", results_I_30_1, "\n")
print("Ergebnisse für I_30 = 1000: ", results_I_30_1000, "\n")
