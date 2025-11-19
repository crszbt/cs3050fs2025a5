#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"
#include <stddef.h>
#include <stdio.h>

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    printf("\nBFS:\n"); //about to print BFS
    for(int i=0;i<countV;i++) //for every vertex...
    {
        (V[i]).color = WHITE; //make it white
    }
    int countB = 0; //number of black vertexed currently 0
    V[s].color = GRAY; //sets first vertex to be gray
    int count = 1; //sets count to 1
    while(countB<countV) //while the number of black vertex is less than the total number of vertexes
    {
        for(int i=0;i<countV;i++) //for every vertex...
        {
            if(V[i].color==GRAY) //if it is currently gray...
            {
                V[i].color=BLACK; //set to black
                countB++; //increase black vertex count
                V[i].d = count; //sets discover time to the current count
                V[i].f = count; //sets found time to the current count
                printf("%d(%d), ",V[i].number,V[i].d); //prints vertex and time
            }
        }
        if(countB>=countV) //if there are no more black nodes...
        {
            break; //don't bother searching for more to improve performance
        }
        for(int i=0;i<countV;i++) //for every node...
        {
            if(V[i].color==BLACK) //if the node is black...
            {
                if(((V[i]).list)!=NULL) //and there exist other nodes around it...
                {
                    for(Adjacency a = *((V[i]).list) ; (a.next)!=NULL ;a = *(a.next)) //for each of those nodes...
                    {
                        if(V[((a.pEdge)->to)].color == WHITE) //if any are white...
                        {
                            V[((a.pEdge)->to)].color = GRAY; //set them to gray so that they can be counted on the next layer
                        }
                    }
                }
                V[i].color= BLUE; //once a black node has no white nodes surrounding it, set it to BLUE so that the program doesn't have to check it again
            }
        }
        count++; //increase count by 1 before moving to the next layer
    }
}
