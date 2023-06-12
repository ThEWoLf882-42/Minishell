/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_creat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:41:14 by agimi             #+#    #+#             */
/*   Updated: 2023/06/11 13:38:37 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*sp_dlr(char *get, int *bf, int *af)
{
	*bf = 0;
	*af = 0;
	if (!*get)
		return (ft_strdup("$"));
	if (get[0] == 31 && get[1] == '\0')
		return (ft_strdup("69"));
	if (get[0] == '?' && get[1] == '\0')
		return (ft_itoa(g_va.exit_s));
	return (NULL);
}

void	replace_tab(char *found)
{
	int	i;

	i = -1;
	while (found[++i])
		if (found[i] == '\t')
			found[i] = ' ';
}

void	creat_expnod(t_exp_utl *exp, char *found, int bf)
{
	t_line	**newlm;
	char	**str;
	int		i;

	newlm = &exp->newlm;
	if (!found)
		return ;
	replace_tab(found);
	str = ft_split(found, ' ');
	if (!str[0])
		return ;
	i = -1;
	if (!bf)
	{
		i = 0;
		free(str[0]);
	}
	while (str[++i])
	{
		ft_backline(newlm, new_lin(str[i], exp->typ, 1));
		free(str[i]);
	}
	free(str);
}

char	*which_env(char *get, int *bf, int *af)
{
	t_env	*em;

	*bf = 0;
	*af = 0;
	em = g_va.env;
	if (!*get || (get[0] == 31 && get[1] == '\0')
		|| (get[0] == '?' && get[1] == '\0'))
		return (sp_dlr(get, bf, af));
	while (em)
	{
		if (!ft_strncmp(get, em->arg, ft_strlen(get))
			&& em->arg[ft_strlen(get)] == '=' && em->arg[ft_strlen(get) + 1])
		{
			if (em->arg[ft_strlen(get) + 1] == ' ' \
				|| em->arg[ft_strlen(get) + 1] == '\t')
				*bf = 1;
			if (em->arg[ft_strlen(em->arg) - 1] == ' ' \
				|| em->arg[ft_strlen(em->arg) - 1] == '\t')
				*af = 1;
			return (ft_strdup(&em->arg[ft_strlen(get) + 1]));
		}
		em = em->nxt;
	}
	return (NULL);
}
