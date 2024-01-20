#include <string>
#include <vector>
#include <cmath>
#include "filtre.h"

using namespace std;

// constructeur
Filtre::Filtre(vector<vector<float>> action, int rayon){
	_action = action;
	// si le rayon et la taille de la matrice ne
	// correspondent pas, corriger le rayon
	if (action.size() != (rayon * 2 + 1)) {
		_rayon = action.size() - 1 / 2;
	}
	else _rayon = rayon;
};

// application
Image Filtre::application(const Image& img) const {
	int longueur = img.getLength();
	int largeur = img.getWidth();

	// initialisaton des vecteurs RVB nuls
	vector<vector<int>> rouge(longueur, vector<int>(largeur, 0));
	vector<vector<int>> vert(longueur, vector<int>(largeur, 0));
	vector<vector<int>> bleu(longueur, vector<int>(largeur, 0));

	// initialisation des valeurs pour le parcours de l'image
	vector<int> pix;
	vector<float> somme(3,0);

	// parcours de la longueur
	for (int i=0; i < longueur; i++) {
		// parcours de la largeur
		for (int j=0; j < largeur; j++) {
			// parcours autour du pixel "racine"
			// en longueur
			for (int k = -_rayon; k <= _rayon; k++) {
				// en largeur
				for (int z = -_rayon; z <= _rayon; z++) {
					// si la case est dans l'image
					if (i+k >= 0 && i+k < longueur && j+z >= 0 && j+z < largeur) {
						pix = img.getPixel(i+k, j+z);
						somme[0] += _action.at(k+_rayon).at(z+_rayon) * float(pix[0]);	// R
						somme[1] += _action.at(k+_rayon).at(z+_rayon) * float(pix[1]);	// V
						somme[2] += _action.at(k+_rayon).at(z+_rayon) * float(pix[2]);	// B
					}
				}
			}
			rouge[i][j] = ceil(somme[0]);		// R
			vert[i][j] = ceil(somme[1]);		// V
			bleu[i][j] = ceil(somme[2]);		// B
			somme = {0,0,0};
		}
	}
	return Image(rouge, vert, bleu);
}
