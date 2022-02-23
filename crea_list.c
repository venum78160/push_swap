/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:50:14 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 11:51:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_deter_int(const char*theString, int max)
{
	int					i;
	long				num;
	int					neg;

	neg = 1;
	i = 0;
	num = 0;
	while (theString[i] == '\t' || theString[i] == '\n' || theString[i] == '\v'
		|| theString[i] == '\f' || theString[i] == '\r' || theString[i] == ' ')
		i++;
	if (theString[i] == '+' || theString[i] == '-')
	{
		if (theString[i] == '-')
			neg *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		if (num > 2147483647 || num < -2147483648)
			return (1);
		num = num * 10 + neg * (theString[i++] - '0');
	}
	if (ft_isdigit(theString[i]) == 404 || num < -2147483648 || num > max)
		return (1);
	return (0);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	crea_lst(t_list **list, char *argv)
{
	char	**tab;
	int		n;

	tab = ft_split(argv, ' ');
	n = -1;
	while (tab[++n] != NULL)
	{
		if (ft_deter_int(tab[n], 2147483647) == 1)
			ft_erreur();
		ft_lstadd_back(list, ft_lstnew(ft_atoi(tab[n])));
	}
	ft_free_tab(tab);
}

int	*crea_tabi(t_list **list)
{
	t_list	*tete;
	int		*tab;
	int		count;

	count = -1;
	tab = malloc(4 * ft_lstsize(*list) + 4);
	tete = *list;
	while (++count < ft_lstsize(*list))
	{
		tab[count] = (tete->content);
		tete = tete->next;
	}
	tab[count] = '\0';
	return (tab);
}

int	find_dup(int *tab, int size)
{
	int	count;

	count = 0;
	while (++count < size)
		if (tab[count] == tab[count - 1])
			return (1);
	return (0);
}
