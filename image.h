#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED


const int 	DISPLAY = 1, COMPOROUGE = 2, NIVGRIS = 3, NOIRBLANC = 4, LUMIUP = 5,
			LUMIDOWN = 6, CONTRAUP = 7, CONTRADOWN = 8, QUIT = 9;

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

		Image(string filename);                         // constructeur ppm

		vector<int> getPixel(int i, int j) const;       // getPixel

		void display() const;                           // affichage

        vector<vector<int>> getRouge() const;           // getRouge

        vector<vector<int>> getVert() const;            // getVert

        vector<vector<int>> getBleu() const;            // getBleu

        bool comparer(const Image& img) const;          // comparer

		Image composanteRouge() const;                  // composanteRouge

		bool detection(int R, int V, int B) const;      // detection

		Image niveauxGris() const;                      // niveauxGris

		Image noirEtBlanc(int seuil) const;             // noirEtBlanc

		vector<int> histogrammeGris() const;            //histogrammeGris

        Image luminosityUp(float lumi) const;           // luminosityUp

		Image luminosityDown(float lumi) const;         // luminosityDown

		Image constrasteUp(float lumi) const;    // contrasteUp

		Image constrasteDown(float lumi) const;  // contrasteDown

};

void loadPicture(const string &picture, vector<vector<int>> &red,
                                        vector<vector<int>> &green,
                                        vector <vector<int>> &blue);		// loadPicture

bool validChoice(int choice);							// validChoice

string saisieFichier();									// saisieFichier

int menu();											// menu

#endif // IMAGE_H_INCLUDED
