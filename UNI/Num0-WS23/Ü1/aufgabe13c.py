import numpy as np

def forward(n, dtype):
#Initialisierung von I_0 und I_values als Liste
#Der dtype Parameter legt den output Datentyp fest
    I_0 = np.exp(1, dtype = dtype) - 1    
    I_values = [I_0] 

    #Berechnung der weiteren Glieder der Rekursion
    for k in range (1, n):
        I_k = np.exp(k, dtype = dtype) - k * I_values[-1]    #die -1 greift immer auf das letzte Element zu
        I_values.append(I_k)

    return I_values

#Testen der Funktion mit den gegebenen Werten
n=15

result_float32 = forward(n, dtype = np.float32)
result_float64 = forward(n, dtype = np.float64)
result_float128 = forward(n, dtype = np.float128)

print("Ergebnis für dtype = np.float32", result_float32, "\n")
print("Ergebnis für dtype = np.float64", result_float64, "\n")
print("Ergebnis für dtype = np.float128", result_float128, "\n")



