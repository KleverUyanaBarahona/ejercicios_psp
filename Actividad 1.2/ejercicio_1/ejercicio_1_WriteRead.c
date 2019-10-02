/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_1_WriteRead.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 01:32:29 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 01:43:11 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char saludo[] = "Un saludo!!!! \n";
	char buffer [10];
	int fd, bytesleidos;

	fd = open ("texto.txt",1);  

	if  (fd  == -1)
	{
		printf ("ERROR AL ABRIR EL FICHERO ……\n");
	}

	printf ("Escribo el saludo….\n");
	write (fd, saludo, strlen(saludo));
	close (fd);  

	fd=open ("texto.txt",0);   
	printf ("Contenido del Fichero:  \n");


	bytesleidos  = read (fd, buffer, 1);

	while (bytesleidos != 0) {

		printf ("%1c", buffer[0]);   
		bytesleidos = read (fd, buffer, 1);  
	}
	close (fd);
    return (0);
}