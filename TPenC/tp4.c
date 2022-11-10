#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define tailleTab1D(n) sizeof(n)/sizeof(n[0])


void ajoute (int *v, int n); //ajoute n à v, renvoie rien

void mutation (char *p, char c); //p deviens c

void echange_points_de_vie( int *vieJoueur1,int *vieJoueur2); 

void conversion(int *s,int *min,int *h,int *j);    // passe de s à jour, h, min,s

int recherche_lineaire (int v, int a[], int taille);

int estTrie(float tab[], int taille);

int recherche_dichotomie (int v, int a[], int taille);

int compteurDeLettres(char c[]);

void affichemaxString(char *argv[], int argc);

void inverseMajMin(char c[]);

int MotEstUnPalindrome(char c[]);


/*------------------------------------------------------------------------------------

                              Exo 1 : pointeur
                             
--------------------------------------------------------------------------------------------------------*/

void ajoute (int *v, int n){
	printf("adresse de n procedure : %p \n", &n);
	printf("adresse de v procedure : %p \n", &v);
	printf("valeur v procedure (dc sont adresse ds le main car ici v est un pointeur): %p \n", v);
	printf("valeur pointé par v procedure : %d \n", *v);
	*v=*v+n;
}

/*int main(){
	int v;
	printf("adresse de v : %p \n", &v);
	int n;
	printf("adresse de n : %p \n", &n);
	v=5;
	n=6;
	ajoute (&v,n);
	printf("v=%d et n=%d \n", v ,n);
	return (0);
}*/


/*------------------------------------------------------------------------------------

                              Exo 2 : pointeur
                             
--------------------------------------------------------------------------------------------------------*/

void mutation (char *p, char c){
	*p=c;	
}

/*int main (){ 
	char p='A';
	char c='G';
	printf("p vaut : %c  et c : %c \n",p,c);
	mutation (&p, c);
	printf("maintenant p vaut : %c et c : %c \n", p,c);
	return (0);
}*/


/*------------------------------------------------------------------------------------

                              Exo 3 : pointeur
                             
--------------------------------------------------------------------------------------------------------*/

void echange_points_de_vie( int *vieJoueur1, int *vieJoueur2){
	int c= *vieJoueur1;
	*vieJoueur1 = *vieJoueur2;
	*vieJoueur2= c;
}

/*int main(){
	int vie1=10;
	int vie2=1;
	printf("vie1 vaut : %d  et vie2 : %d \n",vie1,vie2);
	echange_points_de_vie(&vie1,&vie2);
	printf("Maintenant vie1 vaut : %d  et vie2 : %d \n",vie1,vie2);
	return 0;
}*/


/*------------------------------------------------------------------------------------

                              Exo 4 : pointeur (bonus)
                             
--------------------------------------------------------------------------------------------------------*/

void conversion(int *s,int *min,int *h,int *j){    // passe de s à jour, h, min,s
	*j= *s/(60*60*24);
	*s = *s- (*j) *60*60*24;
	*h=*s/(60*60);
	*s= *s- (*h)*60*60;
	*min= *s/60;
	*s =*s - (*min)*60;
}

/*int main(){
	int s=3500000;
	int min;
	int h;
	int j;
	conversion(&s,&min,&h,&j);
	printf(" %d jours %d h %d min %d s \n", j,h,min,s);
	return 0;
}*/


/*------------------------------------------------------------------------------------

                              Exo 5 : fonction et tableau
                             
--------------------------------------------------------------------------------------------------------*/


/*int main (){
	int tab[2];
	tab[0]=0;
	tab[1]=0;
	printf("l'adresse du tableau est %p \n", tab);
	printf("l'adresse de la case 1 tableau est %p \n", &tab[0]);
	printf("l'adresse de la case 2 tableau est %p \n", &tab[1]);
	printf("l'adresse d'une case hors tableau  est %p \n", &tab[2]);
	printf("une case hors tableau est %d \n", tab[2]);
	tab[2]=13;
	printf("la case hors tableau est %d \n", tab[2]); //on a une erruer mais c'est normal
	return 0;
}*/



/*------------------------------------------------------------------------------------

                              Exo 6 : fonction et tableau
                             
--------------------------------------------------------------------------------------------------------*/

int recherche_lineaire (int v, int a[], int taille){
	for (int i=0; i<taille; i++){
		if (a[i] == v) {return i;}	
	}
	return -1;
}


/*int main(){
	int v= 84;
	int a[]= {1,3,5,84,65,23,19,84,12};
	int n = tailleTab1D(a);
	int indice=recherche_lineaire ( v, a, n);
	printf("première fois qu'on trouve la valeur : indice %d \n",indice);
	return 0;
}*/



/*------------------------------------------------------------------------------------

                              Exo 7 : tableau trié ? (bonus)
                             
--------------------------------------------------------------------------------------------------------*/

int estTrie(float tab[], int taille){
	for(int i=1;i<taille;i++){
		if (tab[i]<tab[i-1]) return 0;
	}
	return 1;
}

/*int main(){
	float tab[]={ 1,9,4,3,6,5};
	float tab2[]={1,2,4,4,5};
	int size = tailleTab1D(tab);
	int size2 = tailleTab1D(tab2);
	printf("tab 1 croissant ? %d \n", estTrie(tab, size));
	printf("tab 2 croissant ? %d \n", estTrie(tab2, size2));
	return 0;}
	*/


