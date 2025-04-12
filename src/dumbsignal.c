/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumbsignal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:24:46 by llage             #+#    #+#             */
/*   Updated: 2025/04/12 10:24:46 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>

static void	(*handler_funcs[NSIG])(void) = {NULL};

static void	signal_wrapper(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (sig >= 0 && sig < NSIG && handler_funcs[sig] != NULL)
		handler_funcs[sig]();
}

int	dumbsignal(const int signum, void (*handler)(void))
{
	struct sigaction sa;

	if (signum < 0 || signum >= NSIG)
		return -1;

	handler_funcs[signum] = handler;

	sa.sa_sigaction = signal_wrapper;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	return sigaction(signum, &sa, NULL);
}