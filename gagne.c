#include "gagne.h"

int gagnant2(struct Joueur* j1, struct Joueur* j2) {
	return 0;
}

int gagnant(struct Jeu* jeu) {
	int i;
	int cur = 0;
	for (i = 1; i < jeu->nb_joueurs; ++i) {
		if (!jeu->joueurs[i].est_couche) {
			if (gagnant2(jeu->joueurs + cur, jeu->joueurs + i)) {
				cur = i;
			}
		}
	}
	return cur;
}