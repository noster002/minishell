/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:43:54 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 17:32:09 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + checks for a digit
 * + returns a nonzero value if character c is a digit and zero if not
 * + man isdigit
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
