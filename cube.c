//Gabriele Simoni 2022
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <termios.h>
#include <unistd.h>

#include "cube.h"

//drawing space
#define MAXSPACE 40

//Number of points placed between one point and another to draw a line between them.
#define LINEACCURACY 20 

char c; //input
int i ,j; 
int x,y,z;

//Cube rotation angle
float angleX = 0;
float angleY = 0;

char mat[MAXSPACE][MAXSPACE];
Point pivot; //center

//to enable non-blocking input:
static struct termios termt, oldtermt;

int main(){

    //get parameters of current terminal
    tcgetattr( STDIN_FILENO, &termt);

    //keeps old settings
    oldtermt = termt;

    //enable non-blocking input and echo  
    termt.c_lflag &= ~(ICANON | ECHO);

    //enable the new settings
    tcsetattr( STDIN_FILENO, TCSANOW, &termt);

    //finds center
    pivot.x = MAXSPACE / 2;
    pivot.y = MAXSPACE / 2;
    pivot.z = MAXSPACE / 2;

    //line info
    #include "data.h"

    //clear screens
    printf("\e[1;1H\e[2J");

    printf("\tBefore continuing make sure your console has\n\t");
    printf("at least %d columns and %d rows or the program won\'t run\n\t",MAXSPACE * 2, MAXSPACE);
    printf("correctly.\n\n\t");

    printf("use W A S D to move the cube and Q to quit.\n\n\t");
    printf("press ENTER to continue.");

    while(getchar() != '\n') { }
    
    while(1){

        //clears the matrix
        for(i = 0; i < MAXSPACE; i++)
            for(j = 0; j < MAXSPACE;j++)
                mat[i][j] = ' ';

        //draws lines
        drawLine(line1);
        drawLine(line2);
        drawLine(line3);
        drawLine(line4);
        drawLine(line5);
        drawLine(line6);
        drawLine(line7);
        drawLine(line8);
        drawLine(line9);
        drawLine(line10);
        drawLine(line11);
        drawLine(line12);

        //clear screens
        printf("\e[1;1H\e[2J");


        //draws matrix
        for(y = 0; y < MAXSPACE; y++){

            for(x = 0; x < MAXSPACE;x++)
                printf(" %c",mat[x][y]);
            
            printf("\n");
        }
   

        //reads input
        c = getchar();

        switch(c){
    
            case 'q':
                //restore previous settings
                tcsetattr( STDIN_FILENO, TCSANOW, &oldtermt);
                return 0;
            break;

            case 'a':
                angleX+= 0.1f;
            break;
            case 'd':
                angleX-= 0.1f;
            break;
            case 'w':
                angleY+= 0.1f;
            break;
            case 's':
                angleY-= 0.1f;
            break;
            
        }

    }

}

/*
        Rotates a point
*/
Point rotatePoint(Point p)
{
      float s,c; //sin, cos
      float xnew,ynew,znew; //new coordinates
      
      //X angle
      s = sin(angleX);
      c = cos(angleX);

      // translate point back to origin:
      p.x -= pivot.x;
      p.y -= pivot.y;

      // rotate point
      xnew = p.x * c - p.y * s;
      ynew = p.x * s + p.y * c;

      // translate point back:
      p.x = xnew + pivot.x;
      p.y = ynew + pivot.y;

      //Y angle
      s = sin(angleY);
      c = cos(angleY);

      // translate point back to origin:
      p.z -= pivot.z;
      p.y -= pivot.y;

      // rotate point
      znew = p.z * s - p.y * c;
      ynew = p.z * c + p.y * s;

      // translate point back:
      p.z = znew + pivot.z;
      p.y = ynew + pivot.y;

      return p;
}

int charToDistance(char c){

    switch(c){
    
    case '@':
        return 0;
    break;

    case '#':
        return 1;
    break;

    case '+':
        return 2;
    break;

    default:
    case ',':
        return 3;
    break;
    case ' ':
        return 5;

    }

}

/*
    Draws a point
*/
void drawPoint(Point p){

        //rotates it
        p = rotatePoint(p);

        x = (int)p.x;
        y = (int)p.y;
        z = (int)p.z;

        //draws on matrix
        if((int)(z / (MAXSPACE / 4)) >= charToDistance(mat[x][y]))
            return;

        switch((int)(z / (MAXSPACE / 4))){
    
            case 4:
                mat[x][y] = ',';
            break;
            case 3:
                mat[x][y] = ',';
            break;

            case 2:
                mat[x][y] = '+';
            break;

            case 1:
                mat[x][y] = '#';
            break;

            case 0:
                mat[x][y] = '@';
            break;

            default:
                mat[x][y] = 'E';
            
            break;


        }

}

/*
    Draws a line
*/
void drawLine(Line l){

    /*
        Basically draws a set of points from a point to another
        to form a line.
    */
    Point it = l.points[0];
    Point dest = l.points[1];
    Point add;
    add.x = (float)(dest.x - it.x) / (float)LINEACCURACY;
    add.y = (float)(dest.y - it.y) / (float)LINEACCURACY;
    add.z = (float)(dest.z - it.z) / (float)LINEACCURACY;

    int dist;

    do{
        dist = sqrt( pow(dest.x-it.x,2) + pow(dest.y-it.y,2) + pow(dest.z-it.z,2) );

        if(it.x != dest.x)
            it.x+= add.x;

        if(it.y != dest.y)
            it.y+= add.y;

        if(it.z != dest.z)
            it.z+= add.z;


        drawPoint(it);

    }while(dist > 1);


}




