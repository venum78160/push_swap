/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:54:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/23 14:37:46 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif(t_list **list,char **argv)
{
	int	n;
	int	*tab;

	printf("test de debug\n");
	n = 0;
	while (argv[++n])
		crea_lst(list,argv[n]);
	tab = crea_tabi(list);
	sort_tab(tab, ft_lstsize(*list));
	if (find_dup(tab, ft_lstsize(*list)) == 1)
		ft_exit(tab);
	free(tab);
}

void	ft_exit(int	*tab)
{
	free(tab);
	ft_erreur();
}

void	ft_erreur()
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	print_list(t_list *list)
{
	if (list)
	{
		while (list)
		{
			printf("valeur de la chaine : %i\n", list->content);
			list = list->next;
		}
	}
}

void	print_tab(int *tab, int size)
{
	int	n;

	n = 0;
	while (n < size)
	{
		printf("valeur du tableau = %i a n = %i\n", tab[n], n);
		n++;
	}
}

// void	ft_brain(t_list **list_a, t_list **list_b)
// {
// 	int		*tab;
// 	int		*temp;
// 	t_list	*tete;
// 	int		count;
// 	int		first;

// 	count = 0;
// 	first = 1;
// 	tab = crea_tabi(list_a);
// 	sort_tab(tab, ft_lstsize(*list_a));
// 	tete = *list_a;
// 	printf("med = %i\n", find_med(tab, ft_lstsize(*list_a)));
// 	while ( ft_if_sort(*list_a) == 1 || ft_lstsize(*list_b) != 0)
// 	{
// 		printf("first = %i\n", first);
// 		if (first == 1)
// 		{
// 			first = ft_firtsort(list_a, list_b, tab, tete->content);
// 			tete = *list_a;
// 			continue;
// 		}
// 		else if(first == 0)
// 			exit(0);
// 		printf("med = %i\n", find_med(tab, ft_lstsize(*list_a)));
// 		if ((ft_lstsize(*list_a) == 2 || ft_lstsize(*list_a) == 3) && ft_if_sort(*list_a) == 1)
// 		{
// 			sort_three(list_a);
// 			printf("sort_three\n");
// 			exit(0);
// 		}
// 		else if (tete->content < find_med(tab, ft_lstsize(*list_a)))
// 		{
// 			ft_pa(list_a, list_b);
// 			printf("ft_pa\n");
// 			exit(0);
// 		}
// 		else if (ft_if_sort(*list_a) == 1 && tete->content >= find_med(tab, ft_lstsize(*list_a)))
// 		{
// 			ft_ra(list_a);
// 			printf("ft_ra\n");
// 			exit(0);
// 		}
// 		else if (ft_if_sort(*list_a) == 0)
// 		{
// 			printf("here = %i\n", tete->content);
// 			exit(0);
// 			temp = crea_tabi(list_b);
// 			sort_tab(temp, ft_lstsize(*list_b));
// 			tete = *list_b;
// 			printf("valeur de temp[count] = %i\n", temp[ft_lstsize(*list_b) - count]);
// 			if (tete->content == temp[ft_lstsize(*list_b) - count])
// 			{
// 				printf("pa tete.content = %i\n", tete->content);
// 				ft_pa(list_b, list_a);
// 				count++;
// 				sort_three_up(list_a);
// 				printf("sort\n");
// 			}
// 		}
// 		tete = *list_a;
// 		printf("b size = %i\n", ft_lstsize(*list_b));
// 		printf("is sort ? = %i\n", ft_if_sort(*list_a));
// 		printf("liste A\n");
// 		print_list(*list_a);
// 		printf("liste B\n");
// 		print_list(*list_b);
// 		printf("end\n");
// 	}
// 	printf("liste A\n");
// 	print_list(*list_a);
// 	printf("liste B\n");
// 	print_list(*list_b);
	
// }

void	ft_brain(t_info *i)
{
	t_list	*tete;

	i->tab = crea_tabi(&i->list_a);
	i->size_tab = ft_lstsize(i->list_a);
	sort_tab(i->tab, i->size_tab);
	tete = i->list_a;
	i->med = find_med(i->list_a);
	printf("med = %i\n", i->med);
	i->last = ft_lstmove_i(i->list_a, i->size_tab);
	while ( ft_if_sort(i->list_a) == 1 || i->first == 1)
	{
		if (i->first == 1)
			i->first = ft_firtsort(i, tete->content);
		else if(i->second == 1)
			ft_second_step(i, tete->content);
		if (i->first == 1)
			tete = i->list_a;
		else
			tete = i->list_a;
	}
	printf("valeur de etat = %i\n", i->etat);
}

