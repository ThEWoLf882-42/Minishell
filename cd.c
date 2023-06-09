/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:09:29 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:15:38 by agimi            ###   ########.fr       */
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

void	cd_env(char *cd, int x)
{
	cd = get_env("HOME");
	if (!cd)
	{
		ft_putstr_fd("minishell-69: cd: HOME not set\n", 2);
		g_va.exit_s = 1;
	}
	else if (chdir(cd) == -1)
		print_error(cd, 1, x);
}

void	old_pwd(void)
{
	char	*old;

	old = ft_strjoin2fr(ft_strdup("OLDPWD="), getcwd(NULL, 0));
	add_env(old);
	add_exp(old);
	free(old);
}

void	cd_cmd(t_line *lm, int x)
{
	t_env	*em;
	char	*cd;

	cd = NULL;
	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	old_pwd();
	while (lm->nxt && ft_strcmp(lm->nxt->typ, "arg"))
		lm = lm->nxt;
	if (lm && !lm->nxt)
		cd_env(cd, x);
	else if (lm && chdir(lm->nxt->shx) == -1)
		print_error(lm->nxt->shx, 1, x);
	if (x)
		exit(0);
	cd = getcwd(NULL, 0);
	em = g_va.env;
	change_pwd(em, cd);
	close_fd();
}
