/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbeom <seungbeom@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 03:33:33 by seungbeom        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int check_printable(char *buff)
{
    int     index;
    
    index = 0;
    while (buff[index] != '\n') // 첫 개행 문자 만나기 전까지 while문 실행
    {
        if ((buff[index]) < 32 || buff[index] > 126) // 출력 가능하지 않은 문자일 경우 return (1);
            return (1);
        index++;
    }
    if (index < 4) // 지도에 있는 줄의 수, 문자들 포함 4자리 이상인지 판별
        return (1);
    return (0);
}

int check_multiple(char *buff, int index) // 문자 중복 체크 (check_letters 함수에 삽입)
{
    if (buff[index] == buff[index + 1] || buff[index + 2])
        return (1);
    if (buff[index + 1] == buff[index + 2])
        return (1);
    return (0); 
}

int check_letters(char *buff) // 행의 수 및 문자들이 유효한지 확인
{
    int     length;
    int     index;
    int     row_size;

    length = 0; // 행의 수, 문자들 총 길이 
    while (buff[length] != '\n')
        length++;
    index = 0;
    row_size = 0;
    while (index < length - 3)
    {
        if ((buff[index] < '0' && buff[index] > '9') || buff[0] == '0')
            return (1);
        row_size = row_size * 10 + buff[index] - '0';
        index++;
    }
    if (row_size < 1 || check_multiple(buff, index))
        return (1);
    return (0);
}

int check_condition(char *buff) // 기본 조건에 대한 검사 (check_instruction.c 함수에 삽입)
{
    if (check_printable(buff)) // 빈 문자, 장애물 문자, 차 있는 문자가 출력 가능한 문자인지 판별
        return (1);
    if (check_letters(buff))
        return (1);
    return (0);
}