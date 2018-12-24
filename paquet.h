#ifndef PAQUET_H
#define PAQUET_H

#include "carte.h"

struct Paquet {
	struct Carte cartes[52];
	int nb_carte;
};

#endif