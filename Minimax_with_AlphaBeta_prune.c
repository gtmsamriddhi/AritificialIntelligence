#include <stdio.h>
#include <limits.h>

int minimax(int depth, int nodeIndex, int maximizingPlayer,
            int values[], int alpha, int beta, int height)
{
    int i, value, best;

    /* Leaf node */
    if (depth == height)
        return values[nodeIndex];

    if (maximizingPlayer)
    {
        best = INT_MIN;

        for (i = 0; i < 2; i++)
        {
            value = minimax(depth + 1, nodeIndex * 2 + i,
                            0, values, alpha, beta, height);

            if (value > best)
                best = value;

            if (best > alpha)
                alpha = best;

            /* Alpha-Beta pruning */
            if (beta <= alpha)
                break;
        }

        return best;
    }
    else
    {
        best = INT_MAX;

        for (i = 0; i < 2; i++)
        {
            value = minimax(depth + 1, nodeIndex * 2 + i,
                            1, values, alpha, beta, height);

            if (value < best)
                best = value;

            if (best < beta)
                beta = best;

            /* Alpha-Beta pruning */
            if (beta <= alpha)
                break;
        }

        return best;
    }
}

int main()
{
    int values[] = {3, 5, 6, 9, 1, 2, 0, -1};
    int height = 3;
    int result;

    result = minimax(0, 0, 1, values, INT_MIN, INT_MAX, height);

    printf("Optimal value: %d\n", result);
    printf("Samriddhi Gautam : BIT 28 : LabI7");
    return 0;
}
