/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

float degree=0,degree1=0,degree2=0;
static int slices = 16;
static int stacks = 16;
float ss1 = .2,ss2=.2,ss3=.2;
float ex=0,ey=0,ez=0,cx=0,cy=0,cz=-2,hx=0,hy=1,hz=0;
float tt1=-1.2,tt2=-1.4,tt3=-7;
float choice=0;
float x_rot=0,y_rot=0,z_rot=0;
float rpy=0,rad=15;
float n1=-1.2,n2=-1.4,n3=-7;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
/*void Triangle()
{
    glBegin(GL_TRIANGLES);
    //front face
    glVertex3f(1.0,4.0,1.0);
     glVertex3f(0,0,2.0);
     glVertex3f(2.0,0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    //back face
    glVertex3f(1.0,4.0,1.0);
     glVertex3f(0,0,0);
     glVertex3f(2.0,0,0);
    glEnd();
    //right
    glBegin(GL_TRIANGLES);
     glVertex3f(1.0,4.0,1.0);
     glVertex3f(0,0,0);
     glVertex3f(0.0,0,2);
    glEnd();
    glBegin(GL_TRIANGLES);
     glVertex3f(1.0,4.0,1.0);
     glVertex3f(2,0,2);
     glVertex3f(2.0,0,0);
    glEnd();
}*/
void main_car()
{
    glBegin(GL_QUADS);


     glVertex3f(0,0,5);
     glVertex3f(15,0,5);
     glVertex3f(15,5,5);
     glVertex3f(0,5,5);


     glVertex3f(0,0,0);
     glVertex3f(0,5,0);
     glVertex3f(15,5,0);
     glVertex3f(15,0,0);

     glVertex3f(0,0,0);
     glVertex3f(0,0,5);
     glVertex3f(0,5,5);
     glVertex3f(0,5,0);

     glVertex3f(15,0,0);
     glVertex3f(15,5,0);
     glVertex3f(15,5,5);
     glVertex3f(15,0,5);

     glVertex3f(0,5,5);
     glVertex3f(15,5,5);
     glVertex3f(15,5,0);
     glVertex3f(0,5,0);

     glVertex3f(0,0,5);
     glVertex3f(0,0,0);
     glVertex3f(15,0,0);
     glVertex3f(15,0,5);


    glEnd();
}
void Cube()
{//Main Body
    glPushMatrix();
    glColor3d(1,.2,.1);
    main_car();
    glPopMatrix();
//Main Body
//Roof
    glPushMatrix();
    glColor3d(0,.9,.2);
    glTranslatef(3,3,.5);
    glScalef(.47,.89,.8);
    main_car();
    glPopMatrix();
//Roof
//Window Right
    glPushMatrix();
    glColor3d(0,.3,1);
    glTranslatef(10,5,1);
    glScalef(.026,.5,.6);
    main_car();
    glPopMatrix();
//Window Right
//Window Middle

    glPushMatrix();
    glColor3d(0,.3,1);
    glTranslatef(3.5,5,4.5);
    glScalef(.4,.5,.1);
    main_car();
    glPopMatrix();
//Window Middle
//Window left
    glPushMatrix();
    glColor3d(0,.3,1);
    glTranslatef(2.5,5,4);
    glScalef(.033,.5,-.6);
    main_car();
    glPopMatrix();
//Window left
//Window beside
    glPushMatrix();
    glColor3d(0,.3,1);
    glTranslatef(3.5,5,0);
    glScalef(.4,.5,.1);
    main_car();
    glPopMatrix();
//Window beside
     //front under light
    glPushMatrix();
    glColor3d(.4,.3,1);
    glTranslatef(15,0,0.5);
    glScalef(.033,.2,.8);
    main_car();
    glPopMatrix();

     //back bumper
    glPushMatrix();
    glColor3d(.4,.3,1);
    glTranslatef(-0.001,1,0.8);
    glScalef(-.033,.2,.8);
    main_car();
    glPopMatrix();
     //back bumper
    //Front bumper
    glPushMatrix();
    glColor3d(.1,.3,.4);
    glTranslatef(-0.001,3,0.8);
    glScalef(-.033,.2,.8);
    main_car();
    glPopMatrix();
    //Front bumper
//Head_Light
     glPushMatrix();
     glColor3d(1,0.6,0);
        glTranslated(15,4,4);
        glScalef(.7,.7,.7);
        glutSolidSphere(1,slices,stacks);

    glPopMatrix();

    glPushMatrix();
     glColor3d(1,0.6,0);
        glTranslated(15,4,1);
        glScalef(.7,.7,.7);
        glutSolidSphere(1,slices,stacks);

    glPopMatrix();
//Head_Light End
    //For front cylinder on front side
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*10000.0;
    glPushMatrix();

    glColor3d(0,0,0);
    glTranslated(3.5,0,-4.1);
    glRotatef(a,0,0,1);
    glTranslated(-3.5,0,4.1);
    glTranslated(3.5,0,4.1);
    glScalef(.5,.5,.5);
    gluCylinder(gluNewQuadric(),
                3,
                3,
                3,
                slices,
                stacks);

    glPopMatrix();
//For front cylinder on front side
//For back cylinder on front side
    glPushMatrix();

    glColor3d(0,0,0);
    glTranslated(10.5,0,-4.1);
    glRotatef(a,0,0,1);
    glTranslated(-10.5,0,4.1);
    glTranslated(10.5,0,4.1);
    glScalef(.5,.5,.5);
    gluCylinder(gluNewQuadric(),
                3,
                3,
                3,
                slices,
                stacks);

    glPopMatrix();
//For back cylinder on front side
//For back cylinder on back side
    glPushMatrix();

    glColor3d(0,0,0);
    glTranslated(3.5,0,-0.7);
    glRotatef(a,0,0,1);
    glTranslated(-3.5,0,0.7);
    glTranslated(3.5,0,-0.7);
    glScalef(.5,.5,.5);
    gluCylinder(gluNewQuadric(),
                3,
                3,
                3,
                slices,
                stacks);

    glPopMatrix();
//For back cylinder on back side
//For back cylinder on front side
    glPushMatrix();

    glColor3d(0,0,0);
    glTranslated(10.5,0,-0.7);
    glRotated(a,0,0,1);
    glTranslated(-10.5,0,0.7);
    glTranslated(10.5,0,-0.7);
    glScalef(.5,.5,.5);
    gluCylinder(gluNewQuadric(),
                3,
                3,
                3,
                slices,
                stacks);

    glPopMatrix();
//For back cylinder on front side



}
//homework pitch,roll,yaw
void my_new_pitch_roll_yaw(GLdouble x, GLdouble y, GLdouble z)
{
    GLfloat m[16];

    m[0] = cos(z)*cos(y);
    m[4] = cos(z)*sin(y)*sin(x)-sin(z)*cos(x);
    m[8] = cos(z)*sin(y)*cos(x)+sin(z)*sin(x);
    m[12] = 0;
    m[1] = sin(z)*cos(x);
    m[5] = sin(z)*sin(y)*sin(x)+cos(z)*cos(x);
    m[9] = sin(z)*sin(y)*cos(x)-cos(z)*sin(x);
    m[13] = 0;
    m[2] = -sin(y);
    m[6] = cos(y)*sin(x);
    m[10] = cos(y)*cos(x);
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    m[15] = 1;

    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(m);
}
//homework pitch,roll,yaw

