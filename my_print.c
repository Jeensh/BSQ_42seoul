#include "my_lib.h"

void    print_result(char **result)
{
    int row;
    int col;

    row = -1;
    col = -1;
    while (result[++row] != 0)
    {
        col = -1;
        while (result[row][++col])
        {
            write(1, &result[row][col], 1);
        }
        write(1, "\n", 1);
    }
}