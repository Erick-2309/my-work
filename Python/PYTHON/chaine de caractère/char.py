"""
exercice
Écrivez un programme qui détermine si une chaîne contient ou non le caractère «e».
"""

def chaine(str):
     A=False
     if("e" in str):
          print("le  caractère e est present ")
          return True
           
     else:
          print("le  caractère e n'est pas present ")
          return False
chaine("chain")



"""
Exercice 2
Écrivez un programme qui compte le nombre d’occurrences du caractère « e » dans une chaîne.
"""

def compte(str):
     A=0
    # for i in len(str):
     for char in str:
          if(char=="e"):
              A=A+1
     print("le caractère e apparet ",A,"fois")
         
compte("chaineee")

"""
Exercice 3
Écrivez un programme qui recopie une chaîne (dans une nouvelle variable), en insérant des astérisques entre les caractères.
Exemple : « toto » devra devenir . « t*o*t*o »

"""
def reecrit(text):
     lc = len(text)   
     i = 1           
     nch = text[0]      # nouvelle chaîne à construire (contient déjà le premier car.)
     while i < lc:
       nch = nch + "*" + text[i]
       i = i + 1
     print (nch)
 
reecrit("toto")

"""
Exercice 4
Écrivez un programme qui inverse une chaîne (dans une nouvelle variable). Exemple : « burgos » devient « sogrub »

"""
def inverse(text):
     l=len(text)
     new_ch=""
     i=l-1
     while i >= 0:          
           new_ch=new_ch+text[i]
           i=i-1
     print(new_ch)
inverse("retour")

"""
Exercice 5
Écrivez un programme qui détermine si une chaîne de caractères est un palindrome (une chaîne qui se lit indifféremment des deux côtés).
Exemple : « radar », « rotor »
"""

def palindrome(text):
     P=1
     i=0
     L=len(text)
     while i<L :
          if(text[i]!=text[L-i-1]):
               P=0
               break
          i=i+1
     if(P == 1):
          print(text,"est un palindrome")
     else:
          print(text,"n'est pas un palindrome")
palindrome("raadaar")