/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/07 20:28:47 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_firtsort(t_info *i, int tete)
{
	static int count = 0;

	// printf("\nfirst\n");
	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
	if (i->first == 1)
	{
		i->med = find_med(i->list_a);
		find_dbl_med(i, i->list_a);
		i->last = ft_lstmove_i(i->list_a, ft_lstsize(i->list_a));
		i->first = 2;
		if (ft_lstsize(i->list_a) > 6)
			i->first = 3;
		if ((ft_lstsize(i->list_a) <= 3) && ft_amoreb(i) == 0)
		{
			sort_three(i, &i->list_a);
			i->first = 0;
		}
	}
	else if (i->first == 3)
		sort_dbl_med(i, tete, &count);
	else if (tete < i->med)
	{
		// printf("inf med pb\n");
		count++;
		ft_pa(i, &i->list_a, &i->list_b, 'b');
	}
	else if (tete >= i->med)
	{
		// printf("sup ou eg med ra\n");
		ft_ra(i, &i->list_a, 'a');
	}
	if (tete == i->last)
	{
		if (count > 0)
			ft_lstadd_front(&i->count, ft_lstnew(count));
		count = 0;
		i->first = 1;
	}
}

void	sort_dbl_med(t_info *i, int tete, int *count)
{
	static int count_pa = 0;

	if (tete <= i->tier1)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		if(ft_lstsize(i->list_b) > 1)
			ft_ra(i, &i->list_b, 'b');
		(*count)++;
	}
	else if(tete <= i->tier2)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_pa++;
	}
	else if (tete > i->tier2)
		ft_ra(i, &i->list_a, 'a');
	if (tete == i->last)
	{
		ft_lstadd_back(&i->count, ft_lstnew((*count)));
		ft_lstadd_front(&i->count, ft_lstnew(count_pa));
		(*count) = 0;
		count_pa = 0;
		i->first = 1;
	}
}

// void	ft_second_step(t_info *i, int tete)
// {
// 	static int count = 0;
//     static int count_a = 0;
	
// 	printf("\ndebut step 2\n");
// 	printf("liste A\n");
// 	print_list(i->list_a);
// 	printf("liste B\n");
// 	print_list(i->list_b);
// 	printf("liste count\n");
// 	print_list(i->count);
// 	exit(0);
// 	if (i->second == 1)
// 	{
// 		crea_lst_inter(i, i->list_b,ft_lstmove_i(i->count, ft_lstsize(i->count)));
// 		i->med = find_med(i->temp);
// 		ft_lstclear(&i->temp);
//         i->second = 2;
//         i->last = ft_lstmove_i(i->list_b, ft_lstmove_i(i->count, ft_lstsize(i->count)));
// 		if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
// 		{
//             while (ft_lstmove_i(i->count, ft_lstsize(i->count)) > 0)
//             {
//                 ft_pa(i, &i->list_b, &i->list_a, 'a');
//                 ft_lstmove(i->count, ft_lstsize(i->count))->content--;
//                 count_a++;
//             }
// 			free(ft_lstmove(i->count, ft_lstsize(i->count)));
// 			if (ft_lstsize(i->list_b) == 0)
// 				i->count = NULL;
// 			else
// 				ft_lstmove(i->count, ft_lstsize(i->count) - 1)->next = NULL;
// 			i->count_a = count_a;
//             count_a = 0;
//             i->second = 0;
// 			i->third = 1;
// 		}
// 	}
// 	else if(ft_lstmove(i->count, ft_lstsize(i->count))->content == 0)
// 	{
// 		while (count > 0)
// 		{
// 			ft_rra(i, &i->list_b, 'b');
// 			count--;
// 			ft_lstmove(i->count, ft_lstsize(i->count))->content++;
// 		}
// 		i->second = 0;
// 		i->third = 1;
// 	}
// 	else if (tete >= i->med)
// 	{
// 		ft_pa(i, &i->list_b, &i->list_a, 'a');
// 		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
//         count_a++;
//         if (tete == i->last)
//         {
// 			i->count_a = count_a;
//             count_a = 0;
//         }
// 	}
// 	else if(tete < i->med)
// 	{
// 		ft_ra(i, &i->list_b, 'b');
// 		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
// 		count++;
//         if (tete == i->last)
//         {
// 			i->count_a = count_a;
//         	count_a = 0;
//         }
// 	}
// }

void	ft_second_step(t_info *i, int tete)
{
	static int count = 0;

	// printf("\ndebut step 2\n");
	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
	// exit(1);
	if (i->second == 1)
	{
		if (i->head == 0)
			declar_step_2_up(i);
		else
		{
			declar_step_2_down(i);
		}
	}
	if (i->second > 1)
	{
		if (i->head == 0)
			sort_step_2_up(i, &count, tete);
		else
		{
			sort_step_2_down(i, &count, tete);
		}
	}
	// printf("end step 2\n");
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
}

