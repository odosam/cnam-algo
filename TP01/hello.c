#include <stdio.h>
#include <math.h>

void nb(){
    int entier;
    float decimal;

    printf("Saisir un entier : \n");
    scanf("%d",&entier);

    printf("Saisir un decimal : \n");
    scanf("%f",&decimal);

    printf("Voici le nombre entier : %d \n", entier);
    printf("Voici le nombre decimal : %f \n", decimal);
}

void estBissextile(int annee){

    if( (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0) ){
        printf("Il y a %d jours dans ce mois.", 28 );
    }
    else{  
        printf("Il y a %d jours dans ce mois.", 29 );
    }

}

void jourDansMois(int mois){

    if(mois == 2 || mois == 4 || mois == 6 || mois == 9 || mois == 11 ){
        printf("Il y a 30 jours dans ce mois.\n");
    }
    else{
        printf("Il y a 31 jours dans ce mois. \n");
    }
}

void carre(){

    int cote;
    printf("Saisir un cote d'un carre : \n");
    scanf("%d",&cote);

    // perimetre
    int peri;
    peri = cote * 4;
    printf("Le perimetre est de : %d \n",peri);

    //surface
    int surface;
    surface = cote * cote;
    printf("La surface est de : %d \n", surface);

    //diagonale
    float diag;
    diag = sqrt(2) * cote;
    printf("La diag est de : %.2f \n", diag);


}

int convertToS(int heure, int min, int seconde){

    return heure * 3600 + min * 60 + seconde;
}

int nbJourDansMois(int mois){

    if(mois == 2 || mois == 4 || mois == 6 || mois == 9 || mois == 11 ){
        return 30;
    }
    else{
        return 31;
    }
}

int main(){

    //printf("Hello world \n");

    // nb();
    //carre();

    // nb de jours dans un mois
    int mois, annee;
    printf("Quel mois et quelle annee veux-tu ?");
    scanf("%d %d",&mois, &annee);


    if( mois == 2){
        estBissextile(annee);
    }
    else{
        jourDansMois(mois);
    }
    
    //Calcul de duree
    int heure, min, seconde, choix, res;
    int heure2, min2, seconde2;
    int temps1, temps2;

    int jour;

    printf("Veuillez saisir un premier temps sous la forme heure minutes secondes . \n");
    scanf("%d %d %d", &heure, &min, &seconde);

    printf("Veuillez saisir un premier temps sous la forme heure minutes secondes . \n");
    scanf("%d %d %d", &heure2, &min2, &seconde2);

    printf("Meme jour (1), Deux jours consecutifs (2)");
    scanf("%d", choix);

    if( choix == 1){

        temps1 = convertToS(heure,min,seconde);
        temps2 = convertToS(heure2,min2,seconde2);

        res = temps2 - temps1;
        printf("Durée en secondes : %d\n", res);

    }
    else if(choix == 2){
        temps1 = convertToS(heure,min,seconde);
        temps2 = convertToS(heure2,min2,seconde2);

        res = (86400 - temps1) + temps2;

    }
    else{
        printf("Veuillez entrer un resultat valide");
    }

    


    // dernier exo
    int nbJours;

    printf("Veuillez entrer une date (jour mois annee)");
    scanf("%d %d %d", &jour, &mois, &annee);

    nbJours = nbJourDansMois(mois);

    if( jour < nbJours){
        jour++;

    }
    else if(jour == nbJours){
        jour = 1;
        mois++;
    }
    else if(mois == 12){
        jour = 1;
        mois = 1;
        annee++;
    }
    else{ 
        printf("Veuillez saisir une date valide");
    }











}