/*------------------------------------------------------------------------------------

                              Exo 8 : dichotomie
                             
--------------------------------------------------------------------------------------------------------*/

int recherche_dichotomie (int v, int a[], int taille){ //pr un tableau trie
	int p=0;
	int g=taille-1;
	int m=(p+g)/2;
	while (a[m] != v && p<=g){
		if(a[m] < v) p=m+1;
		else g=m-1;
		m=(p+g)/2;
	}
	if (p>g) return -1;
	else return m;//l'indice de position
}
		
int main(){
	int tab[]= {0,3,4,8,9,12,16,17,19,26,30,45,50};
	int size= tailleTab1D(tab);
	int nb= 1;
	int indice=recherche_dichotomie(nb,tab,size);
	printf("l'indice de position est %d \n", indice);
	return 0;
}



/*------------------------------------------------------------------------------------

                              Exo 9 : string
                             
--------------------------------------------------------------------------------------------------------*/

int compteurDeLettres(char c[]){
	int i=0;
	int compte=0;
	while( c[i] != '\0'){
		if( (c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')) {compte++;}
		i++;
	}
	return compte;
}

/* int main(){
	char c[]="Vive le C !";
	int nbL= compteurDeLettres(c);
	printf("nb de lettre est %d \n", nbL);
	printf("nb caractère sans le 0 : %ld \n", strlen(c));
	return 0;

}*/

/*------------------------------------------------------------------------------------

                              Exo 10 : string
                             
--------------------------------------------------------------------------------------------------------*/
//version question 1
/*int main(int argc, char *argv[]){ //tp4 arg1 arg2...
	
	for (int i=1; i< argc;i++){
		printf("la chaine de cara est '%s' et elle est de taille %ld \n", argv[i], strlen(argv[i]));
	}
	return 0;
}*/

//version question 2

void affichemaxString(char *argv[], int argc){
	int max=1;
	for (int i=2; i< argc;i++){
		if (strlen (argv[i]) > strlen (argv[max])) {max=i;}
	}
	printf("Le plus long argument est : '%s' \n", argv[max]);
}


/*int main(int argc, char *argv[]){
	affichemaxString( argv, argc);
	return 0;
	}*/



/*------------------------------------------------------------------------------------

                              Exo 11 : Majuscule minuscule
                             
--------------------------------------------------------------------------------------------------------*/

void inverseMajMin(char c[]){
	int i=0;
	while (c[i]!='\0'){
		if(c[i] <='z' && c[i] >= 'a'){ // a=97, z=122 si lettre min
			//la lettre en maj sera code par (lettre-97)+65
			c[i]=c[i]-97 +65;
		}
		else if(c[i] <='Z' && c[i] >= 'A'){ // A=65, Z=90  si lettre maj
			//la lettre en maj sera code par (lettre-65)+97
			c[i]=c[i]-65 +97;
		}
		i++;
	}
	printf("%s \n", c);
}

/*int main (int argc, char *argv[]){
	for (int i=1; i< argc;i++){
		inverseMajMin(argv[i]);
	}
	return 0;
	}
	*/
	
	
/*------------------------------------------------------------------------------------

                              Exo 12 : Palindrome (bonus)
                             
--------------------------------------------------------------------------------------------------------*/

int MotEstUnPalindrome(char c[]){
	int size=strlen(c);
	for (int i=0; i<=(size+1)/2;i++){
		if (c[i] != c[size -1 -i]) {return 0;}
	}
	
	return 1;
}


void PhraseEnMot(char phrase[],char c[],int size){
	//tout coller en enlevant espace et cara ponctuation

	int j=0;
	
	for(int i=0;i<size;i++){ //parcours de c
	
		if (isalpha(c[i])){    //si c'est une lettre 
			phrase[j]=tolower(c[i]); //on la met ds mon tableau phrase en minuscule
			j++;
		}
		else if(c[i]=='\0'){phrase[j]='\0';}
	}	
}


/*int main (){
	char mot[80];
	int size =80;
	
	//recup le txt:
	printf("Votre mot ou phrase : \n");
	fgets(mot, size, stdin);
	mot[strcspn(mot,"\n")]='\0';
	
	//transfo en 1 mot:
	char phrase[80]; //aura la version collé de mot 
	PhraseEnMot(phrase,mot,80);

	//regarde si palindrome:
	int palin=MotEstUnPalindrome(phrase);
	if (palin){printf("C'est un palindrome. \n");}
	else {printf("Ce n'est pas un palindrome. \n");}
	
	return 0; 
	}
*/
	


/*------------------------------------------------------------------------------------

                              Exo 13 : gestion saisie
                             
--------------------------------------------------------------------------------------------------------*/

/*int main(){
	char mot[40+1]; //+1 pr le dernier cara \0
	int size =40+1;
	printf("Votre mot ou phrase : \n");
	fgets(mot, size, stdin);
	mot[strcspn(mot,"\n")]='\0';
	
	printf("mot : %s et taille : %ld \n", mot, strlen(mot));
	return 0;
}*/







