#include "echange.h"

void echanger(struct Paquet* jeu, struct Joueur* joueur, int i) {
	if (i < 0 || i >= jeu->nb_carte || jeu->nb_carte == 0)
		return;
	int c1 = rand() % jeu->nb_carte;		
	struct Carte tmp = jeu->cartes[c1];
	jeu->cartes[c1] = joueur->main[i];
	joueur->main[i] = tmp;
}

int changer_carte_joueur(struct Jeu* jeu, int cur) {
	int nb = -1;	
	while (nb < 0 || nb > 5) {
		printf("Combien voulez-vous changer de cartes ? \n");	
		scanf("%d", &nb);
		getchar();
	}
	int i;
	for (i = 0; i < nb; ++i) {
		int c = -1;
		while (c < 0 || c > 5) {	
			printf("Carte a changer numéro %d ?\n", i);		
			scanf("%d", &c);
			getchar();
		}
		echanger(jeu->paquet, jeu->joueurs + cur, c);
	}
	return nb;
}

int changer_carte_robot(struct Jeu* jeu, int cur) {
	return 0;
}