#include<iostream>
using namespace std;

/*int main()
{
    int a,b;
    int resultat;
    
    cout <<"entrez le primier entier"<<endl;
    cin>>a;
    cout<<"entrez le second"<<endl;
    cin>>b;
    resultat =a*b;
    cout<<"resultat: "<<resultat<<endl;
}



int produit_scalaire(int a,int b,int c,int d)
{
    return a*c +b*d;
}

int main()
{
    int x1,y1,x2,y2;
    cout<<"ebtrez les coordonnées des deus points\n";
    cin>>x1>>y1>>x2>>y2;
    cout<<"le produit scalaire vaut: "<<produit_scalaire(x1,y1,x2,y2)<<endl;
    return 0;
}*/



/*
int pgcd(int x,int y)
{
    int reste;
    reste=x%y;
    if (reste==0)
    {
        return y;
    }
    else
    {
        x=y;
        y=reste;
    }
    return 0;
}

int main()
{
    int a,b;
    cout<<"saisir deux valeurs\n";
    cin>>a>>b;
    cout<<"le pgcd vaut: "<<pgcd(a,b)<<endl;
    return 0;
}


int  swap(int& e,int& r)
{
    int t;
    t=e,e=r,r=t;
    return 0;
}

int  main()
{
    int a,b;
    cout<<"saisir deux valeurs\n";
    cin>>a>>b;
    cout<<swap(a,b)<<endl;
    cout<<"a= "<<a<<endl <<"b= "<<b<<endl;
    return 0;
}
*/



int max(int* L,int D)
{
    int maxi=0;
    for(int i=0;i<D;i++)
    {
        if (L[i]>maxi)
        { 
            maxi=L[i];
        }
     
    }
    return maxi;
}

int pgcd(int x,int y)
{
    int A=2;
    int* L;
    L= new int[A];
    for (int i=2;i<=A;i++)
    {
        if((x%i==0) && (y%i==0))
        {
            L[i]=i;
        } 
        else
        {
            L[i]=0;
        }  
    }
    return max(L,A); 
}

int main()
{
    int A;
    int a,b;
    int* L;
    L=new int[A];
    cout<<"saisir deux valeurs\n";
    cin>>a>>b;
    if (a<b)
    {
        A=a+1;
    }
    else
    {
        A=b+1;
    }
    
    //cout<<"saisir la longueur du tableau: elle doit etre > "<<b<<endl;
   // cin>>A;
    /*for (int i=2;i<=A;i++)
    {
        if((a%i==0) && (b%i==0))
        {
            L[i]=i;
        } 
        else
        {
            L[i]=0;
        }  
    }*/
    cout<<"le pgcd vaut: "<<pgcd(a,b)<<endl; //max(L,A)<<endl;
    cout<<"le ppcm vaut: "<<(a*b)/pgcd(a,b)<<endl; //max(L,A)
    return 0;
}

/*
int*  multiple_diviseur(int a,int b)
{
    int* ptab;
    ptab=new int[2];
    ptab[0]=pgcd(a,b);
    ptab[1]=(a*b)/pgcd(a,b);
   // cout<<ptab[1] <<ptab[1];
    return ptab;   //[1],ptab[2];
}

int main()
{
    int a,b;
    cout<<"entrez deux entiers\n";
    cin>>a>>b;
    cout<<multiple_diviseur(a,b)[0]<<endl;
    cout<<multiple_diviseur(a,b)[1]<<endl;
}
*/