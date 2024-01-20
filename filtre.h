#include <string>
#include <vector>
#include "image.h"

using namespace std;


#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED

class Filtre {
private:
	vector<vector<float>> _action;
	int _rayon;

public:
	Filtre(vector<vector<float>>, int);			// constructeur
	Image application(const Image& img) const;	// application
};


// constantes pour les filtres
const vector<vector<float>> ACTIONG3 = {
	{1.0/16, 1.0/8, 1.0/16},
	{1.0/8,  1.0/4, 1.0/8},
	{1.0/16, 1.0/8, 1.0/16}
};

const vector<vector<float>> ACTIONG5 = {
	{1.0/256, 4.0/256,  6.0/256,  4.0/256,  1.0/256 },
	{4.0/256, 16.0/256, 24.0/256, 16.0/256, 4.0/256 },
	{6.0/256, 24.0/256, 36.0/256, 24.0/256, 6.0/256 },
	{4.0/256, 16.0/256, 24.0/256, 16.0/256, 4.0/256 },
	{1.0/256, 4.0/256,  6.0/256,  4.0/256,  1.0/256 }
};

const int RAYONG3 = 1;
const int RAYONG5 = 2;

// filtres
const Filtre flouG3(ACTIONG3, RAYONG3);
const Filtre flouG5(ACTIONG5, RAYONG5);

#endif

