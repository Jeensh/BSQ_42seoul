/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbeom <seungbeom@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 01:26:19 by seungbeom        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_printable(char *buff)
{
    int     index;
    
    index = 0;
    while (buff[index] != '\n')
    {
        if ((buff[index]) < 32 || buff[index] > 126)
            return (1);
        index++;
    }
    if (index < 4)
        return (1);
    return (0);
}

int check_multiple(char *buff, int index)
{
    if (buff[index] == buff[index + 1] || buff[index + 2])
        return (1);
    if (buff[index + 1] == buff[index + 2])
        return (1);
    return (0); 
}

int check_letters(char *buff)
{
    int     length;
    int     index;
    int     row_size;

    length = 0;
    while (buff[length] != '\n')
        length++;
    index = 0;
    row_size = 0;
    while (index < length - 3)
    {
        if (buff[index] < '0' && buff[index] > '9')
            return (1);
        if (index == 0 && buff[index] == '0')
            return (1);
        row_size = row_size * 10 + buff[index] - '0';
        index++;
    }
    if (row_size < 1 || check_multiple(buff, index))
        return (1);
    return (0);
}

int check_condition(char *buff)
{
    if (check_printable(buff))
        return (1);
    if (check_letters(buff))
        return (1);
    return (0);
}