/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:16:03 by lbally            #+#    #+#             */
/*   Updated: 2022/11/03 18:13:06 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	f_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2, int n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;
	int				j;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	while (s1[i] == ' ')
		i++;
	while (str1[i] && str2[i] && j <= n)
	{
		if (str1[i] != str2[i])
			break ;
		i++;
		j++;
	}
	if (s1[i] == 32 && s2[i] == 0)
		return (0);
	return (str1[i] - str2[i]);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

int	north(char *line, char *lala, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!ft_isalpha(line[i]))
			return (0);
		else
		{
			if (!ft_strcmp(line, lala, n))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int	parse2(char **map, t_data_a *d)
{
	int	n;

	n = 0;
	while (map[d->gg] && f_char(map[d->gg]))
	{
		if (north(map[d->gg], "NO", 2) == 1)
		{
			d->wlln = ft_find_im(d);
			n++;
			printf("WLLN === %s\n", d->wlln);
		}
		if (north(map[d->gg], "SO", 2) == 1)
		{
			d->wlls = ft_find_im(d);
			n++;
			printf("WLLS === %s\n", d->wlls);
		}
		if (north(map[d->gg], "WE", 2) == 1)
		{
			d->wllw = ft_find_im(d);
			n++;
			printf("WLLW === %s\n", d->wllw);
		}
		if (north(map[d->gg], "EA", 2) == 1)
		{
			d->wlle = ft_find_im(d);
			n++;
			printf("WLLE === %s\n", d->wlle);
		}
		if (north(map[d->gg], "F", 1) == 1)
		{
			d->fllr = ft_find_im(d);
			n++;
			printf("FLLR === %s\n", d->fllr);
		}
		if (north(map[d->gg], "C", 1) == 1)
		{
			d->ceil = ft_find_im(d);
			n++;
			printf("CEIL === %s\n", d->ceil);
		}
		d->gg++;
	}
	if (n != 6)
	{
		printf("Error\nProbleme dans la construction de la map\n");
		return (0);
	}
	d->start = d->gg;
	return (1);
}
