/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:21:00 by migugar2          #+#    #+#             */
/*   Updated: 2024/11/25 01:29:35 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stackpush(t_stack *stack, t_dlist *node)
{
	if (stack == NULL || node == NULL)
		return (0);
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
		ft_dlstadd_front(&stack->top, node);
	stack->size++;
	return (stack->size);
}
