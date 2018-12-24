#include "melange.h"

void melange_help(struct Paquet* jeu, int c1, int c2) {
	struct Carte tmp = jeu->cartes[c1];
	jeu->cartes[c1] = jeu->cartes[c2];
	jeu->cartes[c2] = tmp;
}


void melange(struct Paquet* jeu) {
	int i;
	for (i = 0; i < 1000; ++i) {
		int c1 = rand() % jeu->nb_carte;
		int c2 = rand() % jeu->nb_carte;
		
		melange_help(jeu, c1, c2);
	}
}