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
	assert(STREQ(ft_itoa_base(10, 2), "1010"));
	assert(STREQ(ft_itoa_base(42, 2), "101010"));
	assert(STREQ(ft_itoa_base(564, 2), "1000110100"));
	assert(STREQ(ft_itoa_base(515616516, 30), "l6gr76"));
	return (EXIT_SUCCESS);
}
