#include <iostream>
#include <vector>
#include <string>
#include "image.h"

using namespace std;

int main() {

	// Image par défaut dans l'énoncé (cf. image.h > constructeur pour les valeurs)
	Image test;

	/// ------ TESTS MANUELS ------
	// Méthode getPixel()
	cout << "Get pixel (3,3): ";
	cout << test.getPixel(3,3)[0] << ", " << test.getPixel(3,3)[1] << ", "  << test.getPixel(3,3)[2];
	cout << endl << endl;

	// Méthode display()
	cout << "Display:" << endl;
	test.display();

	// Méthode composanteRouge()
	cout << "Composante rouge:" << endl;
	test.composanteRouge().display();

	// Méthode detection()
	cout << "Detection (255, 255, 0): ";
	cout << test.detection(255, 255, 0) << endl << endl;

	// Méthode niveauxGris()
	cout << "Niveaux de gris:" << endl;
	test.niveauxGris().display();

	// Méthode noirEtBlanc()
	cout << "Noir et blanc:" << endl;
	test.noirEtBlanc().display();

	/// --- TESTS AUTOMATIQUES ---

	cout << "Test de composanteRouge...\t\t";
	if (test.composanteRouge() = ) cout << "Réussi!" << endl;
	else cout << "Raté, test.composanteRouge() = ";

	/// ------ FIN DES TESTS ------

	return 0;
}
