/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:09:29 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 13:29:50 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	char	*cd;
	char	home;

	cd = getcwd(NULL, 0);
	home = getenv("HOME");
	if (!cd)
		return (1);
	if (ac == 1)
	{
		if ()
		chdir(home);
	}
	else
	{
		chdir(av[1]);
	}
	printf("%s\n", getcwd(NULL, 0));
}
