#include "MUCSGraph.h"
#include "DFS.h"
#include <stddef.h>
#include <stdio.h>

void DFS_Visit(Vertex * V, int i, int * time)
{
    V[i].color = GRAY;  //sets color to gray
    *time = *time+1; //increases time by 1
    V[i].d = *time; //sets vertex's discover time to d
    if(((V[i]).list)!=NULL) //if the vertex is connected to others...
    {
        for(Adjacency a = *((V[i]).list) ; (a.next)!=NULL ;a = *(a.next)) //for each adjacent vertex...
        {
            if(V[((a.pEdge)->to)].color == WHITE) //if the vertex is white...
            {
                DFS_Visit(V, ((a.pEdge)->to), time); //visit it!
            }
        }
    }
    V[i].color = BLACK; //set vertex color to black
    *time = *time+1; //increase time
    V[i].f = *time; //set found time
    printf("%d(%d), ",V[i].number,V[i].f); //prints vertex and found time
}

void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    printf("\nDFS:\n"); //about to print DFS
    for(int i=0;i<countV;i++) //for everything in the graph...
    {
        (V[i]).color = WHITE; //set color to white
    }
    int time = 0; //sets time to zero
    for(int i=0;i<countV;i++) //for everything in the graph...
    {
        if((V[i]).color == WHITE) //if the vertex is white...
        {
            DFS_Visit(V, i, &time); //visit node
        } 
    }
}
