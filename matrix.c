/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:00:20 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 17:30:57 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
void set_row_chars(char *buf, int *row_size, struct opt *c)
{
	char	*opt_line[100];
	int		i;

	while (buf[i]  && (buf[i] != '\n'))
	{
		opt_line[i];
		i++;
	}
	*row_size = ft_atoi( 
}

char **make_char_matrix(char *buf)
{
	int			col_size;
	int			row_size;
	struct opt	*c;
	
}

char **make_origianl_matrix(char *filename)
{
	int fd;
	char *buf;
	
	fd = 0;
	buf = open_file(filename, &fd);
	
	
}
