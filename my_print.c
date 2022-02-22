/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:12:13 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/22 10:12:37 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
