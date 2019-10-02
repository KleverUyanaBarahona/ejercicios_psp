/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_3_3_Fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:24:41 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:28:58 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
pid_t pid, Hijo_pid, pid2, Hijo2_pid;

pid = fork(); //Soy el abuelo y creo el Hijo

if (pid == -1)      //ha ocurrido un error
{
	printf("No se ha podido crear el proceso hijo…");
	return (-1);
}

if (pid == 0)       //Nos encontramos en el proceso Hijo
{
	pid2 = fork(); // Crea el Nieto
	switch (pid2)
	{
		case -1:    // error
			printf ("No se ha podido crear el Nieto (Hijo del Hijo)");
			return (-1);
			break;
		case 0:      //proceso hijo
			printf("\t\tSoy el proceso NIETO %d ; Mi padre es: %d.\n", getpid(), getppid());
			break;
		default:      //proceso padre
			Hijo2_pid=wait(NULL);
			printf("\tSoy el proceso HIJO %D, Mi padre es:  %d. \n", getpid(), getppid());
			printf ("\tMi hijo: %d terminó. \n", Hijo2_pid);
	}
}
else    //nos encontramos en Proceso padre
	{
	Hijo_pid = wait(NULL);  // espera la finalización del proceso hijo
	printf ("Soy el proceso ABUELO: %D, Mi HIJO: %d terminó.\n", getpid(), pid);
	}
return (0);
}