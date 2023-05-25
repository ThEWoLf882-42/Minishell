/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:09:29 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 20:07:02 by zouaraqa         ###   ########.fr       */
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

void	cd_cmd(t_line *lm, int x)
{
	t_env	*em;
	char	*cd;

	if (!lm->nxt)
	{
		cd = getenv("HOME");
		if (chdir(cd) == -1)
			print_error(cd, 1, x);
	}
	else if (chdir(lm->nxt->shx) == -1)
		print_error(lm->nxt->shx, 1, x);
	if (x)
		exit(0);
	cd = getcwd(NULL, 0);
	em = g_va.env;
	change_pwd(em, cd);
}
