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

void gen_graph(const char*);

/* __________________________________________________________________________________ */
int main(int argn, char *argv[]) {

	//gen_graph(argv[1]);
	gen_graph(INITIAL_STATE);

	return 0;
}

void gen_graph(const char *init_state) {
	int stop;
	char state[16] = {'\0'};
	int player = 1;

	strncpy(state, init_state, strlen(init_state));
	stop = FALSE;
	do {
		dot = strchr(EMPTY);
		*dot = NOUGHTS;
		printf("%s --> %s\n", init_state, state);
	}
	while( stop );
}

int check_winner(int player_last_pos, const char *state)
{
    switch( player_last_pos ) {
        case 0:
            sum = *state + *(state+1) + *(state+2)
            if( sum == 237 )
                return TRUE
            sum = *state + *(state+4) + *(state+8)
            if( sum == 237 )
                return TRUE
            sum = *state + *(state+3) + *(state+6)
            if( sum == 237 )
                return TRUE
        break;

        case 1:
            sum = *(state) + *(state+1) + *(state+2)
            if( sum == 237 )
                return TRUE
            sum = *(state+1) + *(state+4) + *(state+7)
            if( sum == 237 )
                return TRUE

        break;

        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
    }

}
