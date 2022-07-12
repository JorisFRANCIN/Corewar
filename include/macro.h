/*
** EPITECH PROJECT, 2022
** macro.h
** File description:
** .h file that contains macros
*/

#ifndef MACRO_H_
    #define MACRO_H_

    #define SUCCESS 0
    #define FAILURE -1
    #define IGNORED 1

    #define ERROR_ARG 84
    #define ERROR_MSG "ahhhh no, don't agree!\n"

    #define NBR_LIST "-0123456789"

    #define LEFT(nbr) (((nbr>>24) & 0xff) | ((nbr<<8) & 0xff0000))
    #define RIGHT(nbr) (((nbr>>8) & 0xff00) | ((nbr<<24) & 0xff000000))
    #define SWAP_ENDIAN_32(nbr) (LEFT(nbr) | RIGHT(nbr))
    #define SWAP_ENDIAN_16(nbr) (((nbr>>24) & 0xff) | ((nbr<<8) & 0xff00))

#endif /* !MACRO_H_ */
