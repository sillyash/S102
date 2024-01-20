#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

const vector<vector<int>> ROUGE = {
	{0,	  0,   0, 	0  },
	{0,   0,   255, 255},
	{0,   255, 255, 255},
	{255, 255, 255, 255}
};

const vector<vector<int>> VERT = {
	{0,   0,   255, 255},
	{0,   255, 255, 255},
	{255, 255, 255, 0  },
	{255, 255, 0,   0  }
};

const vector<vector<int>> BLEU = {
	{255, 255, 0,   0  },
	{255, 0,   0,   0  },
	{0,   0,   0,   0  },
	{0,   0,   0,   0  }
};

class Image {
private:
  vector<vector<int>> _vert;
  vector<vector<int>> _bleu;
  vector<vector<int>> _rouge;
  int _longueur;
  int _largeur;

public:
  // constructeur (avec valeurs par défaut)
  Image(vector<vector<int>> rouge = ROUGE,
		vector<vector<int>> vert = VERT,
        vector<vector<int>> bleu = BLEU);

  Image(string filename); // constructeur ppm

  vector<int> getPixel(int i, int j) const; // getPixel

  void display() const; // affichage

  vector<vector<int>> getRouge() const; // getRouge

  vector<vector<int>> getVert() const; // getVert

  vector<vector<int>> getBleu() const; // getBleu

  int getWidth() const { return _largeur; }; // getWidth

  int getLength() const { return _longueur; }; // getLength

  bool comparer(const Image &img) const; // comparer

  Image composanteRouge() const; // composanteRouge

  bool detection(int R, int V, int B) const; // detection

  Image niveauxGris() const; // niveauxGris

  Image noirEtBlanc(int seuil) const; // noirEtBlanc

  vector<int> histogrammeGris() const; // histogrammeGris

  Image luminosityUp(float lumi) const; // luminosityUp

  Image luminosityDown(float lumi) const; // luminosityDown

  Image contrasteUp(float lumi) const; // contrasteUp

  Image contrasteDown(float lumi) const; // contrasteDown

  Image rognerD(int); // rognerD

  Image rognerG(int); // rognerG

  Image rognerH(int); // rognerH

  Image rognerB(int); // rognerB

  Image rotationD(); // rotationD

  Image rotationG(); // rotationG

  Image retournementH(); // retournementH

  Image retournementV(); // retournementV

  Image agrandissement(int); // agrandissement

  Image retrecissement(int); // retrecissment
};

// -------- External functions ---------

void loadPicture(const string &picture, vector<vector<int>> &red,
                 vector<vector<int>> &green,
                 vector<vector<int>> &blue); // loadPicture

void writePicture(const string &fileName, const Image &image); // writePicture

void printPixel(int r, int g, int b); // affiche un pixel (bloc) dans le
                                      // terminal avec les valeurs rgb données
									  // ne marche pas sur windows

void printImage(const Image &img); // affiche une image dans le terminal à
                                   // l'aide de printPixel()

#endif // IMAGE_H_INCLUDED
