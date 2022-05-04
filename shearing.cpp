//#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

//function declarations
void mul(int mat[3][3],int vertex[10][3],int n);
void shear(int vertex[10][3],int n);
void init(int vertex[10][3],int n);



int main()
{
  int i,x,y;
  int vertex[10][3],n;
  
  //clear the screen
  //clrscr();
  
  //taking inputs for the polygon object
  printf("\nEnter the no. of vertex : ");
  scanf("%d", &n);
   for(i=0;i<n;i++)
     {
	    printf("Enter the (x, y): ");
	    scanf("%d %d", &x, &y);

	    vertex[i][0]=x;
	    vertex[i][1]=y;
	    vertex[i][2]=1;
     }
	  
	  
	 //calling the shear() function to perform shearing of the given object 
     shear(vertex,n);
	 
	 getch();
	 return 0;
}

/*
Function definition for init()

Function: init(). This function initialises the screen in graphics mode and loads the appropriate graphics driver.
          It also draws the co-ordinate axes,legends, and the image of the given object matrix.
                  
Input: 1) Object matrix (to be sheared later)
       2) Number of vertices(rows in object matrix)  

Returns: This function does not return anything

*/

void init(int vertex[10][3],int n)
{
   //initialisation of the graphics driver
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"C:\\turboc3\\bgi");
   
   //drawing the co-ordinate axes
   setcolor(10);                 
   line(0,240,640,240);       //drawing X axis
   line(320,0,320,480);       //drawing Y axis
   
   
   //drawing graph legends
   setcolor(3);
   line(450,20,490,20);
   setcolor(15);
   line(450,50,490,50);
   setcolor(6);
   outtextxy(500,20,"Original");
   outtextxy(500,50,"Transformed");
   
   
   
   //drawing the object
   setcolor(3);

   for(i=0;i<n-1;i++)
    {
       line(320+vertex[i][0],240-vertex[i][1],320+vertex[i+1][0],240-vertex[i+1][1]);
     }
     line(320+vertex[n-1][0],240-vertex[n-1][1],320+vertex[0][0],240-vertex[0][1]);

}



/*
Function definition for mul()

Function: mul(). This function multiplies the two given matrices(object matrix and shearing
          transformation matrix) and then draws the final image.
		                    
Input: 1) shearing transformation matrix
       2) Object matrix (to be sheared)
       3) Number of vertices (number of rows in object matrix)
	   
Returns: This function does not return anything

*/

void mul(int mat[3][3],int vertex[10][3],int n)
{
  int i,j,k;    // loop variables
  
  //array for storing final image matrix
 int res[10][3];
  
  
  //multiplying the object matrix with shearing transformation matrix
  for(i=0;i<n;i++)
   {
     for(j=0;j<3;j++)
      { 
	     res[i][j]=0;
         for(k=0;k<3;k++)
	      {
	         res[i][j] = res[i][j] + vertex[i][k]*mat[k][j];
	       }
     }
   }
   
   
   //drawing the transformed image (sheared object)
   setcolor(15);
   for(i=0;i<n-1;i++)
    {
       line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1]);
     }
     line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1]);

}



/*
Function definition for shear()

Function: shear(). This function shears the given object in the desired direction and displays the 
          transformed image. Amount of shearing to be performed is taken from the user.

Inputs: 1)Object matrix
        2)Number of vertices in the object

Returns: This function does not return anything

*/

void shear(int vertex[10][3],int n)
{
   int opt;
   
   //shearing transformation matrix
   int shear_array[3][3];
   
   //taking user input for shear direction  
   printf("\n1.x-shear\n2.y-shear\nYour Choice: ");
   scanf("%d",&opt);
   
   //initializing the shearing transformation matrix as per the required direction
   switch(opt)
   {
    case 1: int xsh;   
		    printf("\nEnter the x shear : ");
	      scanf("%d", &xsh);
			
		 //values for X shear	
		 shear_array[0][0]=1;
	     shear_array[1][0]=xsh;
	     shear_array[2][0]=0;
	     shear_array[0][1]=0;
	     shear_array[1][1]=1;
	     shear_array[2][1]=0;
	     shear_array[0][2]=0;
	     shear_array[1][2]=0;
	     shear_array[2][2]=1;
		 
		 //initializing the graphics mode and drawing the original object
	     init(vertex,n);
		 
		 //multiplying the object with shearing transformation matrix and displaying the sheared image
	     mul(shear_array,vertex,n);
	      break;

	case 2:int ysh;
	      printf("\nEnter the y shear : ");
	      scanf("%d", &ysh);
		   
		//values for Y shear	   
		shear_array[0][0]=1;
	    shear_array[1][0]=0;
	    shear_array[2][0]=0;
	    shear_array[0][1]=ysh;
	    shear_array[1][1]=1;
	    shear_array[2][1]=0;
	    shear_array[0][2]=0;
	    shear_array[1][2]=0;
	    shear_array[2][2]=1;
		
		//initializing the graphics mode and drawing the original object
	     init(vertex,n);
		 
		 //multiplying the object with shearing transformation matrix and displaying the sheared image
	     mul(shear_array,vertex,n);
	      break;
     }
 }