/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:24:50 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/17 14:25:43 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + converts uppercase letters to lowercase
 *   If c is neither an unsigned char value nor EOF,
 *   the behavior of these functions is undefined.
 * + returns the converted letter or c if the conversion was not possible
 * + man tolower
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
