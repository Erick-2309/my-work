#include<iostream>
using namespace std;
#include "CString.hpp"


// Implémentation d'une version de strcpy_s
errno_t strcpy_s(char* chaine, size_t longueur_chaine, const char* src) {
    // Vérifier si la destination et la source sont valides
    if (!chaine || !src)
    {
        return -1;  // Retourner une erreur si une des chaînes est nulle
    }

    size_t longueur_src = strlen(src);

    // Vérifier si la destination a suffisamment de place pour la chaîne source
    if (longueur_src >= longueur_chaine)
    {
        return -1;  // Si pas assez de place, retourner une erreur
    }

    strcpy(chaine, src);  // Si tout va bien, copier la chaîne source
    return 0;  // Succès
}

errno_t strcat_s(char* chaine, size_t longueur_chaine, const char* src) {
    // Vérifier si la destination et la source sont valides
    if (!chaine || !src)
    {
        return -1;  // Retourner une erreur si une des chaînes est nulle
    }

    size_t longueur_src = strlen(src);

    // Vérifier si la destination a suffisamment de place pour la chaîne source
    if (longueur_src >= longueur_chaine)
    {
        return -1;  // Si pas assez de place, retourner une erreur
    }

    strcat(chaine, src);  // Si tout va bien, copier la chaîne source
    return 0;  // Succès
}


 CString::CString()
 :m_N(0),m_str(NULL){}


CString::CString(long N)
  :m_N(N),m_str(NULL)
{
    
    if(m_N>0)
    {
        m_str=new char[m_N];
    }
}

CString::CString(long N,char*chaine)
   :m_N(N),m_str(NULL)
{
    N = strlen(chaine);
    m_str=new char[N+1];
    strcpy_s(m_str, N+1, chaine);
           
}

CString::CString(char*chaine1, char*chaine2)
{
    m_N=strlen(chaine1)+strlen(chaine2);
    m_str=new char[m_N+1];
    strcpy_s(m_str, m_N+1, chaine1);
    strcat_s(m_str, m_N+1, chaine2);
   
}

CString::~CString()
{
    if(m_str!=NULL)
    
           m_N=0;
            delete[]m_str;
        m_str=NULL;
    
    
}



void CString::lire()
{
    char* chaine;
    chaine = new char[100];
    cout<<"saisir votre phrase :";
    cin.getline(chaine,100);
    //delete[] m_str;  // Libérer l'ancienne chaîne m_str
    m_str = new char[strlen(chaine)+1];
    strcpy_s(m_str, strlen(chaine)+1, chaine);
   // delete[] chaine;
    
}

istream& operator>>(istream& cin, CString& ST)
{
    
    ST.lire();
    return cin;
    /*
     int n=0;
    cout<<"entrez le nobre max de caracteres\n";
     cin>>n;
     
     if(ST.m_N!=n)
     {
         if(ST.m_str !=NULL) delete[]ST.m_str;
         ST.m_N=n;
         ST.m_str=new char[ST.m_N+1];
     }
    if(ST.m_str !=NULL)
     {
         cout<<"entrez la chaine de caractère \n";
         cin>>ST.m_str;
     }
     return cin;
     */
   
}


ostream& operator<<(ostream& cout, const CString& ST)
{
    if(ST.m_str != NULL)
    {
        cout<<"la chaine de caractère est: "<<ST.m_str <<endl;
       // cout<<"taille :"<<ST.m_N<<endl;
    }
    
    else
    {
        cout<<"la chaine de caractère est vide\n";
    }
    
    return cout;
}



CString::CString(const CString& ST)
 //:m_N(ST.m_N),m_str(NULL)
{
    m_N=strlen(ST.m_str);
    m_str=new char[m_N+1];
    strcpy_s(m_str, m_N+1, ST.m_str);
}


CString CString :: operator=(const CString& ST)
{
    
    if(this!=&ST)
    {
        delete []m_str;
        m_N=ST.m_N;
        m_str=new char[m_N+1];
    }
        if(m_str!=NULL)
        {
            strcpy_s(m_str,m_N+1,ST.m_str);
        }
    
    
    return *this;
}


