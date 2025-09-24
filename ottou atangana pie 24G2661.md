#implemrntation de la somme
'''// 1. Implémentation de la somme de matrices
void sommeMatrices(int matrice1[10][10], int matrice2[10][10], int resultat[10][10], int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}
'''
#implementation du produit le tout a l aide dun tableau et d une simple boucle for
'''// 2. Implémentation du produit de matrices
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
'''
