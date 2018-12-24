#include "distribue.h"

void distribuer_un(struct Paquet* jeu, struct Joueur* joueur) {
	if (joueur->nb_carte == 5 || jeu->nb_carte == 0)
		return;
	joueur->main[joueur->nb_carte] = jeu->cartes[jeu->nb_carte - 1];
	joueur->nb_carte++;
	jeu->nb_carte--;
}

void distribuer(struct Jeu* jeu) {
	int i;
	for (i = 0; i < 5; ++i) {
		int j;
		for (j = 0; j < jeu->nb_joueurs; ++j) {
			distribuer_un(jeu->paquet, jeu->joueurs + j);
		}
	}
}