void	ft_second_step(t_info *i, int tete)
{
	static int count = 0;

	if (i->second == 1)
	{
		crea_lst_inter(i, i->list_b,ft_lstmove_i(i->count, ft_lstsize(i->count)));
		i->med = find_med(i->temp);
		ft_lstclear(&i->temp);
		if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
		{
			ft_pa(&i->list_b, &i->list_a);
			printf("ft_pb\n\n");
			ft_lstdelone(ft_lstmove(i->count, ft_lstsize(i->count)));
		}
		i->second = 0;
	}
	else if (tete > i->med)
	{
		ft_pa(&i->list_b, &i->list_a);
		printf("ft_pb\n\n");
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
	}
	else if(tete <= i->med)
	{
		ft_ra(&i->list_b);
		printf("ft_rb\n\n");
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		count++;
	}
	else if(ft_lstmove(i->count, ft_lstsize(i->count))->content == 0)
	{
		while (count > 0)
		{
			ft_rra(&i->list_b);
			printf("ft_rrb\n\n");
		}
		count = 0;
	}
}

void	crea_lst_inter(t_info *i,t_list *lst, int count)
{
	while (count > 0)
	{
		ft_lstadd_back(&i->temp, ft_lstnew(lst->content));
		count--;
	}
}

int	ft_firtsort(t_info *i, int tete)
{
	static int count = 0;

	if ((ft_lstsize(i->list_a) == 2 || ft_lstsize(i->list_a) == 3) && ft_if_sort(i->list_a) == 1)
	{
		sort_three(&i->list_a);
		printf("sort_three\n\n");
		return (0);
	}
	else if (tete < i->med)
	{
		count++;
		ft_pa(&i->list_a, &i->list_b);
		printf("ft_pa\n\n");
		if (tete == i->last)
		{
			crea_lst(&i->count, ft_itoa(count));
			count = 0;
			i->etat++;
			printf("size of lst_a = %i\n", ft_lstsize(i->list_a));
			printf("size of lst_b = %i\n", ft_lstsize(i->list_b));
			i->med = find_med(i->list_a);
			i->last = ft_lstmove_i(i->list_a, ft_lstsize(i->list_a));
			printf("liste A\n");
			print_list(i->list_a);
			printf("liste B\n");
			print_list(i->list_b);
			printf("end\n");
		}
		return(1);
	}
	else if (tete >= i->med)
	{
		ft_ra(&i->list_a);
		printf("ft_ra\n\n");
		if (tete == i->last)
		{
			crea_lst(&i->count, ft_itoa(count));
			count = 0;
			printf("size of lst_a = %i\n", ft_lstsize(i->list_a));
			printf("size of lst_b = %i\n", ft_lstsize(i->list_b));
			i->med = find_med(i->list_a);
			i->last = ft_lstmove_i(i->list_a, ft_lstsize(i->list_a));
			printf("liste A\n");
			print_list(i->list_a);
			printf("liste B\n");
			print_list(i->list_b);
			printf("end\n");
		}
		return(1);
	}
	printf("Il a une erreur \n\n\n\n\n !!!!!!!!!!!!\n");
	exit(1);
	return(1);
}

int	main(int argc, char *argv[])
{
	t_info i;
	if (argc > 1)
		{
			i.etat = 0;
			i.first = 1;
			i.second = 1;
			i.third = 1;
			i.argc = argc - 1;
			verif(&i.list_a, argv);
			printf("here\n");
			print_list(i.list_a);
			printf("\n\n");
			ft_brain(&i);
			printf("liste A\n");
			print_list(i.list_a);
			printf("liste B\n");
			print_list(i.list_b);
			printf("valeur count\n");
			print_list(i.count);
			printf("end+++\n");
		}
	else
		return 1;
	return 0;
}

// 8358444 6474621 -15333794 -20027401 2418203 -1665143 5683210 6124284 -16291248 19294959 18440575 -2463636 -12235030 -17475888 -21370261 8134026 15710907 -15487818 16485266 14980475 17046058 6499558 10726979 -843465 -8653680 -17633583 9031792 -16866659 16267439 -11026476 -8198982 -4052984 3341807 -7852152 -6350215 -1347412 13145778 4491935 8608101 -16694330 -15635597 -1700828 8688319 -8824445 2344658 9765917 -12644774 -2762950 9943602 15172327