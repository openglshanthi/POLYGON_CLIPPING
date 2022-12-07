#include<GL/glut.h>
#include<stdio.h>
int i,n,x[10],y[10];
void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250.0,250.0,-250.0,250.0);
}
void getdata()
{
printf("Enter the no of vertices:");
scanf("%d",&n);
printf("Enter the cordinates of vertices:");
for(i=0;i<n;i++)
scanf("%d%d",&x[i],&y[i]);

}
void polygon1()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(0,0);
glVertex2i(100,0);
glVertex2i(100,100);
glVertex2i(0,100);
glEnd();
glFlush();
glColor3f(1.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
for(i=0;i<n;i++)
glVertex2i(x[i],y[i]);

glEnd();
glFlush();
for(i=0;i<n;i++)
{
if(x[i]<=100 && x[i]>=0 && y[i]<=100 && y[i]>=0)
{
glVertex2i(x[i],y[i]);
}
else if(x[i]<=100 && x[i]>=0 && y[i]>100 )
{
glVertex2i(x[i],100);
}
else if(x[i]<=100 && x[i]>=0 && y[i]<0 )
{
glVertex2i(x[i],0);
}
else if(y[i]<=100 && y[i]>=0 && x[i]>100 )
{
glVertex2i(100,y[i]);
}
else if(y[i]<=100 && y[i]>=0 && x[i]<0 )
{
glVertex2i(0,y[i]);
}
else if(x[i]>100 && y[i]>100)
{
glVertex2i(100,100);
}
else
{
glVertex2i(0,0);
}
}
glEnd();
glFlush();
}
void main(int argc,char**argv)
{
getdata();

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(500,500);
glutCreateWindow("Polygon Clipping");
glClear(GL_COLOR_BUFFER_BIT);
init();
glutDisplayFunc(polygon1);
glutMainLoop();
}
