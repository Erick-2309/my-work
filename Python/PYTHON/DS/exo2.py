
"""
Soit la chaîne suivante : "Paul 12;Élise 18;Pierre 15;Clara 20;Luc 8;Ana 14" 
1) Découpez la chaîne pour obtenir un dictionnaire au format suivant : {'Paul': 12, 'Élise': 18, 
..., 'Ana': 14}. (Utiliser split()) 
2) Calculez et affichez la moyenne des âges à partir des valeurs du dictionnaire. 
3) Affichez chaque entrée sous la forme : "Paul a 12 ans.". 
4) Trouvez et affichez la personne la plus jeune avec son âge. 
5) Écrivez les résultats dans un fichier resultats.txt avec le format : 
Paul : 12 ans   
Élise : 18 ans   
...   
Moyenne : 14.5 ans
"""
# 1) Découpez la chaîne pour obtenir un dictionnaire
chaine = "Paul 12;Élise 18;Pierre 15;Clara 20;Luc 8;Ana 14"
dictionnaire = {}
for element in chaine.split(';'):
    nom, age = element.split()
    dictionnaire[nom] = int(age)


# 2) Calculez et affichez la moyenne des âges   
moyenne = sum(dictionnaire.values()) / len(dictionnaire)
print("Moyenne des âges :", moyenne ,"ans")


# 3) Affichez chaque entrée sous la forme : "Paul a 12 ans."
for nom, age in dictionnaire.items():
    print(f"{nom} a {age} ans.")


# 4) Trouvez et affichez la personne la plus jeune avec son âge
plus_jeune = min(dictionnaire, key=dictionnaire.get)
age_plus_jeune = dictionnaire[plus_jeune]
print(f"La personne la plus jeune est {plus_jeune} avec {age_plus_jeune} ans.")


# 5) Écrivez les résultats dans un fichier resultats.txt    
with open("resultats.txt", "w") as fichier:
    for nom, age in dictionnaire.items():
        fichier.write(f"{nom} : {age} ans\n")
    fichier.write(f"Moyenne : {moyenne:.1f} ans\n")