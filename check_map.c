/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:28:59 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 09:31:25 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	check_char(t_opt *c)
{
	if (!(c->empty_c >= 32 && c->empty_c <= 126))
		return (0);    
	if (!(c->fill_c >= 32 && c->fill_c <= 126))
		return (0);  
	if (!(c->hurdle_c >= 32 && c->hurdle_c <= 126))
		return (0);  
	if (c->fill_c == c->empty_c)
		return (0);
	if (c->fill_c == c->hurdle_c)
		return (0);
	if (c->empty_c == c->hurdle_c)
		return (0);
	return (1);
}

int check_row_size(char *num)               // 행 개수가 유효하지 않으면 0반환
{                                           // 유효하면 행 개수 반환
	int i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && !(num[i] >= '1' && num[i] <= '9'))
			return (0);
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (ft_atoi(num));
}

int check_firstline(char *buf, t_opt *c)
{
	int i;
	int j;
	char num[100];

	i = 0;
	while(buf[i] && buf[i] != '\n')
		i++;
	if (i < 3)                              // 문자가 4개 미만이면
		return (0);                         // 유효하지 않음
	c->fill_c = buf[--i];
	c->hurdle_c = buf[--i];
	c->empty_c = buf[--i];
	if (!check_char(c))                     // 중복된 문자가 있거나 출력되지 않는 문자가 있으면
		return (0);                         // 유효하지 않음
	j = -1;
	while(++j < i)
		num[j] = buf[j];
	num[++j] = '\0';
	c->row_size = check_row_size(num);
	if (c->row_size <= 0)                   // 행의 개수가 0이하이면
		return (0);                         // 유효하지 않음
	return (1);
}                                                       

int check_col_size(char *buf, t_opt *c)
{
	int i;
	int col_size;

	i = 0;
	col_size = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	while (buf[++i] && buf[i] != '\n')
		col_size++;
	if (col_size <= 0)                      // 열의 길이가 0이하이면
		return (0);                         // 유효하지 않음
	c->col_size = col_size;
	return (1);
}

int check_map_char(t_opt *c, char target)   // 지도의 문자가 첫행의 규칙을 따르면 1반환
{                                           // 따르지 않으면 0반환
	if (target == c->empty_c)
		return (1);
	if (target == c->hurdle_c)
		return (1);
	return (0);
}
