#DS Python GPSE S6
#Ralph Mansour

#Exercice 2
salaires = ['Sal1', 'Sal2', 'Sal3', 'Sal4', 'Sal5']
NbrJours= [100, 20, 45, 55, 200]
PrixJours= [250, 450, 300, 150, 100]

def salaire_NbrJours(salaires,NbrJours):
    res = [ ]   #Résultat temporaire
    for i in range(len(salaires)):
        res.append(salaires[i])
        res.append(NbrJours[i])
    return res


def salaire_NbrJours_Prix(salaires, NbrJours, PrixJours):
    res = [ ]      #Résultat temporaire
    for i in range(len(salaires)):
        res.append(salaires[i])
        res.append(NbrJours[i] * PrixJours[i])
    return res



print(salaire_NbrJours(salaires,NbrJours))
print(salaire_NbrJours_Prix(salaires,NbrJours,PrixJours))
