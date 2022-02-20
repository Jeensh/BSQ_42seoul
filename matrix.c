/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:00:20 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 21:10:31 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void set_col(char *buf, struct opt *c)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (buf[i] && (buf[i] != '\n'))				// 첫 행 건너 뛰기
		i++;
	i++;
	while (buf[i] && (buf[i] != '\n'))				// 한 줄의 길이 세기(열 크기 세기)
	{
		i++;
		size++;
	}
	c->col_size = 
}

void set_row_chars(char *buf, struct opt *c)		// 첫 행 검사하는 함수 필요
{
	char	*opt_line[100];
	int		i;

	i = 0;
	while (buf[i]  && (buf[i] != '\n'))				// 첫 행만 가져오기
	{
		opt_line[i] = buf[i];
		i++;
	}
	buf[i] = '\0'
	c->row_size = ft_atoi(buf);						// 행 개수 세팅
	i = 0;
	while (opt_line[i] && (opt_line[i] >= '0' && opt_line[i] <= '9'))
		i++;
	c->empty_c = opt_line[i];
	c->hurdle_c = opt_line[++i];
	c->fill_c = opt_line[++i];
}

char **make_char_matrix(char *buf)
{
	int			col_size;
	int			row_size;
	struct opt	*c;
	
	set_row_chars(buf, c);
}

char **make_origianl_matrix(char *filename)
{
	int fd;
	char *buf;
	
	fd = 0;
	buf = open_file(filename, &fd);
	
	
}
