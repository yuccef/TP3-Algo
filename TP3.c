#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"TP3.h"


/* Initialiser un nœud avec une valeur donnée */
struct treenode* init_node(int contenue) {
    struct treenode *node = (struct treenode*) malloc(sizeof(struct treenode));
    node->contenue = contenue;
    node->parent = NULL;
    node->fils = NULL;
    node->suivant = NULL;
    return node;
}
/* Ajouter un enfant à un nœud */
void add_child(struct treenode *parent, struct treenode *fils) {
    fils->parent = parent;
    if (parent->fils == NULL) {
        parent->fils = fils;
    } else {
        struct treenode *suivant = parent->fils;
        while (suivant->suivant != NULL) {
            suivant = suivant->suivant;
        }
        suivant->suivant = fils;
    }
}

void print_tree(struct treenode *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->contenue);
    struct treenode *fils = node->fils;
    while (fils != NULL) {
        print_tree(fils, depth + 1);
        fils = fils->suivant;
    }
}

/* Parcours en profondeur d'abord pour la recherche d'un arbre de recouvrement */
void dfs(struct Graph *graph, int node, struct treenode *parent, bool visited[], struct treenode **tree_nodes, int *num_tree_nodes) {
    /* Marquer le nœud comme visité */
    visited[node] = true;

    /* Ajouter le nœud au nouvel arbre de recouvrement */
    struct treenode *tree_node = init_node(node);
    add_child(parent, tree_node);
    tree_nodes[*num_tree_nodes] = tree_node;
    (*num_tree_nodes)++;

    /* Explorer les voisins non visités */
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_matrix[node][i] != 0 && !visited[i]) { // Ajouter une vérification pour éviter les nœuds déjà visités
            /* Trouver un voisin non visité */
            graph->adj_matrix[node][i] = 0;
            dfs(graph, i, tree_node, visited, tree_nodes, num_tree_nodes);
        }
    }
}

/* Recherche de l'arbre de recouvrement pour un graphe connexe */
struct treenode* find_spanning_tree(struct Graph *graph) {
    /* Initialiser la structure d'arbre */
    struct treenode *root = init_node(0);
    struct treenode *tree_nodes[MAX_NODES];
    int num_tree_nodes = 0;
    tree_nodes[num_tree_nodes] = root;
    num_tree_nodes++;

    /* Parcourir le graphe avec une recherche en profondeur d'abord */
    bool visited[MAX_NODES] = {false};  // tableau de booléens pour stocker les sommets visités
    dfs(graph, 0, root, visited, tree_nodes, &num_tree_nodes);

    return root;
}










