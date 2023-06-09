/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:48:57 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:19:42 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_backexp(t_exp **exp, t_exp *new)
{
	if (!exp || !new)
		return ;
	if ((*exp))
		ft_lastexp((*exp))->nxt = new;
	else
		(*exp) = new;
}
