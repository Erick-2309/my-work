#include<iostream>
using namespace std;
#include<math.h>


double discriminent(int a,int b,int c)
{
    double dis=(b*b)-(4*a*c);
    return dis;
}

int Affiche_racine(int a=1,int b=1,int c=1)
{
    double dis=((b*b)-(4*a*c));
    double X1=((-b-sqrt(dis))/2*a);
    double X2=((-b+sqrt(dis))/2*a);
    double X0=((-b)/2*a);
    double X3=((-b)/2*a);
    double X4=(sqrt(-dis))/(2*a);
   
    if(dis>=0)
    {
        if(dis>0)
        {
            cout<<"la solution est: "<<"Aexp("<<X1<<"x"<<")+Bexp("<<X2<<"x)"<<endl;  
        }
        else 
        {
            cout<<"la solution est: "<<"(Ax+B)exp("<<X0<<"x)"<<endl;    
        }
    }
    else
    {
        cout<<"la solution  est: "<<"exp("<<X3<<"x)(Acos("<<X4<<"x)+Bsin("<<X4<<"x))"<<endl;
    }
    return 0;
}

int main()
{
    int a,b,c;
    //char* ch;
    cout<<"saisir le coef de Y2: \n";
    cin>>a;
    cout<<"saisir le coef de Y1: \n";
    cin>>b;
    cout<<"saisir le coef de Y0: \n";
    cin>>c;
    cout<<Affiche_racine(a,b,c)<<endl;
    return 0;
}



 /*char* ch;
        int N;
        ch = new char[N];

         ch[0]='A';
         ch[1]='B';
         ch[3]='exp';
         ch[4]='x';
         ch[5]='cos';
         ch[6]='sin';*/
