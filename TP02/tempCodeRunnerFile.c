void partie1(){
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
