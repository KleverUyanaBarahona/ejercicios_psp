/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_PadresPid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:01:06 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:22:48 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//Identificador de PID
int main (void)
{
	pid_t id_pactual, id_padre;
	id_pactual = getpid();
	id_padre = getppid();

	printf ("PID de este proceso: %d\n", id_pactual);
	printf ("PID del proceso padre: %d\n", id_padre);
}
