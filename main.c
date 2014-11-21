#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define TAILLE 233
    printf("Hello world!\n");
    int tab[TAILLE],i;
    for(i=TAILLE-1;i>=0;i--) tab[TAILLE-i-1]= i;
    for(i=0;i<TAILLE;i++) printf("%d ", tab[i]);
    printf("\n");
    //tri_fusion(tab, 0,TAILLE-1);
    //tri_bulle(tab, TAILLE);
    //tri_insertion(tab,TAILLE);
    //tri_insertion(tab,TAILLE);
    tri_tas(tab,TAILLE);
    for(i=0;i<TAILLE;i++) printf("%d ", tab[i]);
    printf("\n");
    return 0;
}
