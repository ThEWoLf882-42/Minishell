/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:09:29 by agimi             #+#    #+#             */
/*   Updated: 2023/06/12 16:33:57 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change(char *cd)
{
	t_env	*em;
	t_exp	*xp;

	em = g_va.env;
	xp = g_va.xport;
	change_pwd_env(em, cd);
	change_pwd_exp(xp, cd);
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
	change(cd);
	close_fd();
}
