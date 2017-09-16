// Header file to define the printing utility. Will likely add more to this module later.

/**************************************************************/
/*                                                            */
/* safePrint: Send output to stdout that won't intersect with */
/* output from other threads. Should be used unless there is  */
/* only ONE execution thread currently running.               */
/*                                                            */
/* Params:                                                    */
/*    output: STRING indicating the desired output            */
/*                                                            */
/* Returns: Nothing                                           */
/*                                                            */
/**************************************************************/
void safePrint(std::string output);
