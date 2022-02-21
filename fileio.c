/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:36:19 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 15:44:12 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_lib.h"

#include <stdio.h>

char *open_file(char *filename, int *fd)	// 파일 열어서 모든 내용 읽어서 반환, malloc으로 할당함(free처리필요)
{
	int		i;
	char	*buf;

	*fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!buf)
		return (0);
	read(*fd, buf, BUF_SIZE);
	return (buf);
}

int skip_first_fline(char *buf)				// 두 번째 라인 첫 문자 인덱스를 반환
{
	int	i;

	i = 0;
	while (buf[i] && (buf[i] != '\n'))		// 첫 행 건너 뛰기
		i++;
	i++;
	return (i);
}


