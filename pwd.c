/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:54:41 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 15:41:20 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_cmd(int x)
{
	char	*pwd;

	if (open_file(g_va.sp, x))
		return ;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		print_error(pwd, 1, x);
	printf("%s\n", pwd);
	free(pwd);
	if (x)
		exit(0);
	close_fd();
}
