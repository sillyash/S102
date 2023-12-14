#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

// getRouge
vector<vector<int>> Image::getRouge() const
{
    return _rouge;
}

// getVert
vector<vector<int>> Image::getVert() const
{
    return _vert;
}

// getBleu
vector<vector<int>> Image::getBleu() const
{
    return _bleu;
}

// comparer
bool Image::comparer(const Image& img) const
{
    return ((_rouge == img.getRouge()) && (_vert == img.getVert()) && (_bleu == img.getBleu()));
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

// histogrammeGris
vector<int> Image::histogrammeGris() const
{
    vector<int> histoGris = {};
    int nbPix;

    // pour chaque niveau de gris possible dans l'histogramme
    for (int i=0; i<256; i++) {
        nbPix = 0;
        // pour chaque ligne du niveau de gris de l'image
        for (int j=0; j<_longueur; j++) {
            // pour chaque case
            for (int k=0; k<_largeur; k++) {
                // si le pixel a la même valeur que la niveau de l'histogramme
                if (niveauxGris().getPixel(j,k)[0] == i) {
                    nbPix++;
                }
            }
        }
        histoGris.push_back(nbPix);
    }
    return histoGris;
}


Image Image::luminosityUp(float lumi) const
{
    vector<vector<int>> rouge=_rouge;
    vector<vector<int>> vert=_vert;
    vector<vector<int>> bleu=_bleu;

    if(lumi<1){
        return Image(rouge,vert,bleu);
    }

    for(int i=0; i<_rouge.size(); i++){
        for (int j=0; j<_rouge[i].size(); j++){
            if(rouge[i][j]*lumi>255){
                rouge[i][j]=255;
            }
            else{
                rouge[i][j]=rouge[i][j]*lumi;
            }
            if(vert[i][j]*lumi>255){
                vert[i][j]=255;
            }
            else{
                vert[i][j]=vert[i][j]*lumi;
            }
            if(bleu[i][j]*lumi>255){
                bleu[i][j]=255;
            }
            else{
                bleu[i][j]=bleu[i][j]*lumi;
            }
        }
    }
    return Image(rouge,vert,bleu);

}


Image Image::luminosityDown(float lumi) const
{
    vector<vector<int>> rouge=_rouge;
    vector<vector<int>> vert=_vert;
    vector<vector<int>> bleu=_bleu;

    if(lumi>1){
        return Image(rouge,vert,bleu);
    }

    for(int i=0; i<_rouge.size(); i++){
        for (int j=0; j<_rouge[i].size(); j++){
            rouge[i][j]=rouge[i][j]*lumi;
            vert[i][j]=vert[i][j]*lumi;
            bleu[i][j]=bleu[i][j]*lumi;
        }
    }
    return Image(rouge,vert,bleu);

}

Image Image::constrasteUp(float val) const
{
    vector<vector<int>> rouge=_rouge;
    vector<vector<int>> vert=_vert;
    vector<vector<int>> bleu=_bleu;

    if(val<1){
        return Image(rouge,vert,bleu);
    }

    for(int i=0; i<_rouge.size(); i++){
        for (int j=0; j<_rouge[i].size(); j++){
            if((rouge[i][j]-128) > 0){
                rouge[i][j] += (rouge[i][j]-128)*val;
            }
            else if((rouge[i][j]-128) < 0){
                rouge[i][j] -= (rouge[i][j]-128)*val;
            }
        }
    }
    return Image(rouge,vert,bleu);
}

void loadPicture(const string &picture, vector<vector<int>> &red,
                                        vector<vector<int>> &green,
                                        vector <vector<int>> &blue)
{
    // Declaration des variables
    string line; // pour recuperer les lignes du fichier image au format .ppm, qui est code en ASCII.
    string format; //pour recuperer le format de l'image : celui-ci doit être de la forme P3
    string name; // au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    int taille;
    vector <int> mypixels; // pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants
    ifstream entree; // Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    int hauteur; // pour bien verifier que l'image est carree, et de taille respectant les conditions fixees par l'enonce
    // Initialisation des variables
    name = picture;
    // Permet d'ouvrir le fichier portant le nom picture
    // ouverture du fichier portant le nom picture
    entree.open(name);
    // On verifie que le fichier a bien ete ouvert. Si cela n'est pas le cas, on redemande un nom de fichier valide
    while (!entree){
        //cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        entree.open(name); // relance
    }
    // Lecture du nombre definissant le format (ici P3)
    entree >> format;
    // on finit de lire la ligne (caractere d'espacement)
    getline(entree, line);
    // Lecture du commentaire
    getline(entree, line);
    //lecture des dimensions
    entree >> taille >> hauteur;
    getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    // On verifie que l'image a une taille qui verifie bien les conditions requises par l'enonce.
    // Si cela n'est pas le cas, on redemande un fichier valide, et ce, tant que necessaire.
    while (format != "P3"){
        if (format != "P3"){
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }
	entree.close();
        // On va redemander un nom de fichier valide.
        do{
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm." << endl;
            cin >> name;
            entree.open(name); // relance
        }while(!entree);
         // Lecture du nombre definissant le format (ici P3)
         entree >> format;
         getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
        // Lecture du commentaire
        getline(entree, line);
        //lecture des dimensions
        entree >> taille >> hauteur; // relance
        getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    }
    //Lecture de la valeur max
    getline(entree, line);
    //Lecture des donnees et ecriture dans les tableaux :
    // Pour plus de simplicite, on stocke d'abord toutes les donnees dans mypixels
    // dans l'ordre de lecture puis ensuite on les repartira dans les differents tableaux.
    //Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
    // Il faudra donc repartir les valeurs R correspondant a la composante rouge de l'image
    // dans le tableau red, de même pour G et B.
    int pix;
    mypixels.resize(3*taille*hauteur); // taille fixe : on alloue une fois pour toutes
    for (int i = 0; i < 3*taille*hauteur; i++){
      entree >> pix;
      mypixels[i]=pix;
    }
    // Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les bonnes composantes
    // Comme dans mypixels, les donnees sont stockees de la maniere suivante : RGB RGB RGB, il faut mettre
    // les valeurs correspondant a la composante rouge dans red, ...
    // Ainsi, les valeurs de la composante rouge correspondent aux valeurs stockes aux indices
    // congrus a 0 mod 3 dans mypixels, que les valeurs de la composante verte correspond aux valeurs
    // stockes aux indices sont congrus a 1 mod 3, ...
     // les valeurs d'une ligne
    int val;
    red.resize(hauteur);
    green.resize(hauteur);
    blue.resize(hauteur);
    for (int i = 0; i < hauteur; i++){
      vector <int> ligneR(taille);
      vector <int> ligneB(taille);  // les lignes ont toutes la même taille
      vector <int> ligneG(taille);
      for (int j = 0; j < taille; j++){
            val =  mypixels[3*j + 3*taille*i];
            ligneR[j]=val;
            val = mypixels[3*j + 1 + 3*taille*i];
            ligneG[j]=val;
            val = mypixels[3*j + 2 + 3*taille*i];
            ligneB[j]=val;
        }
        red[i]=ligneR;
        green[i]=ligneG;
        blue[i]=ligneB;
    }
    // Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
     entree.close();
 }

string saisieFichier() {
	string nomFichier;
	cout << "Saisissez un nom de fichier ppm  >>> ";
	cin >> nomFichier;
	return nomFichier+".ppm";
}

bool validChoice(int choice)
{
    return (choice > 0 && choice <= QUIT);
}

int menu(){
    int choice;

    cout << "\nEntrez:" << endl;
    cout << "\t" << DISPLAY << " - pour afficher l'image" << endl;
    cout << "\t" << COMPOROUGE << " - pour mettre en composante rouge" << endl;
    cout << "\t" << NIVGRIS << " - pour mettre en niveaux de gris" << endl;
    cout << "\t" << NOIRBLANC << " - pour mettre en noir et blanc" << endl;
    cout << "\t" << LUMIUP << " - pour augmenter la luminosité" << endl;
    cout << "\t" << LUMIDOWN << " - pour diminiuer la luminosité" << endl;
    cout << "\t" << CONTRAUP << " - pour augmenter le contraste" << endl;
    cout << "\t" << CONTRADOWN << " - pour diminuer le contraste" << endl;
    cout << "\t" << QUIT << " - pour quitter le programme" << endl;
    cout << ">>> ";
    cin >> choice;

    while (!validChoice(choice))
    {
        cout << endl << choice << " is not a valid option, please enter again:" << endl << ">>> ";
        cin >> choice; cout << endl << endl;
    }
    return choice;
}
