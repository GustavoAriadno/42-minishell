/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:35:19 by aroque            #+#    #+#             */
/*   Updated: 2021/02/04 22:37:21 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_env(t_shell *shell)
{
	unsigned	i;

	if (!shell->env)
		return ;
	i = 0;
	while (i < shell->env->size)
	{
		if (shell->env->array[i])
		{
			ft_putstr_fd(shell->env->array[i]->key, shell->fd);
			ft_putchar_fd('=', shell->fd);
			ft_putendl_fd((char *)shell->env->array[i]->value, shell->fd);
		}
		i++;
	}
}
