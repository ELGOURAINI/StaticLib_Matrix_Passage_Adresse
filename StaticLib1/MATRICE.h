#pragma once
namespace algebre
{
	class Matrice
	{
		//les attributs
	private:
		int nbre_lgn;
		int nbre_col;
		int** tab;

		//les methodes
	public:
		//constructeurs
		Matrice(int lg, int col);
		Matrice(const Matrice* M);
		//arreter le passage par valeur
		Matrice(const Matrice&) = delete;
		Matrice& operator=(const Matrice& M) = delete;
		void remplissage(int val);
		void remplir();
		Matrice* operator=(const Matrice* M);
		Matrice* operator+(const Matrice* M);
		Matrice* operator-(const Matrice* M);
		Matrice* operator*(int d);
		Matrice* operator*(const Matrice* M);
		void print() const;
		~Matrice();
	};
}
