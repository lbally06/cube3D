/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:49:43 by lbally            #+#    #+#             */
/*   Updated: 2022/11/05 05:52:09 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*strdupp(const char *s1, t_data_a *d)
{
	void	*str;
	char	*a;
	size_t	i;

	str = 0;
	i = 0;
	d->len = 0;
	while (s1[i] != '\0')
	{
		i++;
		d->len++;
	}
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	a = (char *)str;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

int	gnl2(int fd, char **av, char *line, t_data_a *d)
{
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		d->map[d->gg] = strdupp(line, d);
		d->gg++;
		free(line);
	}
	close(fd);
	d->map[d->gg] = NULL;
	d->gg = 0;
	return (1);
}

int	gnl(char **av, t_data_a *d)
{
	int		fd;
	char	*line;

	line = NULL;
	if (opening(av) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nDossier illisible\n");
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf ("GG ==== %s\n", line);
		d->gg++;
		free(line);
	}
	close(fd);
	d->map = malloc(sizeof(char *) * (d->gg + 1));
	d->cap = d->gg;
	d->gg = 0;
	if (gnl2(fd, av, line, d) == 1)
		return (1);
	return (0);
}

int	jerk(int ac, char **av, t_data_a *d)
{
	int	i;

	if (ac != 2)
	{
		printf("Error\nPas bon nombre d'argument\n");
		return (0);
	}
	i = ber(av);
	if (i == 0)
		return (0);
	i = 0;
	init(d);
	i = gnl(av, d);
	if (i == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data_a	*d;
	t_data_a	*img;

	d = malloc(sizeof(t_data_a));
	img = malloc(sizeof(t_data_a));
	if (jerk(ac, av, d) == 0)
		return (0);
	if (parse2(d->map, d) == 0)
		return (0);
	if (parse(d->map, d) == 0)
		return (0);
	remplace(d);
	d->mlx = mlx_init();
	d->mlx_dow = mlx_new_window(d->mlx, 64 * d->len, 64 * d->cap, "cube3d");
	img->img = mlx_new_image (d->mlx, 64 * d->len, 64 * d->cap);
	img->adr = mlx_get_data_addr(img->img, &img->bi_p_pix, &img->line_len,
			&img->endian);
//	creat_img(d);
//	draw(d);
//	mlx_hook(d->mlx_dow, 2, 1L << 0, touche, d);
	mlx_hook(d->mlx_dow, 17, 0, quit, d);
	mlx_loop(d->mlx);
	return (0);
}
