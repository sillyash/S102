#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include "image.h"
#include "menu.h"
#include "filtre.h"

using namespace std;

int maintest() {
	
    // Image par défaut dans l'énoncé (cf. image.h > constructeur pour les valeurs)
	Image test;

	/// --------------- TESTS MANUELS ---------------

	// Méthode display
	cout << "Display:" << endl;
	printImage(test);

	// Méthode niveauxGris
	cout << "Niveaux de gris:" << endl;
	printImage(test.niveauxGris());

	// Méthode noirEtBlanc
	cout << "Noir et blanc:" << endl;
	printImage(test.noirEtBlanc(127));

    // Methode luminosityDown
    cout << "Methode luminosityDown:" << endl;
	printImage(test.luminosityDown(0.5));

	// Methide contrasteDown
	cout << "Methode contrasteDown:" << endl;
	printImage(test.contrasteDown(0.25));

	// Image de test du pdf FlouFiltre
	const vector<vector<int>> GRIS = {
		{0,   50,  100, 150},
		{50,  100, 150, 200},
		{100, 150, 200, 225},
		{150, 200, 225, 255}
	};
	Image gris(GRIS, GRIS, GRIS);

	// Methode application
	cout << "Test de application...\t\t\t" << endl;
	cout << "Image avant le filtre: " << endl;
	printImage(gris);
	
	// flouG3
	cout << "Image après le filtre (flouG3): " << endl;
	gris = flouG3.application(gris);
	printImage(gris);
	
	// flouG5
	cout << "Image après le filtre (flouG5): " << endl;
	gris = flouG5.application(gris);
	printImage(gris);


	/// ------------ TESTS AUTOMATIQUES --------------

	cout << endl << "Test de composanteRouge...\t\t";
	vector<vector<int>> vide(4, vector<int> (4,0));
	Image compoRouge({{0,0,0,0},{0,0,255,255},{0,255,255,255},{255,255,255,255}}, vide, vide);
	if (test.composanteRouge().comparer(compoRouge)) cout << "Reussi!" << endl;
	else cout << endl << "Rate..." << endl;

	cout << "Test de getPixel...\t\t\t\t";
	vector<int> pix = test.getPixel(3,3);
	if (pix[0] == 255 && pix[1] == 0 && pix[2] == 0) cout << "Reussi!" << endl;
	else cout << endl << "Rate... test.getPixel(3,3) = " 
		<< pix[0] << ", " << pix[1] << ", " << pix[2] << " (attendu: 255, 0, 0)" << endl;

	cout << "Test de detection...\t\t\t";
	if (test.detection(255, 255, 0) == true) cout << "Reussi!" << endl;
	else cout << endl << "Rate... test.detection(255, 255, 0) = "
		<< test.detection(255, 255, 0) << endl;

    cout << "Test de histogrammeGris...\t\t";
    vector<int> histo = test.histogrammeGris();
    bool reussi = true;
    for (int i=0; i<histo.size(); i++) {
        if (i == 85 && histo[i] != 10) reussi = false;
        else if (i == 170 && histo[i] != 6) reussi = false;
        else if (i != 85 && i!= 170 && histo[i] != 0) reussi = false;
    }
	if (reussi) cout << "Reussi!" << endl;
	else cout << "Rate..." << endl;

	cout << endl;
	
	return 0;
}
