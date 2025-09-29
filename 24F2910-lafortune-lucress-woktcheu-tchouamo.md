#cahier de suivi de projet - woktcheu tchouamo lafortune lucress

  **matricule: **24F2910
  **groupe de tp: 
  **projet:**gestion des listes chainees

## seance du 25 septembre 2025

###objectifs de la seance
  -ecrire un programme en c qui sert a :
   
1. Lire un élément et supprimer toutes les occurence dans la liste 
2. Insertion d'un élément dans une liste simplement chaîne trié 
3. Insertion d'un élément dans une liste doublement chaîne trié 
4. Insertion en tête et en queue dans une liste simplement chaîne circulaire 
5. Insertion en tête et en queue dans une liste doublement chaîne circulaire 


#### travail realise
 -1. Analyse et Planification

    Analyse du Problème : J'ai analysé les exigences spécifiques des listes chaînées , afin que tous les membres puisse savoir comment le travail va se passer
     dans le travail.

    Division des Tâches : J'ai contribué à la structuration du projet, en définissant des modules clairs pour chaque membres puisse apporter leur contibution dans le tavail.

2. Développement des Fonctions Clés (Mon Rôle Principal)

J'ai codé et testé les fonctions cruciales pour la Liste Simplement Chaînée Circulaire (LSCC) :

    creerListeCirculaireSimple() : Fonction de construction de la LSCC, assurant que le lien de circularité est établi.

    insererTeteCirculaireSimple() : Implémentation de l'insertion en tête. Le défi majeur est d'abord de parcourir la liste (coût O(n)) pour trouver le dernier nœud afin de mettre à jour son pointeur next vers le nouveau nœud (la nouvelle tête).

    insererQueueCirculaireSimple() : Implémentation de l'insertion en queue. Similaire à l'insertion en tête, elle nécessite le parcours de la liste pour localiser le dernier nœud avant de rétablir la circularité en pointant le nouveau nœud vers la tête.

3. Intégration et Tests

    Intégration du Code : J'ai intégré mes fonctions avec celles des autres membres pour développer le corps de la fonction main(), assurant que le menu et l'enchaînement des tests fonctionnent correctement.

    Tests Unitaires : J'ai effectué des tests approfondis sur mes fonctions d'insertion , en vérifiant que :

        Le nouveau nœud est correctement inséré.

        Le lien de circularité n'est pas brisé.

        La liste gère correctement les cas limites (insertion dans une liste vide, bien que cela ne soit pas directement le cas ici).

    Validation Croisée : Le programme final a été compilé et testé par chaque membre pour garantir sa portabilité et son bon fonctionnement.

Résultat et Conclusion

Le programme est entièrement fonctionnel et répond à tous les objectifs fixés. Ma contribution a permis de valider la manipulation correcte des pointeurs dans l'environnement complexe des listes circulaires, garantissant que les insertions en tête et en queue sont effectuées de manière structurée et sécurisée.



 