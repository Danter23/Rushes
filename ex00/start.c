/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaltza- <jbaltza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:15:30 by alcristo          #+#    #+#             */
/*   Updated: 2026/02/07 20:50:52 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ESTO NOS HACE REFERENCIA AL DOCUMENTO QUE PRINTEA LOS VALORES
#include <unistd.h>
//Esto son los comparadores de cada edificio y no se repitan puntos cardinales

int	ft_visual_check(int	visuals[16])
{
	int	iterator;
	int	has_one;
	int	array[16];
	int	error;

	iterator = 0;
	has_one = 0;
	error = 0;
	while (iterator < 16)
	{
		if (visuals[iterator] < 1 || visuals[iterator] > 4)
			error = 1;
		if (visuals[iterator] == 1)
			has_one++;
		iterator++;
		if (iterator % 4 == 0)
		{
			if (has_one == 1)
				has_one = 0;
			else
				error = 1;
		}
	}
	return (error);
}

int	ft_corner_check(int corner1, int corner2)
{
	int	error;

	error = 0;
	if (corner1 == 1 || corner2 == 1) 
	{
		if (corner1 != corner2)
		{
			error = 1;
		}
	}
	return (error);
}

int	ft_rush01_start(int visuals[16])
{
	int	error;

	
	//Esto son las esquinas del cuadrado de aqui hacia abajo 
	while (error == 0)
	{
		error = ft_visual_check(visuals);
		error = ft_corner_check(visuals[0], visuals[8]);
		error = ft_corner_check(visuals[3], visuals[12]);
		error = ft_corner_check(visuals[4], visuals[11]);
		error = ft_corner_check(visuals[7], visuals[15]);
	}
	if (error == 0)
		ft_rush01_place(visuals);
	else
		write(2, "Error\n", 6);
	return (0);
}

int	main(void)
{
	int	visuals[16] = {3, 1, 3, 4, 1, 3, 2, 2, 4, 2, 3, 1, 3, 1, 2, 2};

	int n = ft_rush01_start(visuals);
	return (n);
}
//Intentar dividir funciones para la norminnete cuando tengamos claras las esquinas
//Tambien mirar como distribuir las cajas !!!!IMPORTANTE!!!
