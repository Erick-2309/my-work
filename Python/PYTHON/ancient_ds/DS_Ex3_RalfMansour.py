#DS Python GPSE S6
#Ralph Mansour

#Exercice 3
Prenom=['Jean-Michel', 'Marc', 'Vanessa', 'Anne', 'Maximilien', 'Alexandre', 'Louise']
Nom=['Dupontville', 'Cit', 'Renardin', 'Lee', 'Milie', 'Benoît', 'Vaur']


def trier_noms(prenoms,noms):
    res = [ ]      #Résultat temporaire
    for i in range(len(prenoms)):
        res.append((prenoms[i], noms[i]))
    
    res.sort(key=lambda x: len(x[1]))
    
    prenoms_tries = [t[0] for t in res]
    noms_tries = [t[1] for t in res]
    
    return prenoms_tries, noms_tries


def Affiche(prenoms, noms, positions):
    for i in range(len(prenoms)):
        print(f"{prenoms[i]} {noms[i]}, position : {positions[i]}")



Prenom_tries, Nom_tries = trier_noms(Prenom, Nom)
positions = [Nom_tries.index(nom) + 1 for nom in Nom]

print(Affiche(Prenom_tries, Nom_tries, positions))