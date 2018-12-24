#include "mise.h"

int mise_joueur(struct Jeu* jeu, int cur) {

	int prec;
	if (cur == 0)
		prec = jeu->nb_joueurs - 1;
	else
		prec = cur - 1;

	printf("Votre somme d'argent : %d\n", jeu->joueurs[cur].somme);
	printf("Votre mise actuelle : %d\n", jeu->joueurs[cur].mise);
	
	int mise = -1;
	int min = jeu->joueurs[prec].mise - jeu->joueurs[cur].mise;
	while (mise < 0 || mise + jeu->joueurs[cur].mise > jeu->joueurs[cur].somme || (mise < min && mise != 0)) {
		printf("Combien voulez-vous miser ? (0 = se coucher)\n");
		scanf("%d", &mise);
		getchar();
	}
	printf("Le joueur %s mise %d\n", jeu->joueurs[cur].nom, mise);
	jeu->joueurs[cur].mise += mise;
	return mise;
}

int mise_robot(struct Jeu* jeu, int cur) {
	int prec;
	if (cur == 0)
		prec = jeu->nb_joueurs - 1;
	else
		prec = cur - 1;
	int min = jeu->joueurs[prec].mise - jeu->joueurs[cur].mise;
	if (jeu->joueurs[cur].mise + min > jeu->joueurs[cur].somme)
		min = 0;
	jeu->joueurs[cur].mise += min;
	return min;
}