void	sort_step_2_up(t_info *i, int *count, int tete)
{
	// printf("sort up\n");
	if(i->count->content == 0)
	{
		while ((*count) > 0)
		{
			ft_rra(i, &i->list_b, 'b');
			(*count)--;
			i->count->content++;
		}
		i->second = 0;
		i->third = 1;
	}
	else if (tete >= i->med)
	{
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		i->count->content--;
        i->count_a++;
	}
	else if(tete < i->med)
	{
		ft_ra(i, &i->list_b, 'b');
		i->count->content--;
		(*count)++;
	}
}

void	sort_step_2_down(t_info *i, int *count, int tete)
{
	// printf("sort down\n");
	if(ft_lstmove(i->count, ft_lstsize(i->count))->content == 0)
	{
		while ((*count) > 0)
		{
			ft_ra(i, &i->list_b, 'b');
			(*count)--;
			ft_lstmove(i->count, ft_lstsize(i->count))->content++;
		}
		i->second = 0;
		i->third = 1;
	}
	else if (tete >= i->med)
	{
		ft_rra(i, &i->list_b, 'b');
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
        i->count_a++;
	}
	else if(tete < i->med)
	{
		ft_rra(i, &i->list_b, 'b');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		(*count)++;
	}
}

void	declar_step_2_up(t_info *i)
{
	// printf("decla_2_up\n");
	crea_lst_inter(i, i->list_b, i->count->content);
	i->med = find_med(i->temp);
	ft_lstclear(&i->temp);
	i->second = 2;
    i->last = ft_lstmove_i(i->list_b, i->count->content);
	if (i->count->content <= 3)
	{
		while (i->count->content > 0)
        {
            ft_pa(i, &i->list_b, &i->list_a, 'a');
            i->count->content--;
			i->count_a++;
		}
		if (ft_lstsize(i->list_b) == 0)
			i->count = NULL;
		else
		{
			i->temp2 = i->count->next;
			free(i->count);
			// printf("free step 2 up\n");
			i->count = i->temp2;
			// printf("liste count\n");
			// print_list(i->count);
			// printf("end count\n");
		}
		i->second = 0;
		i->third = 1;
	}
}

void	declar_step_2_down(t_info *i)
{
	// printf("decla_2_down\n");
	crea_lst_inter(i, i->list_b,ft_lstmove_i(i->count, ft_lstsize(i->count)));
	i->med = find_med(i->temp);
	ft_lstclear(&i->temp);
	i->second = 2;
    i->last = ft_lstmove_i(i->list_b, ft_lstmove_i(i->count, ft_lstsize(i->count)));
	if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
	{
		while (ft_lstmove_i(i->count, ft_lstsize(i->count)) > 0)
        {
			ft_rra(i, &i->list_b, 'b');
            ft_pa(i, &i->list_b, &i->list_a, 'a');
            ft_lstmove(i->count, ft_lstsize(i->count))->content--;
			i->count_a++;
		}
		free(ft_lstmove(i->count, ft_lstsize(i->count)));
		if (ft_lstsize(i->list_b) == 0)
			i->count = NULL;
		else
			ft_lstmove(i->count, ft_lstsize(i->count) - 1)->next = NULL;
		i->second = 0;
		i->third = 1;
	}
}

void	ft_third_step(t_info *i, int tete)
{
	static int count = 0;
    static int count_b = 0;

	// printf("step 3 begin fonction\n");
	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
	if (i->third == 1)
	{
		// printf("decla 3\n");
		// printf("i.count_a = %i\n", i->count_a);
		// printf("count_b = %i\n", count_b);
		crea_lst_inter(i, i->list_a,i->count_a);
		i->med = find_med(i->temp);
		ft_lstclear(&i->temp);
        i->third = 2;
        i->last = ft_lstmove_i(i->list_a, i->count_a);
		if (i->count_a <= 3)
		{
			sort_three_up(i, &i->list_a);
			if (count_b > 0)
			{
				ft_lstadd_front(&i->count, ft_lstnew(count_b));
				// printf("step 3 add front count b\n");
				// printf("liste count\n");
				// print_list(i->count);
				// printf("end count\n");
			}
			i->count_a = 0;
			count_b = 0;
            i->second = 1;
			// printf("step 3 end\n");
			// printf("liste count\n");
			// print_list(i->count);
			// printf("end count\n");
		}
	}
	else if(i->count_a == 0)
	{
		// printf("i->count_a == 0\n");
		while (count > 0)
		{
			ft_rra(i, &i->list_a, 'a');
			count--;
			i->count_a++;
		}
		i->third = 1;
	}
	else if (tete >= i->med)
	{
		// printf("tete >= i->med\n");
		ft_ra(i, &i->list_a, 'a');
		i->count_a--;
		count++;
	}
	else if(tete < i->med)
	{
		// printf("tete < i->med\n");
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_b++;
		i->count_a--;
	}
}
