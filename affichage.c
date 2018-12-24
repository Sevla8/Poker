#include "affichage.h"

void affiche_carte(struct Carte* carte) {
	char* valeur;
	static char* v[13] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};
	valeur = v[carte->valeur - 1];
	
	char* couleur;
	static char* c[13] = {"Pique", "Coeur", "Trefle", "Carreau"};	
	couleur = c[carte->couleur];
        	
	printf("%s %s", valeur, couleur);
}

void affiche_main(struct Joueur* joueur) {
	int i;
	for (i = 0; i < joueur->nb_carte - 1; ++i) {
		affiche_carte(&(joueur->main[i]));
		printf(" - ");
	}
	affiche_carte(&(joueur->main[i]));
	printf("\n");	
}