#include <stdio.h>
#include <stdlib.h>

// =============================== STRUCTURES ===============================
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

// =============================== OUTILS GENERIQUES ===============================
void afficherListeSimple(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void afficherListeDouble(DNode *head) {
    DNode *curr = head;
    while (curr) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void afficherListeDoubleCirculaire(DNode *head, int n) {
    if (!head) return;
    DNode *curr = head;
    int count = 0;
    do {
        printf("%d <-> ", curr->data);
        curr = curr->next;
        count++;
    } while (curr != head && count < n);
    printf("(retour au debut...)\n");
}

// =============================== PARTIE 1 ===============================
// Création liste simple prédéfinie et suppression occurrences
Node* creerListeSimple() {
    int valeurs[7] = {2, 4, 2, 7, 5, 2, 9};
    Node *head = NULL, *temp = NULL;
    for (int i = 0; i < 7; i++) {
        Node *n = malloc(sizeof(Node));
        n->data = valeurs[i];
        n->next = NULL;
        if (!head) head = n;
        else temp->next = n;
        temp = n;
    }
    return head;
}

Node* supprimerOccurrences(Node *head, int val) {
    Node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data == val) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            curr = (prev) ? prev->next : head;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

// =============================== PARTIE 2 ===============================
// Vérifier si liste simple est triée, sinon la trier, puis insérer
int estTriee(Node *head) {
    while (head && head->next) {
        if (head->data > head->next->data) return 0;
        head = head->next;
    }
    return 1;
}

Node* insererTrie(Node *head, int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    if (!head || val < head->data) {
        n->next = head;
        return n;
    }
    Node *curr = head;
    while (curr->next && curr->next->data < val) curr = curr->next;
    n->next = curr->next;
    curr->next = n;
    return head;
}

Node* trierListeSimple(Node *head) {
    if (!head) return NULL;
    Node *sorted = NULL;
    Node *curr = head;
    while (curr) {
        sorted = insererTrie(sorted, curr->data);
        Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    return sorted;
}

// =============================== PARTIE 3 ===============================
// Liste doublement chaînée triée
DNode* creerListeDouble() {
    int valeurs[7] = {7, 3, 9, 1, 4, 2, 6};
    DNode *head = NULL, *temp = NULL;
    for (int i = 0; i < 7; i++) {
        DNode *n = malloc(sizeof(DNode));
        n->data = valeurs[i];
        n->prev = n->next = NULL;
        if (!head) head = n;
        else {
            temp->next = n;
            n->prev = temp;
        }
        temp = n;
    }
    return head;
}

DNode* insererDoubleTrie(DNode *head, int val) {
    DNode *n = malloc(sizeof(DNode));
    n->data = val;
    n->prev = n->next = NULL;
    if (!head) return n;
    if (val < head->data) {
        n->next = head;
        head->prev = n;
        return n;
    }
    DNode *curr = head;
    while (curr->next && curr->next->data < val) curr = curr->next;
    n->next = curr->next;
    if (curr->next) curr->next->prev = n;
    curr->next = n;
    n->prev = curr;
    return head;
}

DNode* trierListeDouble(DNode *head) {
    if (!head) return NULL;
    DNode *sorted = NULL;
    DNode *curr = head;
    while (curr) {
        sorted = insererDoubleTrie(sorted, curr->data);
        DNode *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    return sorted;
}

// =============================== PARTIE 4 ===============================
// Liste doublement chaînée circulaire
DNode* creerListeDoubleCirculaire() {
    int valeurs[7] = {1, 2, 3, 4, 5, 6, 7};
    DNode *head = NULL, *temp = NULL;
    for (int i = 0; i < 7; i++) {
        DNode *n = malloc(sizeof(DNode));
        n->data = valeurs[i];
        n->prev = n->next = NULL;
        if (!head) head = n;
        else {
            temp->next = n;
            n->prev = temp;
        }
        temp = n;
    }
    head->prev = temp;
    temp->next = head; // circularité
    return head;
}

DNode* insererTeteCirculaire(DNode *head, int val) {
    DNode *n = malloc(sizeof(DNode));
    n->data = val;
    n->prev = head->prev;
    n->next = head;
    head->prev->next = n;
    head->prev = n;
    return n; // nouvelle tête
}

// =============================== PARTIE 5 ===============================
DNode* insererQueueCirculaire(DNode *head, int val) {
    DNode *n = malloc(sizeof(DNode));
    n->data = val;
    n->prev = head->prev;
    n->next = head;
    head->prev->next = n;
    head->prev = n;
    return head; // tête inchangée
}

// =============================== PROGRAMME PRINCIPAL ===============================
int main() {
    int choix, val;
    Node *listeSimple = NULL;
    DNode *listeDouble = NULL, *listeCirculaire = NULL;

    do {
        printf("\n==== MENU ====\n");
        printf("1 - Liste simple : supprimer occurrences\n");
        printf("2 - Liste simple : verifier tri et inserer\n");
        printf("3 - Liste double : inserer trie (si non triee -> tri)\n");
        printf("4 - Liste double circulaire : inserer en tete\n");
        printf("5 - Liste double circulaire : inserer tete et queue\n");
        printf("0 - Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\n--- PARTIE 1 ---\n");
                printf("Definition : une occurrence est une apparition d'une valeur dans la liste.\n");
                listeSimple = creerListeSimple();
                afficherListeSimple(listeSimple);
                printf("Valeur a supprimer : ");
                scanf("%d", &val);
                listeSimple = supprimerOccurrences(listeSimple, val);
                afficherListeSimple(listeSimple);
                break;

            case 2:
                printf("\n--- PARTIE 2 ---\n");
                printf("Definition : une liste simplement chainee est une suite de nœuds relies par un pointeur vers le suivant.\n");
                listeSimple = creerListeSimple();
                afficherListeSimple(listeSimple);
                if (!estTriee(listeSimple)) {
                    printf("La liste n'est pas triee -> on la trie.\n");
                    listeSimple = trierListeSimple(listeSimple);
                }
                printf("Liste apres tri :\n");
                afficherListeSimple(listeSimple);
                printf("Entrez une valeur a inserer : ");
                scanf("%d", &val);
                listeSimple = insererTrie(listeSimple, val);
                afficherListeSimple(listeSimple);
                break;

            case 3:
                printf("\n--- PARTIE 3 ---\n");
                printf("Definition : une liste doublement chainee a des pointeurs prev et next.\n");
                listeDouble = creerListeDouble();
                afficherListeDouble(listeDouble);
                printf("On trie la liste...\n");
                listeDouble = trierListeDouble(listeDouble);
                afficherListeDouble(listeDouble);
                printf("Entrez une valeur à inserer : ");
                scanf("%d", &val);
                listeDouble = insererDoubleTrie(listeDouble, val);
                afficherListeDouble(listeDouble);
                break;

            case 4:
                printf("\n--- PARTIE 4 ---\n");
                printf("Definition : une liste doublement chainee circulaire relie le dernier au premier.\n");
                listeCirculaire = creerListeDoubleCirculaire();
                afficherListeDoubleCirculaire(listeCirculaire, 10);
                printf("Entrez une valeur à inserer en tete : ");
                scanf("%d", &val);
                listeCirculaire = insererTeteCirculaire(listeCirculaire, val);
                afficherListeDoubleCirculaire(listeCirculaire, 10);
                break;

            case 5:
                printf("\n--- PARTIE 5 ---\n");
                listeCirculaire = creerListeDoubleCirculaire();
                afficherListeDoubleCirculaire(listeCirculaire, 10);
                printf("Entrez une valeur a inserer en tete : ");
                scanf("%d", &val);
                listeCirculaire = insererTeteCirculaire(listeCirculaire, val);
                afficherListeDoubleCirculaire(listeCirculaire, 10);
                printf("Entrez une valeur a inserer en queue : ");
                scanf("%d", &val);
                listeCirculaire = insererQueueCirculaire(listeCirculaire, val);
                afficherListeDoubleCirculaire(listeCirculaire, 10);
                break;
        }
    } while (choix != 0);

    return 0;
}
