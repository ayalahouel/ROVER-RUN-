//
// Created by ayalahouel
//

#ifndef N_ARY_TREE_H
#define N_ARY_TREE_H

#include "loc.h"  // Retrieves the t_position structure (x, y)
#include "map.h"  // Retrieves the t_soil structure (type of soil)
#include "queue.h" // Retrieves the t_queue structure (queue) for breadth-first traversal to find the lowest leaf

/**
 * @brief Structure for a node in an n-ary tree based on t_position and t_soil
 */
typedef struct t_node
{
    t_position pos;          // Position of MARC on the map (x, y)
    int cost;                // Cost associated with moving to this node (depends on soil type)
    int totalCost;           // Accumulated cost to reach this node (useful for backtracking, i.e., finding the least costly path)
    t_soil soilType;         // Type of soil (erg, plain, reg, etc.)

    struct t_node* parent;     // Pointer to the parent node (useful for backtracking/comparing paths, e.g., retrieving the sequence of movements)
    struct t_node** children;  // Pointer to child nodes (possible moves)
    int numChildren;           // Number of children for this node
} t_node;

/**
 * @brief Structure to control an n-ary tree
 */
typedef struct s_nary_tree
{
    t_node* root;  // Starting position (Base Station) of the tree
} t_nary_tree;

/**
 * @brief Initializes a node for an n-ary tree
 * @param pos : Position of the node (x, y)
 * @param cost : Cost of moving to this node based on the soil type
 * @param soilType : Soil type of the current position
 * @param parent : Parent node
 * @param maxChildren : Maximum number of children for this node
 * @return A pointer to the created node
 */
t_node *createNode(t_position pos, int cost, t_soil soilType, t_node *parent, int maxChildren);

/**
 * @brief Adds a child node to a parent node
 * @param parent : Parent node
 * @param child : Child node to be added
 */
void addChild(t_node *parent, t_node *child);

/**
 * @brief Builds a simple tree for testing purposes
 * @param tree : The tree to be built
 */
void build_simple_tree(t_nary_tree* tree);

#endif // N_ARY_TREE_H
