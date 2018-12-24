#include "initialisation.h"

void init(struct Paquet* jeu) {
	int i;
	for (i = 0; i < 13; ++i) {
		jeu->cartes[i].valeur = i+1;
		jeu->cartes[i].couleur = e_pique;
	}
	
	for (i = 0; i < 13; ++i) {
		jeu->cartes[13+i].valeur = i+1;
		jeu->cartes[13+i].couleur = e_coeur;
	}

	for (i = 0; i < 13; ++i) {
		jeu->cartes[26+i].valeur = i+1;
		jeu->cartes[26+i].couleur = e_carreau;
	}

	for (i = 0; i < 13; ++i) {
		jeu->cartes[39+i].valeur = i+1;
		jeu->cartes[39+i].couleur = e_trefle;
	}
	jeu->nb_carte = 52;
}

void init_jeu(struct Jeu* jeu) {
	init(jeu->paquet);
	int i;
	for (i = 0; i < jeu->nb_joueurs; ++i) {
		jeu->joueurs[i].nb_carte = 0;
		jeu->joueurs[i].mise = 0;
		jeu->joueurs[i].est_couche = 0;
	}
	jeu->premier = 	(jeu->premier + 1) % jeu->nb_joueurs;
}