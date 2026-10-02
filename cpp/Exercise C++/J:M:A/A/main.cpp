#include <iostream>
using namespace std;


int affiche_age(int ji, int mi, int ai)
{
    int j=15;
    int m=12;
    int a=2024;
    int age=a-ai;
    
    if( (m==mi && ji>j) || (mi>m && (ji>j || ji<j || ji==j)) )   // (ji==j && mi<m) ||
    {
        age=a-ai-1;
    }
    else if ( (mi=m && ji<j) || (mi<m && (ji<j || ji>j || ji==j)) )    //  (ji==j && mi>m ) ||
    {
        age=a-ai;
    }
    return age;
}


int main()
{
    int ji,age,j=04;
    int mi; int m=01;
    int ai; 
    int a=2024;
    do
    {
        cout<<"votre jour de naissance :\n";
        cin>>ji;
        cout<<"votre mois de naissance :\n";
        cin>>mi;
        cout<<"votre année de naissance :\n";
        cin>>ai;
    }
    while (ji>31 || mi>12 || ai>a);
    
    if (a==ai)
    {
        age =m-mi;
        cout<<"vous avez :"<<age<<"mois\n";
    }
   
    if(ji==j && mi==m)
    {
        cout<<"joyeux anniversaire :\n";
        age=a-ai;
    }
    cout<<"vous avez :" <<affiche_age(ji,mi,ai)<<" ans\n";
    
    return 0;
}




    

  

   
