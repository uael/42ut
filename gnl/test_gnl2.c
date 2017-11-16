/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 17:04:46 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

#include "src/get_next_line.h"

int	main(void)
{
	char *foo;

	assert(-1 == get_next_line(3, &foo));
	assert(-1 == get_next_line(INT32_MAX, &foo));
	assert(-1 == get_next_line(56465445, &foo));
	assert(-1 == get_next_line(0, NULL));
	return (EXIT_SUCCESS);
}
