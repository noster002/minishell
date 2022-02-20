/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:16:25 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/17 14:23:10 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + converts lowercase letters to uppercase
 *   If c is neither an unsigned char value nor EOF,
 *   the behavior of these functions is undefined.
 * + returns the converted letter or c if the conversion was not possible
 * + man toupper
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
