#include "CScdDgr.hpp"


int main ()
{
    //CSolution*solution;
    CScdDgr Sc(1,5,3);              //automatique
    CScdDgr*pSc=new CScdDgr(1,4,4); //dynamique
    Sc.aff();
    pSc->aff();
    
    CScdDgr S(1,5,3);
    CScdDgr*pS=new CScdDgr(1,5,3);
    pS->aff();
    CScdDgr S1(1,4,4);
    CScdDgr*pS1=new CScdDgr(1,4,4);
    pS1->aff();
    CScdDgr S2(1,3,5);
    CScdDgr*pS2=new CScdDgr(1,3,5);
    pS2->aff();
    
    
    
    return 0;
}
