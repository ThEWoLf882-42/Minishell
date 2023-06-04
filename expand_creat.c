/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_creat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:41:14 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 15:41:27 by agimi            ###   ########.fr       */
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

void	creat_expnod(t_line **newlm, char *found, int bf)
{
	char	**str;
	int		i;

	if (!found)
		return ;
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
		ft_backline(newlm, new_lin(str[i], 1));
		free(str[i]);
	}
	free(str);
}

// add tab maybe <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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
		if (!ft_strncmp(get, em->arg, ft_strlen(get)))
		{
			if (em->arg[ft_strlen(get) + 1] == ' ')
				*bf = 1;
			if (em->arg[ft_strlen(em->arg) - 1] == ' ')
				*af = 1;
			return (ft_strdup(&em->arg[ft_strlen(get) + 1]));
		}
		em = em->nxt;
	}
	return (NULL);
}
