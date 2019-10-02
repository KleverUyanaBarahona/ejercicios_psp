/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_4_FIFOescribe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:56:24 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 12:59:24 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int fp;
  char saludo[] = "hola mundo!!!\n";
  fp = open("FIFO2", 1);
 
  if(fp == -1) {
    printf("ERROR AL ABRIR EL FICHERO...");
    exit(1);
  } 
  printf("Mandando información al FIFO...\n");
  write(fp,saludo, strlen(saludo));
  close(fp);   
  return 0; 
}