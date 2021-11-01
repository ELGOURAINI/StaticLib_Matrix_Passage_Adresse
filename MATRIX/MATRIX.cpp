#include <iostream>
#include "MATRICE.h"
using namespace algebre;
using namespace std;

int main()
{
    //Declaration des matrices
    Matrice M(2, 2);
    Matrice M1(2, 2);

    //Remplissages de matrices
    M.remplissage(3);
    M1.remplissage(2);
    //M->rempir();

    //affichage des matrices
    M.print();
    M1.print();

    //Somme de deux matrices
    cout << "La somme" << endl;
    Matrice *M2 = M + M1;
    M2->print();

    //Soustraction de deux matrices
    cout << "La soustraction" << endl;
    Matrice* M3 = M - M1;
    M3->print();

    //multiplication d'une matrice avect un entier
    cout << "multiplication d'une matrice avect un entier" << endl;
    Matrice *M4 = M * 2;
    M4->print();

    //multiplication de deux matrices
    cout << "multiplication de deux matrices" << endl;
    Matrice* M5 = M * M1;
    M5->print();

}