/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_pipe_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 01:45:50 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 01:53:53 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	char buffer[30];
	pid_t pid;

	pipe(fd);  //se crea el pipe

	pid = fork();  //se crea el proceso hijo

	switch (pid) {
		case -1: //ERROR
			printf (" NO SE HA PODIDO CREAR EL HIJO…");
			exit (-1);
			break;
		case 0:   //HIJO
			printf ("El hijo escribe en el pipe…\nHola papi\n");
			write (fd[1], "Hola papi", 10);
			break;
		default:
			wait(NULL); //espera que finalice el proceso hijo
			printf ("el  padre lee del pipe……\n");
			read(fd[0], buffer, 10);
			printf("\tMensaje leído: %s\n",buffer);
			break;
	}
    return (0);
}
