/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbeom <seungbeom@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 03:34:37 by seungbeom        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int check_instruction(char *buff)
{
    t_opt   *c;
    
    if (check_condition(buff)) // 행의 수, 문자 검사
        return (0);
    c = (t_opt *) malloc(sizeof(t_opt)); // 기본 문자, 행 검사 통과 시, 구조체에 값 할당
    if (!c)
        return (0);
    set_opt(buff, c);
    if (check_map(buff, c)) // 지도 유효성 검사
        return (0); 
    return (1);
}