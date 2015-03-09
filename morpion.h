#ifndef MORPION_H
#define MORPHIN_H

#include<stdio.h>
#include<stdbool.h>

#define N 20

typedef int Symbole_t; 

typedef struct{
	char nom[N];
	char prenom[N];
	Symbole_t s;
} Joueur_t;


//Les methodes publiques accessible partout

//permet de ajouter une joueur au jeu (maximum 2 joueurs)
void ajouter_joueur(char * nom, char * prenom, Symbole_t s); 

//permet de joueur une partie
void jouer_partie();  

#endif 