//My new work lab 02
void my_new_scaleFunction(GLfloat sx, GLfloat sy, GLfloat sz){
GLfloat scalemat[16];
scalemat[0] =sx; scalemat[4] = 0; scalemat[8] = 0; scalemat[12] = 0;
scalemat[1] = 0; scalemat[5] =sy; scalemat[9] = 0; scalemat[13] = 0;
scalemat[2] = 0; scalemat[6] = 0; scalemat[10] =sz; scalemat[14] = 0;
scalemat[3] = 0; scalemat[7] = 0; scalemat[11] = 0; scalemat[15] = 1;
glMatrixMode(GL_MODELVIEW);
glMultMatrixf(scalemat);
}

void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);

   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+1.5*cos(th),y+1.5*sin(th));
   }

   glEnd();

}

void wheelanti(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);

   for(int i=359;i>=0;i--)
   {
       th=i*(3.1416/180);
       glVertex2f(x+1.5*cos(th),y+1.5*sin(th));
   }

   glEnd();

}
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*100000.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

   /* glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();
*/
    glPushMatrix();

    glTranslatef(tt1,tt2,tt3);
    glRotated(degree,0,0,1);
    glRotated(degree1,0,1,0);
    glRotated(degree2,1,0,0);
    //pitch_roll_yaw
    my_new_pitch_roll_yaw(x_rot,y_rot,z_rot);
    //pitch_roll_yaw
    glScalef(ss1,ss2,ss3);
    Cube();
    //For back wheel on front side
    glPushMatrix();
    glTranslated(3.49,0,-4.1);
    glRotatef(a,0,0,1);
    glTranslated(-3.49,0,4.1);
    glTranslatef(3.5,0,5.6);
    wheel(0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.491,0,4.1);
    glRotatef(a,0,0,1);
    glTranslated(-3.491,0,-4.1);
    glTranslatef(3.5,0,4.2);
    wheelanti(0,0);
    glPopMatrix();
