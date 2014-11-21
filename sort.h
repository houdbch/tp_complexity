#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/*                sorting functions                     */

// Tri a Bulle
void tri_bulle(int* tab, int taille);
// Tri par insertion
void tri_insertion(int* tab, int taille);
// Tri par selection
void tri_selection(int* tab, int taille);
// Tri rapide
void tri_rapide(int* tab, int taille);
// Tri fusion
void tri_fusion(int* tab, int taille);
// Tri tas
void tri_tas(int* heap, int size);

#endif // SORT_H_INCLUDED
