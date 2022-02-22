/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:54:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 16:34:09 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif(t_list **list,char **argv)
{
	int	n;
	int	*tab;

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

int	add_content_lst(t_list *list)
{
	int	ret;

	ret = 0;
	if (list)
	{
		while (list)
		{
			ret = ret + list->content;
			list = list->next;
		}
	}
	return (ret);
}

void	print_tab(int *tab, int size)
{
	int	n;

	n = 0;
	printf("tableau: ");
	while (n < size)
	{
		printf("%d ", tab[n]);
		n++;
	}
	printf("\n");
}

void ft_bullshit(t_list* a, t_list* b, t_info *i)
{
	t_list* tmp;
	
	printf("PILE A: ");
	tmp = a;
	while (tmp) {
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\nPILE B: ");
	tmp = b;
	while (tmp) {
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\nCOUNT: ");
	tmp = i->count;
	while (tmp) {
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void	ft_brain(t_info *i)
{
	t_list	*tete;
	
	tete = i->list_a;
	while (ft_if_sort(i->list_a) == 1|| ft_lstsize(i->list_b) != 0)
	{
		if (i->first > 0)
		{
			// printf("FIRST | ETAT: %i\n", i->first);
			ft_firtsort(i, tete->content);
		}
		else if(i->second > 0)
		{
			// printf("SECOND\n");
			ft_second_step(i, tete->content);
		}
		else if(i->third > 0)
		{
			// printf("THIRD | count a = %d\n", make_count_a(i));
			ft_third_step(i, tete->content);
		}
		if(ft_if_sort(i->list_a) == 1|| ft_lstsize(i->list_b) != 0)
			swap_tete(i, &tete);
		// printf("MED: %d | TIER1 : %d | TIER2 : %d | LAST : %d | SIZE_A : %d\n", i->med, i->tier1, i->tier2, i->last, ft_lstsize(i->list_a));
		// ft_bullshit(i->list_a, i->list_b, i);
		// getchar();
	}
}

void	free_count(t_info *i)
{
	if(ft_lstsize(i->count) > 0)
	{
		if(ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
		{
			if (ft_lstsize(i->list_b) == 0)
				i->count = NULL;
			else
				ft_lstmove(i->count, ft_lstsize(i->count) - 1)->next = NULL;
		}
		else if(i->count->content == 0)
		{
			if (ft_lstsize(i->list_b) == 0)
				i->count = NULL;
			else
			{
				i->temp2 = i->count->next;
				free(i->count);
				i->count = i->temp2;
			}
		}
	}
}

void	swap_tete(t_info *i, t_list **tete)
{
	(*tete) = i->list_a;
	if (i->first == 0 && i->second > 0)
	{
		if(ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
		{
			// printf("second tete down\n");
			i->head = 1;
			(*tete) = ft_lstmove(i->list_b, ft_lstsize(i->list_b));
		}
		else if(i->count->content == 0)
		{
			// printf("second tete up\n");
			i->head = 0;
			(*tete) = i->list_b;
		}
		else if (i->list_b->content < ft_lstmove_i(i->list_b, add_content_lst(i->count)) && ft_lstsize(i->count) > 1)
		{
			// printf("second tete down\n");
			i->head = 1;
			(*tete) = ft_lstmove(i->list_b, ft_lstsize(i->list_b));
		}
		else
		{
			// printf("second tete up\n");
			i->head = 0;
			(*tete) = i->list_b;
		}
		lock_tete(i, tete);
	}
}

void	lock_tete(t_info *i, t_list **tete)
{
	if (i->lock == 1)
	{
		i->head = 0;
		(*tete) = i->list_b;
	}
	else if (i->lock == 2)
	{
		i->head = 1;
		(*tete) = ft_lstmove(i->list_b, ft_lstsize(i->list_b));
	}
}

void	crea_lst_inter(t_info *i,t_list *lst, int count)
{
	t_list *list;
	
	list = lst;
	while (count > 0)
	{
		ft_lstadd_back(&i->temp, ft_lstnew(list->content));
		count--;
		list = list->next;
	}
}

void	init(t_info *i)
{
	i->first = 1;
	i->second = 1;
	i->third = 1;
	// i->argc = argc - 1;
	i->list_a = NULL;
	i->list_b = NULL;
	i->count = NULL;
	i->count_a = 0;
	i->count2 = 0;
	i->ret = NULL;
	i->temp2 = NULL;
	i->head = 0;
	i->end_count = 0;
}

int	main(int argc, char *argv[])
{
	t_info i;
	int	count;
	
	if (argc > 1)
		{
			init(&i);
			verif(&i.list_a, argv);
			ft_brain(&i);
			count = 10000;
			while (--count > 0 && ft_lstsize_ret(i.ret) > 8)
				lst_change_rt_under(&i.ret);
			print_list_rt(i.ret);
			ft_lstclear(&i.list_a);
			ft_lstclear(&i.list_b);
			ft_lstclear_ret(&i.ret);
			ft_lstclear(&i.temp2);
			ft_lstclear(&i.temp);
			// printf("list_a\n");
			// print_list(i.list_a);
			// printf("listb\n");
			// print_list(i.list_b);
			// printf("ret\n");
			// print_list_rt(i.ret);
			// printf("listemp2\n");
			// print_list(i.temp2);
			// printf("temp\n");
			// print_list(i.temp);
			// printf("count\n");
			// print_list(i.count);
		}
	else
		return 1;
	return 0;
}

void	ft_lstclear_ret(t_ret **lst)
{
	t_ret	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
}

// 8358444 6474621 -15333794 -20027401 2418203 -1665143 5683210 6124284 -16291248 19294959 18440575 -2463636 -12235030 -17475888 -21370261 8134026 15710907 -15487818 16485266 14980475 17046058 6499558 10726979 -843465 -8653680 -17633583 9031792 -16866659 16267439 -11026476 -8198982 -4052984 3341807 -7852152 -6350215 -1347412 13145778 4491935 8608101 -16694330 -15635597 -1700828 8688319 -8824445 2344658 9765917 -12644774 -2762950 9943602 15172327
// 846 353413 24 844354 354 345 51 3435 1351 721 281 21  88 9 62 35 65 86 9121 
// 117 61 49 421 102 95 23 131 136 286 400 238 167 224 38 466 13 244 57 448
// 10 6 13 5 7 12 0 11 3 8 14 1 15 18 16 17 4 19 2 20
// -267 -443 -942 -103 -260 159 970 949 998 -739 -360 370 -656 -509 -573 -297 -150 -62 427 -634 444 -566 481 -481 -593 -613 -924 -448 -781 272 827 -58 725 -755 277 848 -374 610 -674 -630 872 387 251 -34 -43 206 -601 96 -229 -366 -701 320 -447 748 155 25 849 -823 -635 290 723 -336 -432 258 921 280 716 -168 -615 -228 -968 137 357 -175 -841 -86 842 961 824 -483 347 -485 -572 -206 -147 -627 -108 395 -291 943 157 278 188 -773 597 14 645 622 -893 459
// -128 -737 -42 -632 -686 -585 -854 -644 -222 310 719 -192 858 812 803 -876 -559 355 -175 -388 -759 694 960 510 -154 -297 -884 63 613 -102 -885 977 192 -528 -255 -875 -724 914 -203 758 -214 -822 105 -554 -398 -605 768 210 415 736 -562 -57 -985 -148 81 656 -576 908 814 -474 -829 987 956 751 -698 885 78 -252 654 -980 925 425 -54 -868 -604 -609 164 678 -279 384 913 -928 83 819 880 -988 514 198 376 333 -751 -304 -835 725 138 -333 -384 750 -375 959
// -430 -13 354 -483 371 -621 -873 533 -466 907 -122 -166 -784 -134 -322 691 537 426 581 -258 -405 -550 12 -829 429 -525 636 -389 -881 -269 673 194 464 -482 -735 683 413 -264 -52 503 352 -665 646 -579 37 -500 198 851 -298 -184 685 214 -938 -592 -546 229 -39 -503 883 -47 -313 -163 764 95 4 -285 -755 473 694 -41 585 -842 442 -981 -848 -62 283 547 86 971 384 374 312 -766 -591 712 -323 143 830 -378 -656 -446 94 -687 179 -733 -796 361 -227 -594
// 543 -558 -276 827 118 110 -258 841 819 160 594 538 463 -944 891 198 177 619 799 752 732 -51 475 -653 -63 -189 -985 -500 -621 -301 438 315 -358 794 -331 757 -504 447 624 833 558 880 -282 -170 -321 -365 283 256 690 -896 -514 856 -33 -951 194 -789 -454 -463 276 -606 -712 -792 -242 -475 109 9 -581 564 -591 -289 -433 182 -288 -469 569 930 153 988 -265 239 -772 -661 -636 499 -116 60 597 -461 133 266 916 692 -322 410 314 17 -67 -48 -745 -259
// -220 -57 -99 -618 440 56 145 906 -571 296 619 431 995 -975 624 -116 -313 -483 426 366 139 -179 -883 -660 -379