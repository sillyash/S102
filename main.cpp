#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include "image.h"
#include "menu.h"
#include "filtre.h"
#include "mainTest.h"

using namespace std;

int main() {

	// mainTest
	// à commenter si vous voulez 
	// un affichage plus léger au démarrage
	try {
		maintest();
	}
	catch (...) {
		cout << "Tests returned an error: check mainTest.cpp" << endl;
	}
	
	
	vector<vector<int>> red;
    vector<vector<int>> green;
    vector<vector<int>> blue;

	// load picture
	cout << "\nLecture fichier... (\"images/nom.ppm\" pour acceder au dossier)\n";
    string nomFichier = saisieFichier();
	cout << endl;
    loadPicture(nomFichier,red,green,blue);

	// create Image from picture
    Image img(red, green, blue);

	// declare variables for menu purposes
	int choix, seuil, rogner, facteur;
	float lumi;
	char saveImg;

	// test
	printImage(img);

	// menu loop
	do {
		choix = menu();
		switch (choix)
		{
			case DISPLAY:
				printImage(img);
				break;

			case COMPOROUGE:
				img = img.composanteRouge();
				break;

			case NIVGRIS:
				img = img.niveauxGris();
				break;

			case NOIRBLANC:
				cout << "Veuillez entrer un seuil  >>> ";
				cin >> seuil;
				img = img.noirEtBlanc(seuil);
				break;

			case LUMI:
				choix = menuLUMI();
				switch(choix){
					case 1:
						cout << "Veuillez entrer une luminosite >>> ";
						cin >> lumi;
						img= img.luminosityUp(lumi);
						break;

					case 2:
						cout << "Veuillez entrer une luminosite >>> ";
						cin >> lumi;
						img= img.luminosityDown(lumi);
						break;

					default:
						break;
				}
				break;

			case CONTRA:
				choix = menuCONTRA();
				switch(choix) {
					case 1:
						cout << "Veuillez entrer un contraste >>> ";
						cin >> lumi;
						img= img.contrasteUp(lumi);
						break;

					case 2:
						cout << "Veuillez entrer un constraste >>> ";
						cin >> lumi;
						img= img.contrasteDown(lumi);
						break;

					default:
						break;
				}
				break;

			case ROGNER:
				choix = menuROGNER();
				switch(choix){
					case 1:
						cout << "Combien de colonnes voulez-vous rogner ? >>> ";
						cin >> rogner;
						img = img.rognerD(rogner);
						break;

					case 2:
						cout << "Combien de colonnes voulez-vous rogner ? >>> ";
						cin >> rogner;
						img = img.rognerG(rogner);
						break;

					case 3:
						cout << "Combien de colonnes voulez-vous rogner ? >>> ";
						cin >> rogner;
						img = img.rognerH(rogner);
						break;

					case 4:
						cout << "Combien de colonnes voulez-vous rogner ? >>> ";
						cin >> rogner;
						img = img.rognerB(rogner);
						break;

					default:
						break;
				}
				break;

			case ROTA: 
				choix = menuROTA();
				switch(choix){
					case 1:
						img = img.rotationD();
						break;

					case 2:
						img = img.rotationG();
						break;

					default:
						break;
				}
				break;

			case RETOURNEMENT:
				choix = menuRETOURNE();
				switch(choix){
					case 1:
						img = img.retournementH();
						break;

					case 2:
						img = img.retournementV();
						break;

					default:
						break;
				}
				break;

			case TAILLE:
				choix = menuTAILLE();
				switch(choix){
					case 1:
						cout << "Quel facteur? >>> ";
						cin >> facteur;
						img = img.agrandissement(facteur);
						break;

					case 2:
						cout << "Quel facteur? >>> ";
						cin >> facteur;
						img = img.retrecissement(facteur);
						break;

					default:
						break;
				}
				break;

			case FILTRES:
				choix = menuFILTRES();
				switch(choix){
					case 1:
						img = flouG3.application(img);
						break;

					case 2:
						img = flouG5.application(img);
						break;
					
					default:
						break;
				}
				break;
		}
	}
	while (choix != QUIT);

	// demande si l'utilisateur souhaite enregistrer l'image
	cout << endl << "Souhaitez vous enregistrer l'image ? (y/n)  >>> ";
	cin >> saveImg;
	if (saveImg == 'y') {
		// write Image in a file (ppm format)
		cout << "\nEcriture du fichier... (\"images/nom.ppm\" pour acceder au dossier)\n";
		string writePPM = saisieFichier();
		cout << endl;
		writePicture(writePPM, img);
		cout << "\nFichier ecrit! Image sauvegardee.\n";
	}
	cout << "\nA bientot!\n";

	return 0;
}
