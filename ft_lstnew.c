/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:05:04 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:44:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*new_sp(char *str)
{
	t_pipe	*sp;

	sp = malloc(sizeof(t_pipe));
	if (!sp)
		return (NULL);
	sp->pl = ft_strdup(str);
	sp->nxt = NULL;
	sp->lin = NULL;
	return (sp);
}

t_line	*new_lin(char *str)
{
	t_line	*lin;

	lin = malloc(sizeof(t_line));
	if (!lin)
		return (NULL);
	lin->shx = ft_strdup(str);
	lin->path = NULL;
	lin->nxt = NULL;
	lin->typ = NULL;
	lin->prv = NULL;
	return (lin);
}

t_env	*new_env(char *str)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->arg = ft_strdup(str);
	env->nxt = NULL;
	return (env);
}
