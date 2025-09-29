Ce programme en C est une suite complète de fonctions conçues pour implémenter, manipuler et démontrer le fonctionnement des principales structures de données basées sur les listes chaînées : listes simples, listes doubles, et leurs variantes circulaires. Il s'organise autour de cinq parties principales accessibles via un menu interactif.

1. Structures de Nœuds (STRUCTS)

Le programme définit les structures fondamentales pour chaque type de liste :

    Node (Liste Simplement Chaînée): Contient une donnée entière (data) et un pointeur next vers l'élément suivant.

    DNode (Liste Doublement Chaînée): Contient une donnée entière (data) et deux pointeurs : prev vers l'élément précédent et next vers l'élément suivant.

2. Outils Génériques d'Affichage

Quatre fonctions sont dédiées à l'affichage, essentielles pour visualiser l'état des listes :

    afficherListeSimple / afficherListeDouble: Affichent les listes linéaires jusqu'à NULL.

    afficherListeCirculaireSimple / afficherListeCirculaireDouble: Affichent les listes circulaires. Elles utilisent un argument tours pour limiter l'affichage (à 15 nœuds dans le main) et ainsi éviter les boucles infinies.

3. Partie 1 : Gestion des Occurrences (Liste Simple)

Cette section se concentre sur les opérations de modification structurelle des listes simples.

    creerListeSimple1(): Crée une liste simple non triée contenant des doublons (ex: {2, 4, 2, 7, 5, 2, 9}).

    supprimerOccurrences(Node *head, int val):

        Parcourt la liste en utilisant des pointeurs curr (courant) et prev (précédent).

        Si le nœud courant contient la valeur cible, il est supprimé en rechaînant le pointeur next du nœud prev.

        Gère la suppression en tête (mise à jour de head) et au milieu/fin de la liste.

        La mémoire de chaque nœud supprimé est correctement libérée (free).

4. Partie 2 : Tri et Insertion Triée (Liste Simple)

Cette section introduit la notion d'ordre et de maintenance des listes triées.

    estTriee(Node *head): Fonction de vérification simple, retournant vrai (1) si la liste est en ordre croissant.

    insererTrie(Node *head, int val): Insère une nouvelle valeur dans une liste déjà triée tout en maintenant l'ordre. Elle gère l'insertion en tête et au milieu/fin.

    trierListeSimple(Node *head): Implémente le Tri par Insertion (Insertion Sort). Elle construit une nouvelle liste triée (sorted) en transférant les valeurs de la liste d'origine une par une via la fonction insererTrie. Attention : la liste d'origine est détruite et ses nœuds libérés pendant le processus.

5. Partie 3 : Tri et Insertion Triée (Liste Double)

Les concepts précédents sont étendus aux listes doublement chaînées, nécessitant une gestion plus complexe des pointeurs.

    creerListeDouble(): Crée une liste double en initialisant correctement les pointeurs prev et next.

    insererDoubleTrie(DNode *head, int val): Insère une valeur dans une liste double triée. L'opération nécessite de mettre à jour quatre pointeurs pour assurer la cohérence de la double liaison au point d'insertion.

    trierListeDouble(DNode *head): Utilise le tri par insertion en exploitant insererDoubleTrie.

6. Partie 4 : Opérations sur Liste Circulaire Simple

Cette structure relie le dernier nœud au premier.

    creerListeCirculaireSimple(): Initialise la circularité en faisant pointer le dernier nœud (temp->next) vers la tête (head).

    insererTeteCirculaireSimple(Node *head, int val):

        Nécessite de parcourir la liste pour trouver le dernier nœud (celui dont next pointe vers head).

        Met à jour le pointeur next du dernier nœud vers le nouveau nœud, et le nouveau nœud devient la tête.

    insererQueueCirculaireSimple(Node *head, int val): Similaire à l'insertion en tête, elle nécessite de parcourir la liste pour insérer le nouveau nœud entre l'ancien dernier nœud et la tête.

7. Partie 5 : Opérations sur Liste Circulaire Double

Cette structure combine les avantages de la double liaison et de la circularité (le dernier nœud est lié à la tête, et la tête est liée au dernier).

    creerListeCirculaireDouble(): Initialise la double circularité : dernier->next = head et head->prev = dernier.

    insererTeteCirculaireDouble(DNode *head, int val):

        L'insertion en tête est très efficace (complexité O(1)) car le dernier nœud est directement accessible via head->prev.

        Quatre pointeurs sont mis à jour pour insérer le nouveau nœud et en faire la nouvelle tête.

    insererQueueCirculaireDouble(DNode *head, int val):

        Comme l'insertion en tête, l'insertion en queue est O(1) en accédant au dernier élément via head->prev.

        Le nouveau nœud devient le nouveau dernier élément, et la fonction retourne la tête d'origine.

8. Fonction main() et Menu Interactif

La fonction principale (main) sert de pilote pour l'ensemble du programme. Elle offre un menu interactif qui permet à l'utilisateur de choisir et de tester chaque fonctionnalité de manière séquentielle, avec affichage des résultats avant et après chaque opération.

9. Détail des Parties Thématiques (Fonctionnalités)

Chaque cas du menu illustre une problématique courante dans la gestion des listes chaînées.

Partie 1 : Liste Simple - Suppression 🗑️

    Focus: Gérer la suppression d'éléments multiples (occurrences) dans une liste non triée.

    Fonction Clé: supprimerOccurrences. Elle est appelée après que la liste (lsimple) a été créée avec des doublons, démontrant comment maintenir la continuité de la chaîne lors de la libération de la mémoire.

Partie 2 : Liste Simple - Tri et Insertion Triée 📈

    Focus: Appliquer un algorithme de tri (par insertion) et maintenir la liste triée.

    Séquence:

        Vérification de l'état avec estTriee().

        Si non triée, appel à la fonction destructrice trierListeSimple(), qui remplace l'ancienne liste par la nouvelle liste triée.

        Appel à insererTrie() pour ajouter une nouvelle valeur fournie par l'utilisateur tout en préservant l'ordre.

Partie 3 : Liste Double - Tri et Insertion Triée ↔️

    Focus: Effectuer les mêmes opérations de tri et d'insertion que la partie 2, mais en assurant la cohérence des deux pointeurs (prev et next) pour chaque nœud.

    Fonction Clé: trierListeDouble et insererDoubleTrie. L'accent est mis sur la manipulation des quadruples liens lors des insertions.

Partie 4 : Liste Circulaire Simple 🔄

    Focus: Manipuler une liste où la queue pointe vers la tête.

    Méthode: L'insertion en tête ou en queue nécessite de parcourir la liste pour trouver l'élément prédécesseur de la tête (c'est-à-dire le dernier nœud).

Partie 5 : Liste Circulaire Double 🌐

    Focus: Démontrer l'efficacité de l'accès aux deux extrémités d'une liste doublement circulaire.

    Efficacité: L'insertion en tête (insererTeteCirculaireDouble) et en queue (insererQueueCirculaireDouble) est réalisée en complexité O(1) (temps constant), car le dernier nœud est accessible directement via head->prev sans nécessiter de parcours de la liste.

Ce programme est donc un excellent outil didactique illustrant les différences d'implémentation, de complexité et de manipulation des pointeurs inhérentes à chaque type de liste chaînée.

