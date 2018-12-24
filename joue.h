#ifndef JOUE_H
#define JOUE_H

#include "jeu.h"
#include "echange.h"
#include "gagne.h"
#include "mise.h"
#include "distribue.h"
#include "initialisation.h"
#include "affichage.h"
#include <stdio.h>

void jouer_change_card(struct Jeu*);
void jouer_mises(struct Jeu*);
void jouer(struct Jeu*);

#endif