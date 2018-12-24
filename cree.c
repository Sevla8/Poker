#include "cree.h"

struct Jeu* creer_jeu(char* names[], int est_robot[], int nb_joueurs, int somme) {
	if (nb_joueurs <= 1 || nb_joueurs >= 8)
		return NULL;

	struct Jeu* jeu = (struct Jeu*) malloc(sizeof(struct Jeu));
	jeu->paquet = (struct Paquet*) malloc(sizeof(struct Paquet));
	jeu->joueurs = (struct Joueur*) malloc(sizeof(struct Joueur) * nb_joueurs);
	jeu->nb_joueurs = nb_joueurs;
	int i;
	for (i = 0; i < nb_joueurs; ++i) {
		jeu->joueurs[i].nb_carte = 0;
		jeu->joueurs[i].nom = names[i];
		jeu->joueurs[i].somme = somme;
		jeu->joueurs[i].mise = 0;
		jeu->joueurs[i].est_robot = est_robot[i];
	}
	
	jeu->premier = 0;
	
	return jeu;
}