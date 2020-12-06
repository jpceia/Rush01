/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 06:50:44 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:55:52 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_algo.h"
#include <stdlib.h>

int		parse_args(int *conditions, char *str, int size)
{
	int index;
	int i;

	if (ft_strlen(str) != size * size * 2 - 1)
		return (0);
	index = 0;
	while (index < size * size)
	{
		i = str[2 * index] - '0';
		if (i < 1 || i > size)
			return (0);
		conditions[index] = i;
		index++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int size;
	int success;
	int *grid;
	int *conditions;

	size = 4;
	grid = malloc(sizeof(*grid) * size * size);
	conditions = malloc(sizeof(*conditions) * size * size);
	success = 1;
	if (argc > 1)
		success &= parse_args(conditions, argv[1], size);
	else
		success = 0;
	if (success)
		success = add_item(conditions, grid, 0, size);
	if (!success)
		ft_putstr("Error\n");
	free(grid);
	free(conditions);
	return (0);
}