CString CString :: operator=(char*chaine)
{
    m_N=strlen(chaine);
    m_str=new char[m_N+1];
    strcpy_s(m_str,m_N+1,chaine);
    return *this;
}


CString CString :: operator+=(const CString& ST)
{
    long newlenght = m_N+ST.m_N;
    char* newstr; //nouvelle de chaine de caractère de longueur la somme des deux
    newstr=new char[newlenght+1];
    strcpy_s(newstr, newlenght+1, m_str);
    //delete []m_str; //liberation de la memoire de l'ancienne chaine
    strcat_s(newstr, newlenght+1, ST.m_str);
    //*this =newstr;
    return CString(newlenght+1,newstr);
    
    /*ou encore plue simplement:
     CString STR(m_str, ST.m_str);
     *this=STR
     return *this; */ //mais dans ce cas il faudrait faire un constructeur qui prend en paramètre deux objet de type char*
    
}

CString CString :: operator+=(char* chaine)
{
    /*long newlenght= m_N + strlen(chaine);
    char* newstr;
    newstr=new char[newlenght+1];
    strcpy_s(newstr, newlenght+1, m_str);
    //delete[]m_str;//onlibère la mémoire de la donnée menbre car elle a déja été ajouté
    strcat_s(newstr, newlenght+1, chaine);
    // *this=newstr;
    // return *this;
    return CString(newlenght+1, newstr);*/
    
     //ou encore plus simplement:
    CString ST(m_str,chaine);
     *this=ST;
     return *this;
     
}


void CString::length(long * L)
{
    *L = strlen(m_str);
}

long CString::taille()
{
    return strlen(m_str);
}


int CString::operator[](int i)
{
    char c = 0;
    for(int i=0;i<m_N;i++)
        c = m_str[i];
    return c;
}


CString CString::operator+(const CString& ST)
{
   // CString C;
    long newlenght = m_N + ST.m_N;
    char * newmot;
    newmot = new char[m_N + ST.m_N+1];
    strcpy_s(newmot, newlenght+1 , m_str);
    //delete[] m_str;
    strcat_s(newmot, newlenght+1 , ST.m_str);
    *this = newmot;
    return *this;
}


CString CString::operator+(char* chaine)
{
    long nouvellelongueur = m_N + strlen(chaine);
    char* nouvellechaine;
    nouvellechaine = new char[nouvellelongueur+1];
    strcpy_s(nouvellechaine, nouvellelongueur+1, m_str);
    //delete[] m_str;
    strcat_s(nouvellechaine , nouvellelongueur+1 , chaine);
    //CString C(nouvellelongueur+1,nouvellechaine);
    *this = nouvellechaine;
    return *this; //return CString(*this)+=chaine;
}


CString CString::scopy (int pos, long lng)
{
    CString chaine(lng);
    chaine.m_N=lng;
    chaine=new char[lng+1];
    for(int i=pos; i<pos+lng+1; i++)
    {
        chaine.m_str[i-pos]=m_str[i];
    }
    chaine.m_str[lng]='\0';
    return chaine;
}


void CString::sdelete (int pos, int lng)
{
    if(lng<0 || pos>=m_N || pos<0)
    {
        cout<<CString(0)<<endl;
    }
    else if (pos+lng>m_N)
    {
        lng=m_N-pos;
    }
    
    CString partie1(pos), partie2(strlen(m_str)-pos-lng);
    partie1=scopy(0,pos);
    partie2=scopy(pos+lng,strlen(m_str));
    *this=partie1+partie2;
    //*this = scopy(0,pos)+scopy(pos+lng+1,strlen(m_str)) ;
 }


void CString::sinsert (CString source, int pos)
{
    CString partie1(pos), partie3(strlen(m_str)-pos), chaine(strlen(m_str)+strlen(source.m_str));
    partie1=scopy(0,pos);
    partie3=scopy(pos,strlen(m_str)-pos);
    chaine=partie1 + source.m_str + partie3;
    *this = chaine;
}


short CString::spos (CString souschaine)
{
    long pos=0;
    char* presence;
    presence=strstr(m_str,souschaine.m_str);//verifie la presence de souschaine dans la chaine principale 
    if(presence!=NULL)
    {
        pos= strlen(m_str)-strlen(souschaine.m_str);
    }
    return pos;
}

