/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:19 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:46:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*ft_lastpipe(t_pipe *sp)
{
	if (!sp)
		return (NULL);
	while (sp->nxt)
		sp = sp->nxt;
	return (sp);
}

t_line	*ft_lastline(t_line *lin)
{
	if (!lin)
		return (NULL);
	while (lin->nxt)
		lin = lin->nxt;
	return (lin);
}

t_env	*ft_lastenv(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->nxt)
		env = env->nxt;
	return (env);
}
