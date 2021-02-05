/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:14:00 by aroque            #+#    #+#             */
/*   Updated: 2021/02/04 22:38:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "libft.h"
#include "minishell.h"
#include "errcode.h"
#include "commands.h"
#include <unistd.h>

t_shell			*g_shell;

t_hashtable		*load_builtins(void)
{
	t_hashtable *ht;

	ht = ht_create(7);
	ht_set(ht, "echo", ft_echo);
	ht_set(ht, "cd", ft_cd);
	ht_set(ht, "pwd", ft_pwd);
	ht_set(ht, "export", ft_export);
	ht_set(ht, "unset", ft_exit);
	ht_set(ht, "env", ft_env);
	ht_set(ht, "exit", ft_exit);
	return (ht);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_hashtable *env;
	t_shell	*shell;

	if (argc != 1 || ft_strncmp("./minishell", argv[0], 11))
		message_and_exit(EUSAGE, 0x0);
	env = load_env(envp);
	repl(env, envp);
	return (EXIT_SUCCESS);
}
