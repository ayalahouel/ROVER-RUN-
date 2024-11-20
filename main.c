#include <stdio.h>
#include <stdlib.h>
#include "loc.h"
#include "moves.h"
#include "prob_mov.h"
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "n_ary_tree.h"
#include "map.h"


int main() {
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
// Initialize the array to hold selected movements
    t_move selected_moves[SEL_MOV];

    // Reset the probabilities of the movements
    resetProbabilities();

    // Display the initial probabilities
    printf("Initial probabilities:\n");
    printProbabilities(move_probabilities, NUM_MOV);

    // Choose a set of movements based on probabilities
    chooseMoves(selected_moves);

    // Display the selected movements
    printf("\nSelected movements:\n");
    for (int i = 0; i < SEL_MOV; i++) {
        printf("Movement %d selected\n", selected_moves[i]);
    }

    // Display the probabilities after movement selection
    printf("\nProbabilities after selection:\n");
    printProbabilities(move_probabilities, NUM_MOV);

    // Shuffle the probabilities
    shuffle(move_probabilities, NUM_MOV);

    // Display the probabilities after shuffling
    printf("\nProbabilities after shuffling:\n");
    printProbabilities(move_probabilities, NUM_MOV);

    // Create an n-ary tree and build a simple test tree
    t_nary_tree tree;
    build_simple_tree(&tree);

    printf("\nN-ary tree constructed:\n");

    // Display the structure of the tree to verify its construction
    printf("Root: Position (%d, %d), Total Cost: %d\n", tree.root->pos.x, tree.root->pos.y, tree.root->totalCost);
    for (int i = 0; i < tree.root->numChildren; i++)
    {
        printf("Child %d: Position (%d, %d), Total Cost: %d, Soil Type: %d\n", i + 1,
               tree.root->children[i]->pos.x, tree.root->children[i]->pos.y,
               tree.root->children[i]->totalCost, tree.root->children[i]->soilType);
    }

    return 0;
}
