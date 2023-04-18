#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"TP3.h"


/* Fonction de test pour vérifier la recherche de l'arbre de recouvrement */
int main() {
    /* Initialiser la matrice d'adjacence */
    int adj_matrix[MAX_NODES][MAX_NODES] = {
        {0, 0, 36, 0, 0, 19, 0, 0},
        {0, 0, 0, 0, 0, 0, 50, 43},
        {36, 0, 0, 56, 55, 31, 0, 36},
        {0, 0, 56, 0, 0, 0, 15, 0},
        {0, 0, 55, 0, 0, 0, 0, 0},
        {19, 0, 31, 0, 0, 0, 37, 52},
        {0, 50, 0, 15, 0, 37, 0, 0},
        {0, 43, 36, 0, 0, 52, 0, 0}
    };

    int num_nodes = 8;

    /* Initialiser le graphe */
    struct Graph graph;
    graph.num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph.adj_matrix[i][j] = adj_matrix[i][j];
        }
    }

    /* Trouver un arbre de recouvrement */
    struct treenode *root = find_spanning_tree(&graph);

    /* Afficher l'arbre de recouvrement */
    printf("Root node: %d\n", root->contenue);
    printf("Children of root node:\n");
    print_tree(root, 1);

    return 0;
}
