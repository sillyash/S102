#include <iostream>
#include <vector>
#include <string>
#include "image.h"

using namespace std;

// constructeur
Image::Image(vector<vector<int>> rouge, vector<vector<int>> vert, vector<vector<int>> bleu)
{
	_rouge = rouge;
	_vert = vert;
	_bleu = bleu;

	if (!(rouge.size() == bleu.size() && bleu.size() == vert.size())) {
		throw invalid_argument("Erreur: les 3 vecteurs 2D n’ont pas les mêmes dimensions.");
	}
	_longueur = rouge.size();
	_largeur = rouge.size();
};

// getPixel()
vector<int> Image::getPixel(int i, int j) const
{
	return vector<int> {_rouge[i][j], _vert[i][j], _bleu[i][j]};
}

// display()
void Image::display() const
{
	cout << "Rouge: " << endl;
	for (int i=0; i<_rouge.size(); i++)
	{
		for (int j=0; j<_rouge[i].size(); j++)
		{
			cout << "\t" << _rouge[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Vert: " << endl;
	for (int i=0; i<_vert.size(); i++)
	{
		for (int j=0; j<_vert[i].size(); j++)
		{
			cout << "\t" << _vert[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Bleu: " << endl;
	for (int i=0; i<_bleu.size(); i++)
	{
		for (int j=0; j<_bleu[i].size(); j++)
		{
			cout << "\t" << _bleu[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}

// composanteRouge()
Image Image::composanteRouge() const
{
	vector<vector<int>> vide(_largeur, vector<int> (_longueur,0));
	return Image(_rouge, vide, vide);
}

// detection()
bool Image::detection(int R, int V, int B) const
{
	for (int i=0; i<_longueur; i++)
	{
		for(int j=0; j<_largeur; j++)
		{
			if (_rouge[i][j]==R && _vert[i][j]==V && _bleu[i][j]==B)
			{
				return true;
			}
		}
	}
	return false;
}

// niveauxGris()
Image Image::niveauxGris() const
{
	vector<vector<int>> gris(_largeur, vector<int> (_longueur));
	for (int i=0; i<_longueur; i++)
	{
		for(int j=0; j<_largeur; j++)
		{
			gris[i][j]=(_rouge[i][j]+_vert[i][j]+_bleu[i][j])/3;
		}
	}
	return Image(gris, gris, gris);
}

// noirEtBlanc
Image Image::noirEtBlanc(int seuil) const
{
    vector<vector<int>> rouge(_largeur, vector<int> (_longueur,0));
    vector<vector<int>> bleu(_largeur, vector<int> (_longueur,0));
    vector<vector<int>> vert(_largeur, vector<int> (_longueur,0));

	for (int i=0; i < _longueur; i++)
	{
		for (int j=0; j < _largeur; j++)
		{
			if(niveauxGris().getPixel(i,j)[0]>seuil)
            {
                rouge[i][j]=0;
                vert[i][j]=0;
                bleu[i][j]=0;
            }
            if(niveauxGris().getPixel(i,j)[0]<seuil)
            {
                rouge[i][j]=255;
                vert[i][j]=255;
                bleu[i][j]=255;
            }
		}
	}
	return Image(rouge,vert,bleu);
}

vector<int> histogrammeGris() const
{
    vector<int>> histoGris = {};
    int nbPix = 0;

    // pour chaque niveau de gris possible
    for (int i=0; i<255; i++) {
        // pour chaque ligne du
        for (int j=0; j<)
    }
}
