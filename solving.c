/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:12:19 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/22 10:13:07 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int get_square_size(int **sol_m, int row, int col)
{
    int left;
    int diagonal;
    int up;

    if (sol_m[row][col] == 0)
        return (0);
    else if (row == 1 || col == 1)
    {
        return (1);
    }
    else
    {
        left = sol[row][col - 1];
        up = sol[row - 1][col];
        diagonal = sol[row - 1][col - 1];
        return (min(left, diagonal, up) + 1);
    }
}

char    **make_solution_matrix(int **basic_matrix, struct opt *c)
{
    int row;
    int col;

    row = -1;
    col = -1;
    while (++row < c->row_size)
    {
        col = -1;
        while (++col < c->col_size)
        {
            basic_matrix[row][col] = get_square_size(basic_matrix, row, col);
        }
    }
    return (basic_matrix);
}

int find_biggest_sqare(int **sol_m, struct opt *c, int *row, int *col)
{
    int i;
    int j;
    int max;

    max = 0;
    i = -1;
    j = -1;
    while (++i < c->row_size)
    {
        j = -1;
        while (++j < c->col_size)
        {
            if (max < sol_m[i][j])
            {
                max = sol_m[i][j];
                *row = i;
                *col = j;
            }
        }
    }
    return (max);
}

char    **turn_original2answer(int **sol_m, char **ori_m, struct opt *c)
{
    int row;
    int col;
    int r_end;
    int c_end;
    int start;
    int size;

    row = 0;
    col = 0;
    size = find_biggest_sqare(sol_m, c, &row, &col);
    r_end = (row - size) + 1;
    c_end = (col - size) + 1;
    start = col;
    while (row >= r_end)
    {
        col = start;
        while (col >= c_end)
        {
            ori_m[row][col] = c->fill_c;
            col--;
        }
        row--;
    }
    return (ori_m);
}

void    get_solution(char *filename)
{
    struct opt  *c;
    int         fd;
    int         **sol_m;
    char        **ori_m;

    c = make_two_matrix(filename, &fd, ori_m, sol_m);
    sol_m = make_solution_matrix(sol_m, c);
    ori_m = turn_original2answer(sol_m, ori_m, c);
    free_int_matrix(sol_m, c);
    print_result(ori_m);
    free_char_matrix(ori_m, c);
    free(c);
}
