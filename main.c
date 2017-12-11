/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/11 13:59:03 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct	dirent	*file;

	if (argc != 2)
		exit (1);
	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		perror("");
		exit (1);
	}
	while ((file = readdir(dir)))
	{
		ft_putstr(file->d_name);
		ft_putchar('\n');
	}
}
