#include <stdio.h>
#include <stdlib.h>
#include "probability_mov.h"

/**
 * @brief Resets the probabilities of all moves to their default values.
 */
void resetProbabilities()
{
    move_probabilities[0].probability = 22.0;
    move_probabilities[1].probability = 15.0;
    move_probabilities[2].probability = 7.0;
    move_probabilities[3].probability = 7.0;
    move_probabilities[4].probability = 21.0;
    move_probabilities[5].probability = 21.0;
    move_probabilities[6].probability = 7.0;
}

/**
 * @brief Shuffles an array of moves randomly.
 * @param array : Pointer to the array of probabilities to shuffle.
 * @param n : Number of elements in the array.
 */
void shuffle(t_move_probability *array, int n)
{
    if (n > 1) // No need to shuffle arrays with 0 or 1 elements
    {
        for (int i = 0; i < n; i++)
        {
            int j = rand() % (i + 1); // Pick a random index
            t_move_probability temp = array[i]; // Swap array[i] and array[j]
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

/**
 * @brief Selects a move based on probabilities and decreases its probability by 1%.
 * @return The selected move.
 */
t_move selectMove()
{
    shuffle(move_probabilities, NUM_MOV); // Shuffle the probabilities before selecting

    for (int i = 0; i < NUM_MOV; i++)
    {
        if (move_probabilities[i].probability > 0)
        {
            move_probabilities[i].probability *= 0.99; // Reduce the probability by 1%
            // Example: new_prob = prob × 0.99 = 100 × 0.99 = 99
            return move_probabilities[i].move;
        }
    }

    return (t_move)-1; // Error: no valid moves (all probabilities are 0)
}

/**
 * @brief Chooses 9 moves from the list of possible moves.
 * @param selected_moves : Array to store the 9 selected moves.
 */
void chooseNineMoves(t_move selected_moves[9])
{
    resetProbabilities(); // Reset probabilities to default values
    for (int i = 0; i < 9; i++)
    {
        selected_moves[i] = selectMove(); // Select a move for each slot
    }
}

/**
 * @brief Selects a subset of moves to execute.
 * @param selected_moves : Array to store the selected moves (size SEL_MOV).
 */
void chooseMoves(t_move selected_moves[SEL_MOV]) 
{
    t_move nine_moves[9];
    chooseNineMoves(nine_moves); // First, choose 9 moves

    for (int i = 0; i < SEL_MOV; i++)
    {
        selected_moves[i] = nine_moves[i]; // Copy the first SEL_MOV moves
    }
}

/**
 * @brief Prints the probabilities of all moves in the array.
 * @param probabilities : Pointer to the array of probabilities.
 * @param size : Size of the array.
 */
void printProbabilities(t_move_probability *probabilities, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("Move %d: Probability = %.2f\n", i, probabilities[i].probability);
    }
}
