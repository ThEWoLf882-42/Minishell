/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:30:34 by agimi             #+#    #+#             */
/*   Updated: 2023/06/12 16:32:22 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd_exp(t_exp *xp, char *cd)
{
	char	*str;
	int		i;
	int		j;

	while (xp)
	{
		i = -1;
		j = -1;
		if (!ft_strncmp(xp->xarg, "PWD=", 4))
		{
			str = malloc(sizeof(char) * (4 + ft_strlen(cd) + 1));
			if (!str)
				return ;
			while (xp->xarg[++i] && i < 4)
				str[++j] = xp->xarg[i];
			free(xp->xarg);
			i = -1;
			while (cd[++i])
				str[++j] = cd[i];
			str[++j] = '\0';
			xp->xarg = str;
			free(cd);
		}
		xp = xp->nxt;
	}
}

void	change_pwd_env(t_env *em, char *cd)
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
		}
		em = em->nxt;
	}
}
