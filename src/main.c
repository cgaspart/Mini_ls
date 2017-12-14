/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/13 09:44:19 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	struct	stat	fstat;
	struct	passwd	*duser;
	struct	group	*dgroup;

	if (argc != 2)
		exit (1);
	if (stat(argv[1], &fstat) == -1)
	{
		perror("");
		exit (0);
	}
	ft_putstr("Nom: ");
	ft_putstr(argv[1]);
	ft_putchar('\n');

	ft_putstr("Type: ");
	ft_putstr(ft_type(fstat));

	ft_putstr("Modes: ");
	ft_putright(ft_right(fstat));
	ft_putchar('\n');

	ft_putstr("Nombre de liens: ");
	ft_putnbr(fstat.st_nlink);
	ft_putchar('\n');

	duser = getpwuid(fstat.st_uid);
	ft_putstr("Proprietaire: ");
	ft_putstr(duser->pw_name);
	ft_putchar('\n');

	dgroup = getgrgid(fstat.st_gid);
	ft_putstr("Groupe: ");
	ft_putstr(dgroup->gr_name);
	ft_putchar('\n');

	ft_putstr("Taille: ");
	ft_putnbr(fstat.st_size);
	ft_putstr(" octets\n");

	ft_putstr("Date de derniere modification: ");
	ft_putstr(ft_date_converter(ctime(&fstat.st_mtime)));
}
