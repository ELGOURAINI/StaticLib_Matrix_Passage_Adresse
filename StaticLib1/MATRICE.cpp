#include "pch.h"
#include "MATRICE.h"
#include <iostream>
#include "assert.h"

using namespace algebre;
using namespace std;

algebre::Matrice::Matrice(int lg, int col)
{
    this->nbre_lgn = lg;
    this->nbre_col = col;
    tab = new int* [lg];
    for (int j = 0; j < col; j++)
    {
        tab
            [j] = new int[col];
    }

    for (int i = 0; i < lg; i++)
    {
        for (int j = 0; j < col; j++)
        {
            this->tab[i][j] = 0;
        }
    }
}

algebre::Matrice::Matrice(const Matrice* M)
{
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            this->tab[i][j] = M->tab[i][j];
        }
    }
}

void algebre::Matrice::remplissage(int val)
{
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            this->tab[i][j] = val;
        }
    }
}

void algebre::Matrice::remplir()
{
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        cout << "ligne " << i + 1 << endl;
        for (int j = 0; j < this->nbre_col; j++)
        {
            cout << "Matrice[" << i << "][" << j << "] = ";
            cin >> this->tab[i][j];
        }
    }
    cout << endl;
}

Matrice* algebre::Matrice::operator=(const Matrice* M)
{
    assert(M->nbre_lgn == this->nbre_lgn && M->nbre_col == this->nbre_col);
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            this->tab[i][j] = M->tab[i][j];
        }
    }
    return this;
}


Matrice* algebre::Matrice::operator+(const Matrice* M)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
    assert(M->nbre_lgn == this->nbre_lgn && M->nbre_col == this->nbre_col);
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            //cout << M.tab[i][j] << endl;
            M1->tab[i][j] = this->tab[i][j] + M->tab[i][j];
            //cout << M1->tab[i][j] << endl;
        }
    }
    return M1;
}

Matrice* algebre::Matrice::operator-(const Matrice* M)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
    assert(M->nbre_lgn == this->nbre_lgn && M->nbre_col == this->nbre_col);
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            //cout << M.tab[i][j] << endl;
            M1->tab[i][j] = this->tab[i][j] - M->tab[i][j];
            //cout << M1->tab[i][j] << endl;
        }
    }
    return M1;
}

Matrice* algebre::Matrice::operator*(int d)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);

    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            (M1->tab[i][j]) = this->tab[i][j] * d;
        }
    }
    return M1;
}

Matrice* algebre::Matrice::operator*(const Matrice* M)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
    int res;
    assert(M->nbre_lgn == this->nbre_lgn && M->nbre_col == this->nbre_col);
    for (int i = 0; i < this->nbre_lgn; i++)
        for (int j = 0; j < this->nbre_col; j++)
        {
            res = 0;
            for (int k = 0; k < this->nbre_col; k++)
                res += this->tab[i][k] * M->tab[k][j];
            M1->tab[i][j] = res;
        }
    return M1;
}


void algebre::Matrice::print() const
{
    cout << "la matrice est : " << endl;
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            cout << " " << this->tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

algebre::Matrice::~Matrice()
{

    for (int j = 0; j < this->nbre_col; j++)
    {
        delete(tab[j]);
        this->tab[j] = 0;
    }
    delete(tab);
    tab = 0;
}


