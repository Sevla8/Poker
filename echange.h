#ifndef ECHANGE_H
#define ECHANGE_H

#include "paquet.h"
#include "joueur.h"
#include "jeu.h"
#include <stdio.h>
#include "stdlib.h"

void echanger(struct Paquet*, struct Joueur*, int);
int changer_carte_joueur(struct Jeu*, int);
int changer_carte_robot(struct Jeu*, int);

#endif