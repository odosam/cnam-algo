#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


// void partie1(){
//     int x = 5;
//     int y = 10; 

//     //affichage
//     printf("Valeur de x : %d \n", x);
//     printf("Valeur de y : %d \n", y);

//     printf("Adresse de x : %p \n", &x);
//     printf("Adresse de y : %p \n", &y);

//     // conversion des adresses en long int pour faire des calculs
//     long int addr_x = (long int)&x;
//     long int addr_y = (long int)&y;

//     // affichage en long int
//     printf("Adresse de x en long int : %ld\n", addr_x);
//     printf("Adresse de y en long int : %ld\n", addr_y);

//     // différence entre les adresses
//     long int difference = addr_y - addr_x;
//     printf("Difference entre les adresses : %ld\n", difference);

//     //Alignement de variable ---- sizeof : taille en octet de la variable
//     int x1 = 5;
//     double x2 = 5.55;
//     float x3 = 8.555;
//     char x4 = 'A';

//     printf("Taille de x1 (int)  : %ld\n", sizeof(x1));
//     printf("Taille de x2 (double)  : %ld\n", sizeof(x2));
//     printf("Taille de x3 (float)  : %ld\n", sizeof(x3));
//     printf("Taille de x4 (char)  : %ld\n", sizeof(x4));


//     // Alignement d'un tableau
//     int tab[5] = {0,1,2,3,4};

//     for(int i = 0 ; i < 5 ; i++){
//         int a = tab[i];
//         long int addr = (long int) &a;

//         printf("Adresse occurence %d  : %ld\n", i, &tab[i]);
//     }

//     //Effet de ++ sur un pointeur
//     int cpt = 0;
//     cpt++;
//     printf("CPT : %ld \n", cpt);

//     int* cpt2 = 0;
//     cpt2++; 
//     printf("CPT2 : %ld \n", cpt2); // cpt sans pointeur c'est +1, avec pointeur +4

// }

void calculTab(float tab[], int taille, float* min, float* moy, float* max){
//Fonction qui fait calcule le min, le max et la moyenne d'un tableau de float
// -> faire une fonction normale mais sans return : passage des valeurs par des pointeurs. Valeurs qui seront récupérées via le main grace à l'adresse.   

    // initialisation au premier element
    *min= tab[0];
    *max = tab[0];
    int sommeTab;

    for(int i = 0 ; i < taille ; i++){

        // Si l'element i+1 est plus grand que le max actuel, alors c'est le max
        if(tab[i] < *min){
            *min = tab[i];
        }
        if(tab[i] > *max){
            *max = tab[i];
        }
        
        sommeTab += tab[i];
        
    }

    *moy = sommeTab / taille;

}

int tailleChar(char tab[]){

    int longueur = 0;

    while(tab[longueur] != '\0'){
        longueur++;
    }

    return longueur;
}

bool compare(char tab1[], char tab2[]){

    int i = 0;

    while (tab1[i] != '\0' && tab2[i] != '\0') {
        if (tab1[i] != tab2[i]) {
            return false;
        }
        i++;
    }

    if (tab1[i] != '\0' || tab2[i] != '\0') {
        return false;
    }

    return true;

}
// pointeur pour accéder à l'adresse de la premiere lettre du tableau, afin de ne pas à avoir copier la chaine dans la fonction -> gain mémoire
bool palindrome(char* mot){

    int debut = 0;
    int fin = strlen(mot) - 1;

    while(debut < fin){
        if(mot[debut] != mot[fin]){ // si la lettre à l'indice début n'est pas la même que fin, pas palindrome
            return false;
        }
        debut++;
        fin--;
    }

    return true;
}

int find_sub_string(char* chaine1,char* chaine2){

    //parcourir la chaine 1 et la chaine 2 tant qu'elle est pas vide
        //si la lettre de la ch1 correspond à la ch2 : on compare la ch1[i+1] à ch2[i+1]
            // si la même chose, on continue
    
    int longueur1 = 0, longueur2 = 0;

    while(chaine1[longueur1] != '\0'){
        longueur1++;
    }

    while(chaine2[longueur2] != '\0'){
        longueur2++;
    }

    printf("Longueur chaine 1 : %d \n",longueur1);

    // tant que i est inférieur à la longueur de la chaine - longueur chaine 2
    for(int i = 0 ; i < longueur1 - longueur2 ; i++){
        int j;
        for(j = 0 ; j < longueur2 ; j++){
            if(chaine1[i+j] != chaine2[j]){
                break;
            }
        }
        if(j == longueur2){
            return i;

        }
        
    }
    
    return -1;


}

int string_to_int(char* mot){
    return atoi(mot);
}


int main(){
    
    //partie1();
    
    // Fonction à plusieurs résultats
    float tabFloat[] = {1.5, 3.2, 5.8, 0.9, 2.4};
    float min, max, moy;

    // taille totale du tableau / par la taille d'un element = nombre d'elements dans le tableau
    int taille = sizeof(tabFloat) / sizeof(tabFloat[0]);

    calculTab(tabFloat,5, &min, &moy, &max);

    printf("Min: %.2f\n", min);
    printf("Max: %.2f\n", max);
    printf("Moyenne: %.2f\n", moy);

    //Longueur char
    char mot[] = "Test";
    int longChar = tailleChar(mot);
    printf("Voici la longueur du mot : %d \n", longChar);
    

    //Test de deux chaînes
    char chaineA[] = "Test";
    char chaineB[] = "TestA";

    if(compare(chaineA,chaineB)){
        printf("Les chaines sont similaires ! \n");
    }
    else{
        printf("Elles ne sont pas similaires ! \n");
    }

    // Palindrome
    char mot1[] = "kayiak";
    palindrome(mot1);
    
    if( palindrome(mot1)){
        printf("C'est un palindrome ! \n");
    }
    else{ printf("Ce n'est pas un palindrome ! \n");}

    // Sous chaine
    char chaine1[] ="Salut c'est moi !";
    char chaine2[] = "c'est";
    int position;

    position = find_sub_string(chaine1, chaine2);

    if(position != -1){
        printf("Voici la position de la sous chaine : %d \n",position);
    }
    else{ printf("Pas de sous chaine trouvée \n");}

    // String to int
    char mot3[] = "123";

    int nouveauMot3 = string_to_int(mot3);
    printf("Voici le chiffre : %d \n ",nouveauMot3);


}