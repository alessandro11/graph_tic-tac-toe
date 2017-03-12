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
#include <string.h>
#include "queue.h"

#define INITIAL_STATE		"O.X......"

#ifndef TRUE
#define TRUE		(1==1)
#endif

#ifndef FALSE
#define	FALSE		(1!=1)
#endif

#define NOUGHTS		'O'
#define CROSSES		'X'
#define	EMPTY		'.'

int gen_graph(queue*);
int check_winner(int, const char*);


/* __________________________________________________________________________________ */
int main(int argn, char *argv[])
{
	int winner;
	(void)(winner);

	//gen_graph(argv[1]);	
	queue *q = create_queue();

	puts("strict digraph \"ae11\" {");
	push_queue(q, INITIAL_STATE);
	winner = FALSE;
	while( q->next ) {
		winner = gen_graph(q);
		//fprintf(stderr, "winner=%d, q->ele=%s, q->next=%p\n", winner, q->next->element, q->next);
	}
	puts("}");

	return 0;
}


int gen_graph(queue *q)
{
	int i;
	queue head;
	char init_state[16];
	static int winner = FALSE;

	head = pop_queue(q);
	strcpy(init_state, head.element);
	for( i=0; i < 9; ++i ) {
		if( head.element[i] != EMPTY )
			continue;

		head.element[i] = NOUGHTS;
		if( winner ) {
			//if( check_winner(i, head.element) )
			//	printf("\t\"%s\" -> \"%s\" [label=win%d]\n", init_state, head.element, i);
			//else
				printf("\t\"%s\" -> \"%s\"\n", init_state, head.element);
		}else {
			winner = check_winner(i, head.element);
			printf("\t\"%s\" -> \"%s\"\n", init_state, head.element);
			push_queue(q, head.element);
		}
		head.element[i] = EMPTY;
	}

	return winner;
}

int check_winner(int player_last_pos, const char *state)
{
	int sum = 0;

    switch( player_last_pos ) {
        case 0:
            sum = *state + *(state+1) + *(state+2);
            if( sum == 237 )
                return TRUE;
            sum = *state + *(state+4) + *(state+8);
            if( sum == 237 )
                return TRUE;
            sum = *state + *(state+3) + *(state+6);
            if( sum == 237 )
                return TRUE;
        break;

        case 1:
            sum = *(state+1) + *(state) + *(state+2);
            if( sum == 237 )
                return TRUE;
            sum = *(state+1) + *(state+4) + *(state+7);
            if( sum == 237 )
                return TRUE;

        break;

        case 2:
            sum = *(state+2) + *(state+1) + *(state);
            if( sum == 237 )
                return TRUE;
            sum = *(state+2) + *(state+4) + *(state+6);
            if( sum == 237 )
                return TRUE;
            sum = *(state+2) + *(state+5) + *(state+8);
            if( sum == 237 )
                return TRUE;
        break;

        case 3:
            sum = *(state+3) + *(state) + *(state+6);
            if( sum == 237 )
                return TRUE;
            sum = *(state+3) + *(state+4) + *(state+5);
            if( sum == 237 )
                return TRUE;
        break;

        case 4:
            sum = *(state+4) + *(state) + *(state+8);
            if( sum == 237 )
                return TRUE;
            sum = *(state+4) + *(state+1) + *(state+7);
            if( sum == 237 )
                return TRUE;
            sum = *(state+4) + *(state+2) + *(state+6);
            if( sum == 237 )
                return TRUE;
            sum = *(state+4) + *(state+3) + *(state+5);
            if( sum == 237 )
                return TRUE;
        break;

        case 5:
            sum = *(state+5) + *(state+4) + *(state+6);
            if( sum == 237 )
                return TRUE;
            sum = *(state+5) + *(state+2) + *(state+8);
            if( sum == 237 )
                return TRUE;
        break;

        case 6:
            sum = *(state+6) + *(state+3) + *(state);
            if( sum == 237 )
                return TRUE;
            sum = *(state+6) + *(state+4) + *(state+2);
            if( sum == 237 )
                return TRUE;
            sum = *(state+6) + *(state+7) + *(state+8);
            if( sum == 237 )
                return TRUE;
        break;

        case 7:
            sum = *(state+7) + *(state+6) + *(state+8);
            if( sum == 237 )
                return TRUE;
            sum = *(state+7) + *(state+1) + *(state+4);
            if( sum == 237 )
                return TRUE;
        break;

        case 8:
            sum = *(state+8) + *(state+2) + *(state+5);
            if( sum == 237 )
                return TRUE;
            sum = *(state+8) + *(state) + *(state+4);
            if( sum == 237 )
                return TRUE;
            sum = *(state+8) + *(state+6) + *(state+7);
            if( sum == 237 )
                return TRUE;
        break;
    }

	return FALSE;
}
