/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:19 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 17:16:23 by agimi            ###   ########.fr       */
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
