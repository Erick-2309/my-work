#include "CScdDgr.h"


int main()
{
    CScdDgr Eq(1,0,-1);
    Eq.Solution();
    Eq.Affiche();
    
    CScdDgr* pEq = new CScdDgr(2,-1,3);
    pEq->Solution();
    pEq->Affiche();
    
    return 0;
}
