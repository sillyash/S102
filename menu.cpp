#include "image.h"
#include "menu.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

// sasieFichier
string saisieFichier() {
	string nomFichier;
	cout << "Saisissez un nom de fichier ppm  >>> ";
	cin >> nomFichier;
	// if no extension return with extension
	cout << string(nomFichier.end()-4, nomFichier.end()) << endl;
	if (string(nomFichier.end()-4, nomFichier.end()) != ".ppm") 
		return nomFichier + ".ppm";
	// if extension, return string
	else return nomFichier;
}


// validchoice
bool validChoice(const int& choice) { return (choice > 0 && choice <= QUIT); }

// validChoice version 2
bool validChoice(const int& choice, const int& start, const int& end) {
	return (choice >= start && choice <= end);
}


// menu principal
int menu() {
	int choice;
	cout << "\nMenu principal. Entrez:" << endl;
	cout << "\t" << DISPLAY << "  - pour afficher l'image (Linux or Replit only)" << endl;
	cout << "\t" << COMPOROUGE << "  - pour mettre en composante rouge" << endl;
	cout << "\t" << NIVGRIS << "  - pour mettre en niveaux de gris" << endl;
	cout << "\t" << NOIRBLANC << "  - pour mettre en noir et blanc" << endl;
	cout << "\t" << LUMI << "  - pour le menu luminosite" << endl;
	cout << "\t" << CONTRA << "  - pour le menu contraste" << endl;
	cout << "\t" << ROGNER << "  - pour le menu rognage" << endl;
	cout << "\t" << ROTA << "  - pour le menu rotation" << endl;
	cout << "\t" << RETOURNEMENT << " - pour le menu retournement (symmetrie)" << endl;
	cout << "\t" << TAILLE << " - pour le menu taille" << endl;
	cout << "\t" << FILTRES << " - pour le menu filtres" << endl;;
	cout << "\t" << QUIT << " - pour quitter le programme" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu luminosite
int menuLUMI() {
	int choice;
	cout << "\nMenu luminosite. Entrez:" << endl;
	cout << "\t1  - pour augmenter la luminosite" << endl;
	cout << "\t2  - pour diminiuer la luminosite" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;
	
	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu contraste
int menuCONTRA() {
	int choice;
	cout << "\nMenu contraste. Entrez:" << endl;
	cout << "\t1  - pour augmenter le contraste" << endl;
	cout << "\t2  - pour diminuer le contraste" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu rognement
int menuROGNER() {
	int choice;
	cout << "\nMenu rognement. Entrez:" << endl;
	cout << "\t1  - pour rogner l'image a droite" << endl;
	cout << "\t2  - pour rogner l'image a gauche" << endl;
	cout << "\t3  - pour rogner l'image en haut" << endl;
	cout << "\t4  - pour rogner l'image en bas" << endl;
	cout << "\t5  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 6)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu rotation
int menuROTA() {
	int choice;
	cout << "\nMenu rotation. Entrez:" << endl;
	cout << "\t1  - pour faire une rotation de l'image de 90° vers la droite" << endl;
	cout << "\t2  - pour faire une rotation de l'image de 90° vers la gauche" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}

// menu retournement
int menuRETOURNE() {
	int choice;
	cout << "\nMenu retournement (symmetrie). Entrez:" << endl;
	cout << "\t1  - pour faire un retournement horizontal" << endl;
	cout << "\t2  - pour faire un retournement vertical" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu taille
int menuTAILLE() {
	int choice;
	cout << "\nMenu taille. Entrez:" << endl;
	cout << "\t1  - pour agrandir l'image" << endl;
	cout << "\t2  - pour retrecir l'image" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}


// menu filtres
int menuFILTRES() {
	int choice;
	cout << "\nMenu filtres. Entrez:" << endl;
	cout << "\t1  - pour apliquer le filtre flouG3  a l'image" << endl;
	cout << "\t2  - pour apliquer le filtre flouG5  a l'image" << endl;
	cout << "\t3  - pour revenir au menu principal" << endl;
	cout << ">>> ";
	cin >> choice;

	while (!validChoice(choice, 1, 3)) {
		cout << endl << choice << " is not a valid option, please enter again"
			<< endl << ">>> ";
		cin >> choice;
		cout << endl << endl;
	}
	return choice;
}
