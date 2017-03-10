/*
 * =====================================================================================
 *
 *       Filename:  gen-graph.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/03/17 13:21:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  M3COOL (BCC), ae11@inf.ufpr.br
 *        Company:  xxx
 *
 * =====================================================================================
 */

#include <stdio.h>


void gen_graph(const char*);

/* __________________________________________________________________________________ */
int main(int argn, char *argv[]) {

	gen_graph(argv[1]);

	return 0;
}

void gen_graph(const char *init_state) {
	printf("%s\n", init_state);
}
