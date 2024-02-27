/**
 * @file main.h
 * @author Ahmed Hani Atef
 * @brief header file contains includes, new data types and function declaration.
 * @date 2024-02-27
*/

#ifndef MAIN_H
#define MAIN_H

/******************* Includes section ************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
/*************************************************************/

#define STRING_MATCH (0)

/******************* Macro function section ******************/
/*************************************************************/

/******************** New types section **********************/
typedef enum 
{
   CD = 0,
   ECHO,
   EXPORT,
   SHELL_BUILT_IN,
   EXECUTABLE_OR_ERROR,
}COMMANDS_t;
/*************************************************************/

/**************** function declaration section ***************/

/**
 * @brief Contains main operation of shell
*/
void shell();

/**
 * @brief take the input from user then parse it by spaces to array of strings
 * @return a pointer to array of strings 
 */
char **parse_input();

/**
 * @brief check if the command input is CD, ECHO, EXPORT or EXECUTABLE_OR_ERROR
 * @return returns the type of the command input
 */
COMMANDS_t command_detect(char **command);

/**
 * @brief handle execution of bulitin command like cd, echo and export
 * @param input_command type of command
 * @param command full command
 */
void execute_shell_bultin(COMMANDS_t input_command, char **command);

/**
 * @brief handle cd command
 * @param command full command
 */
void cd_command_handle(char **command);

/**
 * @brief handle echo command
 * @param command full command
 */
void echo_command_handle(char **command);

/**
 * @brief handle export command
 * @param command full command
 */
void export_command_handle(char **command);


/*************************************************************/

#endif

/**************************************************************
 **************************** Log *****************************
 **************************************************************
    Name                |Date       |brief
 **************************************************************
 *  Ahmed Hani Atef     |Feb-27     |File creation  
 *  Ahmed Hani Atef     |Feb-27     |(1) Add includes section
 *                      |           |(2) Create function declaration
 *                      |           |(3) Create New data types     
*/