#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void random_fill_int(int tab[],int size, int vmin, int vmax){

    for(int i = 0 ; i < size ; i++){
        tab[i] = vmin + rand() % (vmax - vmin + 1);
    }

}

void random_fill_float(float tabFloat[],int size, int vmin, int vmax){

    for(int i = 0 ; i < size ; i++){
        tabFloat[i] = vmin + ((float)rand() / RAND_MAX) * (vmax - vmin);
    }

}

void print(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]); 
    }
    printf("\n");
}

void printFloat(float tab[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.3f ", tab[i]); 
    }
    printf("\n");
}

void read(int tab[], int size) {
    int nb;
    for(int i = 0; i < size; i++) {
        printf("Entrez l'element %d: ", i);
        scanf("%d", &nb);
        tab[i] = nb;
    }

}

int valMax(int tab[], int size){

    int nbMax = tab[0];  

    for (int i = 1; i < size; i++) {  
        if (tab[i] > nbMax) {
            nbMax = tab[i];
        }
    }

    return nbMax;
}

void swap_elt(int tab[], int i, int j){
    int temp = 0;

    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;

}

int occurences(int tab[], int size, int elt){
    int cpt = 0;

    for(int i = 0; i < size ; i++){
        if(tab[i] == elt){
            cpt++;
        }
    }

    return cpt;
}

int main() {
    srand(time(NULL));
    int size, size2, vmin, vmax, nbOccu;

    //Tab 1D --------------------------------------------
    printf("Entrez la taille du tableau 1: ");
    scanf("%d", &size); //si juste size, scanf aura juste une copie de la valeur et pourra pas modifier la variable originale

    int tabInt[size];
    random_fill_int(tabInt, size,0,5);
    //read(tabInt, size);
    print(tabInt, size);
    int valeurMax = valMax(tabInt,size);
    printf("Voici le max : %d \n",valeurMax);

    swap_elt(tabInt,0,1);
    printf("Tableau apres echange : ");
    print(tabInt,size);

    printf("Quel nombre souhaitez vous compter? \n");
    scanf("%d",&nbOccu);
    int resOccu = occurences(tabInt,size,nbOccu);
    printf("Il apparait %d fois \n",resOccu);


    printf("Entrez la taille du tableau 2 :\n ");
    scanf("%d", &size2); 

    float tabFloat[size2];

    random_fill_float(tabFloat, size,0,5);
    printf("Tableau float : \n");
    printFloat(tabFloat,size);


    return 0;
}   