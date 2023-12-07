#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

class Image {
	private:
		vector<vector<int>> _vert; 
		vector<vector<int>> _bleu;
		vector<vector<int>> _rouge;
		int _longueur; 
		int _largeur;

	public:
		// constructeur (avec valeurs par défaut)
		Image(vector<vector<int>> rouge={{0,0,0,0},{0,0,255,255},{0,255,255,255},{255,255,255,255}}, vector<vector<int>> vert={{0,0,255,255},{0,255,255,255},{255,255,255,0},{255,255,0,0}}, vector<vector<int>> bleu={{255,255,0,0},{255,0,0,0},{0,0,0,0},{0,0,0,0}});

		// getPixel
		vector<int> getPixel(int i, int j) const;
		
		// affichage
		void display() const;

		// composanteRouge
		Image composanteRouge() const;

		// detection
		bool detection(int R, int V, int B) const;

		// niveauxGris
		Image niveauxGris() const;

		// noirEtBlanc
		Image noirEtBlanc(int seuil) const;

		// luminosityUp

		// luminosityDown
		
};

#endif // IMAGE_H_INCLUDED