//For back wheel on front side
//For front wheel on front side
    glPushMatrix();
    glTranslated(10.491,0,-4.1);
    glRotatef(a,0,0,1);
    glTranslated(-10.491,0,4.1);
    glTranslatef(7.5,0,5.6);
    wheel(3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(10.491,0,4.1);
    glRotatef(a,0,0,1);
    glTranslated(-10.491,0,-4.1);
    glTranslatef(7.5,0,4.2);
    wheelanti(3,0);
    glPopMatrix();
//For back wheel on front side
//For back wheel on back side
    glPushMatrix();
    glTranslated(3.49,0,-0.7);
    glRotatef(a,0,0,1);
    glTranslated(-3.49,0,0.7);
    glTranslatef(0.5,0,0.6);
    wheel(3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.49,0,0.7);
    glRotatef(a,0,0,1);
    glTranslated(-3.49,0,-0.7);
    glTranslatef(0.5,0,-0.6);
    wheelanti(3,0);
    glPopMatrix();
//For back wheel on back side
//For back wheel on front side
    glPushMatrix();
    glTranslated(10.49,0,-0.7);
    glRotated(a,0,0,1);
    glTranslated(-10.49,0,0.7);
    glTranslatef(10.5,0,0.6);
    wheel(0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(10.49,0,0.7);
    glRotated(a,0,0,1);
    glTranslated(-10.49,0,-0.7);
    glTranslatef(7.5,0,-0.6);
    wheelanti(3,0);
    glPopMatrix();
//For back wheel on front side
    glPopMatrix();
    //New Lab_work
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ex,ey,ez,cx,cy,cz,hx,hy,hz);
    //New_lab_work_02
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'z':
        degree=0;
        degree1=0;
        degree2=0;
        choice=1;
        break;
    case 'y':
        degree=0;
        degree1=0;
        degree2=0;
        choice=2;
        break;
    case 'x':
        degree=0;
        degree1=0;
        degree2=0;
        choice=3;
        break;
    case 'e':
        choice=4;
        break;
    case 'h':
        choice=5;
        break;
    case 'c':
        choice=6;
        break;
    case 't':
        choice=7;
        break;
    case 's':
        choice=8;
        break;
    case 'r':
        choice=9;
        break;
    case 'p':
        choice=10;
        break;
    case 'w':
        choice=11;
        break;
    case '.':
        choice=12;
        break;
    }

    if(choice==12)
    {
        switch(key)
        {
        case '1':
            choice=13;
            //ey=0;
            //ez=0;
            ex=0;
            rpy=0;
            break;
        case '2':
            choice=14;
            ey=0;
            //ez=0;
            //ex=0;
            rpy=0;
            break;
        case '3':
            choice=15;
            //ey=0;
            ez=-2;
            //ex=0;
            rpy=0;
            break;
        }
    }
    //roll
    if(choice==13)
    {
        switch(key)
        {
        case '+':
            rpy++;
            glTranslated(-n1,-n2,-n3);
            ey = rad * cos(((3.1416)*rpy)/180.0);
            ez = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(n1,n2,n3);
            break;
        case '-':
            rpy--;
            glTranslated(-n1,-n2,-n3);
            ey = rad * cos(((3.1416)*rpy)/180.0);
            ez = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(n1,n2,n3);
            break;
        }
    }
    //roll end
    //pitch
    if(choice==14)
    {
        switch(key)
        {
        case '+':
            rpy++;

            glTranslated(-n1,-n2,-n3);
            ex = rad * cos(((3.1416)*rpy)/180.0);
            ez = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(n1,n2,n3);
            break;
        case '-':
            rpy--;
            glTranslated(-n1,-n2,-n3);
            ex = rad * cos(((3.1416)*rpy)/180.0);
            ez = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(n1,n2,n3);
            break;
        }
    }

    //pitch end
    //yaw
    if(choice==15)
    {
        switch(key)
        {
        case '+':
            rpy++;
            glTranslated(n1,n2,n3);
            ex = rad * cos(((3.1416)*rpy)/180.0);
            ey = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(-n1,-n2,-n3);
            break;
        case '-':
            rpy--;
            glTranslated(n1,n2,n3);
            ex = rad * cos(((3.1416)*rpy)/180.0);
            ey = rad * sin(((3.1416)*rpy)/180.0);
            glTranslated(-n1,-n2,-n3);
            break;
        }
    }
    //yaw end


   /* //roll
    if(choice==9)
    {
        switch(key)
        {
        case '+':
            x_rot+=.5;
            break;
        case '-':
            x_rot-=.5;
            break;
        }
    }
    //roll end

    //pitch
    if(choice==10)
    {
        switch(key)
        {
        case '+':
            y_rot+=.5;
            break;
        case '-':
            y_rot-=.5;
            break;
        }
    }
    //pitch end


     //yaw
    if(choice==10)
    {
        switch(key)
        {
        case '+':
            z_rot+=.5;
            break;
        case '-':
            z_rot-=.5;
            break;
        }
    }
    //yaw end

*/




    //translate
    if(choice==7)
    {
        switch(key)
        {
        case '+':
            tt1+=.5;
            break;
        case '-':
            tt2+=.5;
            break;
        case ')':
            tt3+=.5;
            break;
        case '?':
            tt1-=.5;
            break;
        case '>':
            tt2-=.5;
            break;
        case '<':
            tt3-=.5;
            break;
        }
    }
    //translate end
    //scaling
    if(choice==8)
    {
        switch(key)
        {
        case '+':
            ss1+=.01;
            break;
        case '-':
            ss2+=.01;
            break;
        case ')':
            ss3+=.01;
            break;
        case '?':
            ss1-=.01;
            break;
        case '>':
            ss2-=.01;
            break;
        case '<':
            ss3-=.01;
            break;
        }
    }
    //scaling end
    //x-direction rotation
    if(choice==1)
    {
        switch(key)
        {
        case '+':
            degree+=.8;
            break;
        case '-':
            degree-=.8;
            break;
        }
    }
    //x-direction rotation end
    //y-direction rotation
    if(choice==2)
    {
        switch(key)
        {
        case '+':
            degree1+=.8;
            break;
        case '-':
            degree1-=.8;
            break;
        }
    }
    //y-direction rotation end
    //z-direction rotation

    if(choice==3)
    {
        switch(key)
        {
        case '+':
            degree2+=.8;
            break;
        case '-':
            degree2-=.8;
            break;
        }
    }
    //z-direction rotation end
    //eye-direction rotation
    if(choice==4)
    {
        switch(key)
        {
        case '+':
            ex+=.5;
            break;
        case '-':
            ey+=.5;
            break;
        case ')':
            ez+=.5;
            break;
        case '?':
            ex-=.5;
            break;
        case '>':
            ey-=.5;
            break;
        case '<':
            ez-=.5;
            break;
        }
    }
    //eye-direction rotation end
    //head-direction rotation
    if(choice==5)
    {
        switch(key)
        {
        case '+':
            hx+=.5;
            break;
        case '-':
            hy+=.5;
            break;
        case ')':
            hz+=.5;
            break;
        case '?':
            hx-=.5;
            break;
        case '>':
            hy-=.5;
            break;
        case '<':
            hz-=.5;
            break;
        }
    }
    //head-direction rotation end
    //camera-direction rotation
    if(choice==6)
    {
        switch(key)
        {
        case '+':
            cx+=.5;
            break;
        case '-':
            cy+=.5;
            break;
        case ')':
            cz+=.5;
            break;
        case '?':
            cx-=.5;
            break;
        case '>':
            cy-=.5;
            break;
        case '<':
            cz-=.5;
            break;
        }
    }
    //camera-direction rotation end
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    cout<<"'x' to rotate x-direction\n'y' to rotate y-direction\n'z' to rotate z-direction\n'e' to rotate eye-direction\n'h' to rotate head-direction\n'c' to rotate camera-direction\n'.' to rotate yaw_roll_pitch-direction\n's' to scaling\n't' to rotate translate\n"<<endl;
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
/*
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
*/
    glutMainLoop();

    return EXIT_SUCCESS;
}
