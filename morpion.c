#include"morpion.h"
#include"string.h" 

#define T 3
#define J 2

//Definition de la table interne qui represente les cases du morpion
//Variable Globale
int morpion[T][T]; 

//Tableau des joueurs (maximum 2 joueurs  pour jouer au morpion
Joueur_t joueurs[J]; 
int nbr_joueur = 0; 

void ajouter_joueur(char * nom, char * prenom, Symbole_t s){
	Joueur_t j; 
	j.s = s; 
	strcpy(j.nom, nom); 
	strcpy(j.prenom, prenom); 
	
	if(nbr_joueur < 2){
		joueurs[nbr_joueur] = j; 
	}
	else 
		perror("Impossible d'ajouter un 3ieme joueur"); 
	
	
	nbr_joueur++; 
}

void afficher_joueur(Joueur_t j) {
	printf("%s %s (%d)", j.nom, j.prenom, j.s); 
}

int verification_horizontal(Joueur_t joueur){
	Symbole_t s = joueur.s; 
	
	int i=0, j, n; 
	int gagne = 0; 
	
	while(gagne == 0 && i < T){
		n = 0; 
		for(j=0; j < T; j++){
			if(morpion[i][j] == s) 
				n++; 
		}
		
		if(n == 3)
			gagne = 1; 
		
		i++; 
	}
	
	return gagne; 
}

int verification_verticale(Joueur_t joueur){
	Symbole_t s = joueur.s; 
	
	int i, j=0, n; 
	int gagne = 0; 
	
	while(gagne == 0 && j < T){
		n = 0; 
		for(i=0; i < T; i++){
			if(morpion[i][j] == s) 
				n++; 
		}
		
		if(n == 3)
			gagne = 1; 
		
		j++; 
	}
	
	return gagne;
}

int verification_diagonale(Joueur_t joueur){
	Symbole_t s = joueur.s; 
	
	int i=0, n=0 ; 
	int gagne = 0; 
	
	for(i=0; i < T; i++){
		//on parcours la diagonale (0,0), (1,1), (2,2)
		if(morpion[i][i] == s)
			n++; 
	}
	
	if(n == 3)
		gagne = 1;
	// si la premiere diagonale n'est pas bonne, on verifie la deuxieme diagonale
	else {
		n = 0; 
		for(i=0; i < T; i++){
			//on parcours la diagonale (0,2), (1,1), (2,0)
			if(morpion[i][T-i-1] == s)
				n++; 
		}
		
		if(n == 3)
			gagne = 1;
	} 
		
	return gagne; 
}

void initialiser_morpion(){
	int i, j; 
	for(i = 0; i < T ; i++){
		for(j = 0; j < T ; j++) {
			morpion[i][j] = -1; 
		}
	}
}

int on_peut_joueur(){
	//verifie s'il y a encore une place où l'on peut joueur
	int i=0, j=0; 
	int oui = 0; 
	
	for(i=0; i < T; i++)
		for(j=0; j < T; j++)
			if(morpion[i][j] == -1)
				oui = 1; 
	
	return oui; 
}

//verifie si le joueur j a gagné la partie
int a_gagner(Joueur_t j){
	//si les pions sont bien classés horizontalement le joueur a gagné
	if(verification_horizontal(j)) 
		return 1; 
	//sinon si les pions sont bien classés verticalement le joueur a gagné
	else if(verification_verticale(j))
		return 1; 
	//si les pions sont bien classés diagolement le joueur a gagné
	else if(verification_diagonale(j))
		return 1; 
	//si aucun cas verifier, n'a pas gagné
	else 
		return 0; 
}

void jouer(Joueur_t joueur){
	int i, j; 
	scanf("%d %d", &j, &i); 
	
	if(i <= 3 && i >= 1 && j <= 3 && j >= 1){
		
		if(morpion[i-1][j-1] == -1)
			morpion[i-1][j-1] = joueur.s;
		else {
			printf("\n case déjà utilisée. Rejouez: \n");
			jouer(joueur); 
		} 

 	}
	else {
		printf("\n1 <= i <= 3 \n1 <= j <= 3");
		printf("\n Valeurs i j invalide. Rejouez: \n");
		jouer(joueur); 
	}
	
}

void afficher_morpion(){
	int i, j;
	
	printf("\n\n"); 
	
	for(i = 0; i < T; i++){
		for(j=0; j < T; j++) {
			if(morpion[i][j] == joueurs[0].s)
				printf("J1   ");
			else if(morpion[i][j] == joueurs[1].s)
				printf("J2   ");
			else 
				printf("~~   ");
		}
		printf("\n\n\n"); 
	}
}

void jouer_partie(){
	initialiser_morpion(); 
	int v = 0; 
	int continuer = 1; 
	
	afficher_morpion(); 
	
	while(continuer) {
		Joueur_t joueur = joueurs[v % 2]; //on selection le joueur 1 ou 2 dans le tableau 
				
		printf("\n\n"); 
		afficher_joueur(joueur); 
		printf(", Jouez:\n"); 
		
		jouer(joueur); 
		afficher_morpion();
		
		if(a_gagner(joueur)){
			printf("\n\n\n **********Feliciation***************\n"); 
			printf("le joueur %s %s a gagné\n", joueur.nom, joueur.prenom); 
			
			continuer = 0; 
		}
		
		if(on_peut_joueur() == 0){
			printf("\n\n\n **********Toutes les cases sont pleine, partie terminée***************\n"); 
			printf("************************Aucun gagant**********************************\n");
			continuer = 0; 
		}
		
		v++; 
	}	 
}

