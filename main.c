#include "jeu.h"
#include "cree.h"
#include "joue.h"

int main(int argc, char* argv[]) {
	char* names[3] = {"Eric", "Plop", "Cindy"};
	int robot[3] = {0, 0, 0};
	
	struct Jeu* jeu = creer_jeu(names, robot, 3, 100);
	jouer(jeu);
	
	return 0;
}