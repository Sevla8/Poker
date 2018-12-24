#include "joue.h"

void jouer_change_card(struct Jeu* jeu) {
	int i;
	int cur = jeu->premier;

	printf("\n\n ******* Changement de Cartes : ******* \n");
	getchar();
	for (i = 0; i < jeu->nb_joueurs; ++i) {
		printf("\nDébut tour joueur %s :\n", jeu->joueurs[cur].nom);
		getchar();
		int nb;
		if (jeu->joueurs[cur].est_robot) {
			nb = changer_carte_robot(jeu, cur);				
		} else {
			printf("Votre main : ");
			affiche_main(&(jeu->joueurs[cur]));
			printf("Votre somme d'argent : %d\n", jeu->joueurs[cur].somme);
			nb = changer_carte_joueur(jeu, cur);
			printf("\nVotre nouvelle main : ");
			affiche_main(&(jeu->joueurs[cur]));				
		}
		printf("Le joueur %s a changé %d cartes\n", jeu->joueurs[cur].nom, nb);
		printf("Fin tour joueur %s\n", jeu->joueurs[cur].nom);			
		cur = (cur + 1) % jeu->nb_joueurs;
	}	
}

void jouer_mises(struct Jeu* jeu) {
	printf("\n\n ******* Mises : *******\n");
	getchar();
	int cur = jeu->premier;
	int i = 0;
	int derniere_mise = 0;
	int nb_joueur_pas_couche = jeu->nb_joueurs;
	while (i < nb_joueur_pas_couche) {
		printf("\nDébut tour joueur %s :\n", jeu->joueurs[cur].nom);
		getchar();
		int mise;
		if (jeu->joueurs[cur].est_couche) {
			printf("Joueur couché\n");
		} else {
			if (jeu->joueurs[cur].est_robot) {
				mise = mise_robot(jeu, cur);
				printf("Le joueur %s mise %d\n", jeu->joueurs[cur].nom, mise);
			} else {
				printf("Votre main : ");
				affiche_main(&(jeu->joueurs[cur]));
				mise = mise_joueur(jeu, cur);
			}
			if (mise == 0) {
				jeu->joueurs[cur].est_couche = 1;
				nb_joueur_pas_couche--;
			} else {								
				if (jeu->joueurs[cur].mise == derniere_mise)
					i++;
				else if (jeu->joueurs[cur].mise > derniere_mise)
					i = 1;
			
				derniere_mise = jeu->joueurs[cur].mise;
			}
		}
		
		printf("Fin tour joueur %s\n", jeu->joueurs[cur].nom);			
		cur = (cur + 1) % jeu->nb_joueurs;
	}	
}


void jouer(struct Jeu* jeu) {
	jeu->premier = -1;
	while (1) {
		init_jeu(jeu);
		distribuer(jeu);
		
		jouer_change_card(jeu);
		jouer_mises(jeu);
				
		int winner = gagnant(jeu);

		printf("\n\n ******* Gagnant : *******\n");
		getchar();
		printf("Les mains des joueurs sont :\n");
		int i;
		for (i = 0; i < jeu->nb_joueurs; ++i) {
			printf("%s : ", jeu->joueurs[i].nom);
			if (jeu->joueurs[i].est_couche)
				printf("couché\n");
			else
				affiche_main(&(jeu->joueurs[i]));
			getchar();
		}
		
		printf("Le joueur %s remporte la mise\n", jeu->joueurs[winner].nom);
		for (i = 0; i < jeu->nb_joueurs; ++i) {
			jeu->joueurs[winner].somme += jeu->joueurs[i].mise;
			jeu->joueurs[i].somme -= jeu->joueurs[i].mise;
			jeu->joueurs[i].mise = 0;
		}
		for (i = 0; i < jeu->nb_joueurs; ++i) {
			printf("La somme du joueur %s est maintenant de : %d\n", jeu->joueurs[i].nom, jeu->joueurs[i].somme);
		}
		
	}
}