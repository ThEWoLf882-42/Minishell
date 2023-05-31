/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:09:29 by agimi             #+#    #+#             */
/*   Updated: 2023/05/31 17:59:02 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(t_env *em, char *cd)
{
	char	*str;
	int		i;
	int		j;

	while (em)
	{
		i = -1;
		j = -1;
		if (!ft_strncmp(em->arg, "PWD=", 4))
		{
			str = malloc(sizeof(char) * (4 + ft_strlen(cd) + 1));
			if (!str)
				return ;
			while (em->arg[++i] && i < 4)
				str[++j] = em->arg[i];
			free(em->arg);
			i = -1;
			while (cd[++i])
				str[++j] = cd[i];
			str[++j] = '\0';
			em->arg = str;
			free(cd);
		}
		em = em->nxt;
	}
}
/*
lm->nxt && ft_strcmp(lm->nxt->typ, "arg")  to skip to the next arg 
after cmd  cd k > out
*/

void	cd_cmd(t_line *lm, int x)
{
	t_env	*em;
	char	*cd;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	while (lm->nxt && ft_strcmp(lm->nxt->typ, "arg"))
		lm = lm->nxt;
	if (lm && !lm->nxt)
	{
		cd = get_env("HOME");
		if (chdir(cd) == -1)
			print_error(cd, 1, x);
	}
	else if (lm && chdir(lm->nxt->shx) == -1)
		print_error(lm->nxt->shx, 1, x);
	if (x)
		exit(0);
	cd = getcwd(NULL, 0);
	em = g_va.env;
	change_pwd(em, cd);
	close_fd();
}
