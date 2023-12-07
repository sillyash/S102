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
	test.noirEtBlanc(254).display();

	//Méthode histogrammeGris()
	cout << endl;
	vector<int> histo=test.histogrammeGris();
	for(int i=0; i<histo.size(); i++) {
        cout << i << " : " << histo[i] << "\t\t";
        if (i%6 == 0 && i!=0) cout << endl;
	}

	//Affichage pour luminausite//
    Image img=test.niveauxGris();

    cout << endl << endl;
	//Methode luminosityUp
	cout << "Methode luminosityUp : " << endl;
	Image luminosityup=img.luminosityUp(1.5);
	luminosityup.display();

        //Methode luminosityDown//
        cout << "Methode luminosityDown : " << endl;
        Image luminositydown=img.luminosityDown(0.5);
	luminositydown.display();

	/// --- TESTS AUTOMATIQUES ---

	cout << endl << "Test de composanteRouge...";
	vector<vector<int>> vide(4, vector<int> (4,0));
	Image compoRouge({{0,0,0,0},{0,0,255,255},{0,255,255,255},{255,255,255,255}}, vide, vide);
	if (test.composanteRouge().comparer(compoRouge)) cout << "\t\tReussi!" << endl;
	else cout << endl << "Rate..." << endl;

	cout << "Test de getPixel...";
	vector<int> pix = test.getPixel(3,3);
	if (pix[0] == 255 && pix[1] == 0 && pix[2] == 0) cout << "\t\t\tReussi!" << endl;
	else cout << endl << "Rate... test.getPixel(3,3) = " << pix[0] << ", " << pix[1] << ", " << pix[2] << " (attendu: 255, 0, 0)" << endl;

	cout << "Test de detection...";
	if (test.detection(255, 255, 0) == true) cout << "\t\t\tReussi!" << endl;
	cout << endl << "Rate... test.detection(255, 255, 0) = " << test.detection(255, 255, 0);


	/// ------ FIN DES TESTS ------

	return 0;
}
