/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_3_2_Fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:16:54 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:22:46 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	pid_t pid, Hijo_pid;
	pid = fork();

	if (pid == -1) //Ha ocurrido un error
	{
		printf ("No se ha podido crear el proceso hijo…");
		exit (-1);
	}
	if (pid == 0) // Nos encontramos en Proceso Hijo
	{	
printf (" Soy el proceso hijo \n\t Mi PID es %d, El PID de mi pade es: %d,\n", getpid(), getppid() );
}
else   //Nos encontramos en proceso padre
{
	Hijo_pid = wait (NULL);   // espera la finalización del proceso hijo
	printf ("Soy el proceso padre \n\t Mi PID es %d, el PID de mi padre es:%d.\n\t Mi hijo %d terminó.\n",getpid(), getppid(), pid);
}
return (0);
}