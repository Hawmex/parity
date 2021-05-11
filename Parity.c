#include "stdio.h"

int main()
{
    unsigned int size;

    scanf("%u", &size);

    while (size != 0)
    {
        unsigned int bits[size][size];

        for (size_t row = 0; row < size; row++)
            for (size_t column = 0; column < size; column++)
                scanf("%u", &bits[row][column]);

        unsigned int corruptRows = 0;
        int corruptRowIndex = -1;

        for (size_t row = 0; row < size; row++)
        {
            unsigned int rowSum = 0;

            for (size_t column = 0; column < size; column++)
                rowSum += bits[row][column];

            if (rowSum % 2 != 0)
            {
                corruptRows += 1;
                corruptRowIndex = row;
            }
        }

        unsigned int corruptColumns = 0;
        int corruptColumnIndex = -1;

        for (size_t column = 0; column < size; column++)
        {
            unsigned int columnSum = 0;

            for (size_t row = 0; row < size; row++)
                columnSum += bits[row][column];

            if (columnSum % 2 != 0)
            {
                corruptColumns += 1;
                corruptColumnIndex = column;
            }
        }

        if (corruptColumns < 1 && corruptRows < 1)
            puts("OK");
        else if (corruptColumns == 1 && corruptRows == 1)
            printf("Change bit (%u,%u)\n", corruptRowIndex + 1, corruptColumnIndex + 1);
        else
            puts("Corrupt");

        scanf("%u", &size);
    }

    return 0;
}
