/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:43:50 by lbally            #+#    #+#             */
/*   Updated: 2022/11/05 01:51:43 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	touch(int n)
{
	if (n == 'N' || n == 'E' || n == 'S' || n == 'W' || n == '0' || n == '1'
		|| n == ' ')
		return (1);
	else
	{
		return (0);
	}
}

int	ber2(char *line)
{
	int	z;

	z = 0;
	if (line[z] == 'c')
	{
		z++;
		if (line[z] == 'u')
		{
			z++;
			if (line[z] == 'b')
			{
				z++;
				if (line[z] == '\0')
					return (z);
			}
		}
	}
	return (0);
}

int	ber(char **av)
{
	int	z;
	int	u;

	z = 0;
	u = 0;
	while (av[1][z])
	{
		if (av[1][z] == '.')
		{
			z++;
			u = ber2(&av[1][z]);
			if (u + z >= 5)
				return (1);
		}
		z++;
	}
	printf("Error\nFichier ilisible\n");
	return (0);
}

int	place(t_data_a *d, char n, int r)
{
	if (touch(n) == 0)
		return (0);
	if ((d->gg == (d->cap - 1)) && (n != '1' && n != ' '))
	{
		printf("Error\nLa map n'est pas fermé\n");
		return (0);
	}
	if ((d->map[d->gg][r] != '1' && d->map[d->gg][r + 1] == '\0'))
	{
		printf("Error\nLa map n'est pas fermé\n");
		return (0);
	}
	if (n == 'W' || n == 'N' || n == 'S' || n == 'E')
	{
		d->pp = n;
		printf("PP ====== %c\n", d->pp);
		d->p++;
	}
	return (1);
}

int	parse(char **line, t_data_a *d)
{
	int	n;
	int	w;
	int	i;
	int	t;
	int	r;

	n = 0;
	w = 0;
	i = 0;
	t = 0;
	r = 0;
	while (line[d->gg])
	{
		if (line[d->gg][0] == '\0')
		{
			printf("Error\nLa map n'est pas fermé\n");
			return (0);
		}
		while (line[d->gg][n])
		{
			if (line[d->gg][n] == '1' || line[d->gg][n - t] == '0')
				w++;
			while (line[d->gg][n] == ' ')
			{
				t++;
				n++;
			}
			i = 1;
			if (i == 0)
			{
				printf("Error\nmap illisible\n");
				return (0);
			}
			if (t != 0)
			{
				if (w != 0)
				{
					if (line[d->gg][n - (t + 1)] != '1')
					{
						printf("Error\nLa map n'est pas fermé\n");
						return (0);
					}
				}
				if (line[d->gg][n] != '1')
				{
					printf("Error\nLa map n'est pas fermé\n");
					return (0);
				}
			}
			if (t == 0 && n == 0)
			{
				if (d->map[d->gg][0] != '1')
				{
					printf("Error\nLa map n'est pas fermé\n");
					return (0);
				}
			}
			if (d->map[d->gg][n] == '0' && d->gg != d->start)
			{
				while (d->map[d->gg - 1][r])
					r++;
				if (r - 1 < n)
				{
					printf("Error\nLa map n'est pas fermé\n");
					return (0);
				}
				r = 0;
				while (d->map[d->gg + 1][r])
					r++;
				if (r - 1 < n)
				{
					printf("Error\nLa map n'est pas fermé\n");
					return (0);
				}
				r = 0;
				if (d->map[d->gg - 1][n] == ' ' || d->map[d->gg + 1][n] == ' ')
				{
					printf("Error\nLa map n'est pas fermé\n");
					return (0);
				}
			}
			if (place(d, line[d->gg][n], n) != 1)
				return (0);
			n++;
			t = 0;
		}
		w = 0;
		n = 0;
		d->gg++;
	}
	if (d->p != 1)
	{
		if (d->p != 1)
			printf("Error\nIl y a erreur sur la position de depart\n");
		return (0);
	}
	return (1);
}
