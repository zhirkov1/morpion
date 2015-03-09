#include"morpion.h"

int main(){
	char nom[N]; 
	char prenom[N]; 
	Symbole_t s; 
	
	printf("\n\nIntroduisez: Nom Prenom Symbole (symbole est un entier)\n"); 
	printf("Attention: le nom et le prenom ne doivent pas être composé\n\n"); 
	printf("Exemple: RUKATA David 1\n\n"); 
	printf("Joueur 1: \n"); 
	scanf("%s %s %d", nom, prenom, &s);
	printf("\n\n"); 
	ajouter_joueur(nom, prenom, s); 
	
	printf("Joueur 2: \n"); 
	scanf("%s %s %d", nom, prenom, &s);
	ajouter_joueur(nom, prenom, s);
	
	printf("\nPour joueur, il suffit de taper les coordonnéer (i,j) de la case que vous ciblez\n");
	printf("Sachant que: \n1 <= i <= 3 \n1 <= j <= 3\n\n");
	printf("Debut du jeu:");   
	
	jouer_partie(); 
	
	return 0; 
}
