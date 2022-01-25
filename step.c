/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/25 12:15:45 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_firtsort(t_info *i, int tete)
{
	static int count = 0;

	if ((ft_lstsize(i->list_a) <= 3) && ft_amoreb(i) == 0)
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
			ft_lstadd_back(&i->count, ft_lstnew(count));
			// crea_lst(&i->count, ft_itoa(count));
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
			ft_lstadd_back(&i->count, ft_lstnew(count));
			// crea_lst(&i->count, ft_itoa(count));
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

void	ft_second_step(t_info *i, int tete)
{
	static int count = 0;
    static int count_a = 0;
	

	if (i->second == 1)
	{
        printf("debut phase 2\n");
		printf("size count = %i\n", ft_lstsize(i->count));
		printf("taille int count = %i\n", ft_lstmove_i(i->count, ft_lstsize(i->count)));
		crea_lst_inter(i, i->list_b,ft_lstmove_i(i->count, ft_lstsize(i->count)));
		printf("liste Temp\n");
		print_list(i->temp);
		i->med = find_med(i->temp);
		ft_lstclear(&i->temp);
        i->second = 2;
        i->last = ft_lstmove_i(i->list_b, ft_lstmove_i(i->count, ft_lstsize(i->count)));
		printf("med = %i\n", i->med);
		printf("liste A\n");
		print_list(i->list_a);
		printf("liste B\n");
		print_list(i->list_b);
		printf("valeur count\n");
		print_list(i->count);
		printf("end\n");
		if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
		{
            while (ft_lstmove_i(i->count, ft_lstsize(i->count)) > 0)
            {
                ft_pa(&i->list_b, &i->list_a);
                printf("ft_pb_3\n\n");
                ft_lstmove(i->count, ft_lstsize(i->count))->content--;
                count_a++;
            }
			free(ft_lstmove(i->count, ft_lstsize(i->count)));
			ft_lstmove(i->count, ft_lstsize(i->count) - 1)->next = NULL;
			printf("size of count %i\n", ft_lstsize(i->count));
			printf("step 2, count_a = %i\n", count_a);
			i->count_a = count_a;
			printf("debug\n");
            count_a = 0;
            i->second = 0;
			i->third = 1;
		}
	}
	else if(ft_lstmove(i->count, ft_lstsize(i->count))->content == 0)
	{
		while (count > 0)
		{
			ft_rra(&i->list_b);
			printf("ft_rrb\n\n");
			count--;
			ft_lstmove(i->count, ft_lstsize(i->count))->content++;
		}
		i->second = 0;
		i->third = 1;
	}
	else if (tete >= i->med)
	{
		ft_pa(&i->list_b, &i->list_a);
		printf("ft_pb\n\n");
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
        count_a++;
        if (tete == i->last)
        {
			i->count_a = count_a;
            count_a = 0;
        }
	}
	else if(tete < i->med)
	{
		ft_ra(&i->list_b);
		printf("ft_rb\n\n");
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		count++;
        if (tete == i->last)
        {
			i->count_a = count_a;
        	count_a = 0;
        }
	}
}

void	ft_third_step(t_info *i, int tete)
{
	static int count = 0;
    static int count_b = 0;

	printf("valeur tete %i\n", tete);
	printf("valeur count_a = %i\n", i->count_a);
	if (i->third == 1)
	{
        printf("debut phase 3\n");
		crea_lst_inter(i, i->list_a,i->count_a);
		printf("liste Temp\n");
		print_list(i->temp);
		i->med = find_med(i->temp);
		ft_lstclear(&i->temp);
        i->third = 2;
        i->last = ft_lstmove_i(i->list_a, i->count_a);
		printf("i.last = %i\n", i->last);
		printf("med = %i\n", i->med);
		printf("liste A\n");
		print_list(i->list_a);
		printf("liste B\n");
		print_list(i->list_b);
		printf("valeur count\n");
		print_list(i->count);
		printf("apres valeur count\n");
		printf("valeur count_a = %i\n", i->count_a);
		printf("end\n");
		if (i->count_a <= 3)
		{
			printf("here debug\n");
			sort_three_up(&i->list_a);
			printf("sort_three_up\n\n");
			i->count_a = 0;
			printf("size of count %i\n", ft_lstsize(i->count));
            i->second = 1;
		}
	}
	else if(i->count_a == 0)
	{
		while (count > 0)
		{
			ft_rra(&i->list_a);
			printf("ft_rra\n\n");
			count--;
			i->count_a++;
		}
		i->third = 1;
	}
	else if (tete >= i->med)
	{
		ft_ra(&i->list_a);
		printf("ft_ra\n\n");
		i->count_a--;
		count++;
	}
	else if(tete < i->med)
	{
		ft_pa(&i->list_a, &i->list_b);
		printf("ft_pb\n\n");
		// ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		count_b++;
		i->count_a--;
		if (tete == i->last)
        {
			ft_lstadd_back(&i->count, ft_lstnew(count_b));
    		// crea_lst(&i->count_a, ft_itoa(count));
        	count_b = 0;
        }
	}
}