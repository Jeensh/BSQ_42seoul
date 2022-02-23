/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:28:44 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 09:28:53 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int check_map(char *buf, t_opt *c)          // 지도의 행 개수가 첫 행의 규칙을 따르지 않거나
{                                           // 지도의 모든 열 길이가 같지 않으면 0반환
    int i;
    int row_size;
    int col_size;

    i = 0;
    row_size = 0;
    col_size = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    while (buf[++i])
    {
        if (buf[i] == '\n')
        {
            row_size++;
            if (col_size != c->col_size)
                return (0);
            col_size = 0;
        }
        else
        {
            if (!check_map_char(c, buf[i]))
                return (0);
            col_size++;
        }
    }
    if (row_size != c->row_size)
        return (0);
    return (1);
}

int check_all(char *buf)                        // 지도 파일이 유효한지 확인
{
    t_opt c;
    int i;

    i = 0;
    while (i < 100)                              // 이거 안해주면 제대로 실행이 안됨
        i++;                                    // 이유를 잘 모르겠음
    if (!check_firstline(buf, &c))
        return (0);
    if (!check_col_size(buf, &c))
        return (0);
    if (!check_map(buf, &c))
        return (0);
    return (1);
}