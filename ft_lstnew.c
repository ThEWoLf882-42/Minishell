/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:05:04 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 22:26:33 by agimi            ###   ########.fr       */
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
	lin->err = 0;
	lin->shx = ft_strdup(str);
	lin->nxt = NULL;
	lin->typ = NULL;
	lin->prv = NULL;
	return (lin);
}
