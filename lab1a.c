/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */

/* number of generations to evolve the world */
#define NUM_GENERATIONS 4
#define WORLDWIDTH 39
#define WORLDHEIGHT 20

/* functions to implement */
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(void)
{
	int n;

	/* TODO: initialize the world */
	initialize_world();
	output_world();

	for (n = 0; n < NUM_GENERATIONS; n++)
	{next_generation();
	output_world();}

	/* TODO: output final world state */
	output_world();

	return 0;
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) */
	   int width=get_world_width();
	   int height=get_world_height();
	   int next,x,y;
	   for(x=0;x<width;x++){
		   for(y=0;y<height;y++){
		   nextstates[x][y]=get_next_state(x,y);
	   }}
		 for(x=0;x<width;x++){
		   for(y=0;y<height;y++){
			   set_cell_state(x,y,nextstates[x][y]);		  
		 }}


	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */
	   int state=get_cell_state(x,y);
	   int alive=num_neighbors(x,y);
	   if(state==ALIVE&&(alive>3||alive<2)) state=DEAD;
	   else if(state==DEAD&&alive==3) state=ALIVE;
	  
	   return state;
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */
	   int count=0;
	   int s1=get_cell_state(x-1,y);
	   if(s1==ALIVE) count++;
	   int s2=get_cell_state(x-1,y+1);
	    if(s2==ALIVE) count++;
	   int s3=get_cell_state(x,y+1);
	    if(s3==ALIVE) count++;
	   int s4=get_cell_state(x+1,y+1);
	    if(s4==ALIVE) count++;
	   int s5=get_cell_state(x+1,y);
	    if(s5==ALIVE) count++;
	   int s6=get_cell_state(x+1,y-1);
	    if(s6==ALIVE) count++;
	   int s7=get_cell_state(x,y-1);
	    if(s7==ALIVE) count++;
	   int s8=get_cell_state(x-1,y-1);
	    if(s8==ALIVE) count++;

		return count;
	   }
	   
