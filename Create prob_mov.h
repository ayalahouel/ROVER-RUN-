// eya: Movement part based on probabilities
#ifndef PROB_MOV_H
#define PROB_MOV_H

#include "moves.h"

#define NUM_MOV 7 // Total number of possible moves
#define SEL_MOV 5 // Number of selected moves

/**
 * @brief Structure: movement and probability
 */
typedef struct 
{
    t_move move;       // The type of movement
    float probability; // The probability associated with the movement
} t_move_probability;

/**
 * @brief Array of moves and their probabilities (7 moves, 2 repeated, making a total of 9 moves).
 * Works like a dictionary in Python.
 */
static t_move_probability move_probabilities[NUM_MOV] =
{
    {F_10, 22.0},  // [0] Forward 10
    {F_20, 15.0},  // [1] Forward 20
    {F_30, 7.0},   // [2] Forward 30
    {B_10, 7.0},   // [3] Backward 10
    {T_LEFT, 21.0},// [4] Turn Left
    {T_RIGHT, 21.0},// [5] Turn Right
    {U_TURN, 7.0}  // [6] U-Turn
};

/**
 * @brief Function to reset base probabilities
 */
void resetProbabilities();

/**
 * @brief Function to shuffle probabilities (method suggested by Halim Djerroud)
 * Reference: https://www.youtube.com/watch?v=GS2MxmorEzc
 * @param array : Array of probabilities
 * @param n : Number of movements
 */
void shuffle(t_move_probability *array, int n);

/**
 * @brief Function to select a move, adding a bug that reduces each move's chance by 1%.
 * @return The selected move
 */
t_move selectMove();

/**
 * @brief Function to choose 9 moves among the 7 possible ones (2 repeated moves)
 * @param selected_moves : Array of selected moves (9 total)
 */
void chooseNineMoves(t_move selected_moves[9]);

/**
 * @brief Function to choose the moves to perform
 * @param selected_moves : Array of selected moves
 */
void chooseMoves(t_move selected_moves[SEL_MOV]);

/**
 * @brief Function to display the probabilities of each move
 * @param probabilities : Pointer to an array of probabilities
 * @param size : Size of the array
 */
void printProbabilities(t_move_probability *probabilities, int size);

#endif // PROB_MOV_H