/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:11:46 by alcristo          #+#    #+#             */
/*   Updated: 2026/02/08 12:55:09 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_board(int *array, int row_length);

int	satisfies_visuals(int *array, int *visuals, int iterator)
{
}

void	ft_rush01_fill(int *array, int *visuals)
{
	int	iterator;
	int	rewind;
	int	correct;
	int	*lock;

	iterator = 0;
	rewind = 0;
	while (iterator < 16)
	{
		if (array[iterator] == 0)
			lock[iterator] = 0;
		else
			lock[iterator] = 1;
	}
	iterator = 0;
	while (iterator < 16)
	{
		if (lock[iterator] != 0)
		{
			if (rewind == 0)
			{
				iterator++;
				continue ;
			}
			else
			{
				iterator--;
				continue ;
			}
		}
		if (array[iterator] > 4)
		{
			rewind = 1;
			array[iterator] = 0;
		}
		else
		{
			array[iterator]++;
			rewind = 0;
		}
		if (rewind != 0)
		{
			iterator--;
			continue ;
		}
		correct = satisfies_visuals(array, visuals, iterator);
		if (correct == 1)
			iterator++;
	}
	ft_print_board(array, 4);
}
