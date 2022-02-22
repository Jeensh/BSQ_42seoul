/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbeom <seungbeom@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/23 03:35:10 by seungbeom        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char *argv[])
{
	int	i;
	
	if (argc == 1)
	{
		get_std_solution(get_standard_input());
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			get_solution(argv[i]);
			if (i != (argc - 1))
				write(1, "\n", 1);
		}
	}
	system("leaks bsq");
	return (0);
}
