/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 08:05:27 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

int	main(void)
{
	assert(atoi("") == ft_atoi(""));
	assert(atoi("0") == ft_atoi("0"));
	assert(atoi("0 1") == ft_atoi("0 1"));
	return (EXIT_SUCCESS);
}
