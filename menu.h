#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

const int 	DISPLAY = 1, 
			COMPOROUGE = 2,
			NIVGRIS = 3, 
			NOIRBLANC = 4, 
			LUMI = 5,
			CONTRA = 6, 
			ROGNER = 7,
			ROTA = 8,
			RETOURNEMENT = 10,
			TAILLE = 11,
			FILTRES = 12,
			QUIT = 13;

bool validChoice(const int& choice); // validChoice
// validChoice v2 (pour les sous-menus)
bool validChoice(const int& choice, const int& start, const int& end);

string saisieFichier(); // saisieFichier

int menu(); 		// menu
int menuLUMI(); 	// menu luminosite
int menuCONTRA();	// menu contraste
int menuROGNER();	// menu rognement
int menuROTA();		// menu rotation
int menuRETOURNE();	// menu retournement
int menuTAILLE();	// menu taille
int menuFILTRES();	// menu filtres


#endif // MENU_H_INCLUDED
