/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbeom <seungbeom@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 03:33:11 by seungbeom        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int to_map(char *buff) // 지도가 시작되는 index 값 반환
{
    int     index;

    index = 0;
    while (buff[index] != '\n')
        index++;
    return (index + 1);
}

int check_map(char *buff, t_opt *c)
{
    int     index;
    int     col_check;
    int     row_check;

    index = to_map(buff);
    row_check = 0;
    while (buff[index]) // col, row 및 지도 문자 유효성 검사
    {
        col_check = 0;
        while (buff[index] != '\n') // 각 행 검사
        {
            if (buff[index] == c->empty_c || buff[index] == c->hurdle_c)
                col_check++;
            index++;
        }
        if (col_check != c->col_size)
            return (1);
        row_check++;
        index++;
    }
    if (row_check != c->row_size)
        return (1);
    return (0);
}