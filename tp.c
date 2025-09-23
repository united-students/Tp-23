#include <stdio.h>

// Définition de la structure pour le vecteur 3D
typedef struct {
    double x;
    double y;
    double z;
} Vecteur;

// 1. Implémentation de la somme de matrices
void sommeMatrices(int matrice1[10][10], int matrice2[10][10], int resultat[10][10], int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}

// 2. Implémentation du produit de matrices
void produitMatrices(int matrice1[10][10], int matrice2[10][10], int resultat[10][10], int lignes1, int colonnes1, int colonnes2) {
    for (int i = 0; i < lignes1; i++) {
        for (int j = 0; j < colonnes2; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < colonnes1; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

// 3. Implémentation de la recherche séquentielle
int rechercheSequentielle(int tableau[], int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            return i;
        }
    }
    return -1;
}

// 4. Implémentation de la multiplication avec +1
int produit_plus1(int a, int b) {
    int resultat = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            resultat++;
        }
    }
    return resultat;
}

// 5. Implémentation du test si un tableau est trié
int estTrie(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// 6. Implémentation du tri par insertion (nécessaire pour la médiane)
void triInsertion(int tableau[], int taille) {
    for (int i = 1; i < taille; i++) {
        int temp = tableau[i];
        int j = i - 1;
        while (j >= 0 && tableau[j] > temp) {
            tableau[j + 1] = tableau[j];
            j--;
        }
        tableau[j + 1] = temp;
    }
}

// 7. Implémentation de la médiane
double trouverMedian(int tableau[], int taille) {
    triInsertion(tableau, taille);

    if (taille % 2 == 1) {
        return (double)tableau[taille / 2];
    } else {
        return (double)(tableau[taille / 2 - 1] + tableau[taille / 2]) / 2.0;
    }
}

// 8. Implémentation de l'inversion de tableau
void inverserTableau(int tableau[], int taille) {
    int temp;
    for (int i = 0; i < taille / 2; i++) {
        temp = tableau[i];
        tableau[i] = tableau[taille - 1 - i];
        tableau[taille - 1 - i] = temp;
    }
}

// 9. Implémentation du produit vectoriel
Vecteur produitVectoriel(Vecteur v1, Vecteur v2) {
    Vecteur resultat;
    resultat.x = v1.y * v2.z - v1.z * v2.y;
    resultat.y = v1.z * v2.x - v1.x * v2.z;
    resultat.z = v1.x * v2.y - v1.y * v2.x;
    return resultat;
}

// 10. Implémentation du produit vecteur*matrice
void produitVecteurMatrice(int vecteur[], int matrice[10][10], int resultat[], int tailleVecteur, int colonnesMatrice) {
    for (int j = 0; j < colonnesMatrice; j++) {
        resultat[j] = 0;
        for (int i = 0; i < tailleVecteur; i++) {
            resultat[j] += vecteur[i] * matrice[i][j];
        }
    }
}

// Fonctions d'aide pour l'affichage
void afficherMatrice(int mat[10][10], int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void afficherTableau(int tab[], int taille) {
    printf("[ ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}

int main() {
    int choix;
    int tableau[100];
    int matrice1[10][10], matrice2[10][10], resultatMatrice[10][10];
    int vecteur[10], resultatVecteur[10];
    int taille, lignes1, colonnes1, lignes2, colonnes2;
    int element, indice;
    Vecteur v1, v2, resultatProdVec;
    int a, b;

    do {
        printf("\n--- Menu des Operations ---\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle dans un tableau\n");
        printf("4. Produit a*b en utilisant uniquement +1\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Calculer le median d'un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur * matrice\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le nombre de lignes et de colonnes : ");
                scanf("%d %d", &lignes1, &colonnes1);
                printf("Entrez les elements de la premiere matrice :\n");
                for (int i = 0; i < lignes1; i++) {
                    for (int j = 0; j < colonnes1; j++) {
                        scanf("%d", &matrice1[i][j]);
                    }
                }
                printf("Entrez les elements de la deuxieme matrice :\n");
                for (int i = 0; i < lignes1; i++) {
                    for (int j = 0; j < colonnes1; j++) {
                        scanf("%d", &matrice2[i][j]);
                    }
                }
                sommeMatrices(matrice1, matrice2, resultatMatrice, lignes1, colonnes1);
                printf("Resultat de la somme :\n");
                afficherMatrice(resultatMatrice, lignes1, colonnes1);
                break;

            case 2:
                printf("Entrez les dimensions de la premiere matrice (lignes colonnes) : ");
                scanf("%d %d", &lignes1, &colonnes1);
                printf("Entrez les dimensions de la deuxieme matrice (lignes colonnes) : ");
                scanf("%d %d", &lignes2, &colonnes2);
                if (colonnes1 != lignes2) {
                    printf("Erreur : Les dimensions ne correspondent pas pour le produit.\n");
                    break;
                }
                printf("Entrez les elements de la premiere matrice :\n");
                for (int i = 0; i < lignes1; i++) {
                    for (int j = 0; j < colonnes1; j++) {
                        scanf("%d", &matrice1[i][j]);
                    }
                }
                printf("Entrez les elements de la deuxieme matrice :\n");
                for (int i = 0; i < lignes2; i++) {
                    for (int j = 0; j < colonnes2; j++) {
                        scanf("%d", &matrice2[i][j]);
                    }
                }
                produitMatrices(matrice1, matrice2, resultatMatrice, lignes1, colonnes1, colonnes2);
                printf("Resultat du produit :\n");
                afficherMatrice(resultatMatrice, lignes1, colonnes2);
                break;

            case 3:
                printf("Entrez la taille du tableau : ");
                scanf("%d", &taille);
                printf("Entrez les elements du tableau : ");
                for (int i = 0; i < taille; i++) {
                    scanf("%d", &tableau[i]);
                }
                printf("Entrez l'element a rechercher : ");
                scanf("%d", &element);
                indice = rechercheSequentielle(tableau, taille, element);
                if (indice != -1) {
                    printf("Element trouve a l'indice %d.\n", indice);
                } else {
                    printf("Element non trouve.\n");
                }
                break;

            case 4:
                printf("Entrez deux nombres a et b (a > 0, b > 0) : ");
                scanf("%d %d", &a, &b);
                printf("Le produit de %d * %d est : %d\n", a, b, produit_plus1(a, b));
                break;

            case 5:
                printf("Entrez la taille du tableau : ");
                scanf("%d", &taille);
                printf("Entrez les elements du tableau : ");
                for (int i = 0; i < taille; i++) {
                    scanf("%d", &tableau[i]);
                }
                if (estTrie(tableau, taille)) {
                    printf("Le tableau est trie.\n");
                } else {
                    printf("Le tableau n'est pas trie.\n");
                }
                break;

            case 6:
                printf("Entrez la taille du tableau : ");
                scanf("%d", &taille);
                printf("Entrez les elements du tableau : ");
                for (int i = 0; i < taille; i++) {
                    scanf("%d", &tableau[i]);
                }
                printf("La mediane est : %.2f\n", trouverMedian(tableau, taille));
                break;

            case 7:
                printf("Entrez la taille du tableau : ");
                scanf("%d", &taille);
                printf("Entrez les elements du tableau : ");
                for (int i = 0; i < taille; i++) {
                    scanf("%d", &tableau[i]);
                }
                inverserTableau(tableau, taille);
                printf("Tableau inverse : ");
                afficherTableau(tableau, taille);
                break;

            case 8:
                printf("Entrez les coordonnees du vecteur 1 (x y z) : ");
                scanf("%lf %lf %lf", &v1.x, &v1.y, &v1.z);
                printf("Entrez les coordonnees du vecteur 2 (x y z) : ");
                scanf("%lf %lf %lf", &v2.x, &v2.y, &v2.z);
                resultatProdVec = produitVectoriel(v1, v2);
                printf("Resultat du produit vectoriel : (%.2f, %.2f, %.2f)\n", resultatProdVec.x, resultatProdVec.y, resultatProdVec.z);
                break;

            case 9:
                printf("Entrez la taille du vecteur et le nombre de colonnes de la matrice : ");
                scanf("%d %d", &taille, &colonnes1);
                printf("Entrez les elements du vecteur : ");
                for (int i = 0; i < taille; i++) {
                    scanf("%d", &vecteur[i]);
                }
                printf("Entrez les elements de la matrice (taille %d x %d) :\n", taille, colonnes1);
                for (int i = 0; i < taille; i++) {
                    for (int j = 0; j < colonnes1; j++) {
                        scanf("%d", &matrice1[i][j]);
                    }
                }
                produitVecteurMatrice(vecteur, matrice1, resultatVecteur, taille, colonnes1);
                printf("Resultat du produit vecteur * matrice : ");
                afficherTableau(resultatVecteur, colonnes1);
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}
