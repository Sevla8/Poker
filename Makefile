CFILES = affichage.c \
			cree.c \
			distribue.c \
			echange.c \
			gagne.c \
			initialisation.c \
			joue.c \
			mise.c \
			main.c

HFILES = affichage.h \
			cree.h \
			distribue.h \
			echange.h \
			gagne.h \
			initialisation.h \
			joue.h \
			mise.h \
			carte.h \
			couleur.h \
			jeu.h \
			joueur.h \
			paquet.h

OFILES = affichage.o \
			cree.o \
			distribue.o \
			echange.o \
			gagne.o \
			initialisation.o \
			joue.o \
			mise.o \
			main.o

FLAGS = -Wall -ansi -pedantic -g

exe : $(OFILES)
	gcc $(FLAGS) -o exe $(OFILES)

main.o : main.c jeu.h cree.h joue.h
	gcc -c main.c

mise.o : mise.c jeu.h
	gcc -c mise.c

joue.o : joue.c joue.h
	gcc -c joue.c

initialisation.o : initialisation.c initialisation.h
	gcc -c initialisation.c

gagne.o : gagne.c gagne.h 
	gcc -c gagne.c

echange.o : echange.c echange.h
	gcc -c echange.c

distribue.o : distribue.c distribue.h
	gcc -c distribue.c

cree.o : cree.c cree.h
	gcc -c cree.c

affichage.o : affichage.c affichage.h
	fcc -c affichage.c

.PHONY : clean

clean :
	rm -f $(OFILES) exe