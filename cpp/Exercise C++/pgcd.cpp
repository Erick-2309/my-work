#include<iostream>
using namespace std;


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
    int A;
    if(x<y)
    {
        A=x+1;
    }
    else
        A=y+1;
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
    if(a<b)
    {
        A=a+1;
    }
    else
        A=b+1;
    
    cout<<"le pgcd vaut: "<<pgcd(a,b)<<endl;
    cout<<"le ppcm vaut: "<<(a*b)/pgcd(a,b)<<endl; 
    
    return 0;

}

 //cout<<"saisir la longueur du tableau: elle doit etre > "<<b<<endl;
   // cin>>A;
    

   /* if (a<b)
    {
        A=a+1;
    }
    else
    {
        A=b+1;
    }
    */