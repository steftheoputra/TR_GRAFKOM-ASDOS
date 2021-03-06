#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;



float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("TR GRAFKOM BINUS | KRU SHP");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(3.0f);
	glPointSize(5.0f);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
	glPushMatrix();
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 200.0f, 0.0f, 0.0f, 0.0f, 0.0f, 10.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    //BINTANG 1
    float a1x = 50, a1y = 50, b1x = 55, b1y = 62,
    a2x = 55, a2y = 62, b2x = 60, b2y = 50,
    a3x = 60, a3y = 50, b3x = 47, b3y = 57,
    a4x = 47, a4y = 57, b4x= 63, b4y= 57,
    a5x = 63, a5y = 57, b5x = 50, b5y = 50,

	Ma1b1, Ma2b2, Ma3b3, Ma4b4, Ma5b5, Ca1b1, Ca2b2, Ca3b3, Ca4b4, Ca5b5, px, py, pz, pi, pq, pr, pm, pn, pj, pk;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(a1x, a1y);
	glVertex2f(b1x, b1y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(a2x, a2y);
	glVertex2f(b2x, b2y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(a3x, a3y);
	glVertex2f(b3x, b3y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(a4x, a4y);
	glVertex2f(b4x, b4y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(a5x, a5y);
	glVertex2f(b5x, b5y);
	glEnd();

	//Rumus Perpotongan
	Ma1b1 = (b1y - a1y) / (b1x - a1x);
	Ma2b2 = (b2y - a2y) / (b2x - a2x);
	Ma3b3 = (b3y - a3y) / (b3x - a3x);
	Ma4b4 = (b4y - a4y) / (b4x - a4x);
   	Ma5b5 = (b5y - a5y) / (b5x - a5x);



	Ca1b1 = a1y - (a1x * Ma1b1);
	Ca2b2 = a2y - (a2x * Ma2b2);
	Ca3b3 = a3y - (a3x * Ma3b3);
	Ca4b4 = a4y - (a4x * Ma4b4);
	Ca5b5 = a5y - (a5x * Ma5b5);

	//Titik potong
	px = (Ca5b5 - Ca2b2) / (Ma2b2 - Ma5b5);
	py = (Ma2b2 * px) + Ca2b2;
	pm = (Ca5b5 - Ca3b3) / (Ma3b3 - Ma5b5);
	pn = (Ma3b3 * pm) + Ca3b3;
	pz = (Ca4b4 - Ca2b2) / (Ma2b2 - Ma4b4);
	pi = (Ma2b2 * pz) + Ca2b2;
	pq = (Ca4b4 - Ca1b1) / (Ma1b1 - Ma4b4);
	pr = (Ma1b1 * pq) + Ca1b1;
	pj = (Ca1b1 - Ca3b3) / (Ma3b3 - Ma1b1);
	pk = (Ma3b3 * pj) + Ca3b3;

	//Hasil
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px, py);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(pz, pi);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(pq, pr);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(pm, pn);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(pj, pk);
	glEnd();
	glFlush();

	//BINTANG 2
    float c1x = 80, c1y = 80, d1x = 85, d1y = 92,
    c2x = 85, c2y = 92, d2x = 90, d2y = 80,
    c3x = 90, c3y = 80, d3x = 77, d3y = 87,
    c4x = 77, c4y = 87, d4x= 93, d4y= 87,
    c5x = 93, c5y = 87, d5x = 80, d5y = 80,
	Mc1d1, Mc2d2, Mc3d3, Mc4d4, Mc5d5, Cc1d1, Cc2d2, Cc3d3, Cc4d4, Cc5d5, qa, qb, qc, qd, qe, qf, qg, qh, qi, qj;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(c1x, c1y);
	glVertex2f(d1x, d1y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(c2x, c2y);
	glVertex2f(d2x, d2y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(c3x, c3y);
	glVertex2f(d3x, d3y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(c4x, c4y);
	glVertex2f(d4x, d4y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(c5x, c5y);
	glVertex2f(d5x, d5y);
	glEnd();

	//Rumus Perpotongan
	Mc1d1 = (d1y - c1y) / (d1x - c1x);
	Mc2d2 = (d2y - c2y) / (d2x - c2x);
	Mc3d3 = (d3y - c3y) / (d3x - c3x);
	Mc4d4 = (d4y - c4y) / (d4x - c4x);
   	Mc5d5 = (d5y - c5y) / (d5x - c5x);



	Cc1d1 = c1y - (c1x * Mc1d1);
	Cc2d2 = c2y - (c2x * Mc2d2);
	Cc3d3 = c3y - (c3x * Mc3d3);
	Cc4d4 = c4y - (c4x * Mc4d4);
	Cc5d5 = c5y - (c5x * Mc5d5);

	//Titik potong
	qa = (Cc5d5 - Cc2d2) / (Mc2d2 - Mc5d5);
	qb = (Mc2d2 * qa) + Cc2d2;
	qc = (Cc5d5 - Cc3d3) / (Mc3d3 - Mc5d5);
	qd = (Mc3d3 * qc) + Cc3d3;
	qe = (Cc4d4 - Cc2d2) / (Mc2d2 - Mc4d4);
	qf = (Mc2d2 * qe) + Cc2d2;
	qg = (Cc4d4 - Cc1d1) / (Mc1d1 - Mc4d4);
	qh = (Mc1d1 * qg) + Cc1d1;
	qi = (Cc1d1 - Cc3d3) / (Mc3d3 - Mc1d1);
	qj = (Mc3d3 * qi) + Cc3d3;

	//Hasil
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(qa, qb);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(qc, qd);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(qe, qf);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(qg, qh);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(qi, qj);
	glEnd();


	//BINTANG 3
    float e1x = 130, e1y = 130, f1x = 135, f1y = 142,
    e2x = 135, e2y = 142, f2x = 140, f2y = 130,
    e3x = 140, e3y = 130, f3x = 127, f3y = 137,
    e4x = 127, e4y = 137, f4x= 143, f4y= 137,
    e5x = 143, e5y = 137, f5x = 130, f5y = 130,
	Me1f1, Me2f2, Me3f3, Me4f4, Me5f5, Ce1f1, Ce2f2, Ce3f3, Ce4f4, Ce5f5, ra, rb, rc, rd, re, rf, rg, rh, ri, rj;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(e1x, e1y);
	glVertex2f(f1x, f1y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(e2x, e2y);
	glVertex2f(f2x, f2y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(e3x, e3y);
	glVertex2f(f3x, f3y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(e4x, e4y);
	glVertex2f(f4x, f4y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(e5x, e5y);
	glVertex2f(f5x, f5y);
	glEnd();

	//Rumus Perpotongan
	Me1f1 = (f1y - e1y) / (f1x - e1x);
	Me2f2 = (f2y - e2y) / (f2x - e2x);
	Me3f3 = (f3y - e3y) / (f3x - e3x);
	Me4f4 = (f4y - e4y) / (f4x - e4x);
   	Me5f5 = (f5y - e5y) / (f5x - e5x);



	Ce1f1 = e1y - (e1x * Me1f1);
	Ce2f2 = e2y - (e2x * Me2f2);
	Ce3f3 = e3y - (e3x * Me3f3);
	Ce4f4 = e4y - (e4x * Me4f4);
	Ce5f5 = e5y - (e5x * Me5f5);

	//Titik potong
	ra = (Ce5f5 - Ce2f2) / (Me2f2 - Me5f5);
	rb = (Me2f2 * ra) + Ce2f2;
	rc = (Ce5f5 - Ce3f3) / (Me3f3 - Me5f5);
	rd = (Me3f3 * rc) + Ce3f3;
	re = (Ce4f4 - Ce2f2) / (Me2f2 - Me4f4);
	rf = (Me2f2 * re) + Ce2f2;
	rg = (Ce4f4 - Ce1f1) / (Me1f1 - Me4f4);
	rh = (Me1f1 * rg) + Ce1f1;
	ri = (Ce1f1 - Ce3f3) / (Me3f3 - Me1f1);
	rj = (Me3f3 * ri) + Ce3f3;

	//Hasil
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(ra, rb);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(rc, rd);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(re, rf);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(rg, rh);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(ri, rj);
	glEnd();
	glFlush();


    //depan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.0, -30.0, 10.0);
    glVertex3f(-25.0, 160.0, 10.0);
    glVertex3f(12.0, 160.0, 10.0);
    glVertex3f(12.0, -30.0, 10.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.0, -30.0, -30.0);
    glVertex3f(-25.0, 160.0, -30.0);
    glVertex3f(12.0, 160.0, -30.0);
    glVertex3f(12.0, -30.0, -30.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(12.0, 160.0, 10.0);
    glVertex3f(12.0, -30.0, 10.0);
    glVertex3f(12.0, -30.0, -30.0);
    glVertex3f(12.0, 160.0, -30.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.0, 160.0, 10.0);
    glVertex3f(-25.0, -30.0, 10.0);
    glVertex3f(-25.0, -30.0, -30.0);
    glVertex3f(-25.0, 160.0, -30.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-25.0, 158.1, 10.0);
    glVertex3f(12.0, 158.1, 10.0);
    glVertex3f(12.0, 158.1, -30.0);
    glVertex3f(-25.0, 158.1, -30.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.1, 168.0, 15.0);
    glVertex3f(25.0, 168.0, 15.0);
    glVertex3f(25.0, 168.0, -5.0);
    glVertex3f(4.1, 168.0, -5.0);
    glEnd();

      //depan2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(4.1, -30.0, 15.0);
    glVertex3f(4.1, 30.0, 15.0);
    glVertex3f(25.0, 30.0, 15.0);
    glVertex3f(25.0, -30.0, 15.0);
    glEnd();
    //belakang2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(4.1, -30.0, -5.0);
    glVertex3f(4.1, 30.0, -5.0);
    glVertex3f(25.0, 30.0, -5.0);
    glVertex3f(25.0, -30.0, -5.0);
    glEnd();
    //kanan2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(25.0, 30.0, 15.0);
    glVertex3f(25.0, -30.0, 15.0);
    glVertex3f(25.0, -30.0, -5.0);
    glVertex3f(25.0, 30.0, -5.0);
    glEnd();
    //kiri2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(4.1, 30.0, 15.0);
    glVertex3f(4.1, -30.0, 15.0);
    glVertex3f(4.1, -30.0, -5.0);
    glVertex3f(4.1, 30.0, -5.0);
    glEnd();
    //atas 2
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(4.0, 28.0, 15.0);
    glVertex3f(25.0, 28.0, 15.0);
    glVertex3f(25.0, 28.0, -5.0);
    glVertex3f(4.0, 28.0, -5.0);
    glEnd();

      //sekat antar lantai depan kanan bawah
       //depan
    glLineWidth(1.0); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.1, -18.0, 15.05);
    glVertex3f(25.0, -18.0, 15.05);

    glVertex3f(4.1, -6.0, 15.05);
    glVertex3f(25.0, -6.0, 15.05);

    glVertex3f(4.1, 6.0, 15.05);
    glVertex3f(25.0, 6.0, 15.05);

    glVertex3f(4.1, 18.0, 15.05);
    glVertex3f(25.0, 18.0, 15.05);

       //kanan
    glVertex3f(25.05, -18.0, -5.05);
    glVertex3f(25.05, -18.0, 15.05);

    glVertex3f(25.05, -6.0, -5.05);
    glVertex3f(25.05, -6.0, 15.05);

    glVertex3f(25.05, 6.0, -5.05);
    glVertex3f(25.05, 6.0, 15.05);

    glVertex3f(25.05, 18.0, -5.05);
    glVertex3f(25.05, 18.0, 15.05);

       //kiri
    glVertex3f(4.05, -18.0, -5.05);
    glVertex3f(4.05, -18.0, 15.05);

    glVertex3f(4.05, -6.0, -5.05);
    glVertex3f(4.05, -6.0, 15.05);

    glVertex3f(4.05, 6.0, -5.05);
    glVertex3f(4.05, 6.0, 15.05);

    glVertex3f(4.05, 18.0, -5.05);
    glVertex3f(4.05, 18.0, 15.05);

        //belakang
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);
    glVertex3f(4.1, -18.0, -5.05);
    glVertex3f(25.0, -18.0, -5.05);

    glVertex3f(4.1, -6.0, -5.05);
    glVertex3f(25.0, -6.0, -5.05);

    glVertex3f(4.1, 6.0, -5.05);
    glVertex3f(25.0, 6.0, -5.05);

    glVertex3f(4.1, 18.0, -5.05);
    glVertex3f(25.0, 18.0, -5.05);

    glEnd();

      //jendela lantai depan kanan bawah tulisan BINUS 1
       //depan
    glLineWidth(2.5); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(8.1, -27.0, 15.05);
    glVertex3f(12.0, -27.0, 15.05);

    glVertex3f(10.1, -26.0, 15.05);
    glVertex3f(14.0, -26.0, 15.05);

    glVertex3f(10.1, -25.0, 15.05);
    glVertex3f(20.0, -25.0, 15.05);

    glVertex3f(7.1, -24.0, 15.05);
    glVertex3f(10.0, -24.0, 15.05);

    glVertex3f(12.1, -23.0, 15.05);
    glVertex3f(16.0, -23.0, 15.05);

    glVertex3f(19.1, -23.0, 15.05);
    glVertex3f(16.0, -23.0, 15.05);
        //L2
    glVertex3f(7.1, -14.0, 15.05);
    glVertex3f(10.0, -14.0, 15.05);

    glVertex3f(11.1, -14.0, 15.05);
    glVertex3f(7.0, -14.0, 15.05);

    glVertex3f(10.1, -13.0, 15.05);
    glVertex3f(14.0, -13.0, 15.05);

    glVertex3f(9.1, -12.0, 15.05);
    glVertex3f(18.0, -12.0, 15.05);

    glVertex3f(7.1, -11.0, 15.05);
    glVertex3f(12.0, -11.0, 15.05);

    glVertex3f(12.1, -10.0, 15.05);
    glVertex3f(14.0, -10.0, 15.05);
        //L3
    glVertex3f(8.1, -2.0, 15.05);
    glVertex3f(10.0, -2.0, 15.05);

    glVertex3f(10.1, -1.0, 15.05);
    glVertex3f(14.0, -1.0, 15.05);

    glVertex3f(14.1, -0.0, 15.05);
    glVertex3f(20.0, -0.0, 15.05);

    glVertex3f(10.1, 1.0, 15.05);
    glVertex3f(15.0, 1.0, 15.05);

    glVertex3f(12.1, 2.0, 15.05);
    glVertex3f(14.0, 2.0, 15.05);

    glVertex3f(10.1, 3.0, 15.05);
    glVertex3f(9.0, 3.0, 15.05);
        //L4
    glVertex3f(13.1, 10.0, 15.05);
    glVertex3f(10.0, 10.0, 15.05);

    glVertex3f(10.1, 11.0, 15.05);
    glVertex3f(14.0, 11.0, 15.05);

    glVertex3f(15.1, 12.0, 15.05);
    glVertex3f(20.0, 12.0, 15.05);

    glVertex3f(12.1, 12.0, 15.05);
    glVertex3f(10.0, 12.0, 15.05);

    glVertex3f(20.1, 13.0, 15.05);
    glVertex3f(17.0, 13.0, 15.05);

    glVertex3f(8.1, 13.0, 15.05);
    glVertex3f(13.0, 13.0, 15.05);

    glVertex3f(11.1, 14.0, 15.05);
    glVertex3f(14.0, 14.0, 15.05);

    glVertex3f(11.1, 15.0, 15.05);
    glVertex3f(8.0, 15.0, 15.05);
        //L5
    glVertex3f(13.1, 22.0, 15.05);
    glVertex3f(10.0, 22.0, 15.05);

    glVertex3f(9.1, 22.0, 15.05);
    glVertex3f(8.0, 22.0, 15.05);

    glVertex3f(9.1, 22.0, 15.05);
    glVertex3f(18.0, 22.0, 15.05);

    glVertex3f(10.1, 23.0, 15.05);
    glVertex3f(12.0, 23.0, 15.05);

    glVertex3f(15.1, 23.0, 15.05);
    glVertex3f(17.0, 23.0, 15.05);

    glVertex3f(12.1, 24.0, 15.05);
    glVertex3f(10.0, 24.0, 15.05);

    glVertex3f(20.1, 25.0, 15.05);
    glVertex3f(17.0, 25.0, 15.05);

    glVertex3f(8.1, 26.0, 15.05);
    glVertex3f(13.0, 26.0, 15.05);

    glVertex3f(16.1, 26.0, 15.05);
    glVertex3f(18.0, 26.0, 15.05);

       //kanan
        //L1
    glVertex3f(25.05, -27.0, 5.05);
    glVertex3f(25.05, -27.0, 10.05);

    glVertex3f(25.05, -26.0, 4.05);
    glVertex3f(25.05, -26.0, 6.05);

    glVertex3f(25.05, -25.0, 0.05);
    glVertex3f(25.05, -25.0, 6.05);

    glVertex3f(25.05, -24.0, 9.05);
    glVertex3f(25.05, -24.0, 12.05);

    glVertex3f(25.05, -23.0, 8.05);
    glVertex3f(25.05, -23.0, 12.05);

    glVertex3f(25.05, -22.0, -2.05);
    glVertex3f(25.05, -22.0, 4.05);

    glVertex3f(25.05, -21.0, -3.05);
    glVertex3f(25.05, -21.0, 0.05);
        //L2
    glVertex3f(25.05, -14.0, 7.05);
    glVertex3f(25.05, -14.0, 10.05);

    glVertex3f(25.05, -13.0, 4.05);
    glVertex3f(25.05, -13.0, 6.05);

    glVertex3f(25.05, -12.0, 0.05);
    glVertex3f(25.05, -12.0, 6.05);

    glVertex3f(25.05, -11.0, 9.05);
    glVertex3f(25.05, -11.0, 12.05);

    glVertex3f(25.05, -10.0, 5.05);
    glVertex3f(25.05, -10.0, 11.05);

    glVertex3f(25.05, -9.0, -2.05);
    glVertex3f(25.05, -9.0, 3.05);
        //L3
    glVertex3f(25.05, -3.0, 10.05);
    glVertex3f(25.05, -3.0, 12.05);

    glVertex3f(25.05, -2.0, 4.05);
    glVertex3f(25.05, -2.0, 6.05);

    glVertex3f(25.05, -1.0, 0.05);
    glVertex3f(25.05, -1.0, 6.05);

    glVertex3f(25.05, 0.0, 9.05);
    glVertex3f(25.05, 0.0, 10.05);

    glVertex3f(25.05, 1.0, 5.05);
    glVertex3f(25.05, 1.0, 10.05);

    glVertex3f(25.05, 2.0, -2.05);
    glVertex3f(25.05, 2.0, 3.05);
        //L4
    glVertex3f(25.05, 10.0, -3.05);
    glVertex3f(25.05, 10.0, 8.05);

    glVertex3f(25.05, 11.0, -3.05);
    glVertex3f(25.05, 11.0, 1.05);

    glVertex3f(25.05, 12.0, 4.05);
    glVertex3f(25.05, 12.0, 13.05);

    glVertex3f(25.05, 13.0, 1.05);
    glVertex3f(25.05, 13.0, 4.05);

    glVertex3f(25.05, 14.0, 3.05);
    glVertex3f(25.05, 14.0, -1.05);

    glVertex3f(25.05, 15.0, -2.05);
    glVertex3f(25.05, 15.0, 3.05);
        //L5
    glVertex3f(25.05, 21.0, 13.05);
    glVertex3f(25.05, 21.0, 11.05);

    glVertex3f(25.05, 22.0, 12.05);
    glVertex3f(25.05, 22.0, 6.05);

    glVertex3f(25.05, 23.0, -3.05);
    glVertex3f(25.05, 23.0, 5.05);

    glVertex3f(25.05, 24.0, 4.05);
    glVertex3f(25.05, 24.0, 8.05);

    glVertex3f(25.05, 25.0, 9.05);
    glVertex3f(25.05, 25.0, 11.05);

    glVertex3f(25.05, 26.0, 10.05);
    glVertex3f(25.05, 26.0, 13.05);
       //belakang
        //L1
    glVertex3f(8.1, -27.0, -5.05);
    glVertex3f(12.0, -27.0, -5.05);

    glVertex3f(10.1, -26.0, -5.05);
    glVertex3f(14.0, -26.0, -5.05);

    glVertex3f(10.1, -25.0, -5.05);
    glVertex3f(20.0, -25.0, -5.05);

    glVertex3f(7.1, -24.0, -5.05);
    glVertex3f(10.0, -24.0, -5.05);

    glVertex3f(12.1, -23.0, -5.05);
    glVertex3f(16.0, -23.0, -5.05);

    glVertex3f(19.1, -23.0, -5.05);
    glVertex3f(16.0, -23.0, -5.05);
        //L2
    glVertex3f(7.1, -14.0, -5.05);
    glVertex3f(10.0, -14.0, -5.05);

    glVertex3f(11.1, -14.0, -5.05);
    glVertex3f(7.0, -14.0, -5.05);

    glVertex3f(10.1, -13.0, -5.05);
    glVertex3f(14.0, -13.0, -5.05);

    glVertex3f(9.1, -12.0, -5.05);
    glVertex3f(18.0, -12.0, -5.05);

    glVertex3f(7.1, -11.0, -5.05);
    glVertex3f(12.0, -11.0, -5.05);

    glVertex3f(12.1, -10.0, -5.05);
    glVertex3f(14.0, -10.0, -5.05);
        //L3
    glVertex3f(8.1, -2.0, -5.05);
    glVertex3f(10.0, -2.0, -5.05);

    glVertex3f(10.1, -1.0, -5.05);
    glVertex3f(14.0, -1.0, -5.05);

    glVertex3f(14.1, -0.0, -5.05);
    glVertex3f(20.0, -0.0, -5.05);

    glVertex3f(10.1, 1.0, -5.05);
    glVertex3f(15.0, 1.0, -5.05);

    glVertex3f(12.1, 2.0, -5.05);
    glVertex3f(14.0, 2.0, -5.05);

    glVertex3f(10.1, 3.0, -5.05);
    glVertex3f(9.0, 3.0, -5.05);
        //L4
    glVertex3f(13.1, 10.0, -5.05);
    glVertex3f(10.0, 10.0, -5.05);

    glVertex3f(10.1, 11.0, -5.05);
    glVertex3f(14.0, 11.0, -5.05);

    glVertex3f(15.1, 12.0, -5.05);
    glVertex3f(20.0, 12.0, -5.05);

    glVertex3f(12.1, 12.0, -5.05);
    glVertex3f(10.0, 12.0, -5.05);

    glVertex3f(20.1, 13.0, -5.05);
    glVertex3f(17.0, 13.0, -5.05);

    glVertex3f(8.1, 13.0, -5.05);
    glVertex3f(13.0, 13.0, -5.05);

    glVertex3f(11.1, 14.0, -5.05);
    glVertex3f(14.0, 14.0, -5.05);

    glVertex3f(11.1, 15.0, -5.05);
    glVertex3f(8.0, 15.0, -5.05);
        //L5
    glVertex3f(13.1, 22.0, -5.05);
    glVertex3f(10.0, 22.0, -5.05);

    glVertex3f(9.1, 22.0, -5.05);
    glVertex3f(8.0, 22.0, -5.05);

    glVertex3f(9.1, 22.0, -5.05);
    glVertex3f(18.0, 22.0, -5.05);

    glVertex3f(10.1, 23.0, -5.05);
    glVertex3f(12.0, 23.0, -5.05);

    glVertex3f(15.1, 23.0, -5.05);
    glVertex3f(17.0, 23.0, -5.05);

    glVertex3f(12.1, 24.0, -5.05);
    glVertex3f(10.0, 24.0, -5.05);

    glVertex3f(20.1, 25.0, -5.05);
    glVertex3f(17.0, 25.0, -5.05);

    glVertex3f(8.1, 26.0, -5.05);
    glVertex3f(13.0, 26.0, -5.05);

    glVertex3f(16.1, 26.0, -5.05);
    glVertex3f(18.0, 26.0, -5.05);

    glEnd();

    //paling atas binus
    //depan2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(4.1, 115.0, 15.0);
    glVertex3f(4.1, 170.0, 15.0);
    glVertex3f(25.0, 170.0, 15.0);
    glVertex3f(25.0, 115.0, 15.0);
    glEnd();
    //belakang2
    glBegin(GL_QUADS);
     glColor3f(0.2, 0.2, 0.2);
    glVertex3f(4.1, 115.0, -5.0);
    glVertex3f(4.1, 170.0, -5.0);
    glVertex3f(25.0, 170.0, -5.0);
    glVertex3f(25.0, 115.0, -5.0);
    glEnd();
    //kanan2
    glBegin(GL_QUADS);
     glColor3f(0.2, 0.2, 0.2);
    glVertex3f(25.0, 115.0, 15.0);
    glVertex3f(25.0, 170.0, 15.0);
    glVertex3f(25.0, 170.0, -5.0);
    glVertex3f(25.0, 115.0, -5.0);
    glEnd();
    //kiri2
    glBegin(GL_QUADS);
     glColor3f(0.2, 0.2, 0.2);
    glVertex3f(4.1, 115.0, 15.0);
    glVertex3f(4.1, 170.0, 15.0);
    glVertex3f(4.1, 170.0, -5.0);
    glVertex3f(4.1, 115.0, -5.0);
    glEnd();

    //tulisan BINUS 1
     //B
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 14.8);
    glVertex3f(25.05, 170.0, 14.8);
    glVertex3f(25.05, 170.0, 10.7);
    glVertex3f(25.05, 162.0, 10.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(25.07, 169.0, 13.85);
    glVertex3f(25.07, 167.5, 13.85);
    glVertex3f(25.07, 167.5, 11.75);
    glVertex3f(25.07, 169.0, 11.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(25.07, 164.5, 13.85);
    glVertex3f(25.07, 163.0, 13.85);
    glVertex3f(25.07, 163.0, 11.75);
    glVertex3f(25.07, 164.5, 11.75);
    glEnd();
     //I
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 8.7);
    glVertex3f(25.05, 170.0, 8.7);
    glVertex3f(25.05, 170.0, 9.7);
    glVertex3f(25.05, 162.0, 9.7);
    glEnd();
     //N
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 7.7);
    glVertex3f(25.05, 170.0, 7.7);
    glVertex3f(25.05, 170.0, 6.7);
    glVertex3f(25.05, 162.0, 6.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 165.0, 4.7);
    glVertex3f(25.05, 162.0, 4.7);
    glVertex3f(25.05, 167.0, 6.7);
    glVertex3f(25.05, 170.0, 6.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 4.7);
    glVertex3f(25.05, 170.0, 4.7);
    glVertex3f(25.05, 170.0, 3.7);
    glVertex3f(25.05, 162.0, 3.7);
    glEnd();
     //U
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 2.7);
    glVertex3f(25.05, 170.0, 2.7);
    glVertex3f(25.05, 170.0, 1.7);
    glVertex3f(25.05, 162.0, 1.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 0.2);
    glVertex3f(25.05, 163.0, 0.2);
    glVertex3f(25.05, 163.0, 1.7);
    glVertex3f(25.05, 162.0, 1.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, 0.2);
    glVertex3f(25.05, 170.0, 0.2);
    glVertex3f(25.05, 170.0, -0.8);
    glVertex3f(25.05, 162.0, -0.8);
    glEnd();
     //S
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 169.0, -1.8);
    glVertex3f(25.05, 170.0, -1.8);
    glVertex3f(25.05, 170.0, -5.0);
    glVertex3f(25.05, 169.0, -5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 170.0, -1.8);
    glVertex3f(25.05, 166.0, -1.8);
    glVertex3f(25.05, 166.0, -2.8);
    glVertex3f(25.05, 170.0, -2.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 165.5, -1.8);
    glVertex3f(25.05, 166.5, -1.8);
    glVertex3f(25.05, 166.5, -5.0);
    glVertex3f(25.05, 165.5, -5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 166.0, -4.0);
    glVertex3f(25.05, 162.0, -4.0);
    glVertex3f(25.05, 162.0, -5.0);
    glVertex3f(25.05, 166.0, -5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.05, 162.0, -1.8);
    glVertex3f(25.05, 163.0, -1.8);
    glVertex3f(25.05, 163.0, -5.0);
    glVertex3f(25.05, 162.0, -5.0);
    glEnd();

    //depan3
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.0, 30.0, 18.0);
    glVertex3f(4.0, 73.0, 18.0);
    glVertex3f(25.0, 73.0, 18.0);
    glVertex3f(25.0, 30.0, 18.0);
    glEnd();
    //belakang3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.0, 30.0, -4.0);
    glVertex3f(4.0, 73.0, -4.0);
    glVertex3f(25.0, 73.0, -4.0);
    glVertex3f(25.0, 30.0, -4.0);
    glEnd();
    //kanan3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(25.0, 73.0, 18.0);
    glVertex3f(25.0, 30.0, 18.0);
    glVertex3f(25.0, 30.0, -4.0);
    glVertex3f(25.0, 73.0, -4.0);
    glEnd();
    //kiri3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.0, 73.0, 18.0);
    glVertex3f(4.0, 30.0, 18.0);
    glVertex3f(4.0, 30.0, -4.0);
    glVertex3f(4.0, 73.0, -4.0);
    glEnd();
    //atas bawah3
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(4.0, 71.0, 18.0);
    glVertex3f(25.0, 71.0, 18.0);
    glVertex3f(25.0, 71.0, -4.0);
    glVertex3f(4.0, 71.0, -4.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(4.0, 32.0, 18.0);
    glVertex3f(25.0, 32.0, 18.0);
    glVertex3f(25.0, 32.0, -4.0);
    glVertex3f(4.0, 32.0, -4.0);
    glEnd();

      //sekat antar lantai depan kanan tengah bawah
       //depan
    glLineWidth(1.0); //jarak per lantai 10 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.0, 41.0, 18.05);
    glVertex3f(25.0, 41.0, 18.05);

    glVertex3f(4.1, 52.0, 18.05);
    glVertex3f(25.0, 52.0, 18.05);

    glVertex3f(4.1, 63.0, 18.05);
    glVertex3f(25.0, 63.0, 18.05);

       //kanan
    glVertex3f(25.05, 41.0, -4.0);
    glVertex3f(25.05, 41.0, 18.0);

    glVertex3f(25.05, 52.0, -4.0);
    glVertex3f(25.05, 52.0, 18.0);

    glVertex3f(25.05, 63.0, -4.0);
    glVertex3f(25.05, 63.0, 18.0);

        //kiri
    glVertex3f(3.95, 41.0, -4.0);
    glVertex3f(3.95, 41.0, 18.0);

    glVertex3f(3.95, 52.0, -4.0);
    glVertex3f(3.95, 52.0, 18.0);

    glVertex3f(3.95, 63.0, -4.0);
    glVertex3f(3.95, 63.0, 18.0);

        //belakang
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);
    glVertex3f(4.0, 41.0, -4.05);
    glVertex3f(25.0, 41.0, -4.05);

    glVertex3f(4.1, 52.0, -4.05);
    glVertex3f(25.0, 52.0, -4.05);

    glVertex3f(4.1, 63.0, -4.05);
    glVertex3f(25.0, 63.0, -4.05);

    glEnd();

      //jendela lantai depan kanan tengah bawah tulisan BINUS 1
       //depan
    glLineWidth(2.5); //jarak per lantai 11 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(8.1, 33.0, 18.05);
    glVertex3f(12.0, 33.0, 18.05);

    glVertex3f(10.1, 34.0, 18.05);
    glVertex3f(14.0, 34.0, 18.05);

    glVertex3f(10.1, 35.0, 18.05);
    glVertex3f(20.0, 35.0, 18.05);

    glVertex3f(7.1, 36.0, 18.05);
    glVertex3f(10.0, 36.0, 18.05);

    glVertex3f(12.1, 37.0, 18.05);
    glVertex3f(16.0, 37.0, 18.05);

    glVertex3f(19.1, 38.0, 18.05);
    glVertex3f(16.0, 38.0, 18.05);
        //L2
    glVertex3f(7.1, 44.0, 18.05);
    glVertex3f(10.0, 44.0, 18.05);

    glVertex3f(11.1, 44.0, 18.05);
    glVertex3f(7.0, 44.0, 18.05);

    glVertex3f(10.1, 45.0, 18.05);
    glVertex3f(14.0, 45.0, 18.05);

    glVertex3f(9.1, 46.0, 18.05);
    glVertex3f(18.0, 46.0, 18.05);

    glVertex3f(7.1, 47.0, 18.05);
    glVertex3f(12.0, 47.0, 18.05);

    glVertex3f(12.1, 48.0, 18.05);
    glVertex3f(14.0, 48.0, 18.05);
        //L3
    glVertex3f(8.1, 54.0, 18.05);
    glVertex3f(10.0, 54.0, 18.05);

    glVertex3f(10.1, 55.0, 18.05);
    glVertex3f(14.0, 55.0, 18.05);

    glVertex3f(14.1, 56.0, 18.05);
    glVertex3f(20.0, 56.0, 18.05);

    glVertex3f(10.1, 57.0, 18.05);
    glVertex3f(15.0, 57.0, 18.05);

    glVertex3f(12.1, 58.0, 18.05);
    glVertex3f(14.0, 58.0, 18.05);

    glVertex3f(10.1, 59.0, 18.05);
    glVertex3f(9.0, 59.0, 18.05);

    glVertex3f(12.1, 60.0, 18.05);
    glVertex3f(14.0, 60.0, 18.05);

    glVertex3f(10.1, 60.0, 18.05);
    glVertex3f(9.0, 60.0, 18.05);
        //L4
    glVertex3f(13.1, 66.0, 18.05);
    glVertex3f(10.0, 66.0, 18.05);

    glVertex3f(9.1, 66.0, 18.05);
    glVertex3f(8.0, 66.0, 18.05);

    glVertex3f(9.1, 66.0, 18.05);
    glVertex3f(18.0, 66.0, 18.05);

    glVertex3f(10.1, 67.0, 18.05);
    glVertex3f(12.0, 67.0, 18.05);

    glVertex3f(15.1, 67.0, 18.05);
    glVertex3f(17.0, 67.0, 18.05);

    glVertex3f(12.1, 68.0, 18.05);
    glVertex3f(10.0, 68.0, 18.05);

    glVertex3f(20.1, 69.0, 18.05);
    glVertex3f(17.0, 69.0, 18.05);

    glVertex3f(8.1, 70.0, 18.05);
    glVertex3f(13.0, 70.0, 18.05);

    glVertex3f(16.1, 70.0, 18.05);
    glVertex3f(18.0, 70.0, 18.05);
       //kanan
        //L1
    glVertex3f(25.05, 33.0, 7.05);
    glVertex3f(25.05, 33.0, 11.05);

    glVertex3f(25.05, 34.0, 6.05);
    glVertex3f(25.05, 34.0, 8.05);

    glVertex3f(25.05, 35.0, 2.05);
    glVertex3f(25.05, 35.0, 8.05);

    glVertex3f(25.05, 36.0, 11.05);
    glVertex3f(25.05, 36.0, 14.05);

    glVertex3f(25.05, 37.0, 10.05);
    glVertex3f(25.05, 37.0, 14.05);

    glVertex3f(25.05, 38.0, -0.05);
    glVertex3f(25.05, 38.0, 6.05);

    glVertex3f(25.05, 39.0, -1.05);
    glVertex3f(25.05, 39.0, 2.05);
        //L2
    glVertex3f(25.05, 44.0, 9.05);
    glVertex3f(25.05, 44.0, 12.05);

    glVertex3f(25.05, 45.0, 6.05);
    glVertex3f(25.05, 45.0, 8.05);

    glVertex3f(25.05, 46.0, 2.05);
    glVertex3f(25.05, 46.0, 8.05);

    glVertex3f(25.05, 47.0, 11.05);
    glVertex3f(25.05, 47.0, 14.05);

    glVertex3f(25.05, 48.0, 7.05);
    glVertex3f(25.05, 48.0, 13.05);

    glVertex3f(25.05, 49.0, -0.05);
    glVertex3f(25.05, 49.0, 5.05);
        //L3
    glVertex3f(25.05, 54.0, -1.05);
    glVertex3f(25.05, 54.0, 10.05);

    glVertex3f(25.05, 55.0, -1.05);
    glVertex3f(25.05, 55.0, 3.05);

    glVertex3f(25.05, 56.0, 6.05);
    glVertex3f(25.05, 56.0, 15.05);

    glVertex3f(25.05, 57.0, 3.05);
    glVertex3f(25.05, 57.0, 6.05);

    glVertex3f(25.05, 58.0, 5.05);
    glVertex3f(25.05, 58.0, 1.05);

    glVertex3f(25.05, 59.0, -0.05);
    glVertex3f(25.05, 59.0, 5.05);
        //L4
    glVertex3f(25.05, 66.0, 15.05);
    glVertex3f(25.05, 66.0, 13.05);

    glVertex3f(25.05, 67.0, 14.05);
    glVertex3f(25.05, 67.0, 8.05);

    glVertex3f(25.05, 68.0, -1.05);
    glVertex3f(25.05, 68.0, 7.05);

    glVertex3f(25.05, 69.0, 6.05);
    glVertex3f(25.05, 69.0, 10.05);

    glVertex3f(25.05, 70.0, 11.05);
    glVertex3f(25.05, 70.0, 13.05);

    glVertex3f(25.05, 71.0, 12.05);
    glVertex3f(25.05, 71.0, 15.05);
       //belakang
        //L1
    glVertex3f(7.1, 33.0, -4.05);
    glVertex3f(10.0, 33.0, -4.05);

    glVertex3f(11.1, 34.0, -4.05);
    glVertex3f(7.0, 34.0, -4.05);

    glVertex3f(10.1, 35.0, -4.05);
    glVertex3f(14.0, 35.0, -4.05);

    glVertex3f(9.1, 36.0, -4.05);
    glVertex3f(18.0, 36.0, -4.05);

    glVertex3f(7.1, 37.0, -4.05);
    glVertex3f(12.0, 37.0, -4.05);

    glVertex3f(12.1, 38.0, -4.05);
    glVertex3f(14.0, 38.0, -4.05);
        //L2
    glVertex3f(8.1, 44.0, -4.05);
    glVertex3f(12.0, 44.0, -4.05);

    glVertex3f(10.1, 45.0, -4.05);
    glVertex3f(14.0, 45.0, -4.05);

    glVertex3f(10.1, 46.0, -4.05);
    glVertex3f(20.0, 46.0, -4.05);

    glVertex3f(7.1, 47.0, -4.05);
    glVertex3f(10.0, 47.0, -4.05);

    glVertex3f(12.1, 48.0, -4.05);
    glVertex3f(16.0, 48.0, -4.05);

    glVertex3f(19.1, 48.0, -4.05);
    glVertex3f(16.0, 48.0, -4.05);
        //L3
    glVertex3f(8.1, 54.0, -4.05);
    glVertex3f(10.0, 54.0, -4.05);

    glVertex3f(10.1, 55.0, -4.05);
    glVertex3f(14.0, 55.0, -4.05);

    glVertex3f(14.1, 56.0, -4.05);
    glVertex3f(20.0, 56.0, -4.05);

    glVertex3f(10.1, 57.0, -4.05);
    glVertex3f(15.0, 57.0, -4.05);

    glVertex3f(12.1, 58.0, -4.05);
    glVertex3f(14.0, 58.0, -4.05);

    glVertex3f(10.1, 59.0, -4.05);
    glVertex3f(9.0, 59.0, -4.05);
        //L4
    glVertex3f(13.1, 66.0, -4.05);
    glVertex3f(10.0, 66.0, -4.05);

    glVertex3f(10.1, 67.0, -4.05);
    glVertex3f(14.0, 67.0, -4.05);

    glVertex3f(15.1, 68.0, -4.05);
    glVertex3f(20.0, 68.0, -4.05);

    glVertex3f(12.1, 68.0, -4.05);
    glVertex3f(10.0, 68.0, -4.05);

    glVertex3f(20.1, 69.0, -4.05);
    glVertex3f(17.0, 69.0, -4.05);

    glVertex3f(8.1, 69.0, -4.05);
    glVertex3f(13.0, 69.0, -4.05);

    glVertex3f(11.1, 70.0, -4.05);
    glVertex3f(14.0, 70.0, -4.05);

    glVertex3f(11.1, 71.0, -4.05);
    glVertex3f(8.0, 71.0, -4.05);

    glEnd();

        //depan 4
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(4.0, 80.0, 18.0);
    glVertex3f(4.0, 110.0, 18.0);
    glVertex3f(25.0, 110.0, 18.0);
    glVertex3f(25.0, 80.0, 18.0);
    glEnd();
    //belakang4
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(4.0, 80.0, -4.0);
    glVertex3f(4.0, 110.0, -4.0);
    glVertex3f(25.0, 110.0, -4.0);
    glVertex3f(25.0, 80.0, -4.0);
    glEnd();
    //kanan4
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, 110.0, 18.0);
    glVertex3f(25.0, 80.0, 18.0);
    glVertex3f(25.0, 80.0, -4.0);
    glVertex3f(25.0, 110.0, -4.0);
    glEnd();
    //kiri34
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(4.0, 110.0, 18.0);
    glVertex3f(4.0, 80.0, 18.0);
    glVertex3f(4.0, 80.0, -4.0);
    glVertex3f(4.0, 110.0, -4.0);
    glEnd();
    //atas bawah 4
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(4.0, 108.0, 18.0);
    glVertex3f(25.0, 108.0, 18.0);
    glVertex3f(25.0, 108.0, -4.0);
    glVertex3f(4.0, 108.0, -4.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(4.0, 82.0, 18.0);
    glVertex3f(25.0, 82.0, 18.0);
    glVertex3f(25.0, 82.0, -4.0);
    glVertex3f(4.0, 82.0, -4.0);
    glEnd();

      //sekat antar lantai depan kanan tengah atas
       //depan
    glLineWidth(1.0); //jarak per lantai 10 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.0, 90.0, 18.05);
    glVertex3f(25.0, 90.0, 18.05);

    glVertex3f(4.1, 100.0, 18.05);
    glVertex3f(25.0, 100.0, 18.05);

       //kanan
    glVertex3f(25.05, 90.0, -4.05);
    glVertex3f(25.05, 90.0, 18.05);

    glVertex3f(25.05, 100.0, -4.05);
    glVertex3f(25.05, 100.0, 18.05);

        //kiri
    glVertex3f(3.95, 90.0, -4.05);
    glVertex3f(3.95, 90.0, 18.05);

    glVertex3f(3.95, 100.0, -4.05);
    glVertex3f(3.95, 100.0, 18.05);

        //belakang
    glVertex3f(4.0, 90.0, -4.05);
    glVertex3f(25.0, 90.0, -4.05);

    glVertex3f(4.1, 100.0, -4.05);
    glVertex3f(25.0, 100.0, -4.05);

    glEnd();

    //jendela lantai depan kanan tengah atas bawahnya tulisan BINUS 1
       //depan
    glLineWidth(2.5); //jarak per lantai 11 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(7.1, 83.0, 18.05);
    glVertex3f(10.0, 83.0, 18.05);

    glVertex3f(11.1, 83.0, 18.05);
    glVertex3f(7.0, 83.0, 18.05);

    glVertex3f(10.1, 84.0, 18.05);
    glVertex3f(14.0, 84.0, 18.05);

    glVertex3f(9.1, 85.0, 18.05);
    glVertex3f(18.0, 85.0, 18.05);

    glVertex3f(7.1, 86.0, 18.05);
    glVertex3f(12.0, 86.0, 18.05);

    glVertex3f(12.1, 87.0, 18.05);
    glVertex3f(14.0, 87.0, 18.05);
        //L2
    glVertex3f(13.1, 93.0, 18.05);
    glVertex3f(10.0, 93.0, 18.05);

    glVertex3f(9.1, 93.0, 18.05);
    glVertex3f(8.0, 93.0, 18.05);

    glVertex3f(9.1, 93.0, 18.05);
    glVertex3f(18.0, 93.0, 18.05);

    glVertex3f(10.1, 94.0, 18.05);
    glVertex3f(12.0, 94.0, 18.05);

    glVertex3f(15.1, 94.0, 18.05);
    glVertex3f(17.0, 94.0, 18.05);

    glVertex3f(12.1, 95.0, 18.05);
    glVertex3f(10.0, 95.0, 18.05);

    glVertex3f(20.1, 96.0, 18.05);
    glVertex3f(17.0, 96.0, 18.05);

    glVertex3f(8.1, 97.0, 18.05);
    glVertex3f(13.0, 97.0, 18.05);

    glVertex3f(16.1, 98.0, 18.05);
    glVertex3f(18.0, 98.0, 18.05);
        //L3
    glVertex3f(8.1, 103.0, 18.05);
    glVertex3f(10.0, 103.0, 18.05);

    glVertex3f(10.1, 104.0, 18.05);
    glVertex3f(14.0, 104.0, 18.05);

    glVertex3f(14.1, 105.0, 18.05);
    glVertex3f(20.0, 105.0, 18.05);

    glVertex3f(10.1, 106.0, 18.05);
    glVertex3f(15.0, 106.0, 18.05);

    glVertex3f(12.1, 107.0, 18.05);
    glVertex3f(14.0, 107.0, 18.05);

    glVertex3f(10.1, 108.0, 18.05);
    glVertex3f(9.0, 108.0, 18.05);

    glVertex3f(12.1, 109.0, 18.05);
    glVertex3f(14.0, 109.0, 18.05);

    glVertex3f(10.1, 109.0, 18.05);
    glVertex3f(9.0, 109.0, 18.05);

       //kanan
        //L1
    glVertex3f(25.05, 83.0, 9.05);
    glVertex3f(25.05, 83.0, 12.05);

    glVertex3f(25.05, 84.0, 6.05);
    glVertex3f(25.05, 84.0, 8.05);

    glVertex3f(25.05, 85.0, 2.05);
    glVertex3f(25.05, 85.0, 8.05);

    glVertex3f(25.05, 86.0, 11.05);
    glVertex3f(25.05, 86.0, 14.05);

    glVertex3f(25.05, 87.0, 7.05);
    glVertex3f(25.05, 87.0, 13.05);

    glVertex3f(25.05, 88.0, -0.05);
    glVertex3f(25.05, 88.0, 5.05);
        //L2
    glVertex3f(25.05, 93.0, 7.05);
    glVertex3f(25.05, 93.0, 11.05);

    glVertex3f(25.05, 94.0, 6.05);
    glVertex3f(25.05, 94.0, 8.05);

    glVertex3f(25.05, 95.0, 2.05);
    glVertex3f(25.05, 95.0, 8.05);

    glVertex3f(25.05, 96.0, 11.05);
    glVertex3f(25.05, 96.0, 14.05);

    glVertex3f(25.05, 97.0, 10.05);
    glVertex3f(25.05, 97.0, 14.05);

    glVertex3f(25.05, 98.0, -0.05);
    glVertex3f(25.05, 98.0, 6.05);

    glVertex3f(25.05, 99.0, -1.05);
    glVertex3f(25.05, 99.0, 2.05);
        //L3
    glVertex3f(25.05, 103.0, 15.05);
    glVertex3f(25.05, 103.0, 13.05);

    glVertex3f(25.05, 104.0, 14.05);
    glVertex3f(25.05, 104.0, 8.05);

    glVertex3f(25.05, 105.0, -1.05);
    glVertex3f(25.05, 105.0, 7.05);

    glVertex3f(25.05, 106.0, 6.05);
    glVertex3f(25.05, 106.0, 10.05);

    glVertex3f(25.05, 107.0, 11.05);
    glVertex3f(25.05, 107.0, 13.05);

    glVertex3f(25.05, 108.0, 12.05);
    glVertex3f(25.05, 108.0, 15.05);

       //belakang
        //L1
    glVertex3f(13.1, 83.0, -4.05);
    glVertex3f(10.0, 83.0, -4.05);

    glVertex3f(10.1, 84.0, -4.05);
    glVertex3f(14.0, 84.0, -4.05);

    glVertex3f(15.1, 85.0, -4.05);
    glVertex3f(20.0, 85.0, -4.05);

    glVertex3f(12.1, 85.0, -4.05);
    glVertex3f(10.0, 85.0, -4.05);

    glVertex3f(20.1, 86.0, -4.05);
    glVertex3f(17.0, 86.0, -4.05);

    glVertex3f(8.1, 86.0, -4.05);
    glVertex3f(13.0, 86.0, -4.05);

    glVertex3f(11.1, 87.0, -4.05);
    glVertex3f(14.0, 87.0, -4.05);

    glVertex3f(11.1, 88.0, -4.05);
    glVertex3f(8.0, 88.0, -4.05);
        //L2
    glVertex3f(7.1, 93.0, -4.05);
    glVertex3f(10.0, 93.0, -4.05);

    glVertex3f(11.1, 94.0, -4.05);
    glVertex3f(7.0, 94.0, -4.05);

    glVertex3f(10.1, 95.0, -4.05);
    glVertex3f(14.0, 95.0, -4.05);

    glVertex3f(9.1, 96.0, -4.05);
    glVertex3f(18.0, 96.0, -4.05);

    glVertex3f(7.1, 97.0, -4.05);
    glVertex3f(12.0, 97.0, -4.05);

    glVertex3f(12.1, 98.0, -4.05);
    glVertex3f(14.0, 98.0, -4.05);
        //L3
    glVertex3f(8.1, 103.0, -4.05);
    glVertex3f(12.0, 103.0, -4.05);

    glVertex3f(10.1, 104.0, -4.05);
    glVertex3f(14.0, 104.0, -4.05);

    glVertex3f(10.1, 105.0, -4.05);
    glVertex3f(20.0, 105.0, -4.05);

    glVertex3f(7.1, 106.0, -4.05);
    glVertex3f(10.0, 106.0, -4.05);

    glVertex3f(12.1, 107.0, -4.05);
    glVertex3f(16.0, 107.0, -4.05);

    glVertex3f(19.1, 107.0, -4.05);
    glVertex3f(16.0, 107.0, -4.05);

    glEnd();

    //depan4
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-46.0, 35.0, 18.0);
    glVertex3f(-46.0, 85.0, 18.0);
    glVertex3f(-24.1, 85.0, 18.0);
    glVertex3f(-24.1, 35.0, 18.0);
    glEnd();
    //belakang4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-46.0, 35.0, -3.0);
    glVertex3f(-46.0, 85.0, -3.0);
    glVertex3f(-24.1, 85.0, -3.0);
    glVertex3f(-24.1, 35.0, -3.0);
    glEnd();
    //kanan4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-24.1, 85.0, 18.0);
    glVertex3f(-24.1, 35.0, 18.0);
    glVertex3f(-24.1, 35.0, -3.0);
    glVertex3f(-24.1, 85.0, -3.0);
    glEnd();
    //kiri4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-46.0, 85.0, 18.0);
    glVertex3f(-46.0, 35.0, 18.0);
    glVertex3f(-46.0, 35.0, -3.0);
    glVertex3f(-46.0, 85.0, -3.0);
    glEnd();

    //atas bawah 4
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-46.0, 83.0, 18.0);
    glVertex3f(-24.0, 83.0, 18.0);
    glVertex3f(-24.0, 83.0, -3.0);
    glVertex3f(-46.0, 83.0, -3.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-46.0, 37.0, 18.0);
    glVertex3f(-24.0, 37.0, 18.0);
    glVertex3f(-24.0, 37.0, -3.0);
    glVertex3f(-46.0, 37.0, -3.0);
    glEnd();

    //sekat antar lantai depan kiri tengah atas
       //depan
    glLineWidth(1.0); //jarak per lantai 16.5 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-46.0, 51.5, 18.05);
    glVertex3f(-24.0, 51.5, 18.05);

    glVertex3f(-46.0, 68.0, 18.05);
    glVertex3f(-24.0, 68.0, 18.05);

       //kanan
    glVertex3f(-24.1, 51.5, 18.0);
    glVertex3f(-24.1, 51.5, -3.0);

    glVertex3f(-24.1, 68.0,18.0);
    glVertex3f(-24.1, 68.0, -3.0);

        //kiri
    glVertex3f(-46.05, 51.5, 18.0);
    glVertex3f(-46.05, 51.5, -3.0);

    glVertex3f(-46.05, 68.0,18.0);
    glVertex3f(-46.05, 68.0, -3.0);

        //belakang
    glVertex3f(-46.0, 51.5, -3.05);
    glVertex3f(-24.0, 51.5, -3.05);

    glVertex3f(-46.0, 68.0, -3.05);
    glVertex3f(-24.0, 68.0, -3.05);

    glEnd();

    //jendela lantai depan kiri tengah bawah
       //depan
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1 x=-43 sampai -27
    glVertex3f(-43.0, 40.0, 18.05);
    glVertex3f(-38.0, 40.0, 18.05);

    glVertex3f(-39.0, 41.0, 18.05);
    glVertex3f(-28.0, 41.0, 18.05);

    glVertex3f(-34.0, 42.0, 18.05);
    glVertex3f(-36.0, 42.0, 18.05);

    glVertex3f(-40.0, 43.0, 18.05);
    glVertex3f(-43.0, 43.0, 18.05);

    glVertex3f(-36.0, 44.0, 18.05);
    glVertex3f(-34.0, 44.0, 18.05);

    glVertex3f(-27.0, 44.0, 18.05);
    glVertex3f(-24.0, 44.0, 18.05);

    glVertex3f(-40.0, 45.0, 18.05);
    glVertex3f(-30.0, 45.0, 18.05);

    glVertex3f(-43.0, 46.0, 18.05);
    glVertex3f(-38.0, 46.0, 18.05);
        //L2
    glVertex3f(-43.0, 56.0, 18.05);
    glVertex3f(-38.0, 56.0, 18.05);

    glVertex3f(-43.0, 57.0, 18.05);
    glVertex3f(-38.0, 57.0, 18.05);

    glVertex3f(-40.0, 58.0, 18.05);
    glVertex3f(-30.0, 58.0, 18.05);

    glVertex3f(-39.0, 59.0, 18.05);
    glVertex3f(-28.0, 59.0, 18.05);

    glVertex3f(-34.0, 60.0, 18.05);
    glVertex3f(-36.0, 60.0, 18.05);

    glVertex3f(-40.0, 60.0, 18.05);
    glVertex3f(-43.0, 60.0, 18.05);

    glVertex3f(-36.0, 61.0, 18.05);
    glVertex3f(-34.0, 61.0, 18.05);

    glVertex3f(-30.0, 62.0, 18.05);
    glVertex3f(-27.0, 62.0, 18.05);
        //L3
    glVertex3f(-43.0, 73.0, 18.05);
    glVertex3f(-38.0, 73.0, 18.05);

    glVertex3f(-40.0, 74.0, 18.05);
    glVertex3f(-30.0, 74.0, 18.05);

    glVertex3f(-34.0, 75.0, 18.05);
    glVertex3f(-36.0, 75.0, 18.05);

    glVertex3f(-36.0, 76.0, 18.05);
    glVertex3f(-34.0, 76.0, 18.05);

    glVertex3f(-39.0, 77.0, 18.05);
    glVertex3f(-28.0, 77.0, 18.05);

    glVertex3f(-40.0, 77.0, 18.05);
    glVertex3f(-43.0, 77.0, 18.05);

    glVertex3f(-30.0, 78.0, 18.05);
    glVertex3f(-27.0, 78.0, 18.05);

    glVertex3f(-43.0, 79.0, 18.05);
    glVertex3f(-38.0, 79.0, 18.05);
       //kiri
        //L1
    glVertex3f(-46.05, 40.0, 14.05);
    glVertex3f(-46.05, 40.0, 14.05);

    glVertex3f(-46.05, 41.0, 13.05);
    glVertex3f(-46.05, 41.0, 1.05);

    glVertex3f(-46.05, 42.0, 14.05);
    glVertex3f(-46.05, 42.0, 10.05);

    glVertex3f(-46.05, 43.0, 14.05);
    glVertex3f(-46.05, 43.0, -2.05);

    glVertex3f(-46.05, 44.0, 12.05);
    glVertex3f(-46.05, 44.0, 10.05);

    glVertex3f(-46.05, 44.0, 3.05);
    glVertex3f(-46.05, 44.0, 1.05);

    glVertex3f(-46.05, 45.0, 10.05);
    glVertex3f(-46.05, 45.0, 5.05);

    glVertex3f(-46.05, 46.0, 4.05);
    glVertex3f(-46.05, 46.0, 1.05);
        //L2
    glVertex3f(-46.05, 56.0, 4.05);
    glVertex3f(-46.05, 56.0, 1.05);

    glVertex3f(-46.05, 57.0, 14.05);
    glVertex3f(-46.05, 57.0, 14.05);

    glVertex3f(-46.05, 59.0, 13.05);
    glVertex3f(-46.05, 59.0, 1.05);

    glVertex3f(-46.05, 58.0, 14.05);
    glVertex3f(-46.05, 58.0, 10.05);

    glVertex3f(-46.05, 60.0, 14.05);
    glVertex3f(-46.05, 60.0, -2.05);

    glVertex3f(-46.05, 61.0, 3.05);
    glVertex3f(-46.05, 61.0, 1.05);

    glVertex3f(-46.05, 61.0, 10.05);
    glVertex3f(-46.05, 61.0, 5.05);

    glVertex3f(-46.05, 62.0, 12.05);
    glVertex3f(-46.05, 62.0, 10.05);

        //L3
    glVertex3f(-46.05, 73.0, 4.05);
    glVertex3f(-46.05, 73.0, 1.05);

    glVertex3f(-46.05, 74.0, 14.05);
    glVertex3f(-46.05, 74.0, 14.05);

    glVertex3f(-46.05, 75.0, 13.05);
    glVertex3f(-46.05, 75.0, 1.05);

    glVertex3f(-46.05, 77.0, 14.05);
    glVertex3f(-46.05, 77.0, 10.05);

    glVertex3f(-46.05, 76.0, 14.05);
    glVertex3f(-46.05, 76.0, -2.05);

    glVertex3f(-46.05, 78.0, 3.05);
    glVertex3f(-46.05, 78.0, 1.05);

    glVertex3f(-46.05, 79.0, 10.05);
    glVertex3f(-46.05, 79.0, 5.05);

    glVertex3f(-46.05, 78.0, 12.05);
    glVertex3f(-46.05, 78.0, 10.05);
       //belakang
        //L1
    glVertex3f(-43.0, 40.0, -3.05);
    glVertex3f(-38.0, 40.0, -3.05);

    glVertex3f(-39.0, 41.0, -3.05);
    glVertex3f(-28.0, 41.0, -3.05);

    glVertex3f(-34.0, 42.0, -3.05);
    glVertex3f(-36.0, 42.0, -3.05);

    glVertex3f(-40.0, 43.0, -3.05);
    glVertex3f(-43.0, 43.0, -3.05);

    glVertex3f(-36.0, 44.0, -3.05);
    glVertex3f(-34.0, 44.0, -3.05);

    glVertex3f(-27.0, 44.0, -3.05);
    glVertex3f(-24.0, 44.0, -3.05);

    glVertex3f(-40.0, 45.0, -3.05);
    glVertex3f(-30.0, 45.0, -3.05);

    glVertex3f(-43.0, 46.0, -3.05);
    glVertex3f(-38.0, 46.0, -3.05);
        //L2
    glVertex3f(-43.0, 56.0, -3.05);
    glVertex3f(-38.0, 56.0, -3.05);

    glVertex3f(-43.0, 57.0, -3.05);
    glVertex3f(-38.0, 57.0, -3.05);

    glVertex3f(-40.0, 58.0, -3.05);
    glVertex3f(-30.0, 58.0, -3.05);

    glVertex3f(-39.0, 59.0, -3.05);
    glVertex3f(-28.0, 59.0, -3.05);

    glVertex3f(-34.0, 60.0, -3.05);
    glVertex3f(-36.0, 60.0, -3.05);

    glVertex3f(-40.0, 60.0, -3.05);
    glVertex3f(-43.0, 60.0, -3.05);

    glVertex3f(-36.0, 61.0, -3.05);
    glVertex3f(-34.0, 61.0, -3.05);

    glVertex3f(-30.0, 62.0, -3.05);
    glVertex3f(-27.0, 62.0, -3.05);
        //L3
    glVertex3f(-43.0, 73.0, -3.05);
    glVertex3f(-38.0, 73.0, -3.05);

    glVertex3f(-40.0, 74.0, -3.05);
    glVertex3f(-30.0, 74.0, -3.05);

    glVertex3f(-34.0, 75.0, -3.05);
    glVertex3f(-36.0, 75.0, -3.05);

    glVertex3f(-36.0, 76.0, -3.05);
    glVertex3f(-34.0, 76.0, -3.05);

    glVertex3f(-39.0, 77.0, -3.05);
    glVertex3f(-28.0, 77.0, -3.05);

    glVertex3f(-40.0, 77.0, -3.05);
    glVertex3f(-43.0, 77.0, -3.05);

    glVertex3f(-30.0, 78.0, -3.05);
    glVertex3f(-27.0, 78.0, -3.05);

    glVertex3f(-43.0, 79.0, -3.05);
    glVertex3f(-38.0, 79.0, -3.05);

    glEnd();

    //depan5
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-44.0, -30.0, 15.0);
    glVertex3f(-44.0, 30.0, 15.0);
    glVertex3f(-24.0, 30.0, 15.0);
    glVertex3f(-24.0, -30.0, 15.0);
    glEnd();
    //belakang5
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-44.0, -30.0, -4.0);
    glVertex3f(-44.0, 30.0, -4.0);
    glVertex3f(-24.0, 30.0, -4.0);
    glVertex3f(-24.0, -30.0, -4.0);
    glEnd();
    //kanan5
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-24.0, 30.0, 15.0);
    glVertex3f(-24.0, -30.0, 15.0);
    glVertex3f(-24.0, -30.0, -4.0);
    glVertex3f(-24.0, 30.0, -4.0);
    glEnd();
    //kiri5
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-44.0, 30.0, 15.0);
    glVertex3f(-44.0, -30.0, 15.0);
    glVertex3f(-44.0, -30.0, -4.0);
    glVertex3f(-44.0, 30.0, -4.0);
    glEnd();

    //atas5
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 28.0, 15.0);
    glVertex3f(-24.0, 28.0, 15.0);
    glVertex3f(-24.0, 28.0, -4.0);
    glVertex3f(-44.0, 28.0, -4.0);
    glEnd();

      //sekat antar lantai depan kiri bawah
       //depan
    glLineWidth(1.0); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-44.05, -18.0, 15.05);
    glVertex3f(-23.95, -18.0, 15.05);

    glVertex3f(-44.05, -6.0, 15.05);
    glVertex3f(-23.95, -6.0, 15.05);

    glVertex3f(-44.05, 6.0, 15.05);
    glVertex3f(-23.95, 6.0, 15.05);

    glVertex3f(-44.05, 18.0, 15.05);
    glVertex3f(-23.95, 18.0, 15.05);

       //kiri
    glVertex3f(-44.05, -18.0, -4.05);
    glVertex3f(-44.05, -18.0, 15.05);

    glVertex3f(-44.05, -6.0, -4.05);
    glVertex3f(-44.05, -6.0, 15.05);

    glVertex3f(-44.05, 6.0, -4.05);
    glVertex3f(-44.05, 6.0, 15.05);

    glVertex3f(-44.05, 18.0, -4.05);
    glVertex3f(-44.05, 18.0, 15.05);
        //kanan
    glVertex3f(-24.05, -18.0, -4.05);
    glVertex3f(-24.05, -18.0, 15.05);

    glVertex3f(-24.05, -6.0, -4.05);
    glVertex3f(-24.05, -6.0, 15.05);

    glVertex3f(-24.05, 6.0, -4.05);
    glVertex3f(-24.05, 6.0, 15.05);

    glVertex3f(-24.05, 18.0, -4.05);
    glVertex3f(-24.05, 18.0, 15.05);
        //belakang
    glVertex3f(-44.05, -18.0, -4.05);
    glVertex3f(-23.95, -18.0, -4.05);

    glVertex3f(-44.05, -6.0, -4.05);
    glVertex3f(-23.95, -6.0, -4.05);

    glVertex3f(-44.05, 6.0, -4.05);
    glVertex3f(-23.95, 6.0, -4.05);

    glVertex3f(-44.05, 18.0, -4.05);
    glVertex3f(-23.95, 18.0, -4.05);

    glEnd();

    //jendela lantai depan kiri bawah
       //depan
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(-43.0, -27.0, 15.05);
    glVertex3f(-38.0, -27.0, 15.05);

    glVertex3f(-39.0, -26.0, 15.05);
    glVertex3f(-28.0, -26.0, 15.05);

    glVertex3f(-34.0, -25.0, 15.05);
    glVertex3f(-36.0, -25.0, 15.05);

    glVertex3f(-40.0, -24.0, 15.05);
    glVertex3f(-43.0, -24.0, 15.05);

    glVertex3f(-36.0, -23.0, 15.05);
    glVertex3f(-34.0, -23.0, 15.05);

    glVertex3f(-27.0, -23.0, 15.05);
    glVertex3f(-24.0, -23.0, 15.05);

    glVertex3f(-40.0, -22.0, 15.05);
    glVertex3f(-30.0, -22.0, 15.05);

    glVertex3f(-43.0, -21.0, 15.05);
    glVertex3f(-38.0, -21.0, 15.05);
        //L2
    glVertex3f(-43.0, -14.0, 15.05);
    glVertex3f(-38.0, -14.0, 15.05);

    glVertex3f(-43.0, -13.0, 15.05);
    glVertex3f(-38.0, -13.0, 15.05);

    glVertex3f(-40.0, -12.0, 15.05);
    glVertex3f(-30.0, -12.0, 15.05);

    glVertex3f(-39.0, -11.0, 15.05);
    glVertex3f(-28.0, -11.0, 15.05);

    glVertex3f(-34.0, -10.0, 15.05);
    glVertex3f(-36.0, -10.0, 15.05);

    glVertex3f(-40.0, -10.0, 15.05);
    glVertex3f(-43.0, -10.0, 15.05);

    glVertex3f(-36.0, -9.0, 15.05);
    glVertex3f(-34.0, -9.0, 15.05);

    glVertex3f(-30.0, -8.0, 15.05);
    glVertex3f(-27.0, -8.0, 15.05);
        //L3
    glVertex3f(-43.0, -3.0, 15.05);
    glVertex3f(-38.0, -3.0, 15.05);

    glVertex3f(-40.0, -2.0, 15.05);
    glVertex3f(-30.0, -2.0, 15.05);

    glVertex3f(-34.0, -1.0, 15.05);
    glVertex3f(-36.0, -1.0, 15.05);

    glVertex3f(-36.0, 0.0, 15.05);
    glVertex3f(-34.0, 0.0, 15.05);

    glVertex3f(-39.0, 1.0, 15.05);
    glVertex3f(-28.0, 1.0, 15.05);

    glVertex3f(-40.0, 1.0, 15.05);
    glVertex3f(-43.0, 1.0, 15.05);

    glVertex3f(-30.0, 2.0, 15.05);
    glVertex3f(-27.0, 2.0, 15.05);

    glVertex3f(-43.0, 3.0, 15.05);
    glVertex3f(-38.0, 3.0, 15.05);
        //L4
    glVertex3f(-43.0, 10.0, 15.05);
    glVertex3f(-38.0, 10.0, 15.05);

    glVertex3f(-43.0, 11.0, 15.05);
    glVertex3f(-38.0, 11.0, 15.05);

    glVertex3f(-40.0, 12.0, 15.05);
    glVertex3f(-30.0, 12.0, 15.05);

    glVertex3f(-39.0, 11.0, 15.05);
    glVertex3f(-28.0, 11.0, 15.05);

    glVertex3f(-34.0, 13.0, 15.05);
    glVertex3f(-36.0, 13.0, 15.05);

    glVertex3f(-40.0, 14.0, 15.05);
    glVertex3f(-43.0, 14.0, 15.05);

    glVertex3f(-36.0, 15.0, 15.05);
    glVertex3f(-34.0, 15.0, 15.05);

    glVertex3f(-30.0, 15.0, 15.05);
    glVertex3f(-27.0, 15.0, 15.05);
        //L5
    glVertex3f(-43.0, 22.0, 15.05);
    glVertex3f(-38.0, 22.0, 15.05);

    glVertex3f(-40.0, 23.0, 15.05);
    glVertex3f(-30.0, 23.0, 15.05);

    glVertex3f(-34.0, 24.0, 15.05);
    glVertex3f(-36.0, 24.0, 15.05);

    glVertex3f(-36.0, 25.0, 15.05);
    glVertex3f(-34.0, 25.0, 15.05);

    glVertex3f(-39.0, 26.0, 15.05);
    glVertex3f(-28.0, 26.0, 15.05);

    glVertex3f(-40.0, 26.0, 15.05);
    glVertex3f(-43.0, 26.0, 15.05);

    glVertex3f(-30.0, 27.0, 15.05);
    glVertex3f(-27.0, 27.0, 15.05);

    glVertex3f(-43.0, 24.0, 15.05);
    glVertex3f(-38.0, 24.0, 15.05);
       //kiri
        //L1
    glVertex3f(-44.05, -27.0, 14.05);
    glVertex3f(-44.05, -27.0, 14.05);

    glVertex3f(-44.05, -26.0, 13.05);
    glVertex3f(-44.05, -26.0, 1.05);

    glVertex3f(-44.05, -25.0, 14.05);
    glVertex3f(-44.05, -25.0, 10.05);

    glVertex3f(-44.05, -24.0, 14.05);
    glVertex3f(-44.05, -24.0, -2.05);

    glVertex3f(-44.05, -23.0, 12.05);
    glVertex3f(-44.05, -23.0, 10.05);

    glVertex3f(-44.05, -23.0, 3.05);
    glVertex3f(-44.05, -23.0, 1.05);

    glVertex3f(-44.05, -22.0, 10.05);
    glVertex3f(-44.05, -22.0, 5.05);

    glVertex3f(-44.05, -21.0, 4.05);
    glVertex3f(-44.05, -21.0, 1.05);
        //L2
    glVertex3f(-44.05, -14.0, 4.05);
    glVertex3f(-44.05, -14.0, 1.05);

    glVertex3f(-44.05, -13.0, 14.05);
    glVertex3f(-44.05, -13.0, 14.05);

    glVertex3f(-44.05, -12.0, 13.05);
    glVertex3f(-44.05, -12.0, 1.05);

    glVertex3f(-44.05, -11.0, 14.05);
    glVertex3f(-44.05, -11.0, 10.05);

    glVertex3f(-44.05, -10.0, 14.05);
    glVertex3f(-44.05, -10.0, -2.05);

    glVertex3f(-44.05, -9.0, 3.05);
    glVertex3f(-44.05, -9.0, 1.05);

    glVertex3f(-44.05, -9.0, 10.05);
    glVertex3f(-44.05, -9.0, 5.05);

    glVertex3f(-44.05, -12.0, 12.05);
    glVertex3f(-44.05, -12.0, 10.05);

        //L3
    glVertex3f(-44.05, -2.0, 4.05);
    glVertex3f(-44.05, -2.0, 1.05);

    glVertex3f(-44.05, -1.0, 14.05);
    glVertex3f(-44.05, -1.0, 14.05);

    glVertex3f(-44.05, 0.0, 13.05);
    glVertex3f(-44.05, 0.0, 1.05);

    glVertex3f(-44.05, 1.0, 14.05);
    glVertex3f(-44.05, 1.0, 10.05);

    glVertex3f(-44.05, 2.0, 14.05);
    glVertex3f(-44.05, 2.0, -2.05);

    glVertex3f(-44.05, 3.0, 3.05);
    glVertex3f(-44.05, 3.0, 1.05);

    glVertex3f(-44.05, 3.0, 10.05);
    glVertex3f(-44.05, 3.0, 5.05);

    glVertex3f(-44.05, 4.0, 12.05);
    glVertex3f(-44.05, 4.0, 10.05);
        //L4
    glVertex3f(-44.05, 10.0, 4.05);
    glVertex3f(-44.05, 10.0, 1.05);

    glVertex3f(-44.05, 11.0, 14.05);
    glVertex3f(-44.05, 11.0, 14.05);

    glVertex3f(-44.05, 12.0, 13.05);
    glVertex3f(-44.05, 12.0, 1.05);

    glVertex3f(-44.05, 11.0, 14.05);
    glVertex3f(-44.05, 11.0, 10.05);

    glVertex3f(-44.05, 13.0, 14.05);
    glVertex3f(-44.05, 13.0, -2.05);

    glVertex3f(-44.05, 14.0, 3.05);
    glVertex3f(-44.05, 14.0, 1.05);

    glVertex3f(-44.05, 15.0, 10.05);
    glVertex3f(-44.05, 15.0, 5.05);

    glVertex3f(-44.05, 16.0, 12.05);
    glVertex3f(-44.05, 16.0, 10.05);

        //L5
    glVertex3f(-44.05, 22.0, 4.05);
    glVertex3f(-44.05, 22.0, 1.05);

    glVertex3f(-44.05, 23.0, 14.05);
    glVertex3f(-44.05, 23.0, 14.05);

    glVertex3f(-44.05, 24.0, 13.05);
    glVertex3f(-44.05, 24.0, 1.05);

    glVertex3f(-44.05, 25.0, 14.05);
    glVertex3f(-44.05, 25.0, 10.05);

    glVertex3f(-44.05, 26.0, 14.05);
    glVertex3f(-44.05, 26.0, -2.05);

    glVertex3f(-44.05, 26.0, 3.05);
    glVertex3f(-44.05, 26.0, 1.05);

    glVertex3f(-44.05, 27.0, 10.05);
    glVertex3f(-44.05, 27.0, 5.05);

    glVertex3f(-44.05, 22.0, 12.05);
    glVertex3f(-44.05, 22.0, 10.05);
       //belakang
        //L1
    glVertex3f(-43.0, 40.0, -3.05);
    glVertex3f(-38.0, 40.0, -3.05);

    glVertex3f(-39.0, 41.0, -3.05);
    glVertex3f(-28.0, 41.0, -3.05);

    glVertex3f(-34.0, 42.0, -3.05);
    glVertex3f(-36.0, 42.0, -3.05);

    glVertex3f(-40.0, 43.0, -3.05);
    glVertex3f(-43.0, 43.0, -3.05);

    glVertex3f(-36.0, 44.0, -3.05);
    glVertex3f(-34.0, 44.0, -3.05);

    glVertex3f(-27.0, 44.0, -3.05);
    glVertex3f(-24.0, 44.0, -3.05);

    glVertex3f(-40.0, 45.0, -3.05);
    glVertex3f(-30.0, 45.0, -3.05);

    glVertex3f(-43.0, 46.0, -3.05);
    glVertex3f(-38.0, 46.0, -3.05);
        //L2
    glVertex3f(-43.0, 56.0, -3.05);
    glVertex3f(-38.0, 56.0, -3.05);

    glVertex3f(-43.0, 57.0, -3.05);
    glVertex3f(-38.0, 57.0, -3.05);

    glVertex3f(-40.0, 58.0, -3.05);
    glVertex3f(-30.0, 58.0, -3.05);

    glVertex3f(-39.0, 59.0, -3.05);
    glVertex3f(-28.0, 59.0, -3.05);

    glVertex3f(-34.0, 60.0, -3.05);
    glVertex3f(-36.0, 60.0, -3.05);

    glVertex3f(-40.0, 60.0, -3.05);
    glVertex3f(-43.0, 60.0, -3.05);

    glVertex3f(-36.0, 61.0, -3.05);
    glVertex3f(-34.0, 61.0, -3.05);

    glVertex3f(-30.0, 62.0, -3.05);
    glVertex3f(-27.0, 62.0, -3.05);
        //L3
    glVertex3f(-43.0, 73.0, -3.05);
    glVertex3f(-38.0, 73.0, -3.05);

    glVertex3f(-40.0, 74.0, -3.05);
    glVertex3f(-30.0, 74.0, -3.05);

    glVertex3f(-34.0, 75.0, -3.05);
    glVertex3f(-36.0, 75.0, -3.05);

    glVertex3f(-36.0, 76.0, -3.05);
    glVertex3f(-34.0, 76.0, -3.05);

    glVertex3f(-39.0, 77.0, -3.05);
    glVertex3f(-28.0, 77.0, -3.05);

    glVertex3f(-40.0, 77.0, -3.05);
    glVertex3f(-43.0, 77.0, -3.05);

    glVertex3f(-30.0, 78.0, -3.05);
    glVertex3f(-27.0, 78.0, -3.05);

    glVertex3f(-43.0, 79.0, -3.05);
    glVertex3f(-38.0, 79.0, -3.05);

    glEnd();  glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 50);

    //depan6
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-44.0, 90.0, 15.0);
    glVertex3f(-44.0, 140.0, 15.0);
    glVertex3f(-24.0, 140.0, 15.0);
    glVertex3f(-24.0, 90.0, 15.0);
    glEnd();
    //belakang6
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-44.0, 90.0, -4.0);
    glVertex3f(-44.0, 140.0, -4.0);
    glVertex3f(-24.0, 140.0, -4.0);
    glVertex3f(-24.0, 90.0, -4.0);
    glEnd();
    //kanan6
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-24.0, 140.0, 15.0);
    glVertex3f(-24.0, 90.0, 15.0);
    glVertex3f(-24.0, 90.0, -4.0);
    glVertex3f(-24.0, 140.0, -4.0);
    glEnd();
    //kiri6
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-44.0, 140.0, 15.0);
    glVertex3f(-44.0, 90.0, 15.0);
    glVertex3f(-44.0, 90.0, -4.0);
    glVertex3f(-44.0, 140.0, -4.0);
    glEnd();

    //atas bawah 6
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 138.0, 15.0);
    glVertex3f(-24.0, 138.0, 15.0);
    glVertex3f(-24.0, 138.0, -4.0);
    glVertex3f(-44.0, 138.0, -4.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 92.0, 15.0);
    glVertex3f(-24.0, 92.0, 15.0);
    glVertex3f(-24.0, 92.0, -4.0);
    glVertex3f(-44.0, 92.0, -4.0);
    glEnd();

    //sekat antar lantai depan kiri atas
    glLineWidth(1.0); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-44.0, 100.0, 15.05);
    glVertex3f(-24.0, 100.0, 15.05);

    glVertex3f(-44.05, 110.0, 15.05);
    glVertex3f(-24.0, 110.0, 15.05);

    glVertex3f(-44.05, 120.0, 15.05);
    glVertex3f(-24.0, 120.0, 15.05);

    glVertex3f(-44.05, 130.0, 15.05);
    glVertex3f(-24.0, 130.0, 15.05);

       //kiri
    glVertex3f(-44.05, 100.0, -4.05);
    glVertex3f(-44.05, 100.0, 15.05);

    glVertex3f(-44.05, 110.0, -4.05);
    glVertex3f(-44.05, 110.0, 15.05);

    glVertex3f(-44.05, 120.0, -4.05);
    glVertex3f(-44.05, 120.0, 15.05);

    glVertex3f(-44.05, 130.0, -4.05);
    glVertex3f(-44.05, 130.0, 15.05);
        //kanan
    glVertex3f(-24.05, 100.0, -4.05);
    glVertex3f(-24.05, 100.0, 15.05);

    glVertex3f(-24.05, 110.0, -4.05);
    glVertex3f(-24.05, 110.0, 15.05);

    glVertex3f(-24.05, 120.0, -4.05);
    glVertex3f(-24.05, 120.0, 15.05);

    glVertex3f(-24.05, 130.0, -4.05);
    glVertex3f(-24.05, 130.0, 15.05);
        //belakang
    glVertex3f(-44.05, 100.0, -4.05);
    glVertex3f(-23.95, 100.0, -4.05);

    glVertex3f(-44.05, 110.0, -4.05);
    glVertex3f(-23.95, 110.0, -4.05);

    glVertex3f(-44.05, 120.0, -4.05);
    glVertex3f(-23.95, 120.0, -4.05);

    glVertex3f(-44.05, 130.0, -4.05);
    glVertex3f(-23.95, 130.0, -4.05);

    glEnd();

    //jendela lantai depan kiri atas
       //depan
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(-43.0, 92.0, 15.05);
    glVertex3f(-38.0, 92.0, 15.05);

    glVertex3f(-39.0, 93.0, 15.05);
    glVertex3f(-28.0, 93.0, 15.05);

    glVertex3f(-34.0, 94.0, 15.05);
    glVertex3f(-36.0, 94.0, 15.05);

    glVertex3f(-40.0, 95.0, 15.05);
    glVertex3f(-43.0, 95.0, 15.05);

    glVertex3f(-36.0, 95.0, 15.05);
    glVertex3f(-34.0, 95.0, 15.05);

    glVertex3f(-27.0, 96.0, 15.05);
    glVertex3f(-24.0, 96.0, 15.05);

    glVertex3f(-40.0, 97.0, 15.05);
    glVertex3f(-30.0, 97.0, 15.05);

    glVertex3f(-43.0, 98.0, 15.05);
    glVertex3f(-38.0, 98.0, 15.05);
        //L2
    glVertex3f(-43.0, 102.0, 15.05);
    glVertex3f(-38.0, 102.0, 15.05);

    glVertex3f(-43.0, 103.0, 15.05);
    glVertex3f(-38.0, 103.0, 15.05);

    glVertex3f(-40.0, 104.0, 15.05);
    glVertex3f(-30.0, 104.0, 15.05);

    glVertex3f(-39.0, 105.0, 15.05);
    glVertex3f(-28.0, 105.0, 15.05);

    glVertex3f(-34.0, 106.0, 15.05);
    glVertex3f(-36.0, 106.0, 15.05);

    glVertex3f(-40.0, 107.0, 15.05);
    glVertex3f(-43.0, 107.0, 15.05);

    glVertex3f(-36.0, 108.0, 15.05);
    glVertex3f(-34.0, 108.0, 15.05);

    glVertex3f(-30.0, 108.0, 15.05);
    glVertex3f(-27.0, 108.0, 15.05);
        //L3
    glVertex3f(-43.0, 112.0, 15.05);
    glVertex3f(-38.0, 112.0, 15.05);

    glVertex3f(-40.0, 113.0, 15.05);
    glVertex3f(-30.0, 113.0, 15.05);

    glVertex3f(-34.0, 114.0, 15.05);
    glVertex3f(-36.0, 114.0, 15.05);

    glVertex3f(-36.0, 115.0, 15.05);
    glVertex3f(-34.0, 115.0, 15.05);

    glVertex3f(-39.0, 116.0, 15.05);
    glVertex3f(-28.0, 116.0, 15.05);

    glVertex3f(-40.0, 116.0, 15.05);
    glVertex3f(-43.0, 116.0, 15.05);

    glVertex3f(-30.0, 117.0, 15.05);
    glVertex3f(-27.0, 117.0, 15.05);

    glVertex3f(-43.0, 118.0, 15.05);
    glVertex3f(-38.0, 118.0, 15.05);
        //L4
    glVertex3f(-43.0, 122.0, 15.05);
    glVertex3f(-38.0, 122.0, 15.05);

    glVertex3f(-43.0, 123.0, 15.05);
    glVertex3f(-38.0, 123.0, 15.05);

    glVertex3f(-40.0, 124.0, 15.05);
    glVertex3f(-30.0, 124.0, 15.05);

    glVertex3f(-39.0, 123.0, 15.05);
    glVertex3f(-28.0, 123.0, 15.05);

    glVertex3f(-34.0, 124.0, 15.05);
    glVertex3f(-36.0, 124.0, 15.05);

    glVertex3f(-40.0, 125.0, 15.05);
    glVertex3f(-43.0, 125.0, 15.05);

    glVertex3f(-36.0, 126.0, 15.05);
    glVertex3f(-34.0, 126.0, 15.05);

    glVertex3f(-30.0, 127.0, 15.05);
    glVertex3f(-27.0, 127.0, 15.05);
        //L5
    glVertex3f(-43.0, 132.0, 15.05);
    glVertex3f(-38.0, 132.0, 15.05);

    glVertex3f(-40.0, 133.0, 15.05);
    glVertex3f(-30.0, 133.0, 15.05);

    glVertex3f(-34.0, 134.0, 15.05);
    glVertex3f(-36.0, 134.0, 15.05);

    glVertex3f(-36.0, 135.0, 15.05);
    glVertex3f(-34.0, 135.0, 15.05);

    glVertex3f(-39.0, 136.0, 15.05);
    glVertex3f(-28.0, 136.0, 15.05);

    glVertex3f(-40.0, 136.0, 15.05);
    glVertex3f(-43.0, 136.0, 15.05);

    glVertex3f(-30.0, 137.0, 15.05);
    glVertex3f(-27.0, 137.0, 15.05);

    glVertex3f(-43.0, 138.0, 15.05);
    glVertex3f(-38.0, 138.0, 15.05);
       //kiri
        //L1
    glVertex3f(-44.05, 92.0, 14.05);
    glVertex3f(-44.05, 92.0, 14.05);

    glVertex3f(-44.05, 93.0, 13.05);
    glVertex3f(-44.05, 93.0, 1.05);

    glVertex3f(-44.05, 94.0, 14.05);
    glVertex3f(-44.05, 94.0, 10.05);

    glVertex3f(-44.05, 95.0, 14.05);
    glVertex3f(-44.05, 95.0, -2.05);

    glVertex3f(-44.05, 95.0, 12.05);
    glVertex3f(-44.05, 95.0, 10.05);

    glVertex3f(-44.05, 96.0, 3.05);
    glVertex3f(-44.05, 96.0, 1.05);

    glVertex3f(-44.05, 97.0, 10.05);
    glVertex3f(-44.05, 97.0, 5.05);

    glVertex3f(-44.05, 98.0, 4.05);
    glVertex3f(-44.05, 98.0, 1.05);
        //L2
    glVertex3f(-44.05, 102.0, 4.05);
    glVertex3f(-44.05, 102.0, 1.05);

    glVertex3f(-44.05, 103.0, 14.05);
    glVertex3f(-44.05, 103.0, 14.05);

    glVertex3f(-44.05, 104.0, 13.05);
    glVertex3f(-44.05, 104.0, 1.05);

    glVertex3f(-44.05, 105.0, 14.05);
    glVertex3f(-44.05, 105.0, 10.05);

    glVertex3f(-44.05, 106.0, 14.05);
    glVertex3f(-44.05, 106.0, -2.05);

    glVertex3f(-44.05, 107.0, 3.05);
    glVertex3f(-44.05, 107.0, 1.05);

    glVertex3f(-44.05, 108.0, 10.05);
    glVertex3f(-44.05, 108.0, 5.05);

    glVertex3f(-44.05, 107.0, 12.05);
    glVertex3f(-44.05, 107.0, 10.05);

        //L3
    glVertex3f(-44.05, 112.0, 4.05);
    glVertex3f(-44.05, 112.0, 1.05);

    glVertex3f(-44.05, 113.0, 14.05);
    glVertex3f(-44.05, 113.0, 14.05);

    glVertex3f(-44.05, 114.0, 13.05);
    glVertex3f(-44.05, 114.0, 1.05);

    glVertex3f(-44.05, 115.0, 14.05);
    glVertex3f(-44.05, 115.0, 10.05);

    glVertex3f(-44.05, 116.0, 14.05);
    glVertex3f(-44.05, 116.0, -2.05);

    glVertex3f(-44.05, 117.0, 3.05);
    glVertex3f(-44.05, 117.0, 1.05);

    glVertex3f(-44.05, 117.0, 10.05);
    glVertex3f(-44.05, 117.0, 5.05);

    glVertex3f(-44.05, 118.0, 12.05);
    glVertex3f(-44.05, 118.0, 10.05);
        //L4
    glVertex3f(-44.05, 122.0, 4.05);
    glVertex3f(-44.05, 122.0, 1.05);

    glVertex3f(-44.05, 123.0, 14.05);
    glVertex3f(-44.05, 123.0, 14.05);

    glVertex3f(-44.05, 124.0, 13.05);
    glVertex3f(-44.05, 124.0, 1.05);

    glVertex3f(-44.05, 125.0, 14.05);
    glVertex3f(-44.05, 125.0, 10.05);

    glVertex3f(-44.05, 126.0, 14.05);
    glVertex3f(-44.05, 126.0, -2.05);

    glVertex3f(-44.05, 127.0, 3.05);
    glVertex3f(-44.05, 127.0, 1.05);

    glVertex3f(-44.05, 128.0, 10.05);
    glVertex3f(-44.05, 128.0, 5.05);

    glVertex3f(-44.05, 127.0, 12.05);
    glVertex3f(-44.05, 127.0, 10.05);

        //L5
    glVertex3f(-44.05, 132.0, 4.05);
    glVertex3f(-44.05, 132.0, 1.05);

    glVertex3f(-44.05, 133.0, 14.05);
    glVertex3f(-44.05, 133.0, 14.05);

    glVertex3f(-44.05, 134.0, 13.05);
    glVertex3f(-44.05, 134.0, 1.05);

    glVertex3f(-44.05, 135.0, 14.05);
    glVertex3f(-44.05, 135.0, 10.05);

    glVertex3f(-44.05, 136.0, 14.05);
    glVertex3f(-44.05, 136.0, -2.05);

    glVertex3f(-44.05, 136.0, 3.05);
    glVertex3f(-44.05, 136.0, 1.05);

    glVertex3f(-44.05, 137.0, 10.05);
    glVertex3f(-44.05, 137.0, 5.05);

    glVertex3f(-44.05, 138.0, 12.05);
    glVertex3f(-44.05, 138.0, 10.05);
       //belakang
        //L1
    glVertex3f(-43.0, 92.0, -4.05);
    glVertex3f(-38.0, 92.0, -4.05);

    glVertex3f(-39.0, 93.0, -4.05);
    glVertex3f(-28.0, 93.0, -4.05);

    glVertex3f(-34.0, 94.0, -4.05);
    glVertex3f(-36.0, 94.0, -4.05);

    glVertex3f(-40.0, 95.0, -4.05);
    glVertex3f(-43.0, 95.0, -4.05);

    glVertex3f(-36.0, 96.0, -4.05);
    glVertex3f(-34.0, 96.0, -4.05);

    glVertex3f(-27.0, 96.0, -4.05);
    glVertex3f(-24.0, 96.0, -4.05);

    glVertex3f(-40.0, 97.0, -4.05);
    glVertex3f(-30.0, 97.0, -4.05);

    glVertex3f(-43.0, 98.0, -4.05);
    glVertex3f(-38.0, 98.0, -4.05);
        //L2
    glVertex3f(-43.0, 102.0, -4.05);
    glVertex3f(-38.0, 102.0, -4.05);

    glVertex3f(-43.0, 103.0, -4.05);
    glVertex3f(-38.0, 103.0, -4.05);

    glVertex3f(-40.0, 104.0, -4.05);
    glVertex3f(-30.0, 104.0, -4.05);

    glVertex3f(-39.0, 105.0, -4.05);
    glVertex3f(-28.0, 105.0, -4.05);

    glVertex3f(-34.0, 106.0, -4.05);
    glVertex3f(-36.0, 106.0, -4.05);

    glVertex3f(-40.0, 106.0, -4.05);
    glVertex3f(-43.0, 106.0, -4.05);

    glVertex3f(-36.0, 107.0, -4.05);
    glVertex3f(-34.0, 107.0, -4.05);

    glVertex3f(-30.0, 108.0, -4.05);
    glVertex3f(-27.0, 108.0, -4.05);
        //L3
    glVertex3f(-43.0, 112.0, -4.05);
    glVertex3f(-38.0, 112.0, -4.05);

    glVertex3f(-40.0, 113.0, -4.05);
    glVertex3f(-30.0, 113.0, -4.05);

    glVertex3f(-34.0, 114.0, -4.05);
    glVertex3f(-36.0, 114.0, -4.05);

    glVertex3f(-36.0, 115.0, -4.05);
    glVertex3f(-34.0, 115.0, -4.05);

    glVertex3f(-39.0, 116.0, -4.05);
    glVertex3f(-28.0, 116.0, -4.05);

    glVertex3f(-40.0, 116.0, -4.05);
    glVertex3f(-43.0, 116.0, -4.05);

    glVertex3f(-30.0, 117.0, -4.05);
    glVertex3f(-27.0, 117.0, -4.05);

    glVertex3f(-43.0, 118.0, -4.05);
    glVertex3f(-38.0, 118.0, -4.05);
        //L4
    glVertex3f(-43.0, 122.0, -4.05);
    glVertex3f(-38.0, 122.0, -4.05);

    glVertex3f(-39.0, 123.0, -4.05);
    glVertex3f(-28.0, 123.0, -4.05);

    glVertex3f(-34.0, 124.0, -4.05);
    glVertex3f(-36.0, 124.0, -4.05);

    glVertex3f(-40.0, 125.0, -4.05);
    glVertex3f(-43.0, 125.0, -4.05);

    glVertex3f(-36.0, 125.0, -4.05);
    glVertex3f(-34.0, 125.0, -4.05);

    glVertex3f(-27.0, 126.0, -4.05);
    glVertex3f(-24.0, 126.0, -4.05);

    glVertex3f(-40.0, 127.0, -4.05);
    glVertex3f(-30.0, 127.0, -4.05);

    glVertex3f(-43.0, 128.0, -4.05);
    glVertex3f(-38.0, 128.0, -4.05);
        //L5
    glVertex3f(-43.0, 132.0, -4.05);
    glVertex3f(-38.0, 132.0, -4.05);

    glVertex3f(-43.0, 133.0, -4.05);
    glVertex3f(-38.0, 133.0, -4.05);

    glVertex3f(-40.0, 134.0, -4.05);
    glVertex3f(-30.0, 134.0, -4.05);

    glVertex3f(-39.0, 135.0, -4.05);
    glVertex3f(-28.0, 135.0, -4.05);

    glVertex3f(-34.0, 136.0, -4.05);
    glVertex3f(-36.0, 136.0, -4.05);

    glVertex3f(-40.0, 136.0, -4.05);
    glVertex3f(-43.0, 136.0, -4.05);

    glVertex3f(-36.0, 137.0, -4.05);
    glVertex3f(-34.0, 137.0, -4.05);

    glVertex3f(-30.0, 138.0, -4.05);
    glVertex3f(-27.0, 138.0, -4.05);

    glEnd();

    //depan7
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-44.0, -30.0, -20.0);
    glVertex3f(-44.0, 30.0, -20.0);
    glVertex3f(-24.0, 30.0, -20.0);
    glVertex3f(-24.0, -30.0, -20.0);
    glEnd();
    //belakang7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-44.0, -30.0, -40.0);
    glVertex3f(-44.0, 30.0, -40.0);
    glVertex3f(-24.0, 30.0, -40.0);
    glVertex3f(-24.0, -30.0, -40.0);
    glEnd();
    //kanan7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-24.0, 30.0, -20.0);
    glVertex3f(-24.0, -30.0, -20.0);
    glVertex3f(-24.0, -30.0, -40.0);
    glVertex3f(-24.0, 30.0, -40.0);
    glEnd();
    //kiri7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-44.0, 30.0, -20.0);
    glVertex3f(-44.0, -30.0, -20.0);
    glVertex3f(-44.0, -30.0, -40.0);
    glVertex3f(-44.0, 30.0, -40.0);
    glEnd();

    //atas7
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 28.0, -20.0);
    glVertex3f(-24.0, 28.0, -20.0);
    glVertex3f(-24.0, 28.0, -40.0);
    glVertex3f(-44.0, 28.0, -40.0);
    glEnd();

      //sekat antar lantai belakang kiri bawah
       //depan
    glLineWidth(1.0); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-44.05, -18.0, -20.05);
    glVertex3f(-23.95, -18.0, -20.05);

    glVertex3f(-44.05, -6.0, -20.05);
    glVertex3f(-23.95, -6.0, -20.05);

    glVertex3f(-44.05, 6.0, -20.05);
    glVertex3f(-23.95, 6.0, -20.05);

    glVertex3f(-44.05, 18.0, -20.05);
    glVertex3f(-23.95, 18.0, -20.05);

       //kiri
    glVertex3f(-44.05, -18.0, -40.05);
    glVertex3f(-44.05, -18.0, -20.05);

    glVertex3f(-44.05, -6.0, -40.05);
    glVertex3f(-44.05, -6.0, -20.05);

    glVertex3f(-44.05, 6.0, -40.05);
    glVertex3f(-44.05, 6.0, -20.05);

    glVertex3f(-44.05, 18.0, -40.05);
    glVertex3f(-44.05, 18.0, -20.05);
        //kanan
    glVertex3f(-24.05, -18.0, -40.05);
    glVertex3f(-24.05, -18.0, -20.05);

    glVertex3f(-24.05, -6.0, -40.05);
    glVertex3f(-24.05, -6.0, -20.05);

    glVertex3f(-24.05, 6.0, -40.05);
    glVertex3f(-24.05, 6.0, -20.05);

    glVertex3f(-24.05, 18.0, -40.05);
    glVertex3f(-24.05, 18.0, -20.05);
        //belakang
    glVertex3f(-44.05, -18.0, -40.05);
    glVertex3f(-23.95, -18.0, -40.05);

    glVertex3f(-44.05, -6.0, -40.05);
    glVertex3f(-23.95, -6.0, -40.05);

    glVertex3f(-44.05, 6.0, -40.05);
    glVertex3f(-23.95, 6.0, -40.05);

    glVertex3f(-44.05, 18.0, -40.05);
    glVertex3f(-23.95, 18.0, -40.05);

    glEnd();

      //jendela lantai kiri belakang bawah
       //belakang
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(-43.0, -27.0, -40.05);
    glVertex3f(-38.0, -27.0, -40.05);

    glVertex3f(-39.0, -26.0, -40.05);
    glVertex3f(-28.0, -26.0, -40.05);

    glVertex3f(-34.0, -25.0, -40.05);
    glVertex3f(-36.0, -25.0, -40.05);

    glVertex3f(-40.0, -24.0, -40.05);
    glVertex3f(-43.0, -24.0, -40.05);

    glVertex3f(-36.0, -23.0, -40.05);
    glVertex3f(-34.0, -23.0, -40.05);

    glVertex3f(-27.0, -23.0, -40.05);
    glVertex3f(-24.0, -23.0, -40.05);

    glVertex3f(-40.0, -22.0, -40.05);
    glVertex3f(-30.0, -22.0, -40.05);

    glVertex3f(-43.0, -21.0, -40.05);
    glVertex3f(-38.0, -21.0, -40.05);
        //L2
    glVertex3f(-43.0, -14.0, -40.05);
    glVertex3f(-38.0, -14.0, -40.05);

    glVertex3f(-43.0, -13.0, -40.05);
    glVertex3f(-38.0, -13.0, -40.05);

    glVertex3f(-40.0, -12.0, -40.05);
    glVertex3f(-30.0, -12.0, -40.05);

    glVertex3f(-39.0, -11.0, -40.05);
    glVertex3f(-28.0, -11.0, -40.05);

    glVertex3f(-34.0, -10.0, -40.05);
    glVertex3f(-36.0, -10.0, -40.05);

    glVertex3f(-40.0, -10.0, -40.05);
    glVertex3f(-43.0, -10.0, -40.05);

    glVertex3f(-36.0, -9.0, -40.05);
    glVertex3f(-34.0, -9.0, -40.05);

    glVertex3f(-30.0, -8.0, -40.05);
    glVertex3f(-27.0, -8.0, -40.05);
        //L3
    glVertex3f(-43.0, -3.0, -40.05);
    glVertex3f(-38.0, -3.0, -40.05);

    glVertex3f(-40.0, -2.0, -40.05);
    glVertex3f(-30.0, -2.0, -40.05);

    glVertex3f(-34.0, -1.0, -40.05);
    glVertex3f(-36.0, -1.0, -40.05);

    glVertex3f(-36.0, 0.0, -40.05);
    glVertex3f(-34.0, 0.0, -40.05);

    glVertex3f(-39.0, 1.0, -40.05);
    glVertex3f(-28.0, 1.0, -40.05);

    glVertex3f(-40.0, 1.0, -40.05);
    glVertex3f(-43.0, 1.0, -40.05);

    glVertex3f(-30.0, 2.0, -40.05);
    glVertex3f(-27.0, 2.0, -40.05);

    glVertex3f(-43.0, 3.0, -40.05);
    glVertex3f(-38.0, 3.0, -40.05);
        //L4
    glVertex3f(-43.0, 10.0, -40.05);
    glVertex3f(-38.0, 10.0, -40.05);

    glVertex3f(-43.0, 11.0, -40.05);
    glVertex3f(-38.0, 11.0, -40.05);

    glVertex3f(-40.0, 12.0, -40.05);
    glVertex3f(-30.0, 12.0, -40.05);

    glVertex3f(-39.0, 11.0, -40.05);
    glVertex3f(-28.0, 11.0, -40.05);

    glVertex3f(-34.0, 13.0, -40.05);
    glVertex3f(-36.0, 13.0, -40.05);

    glVertex3f(-40.0, 14.0, -40.05);
    glVertex3f(-43.0, 14.0, -40.05);

    glVertex3f(-36.0, 15.0, -40.05);
    glVertex3f(-34.0, 15.0, -40.05);

    glVertex3f(-30.0, 15.0, -40.05);
    glVertex3f(-27.0, 15.0, -40.05);
        //L5
    glVertex3f(-43.0, 22.0, -40.05);
    glVertex3f(-38.0, 22.0, -40.05);

    glVertex3f(-40.0, 23.0, -40.05);
    glVertex3f(-30.0, 23.0, -40.05);

    glVertex3f(-34.0, 24.0, -40.05);
    glVertex3f(-36.0, 24.0, -40.05);

    glVertex3f(-36.0, 25.0, -40.05);
    glVertex3f(-34.0, 25.0, -40.05);

    glVertex3f(-39.0, 26.0, -40.05);
    glVertex3f(-28.0, 26.0, -40.05);

    glVertex3f(-40.0, 26.0, -40.05);
    glVertex3f(-43.0, 26.0, -40.05);

    glVertex3f(-30.0, 27.0, -40.05);
    glVertex3f(-27.0, 27.0, -40.05);

    glVertex3f(-43.0, 24.0, -40.05);
    glVertex3f(-38.0, 24.0, -40.05);
       //kiri
        //L1
    glVertex3f(-44.05, -27.0, -37.05);
    glVertex3f(-44.05, -27.0, -34.05);

    glVertex3f(-44.05, -26.0, -35.05);
    glVertex3f(-44.05, -26.0, -30.05);

    glVertex3f(-44.05, -25.0, -22.05);
    glVertex3f(-44.05, -25.0, -25.05);

    glVertex3f(-44.05, -24.0, -30.05);
    glVertex3f(-44.05, -24.0, -20.05);

    glVertex3f(-44.05, -23.0, -25.05);
    glVertex3f(-44.05, -23.0, -28.05);

    glVertex3f(-44.05, -23.0, -30.05);
    glVertex3f(-44.05, -23.0, -32.05);

    glVertex3f(-44.05, -22.0, -25.05);
    glVertex3f(-44.05, -22.0, -30.05);

    glVertex3f(-44.05, -21.0, -28.05);
    glVertex3f(-44.05, -21.0, -30.05);
        //L2
    glVertex3f(-44.05, -14.0, -35.05);
    glVertex3f(-44.05, -14.0, -38.05);

    glVertex3f(-44.05, -13.0, -36.05);
    glVertex3f(-44.05, -13.0, -25.05);

    glVertex3f(-44.05, -12.0, -23.05);
    glVertex3f(-44.05, -12.0, -25.05);

    glVertex3f(-44.05, -11.0, -25.05);
    glVertex3f(-44.05, -11.0, -30.05);

    glVertex3f(-44.05, -10.0, -23.05);
    glVertex3f(-44.05, -10.0, -26.05);

    glVertex3f(-44.05, -9.0, -31.05);
    glVertex3f(-44.05, -9.0, -33.05);

    glVertex3f(-44.05, -9.0, -28.05);
    glVertex3f(-44.05, -9.0, -22.05);

    glVertex3f(-44.05, -12.0, -38.05);
    glVertex3f(-44.05, -12.0, -32.05);

        //L3
    glVertex3f(-44.05, -2.0, -35.05);
    glVertex3f(-44.05, -2.0, -38.05);

    glVertex3f(-44.05, -1.0, -32.05);
    glVertex3f(-44.05, -1.0, -29.05);

    glVertex3f(-44.05, 0.0, -25.05);
    glVertex3f(-44.05, 0.0, -32.05);

    glVertex3f(-44.05, 1.0, -38.05);
    glVertex3f(-44.05, 1.0, -30.05);

    glVertex3f(-44.05, 2.0, -23.05);
    glVertex3f(-44.05, 2.0, -26.05);

    glVertex3f(-44.05, 3.0, -36.05);
    glVertex3f(-44.05, 3.0, -34.05);

    glVertex3f(-44.05, 3.0, -30.05);
    glVertex3f(-44.05, 3.0, -35.05);

    glVertex3f(-44.05, 4.0, -24.05);
    glVertex3f(-44.05, 4.0, -29.05);
        //L4
    glVertex3f(-44.05, 10.0, -32.05);
    glVertex3f(-44.05, 10.0, -37.05);

    glVertex3f(-44.05, 11.0, -32.05);
    glVertex3f(-44.05, 11.0, -35.05);

    glVertex3f(-44.05, 12.0, -23.05);
    glVertex3f(-44.05, 12.0, -35.05);

    glVertex3f(-44.05, 11.0, -25.05);
    glVertex3f(-44.05, 11.0, -29.05);

    glVertex3f(-44.05, 13.0, -33.05);
    glVertex3f(-44.05, 13.0, -30.05);

    glVertex3f(-44.05, 14.0, -27.05);
    glVertex3f(-44.05, 14.0, -22.05);

    glVertex3f(-44.05, 15.0, -36.05);
    glVertex3f(-44.05, 15.0, -32.05);

    glVertex3f(-44.05, 16.0, -28.05);
    glVertex3f(-44.05, 16.0, -30.05);

        //L5
    glVertex3f(-44.05, 22.0, -25.05);
    glVertex3f(-44.05, 22.0, -30.05);

    glVertex3f(-44.05, 23.0, -35.05);
    glVertex3f(-44.05, 23.0, -38.05);

    glVertex3f(-44.05, 24.0, -25.05);
    glVertex3f(-44.05, 24.0, -38.05);

    glVertex3f(-44.05, 25.0, -23.05);
    glVertex3f(-44.05, 25.0, -30.05);

    glVertex3f(-44.05, 26.0, -27.05);
    glVertex3f(-44.05, 26.0, -23.05);

    glVertex3f(-44.05, 26.0, -26.05);
    glVertex3f(-44.05, 26.0, -30.05);

    glVertex3f(-44.05, 27.0, -38.05);
    glVertex3f(-44.05, 27.0, -36.05);

    glVertex3f(-44.05, 22.0, -33.05);
    glVertex3f(-44.05, 22.0, -27.05);

    glEnd();

    //depan8
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-46.0, 35.0, -23.0);
    glVertex3f(-46.0, 85.0, -23.0);
    glVertex3f(-24.1, 85.0, -23.0);
    glVertex3f(-24.1, 35.0, -23.0);
    glEnd();
    //belakang8
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-46.0, 35.0, -43.0);
    glVertex3f(-46.0, 85.0, -43.0);
    glVertex3f(-24.1, 85.0, -43.0);
    glVertex3f(-24.1, 35.0, -43.0);
    glEnd();
    //kanan8
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-24.1, 85.0, -23.0);
    glVertex3f(-24.1, 35.0, -23.0);
    glVertex3f(-24.1, 35.0, -43.0);
    glVertex3f(-24.1, 85.0, -43.0);
    glEnd();
    //kiri8
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-46.0, 85.0, -23.0);
    glVertex3f(-46.0, 35.0, -23.0);
    glVertex3f(-46.0, 35.0, -43.0);
    glVertex3f(-46.0, 85.0, -43.0);
    glEnd();

    //atas bawah 8
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-46.0, 83.0, -23.0);
    glVertex3f(-24.0, 83.0, -23.0);
    glVertex3f(-24.0, 83.0, -43.0);
    glVertex3f(-46.0, 83.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-46.0, 37.0, -23.0);
    glVertex3f(-24.0, 37.0, -23.0);
    glVertex3f(-24.0, 37.0, -43.0);
    glVertex3f(-46.0, 37.0, -43.0);
    glEnd();

    //sekat antar lantai belakang kiri tengah
       //depan
    glLineWidth(1.0); //jarak per lantai 16.5 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-46.0, 51.5, -23.05);
    glVertex3f(-24.0, 51.5, -23.05);

    glVertex3f(-46.0, 68.0, -23.05);
    glVertex3f(-24.0, 68.0, -23.05);

       //kiri
    glVertex3f(-24.1, 51.5, -43.0);
    glVertex3f(-24.1, 51.5, -23.0);

    glVertex3f(-24.1, 68.0, -43.0);
    glVertex3f(-24.1, 68.0, -23.0);

        //kiri
    glVertex3f(-46.05, 51.5, -43.0);
    glVertex3f(-46.05, 51.5, -23.0);

    glVertex3f(-46.05, 68.0, -43.0);
    glVertex3f(-46.05, 68.0, -23.0);

        //belakang
    glVertex3f(-46.0, 51.5, -43.05);
    glVertex3f(-24.0, 51.5, -43.05);

    glVertex3f(-46.0, 68.0, -43.05);
    glVertex3f(-24.0, 68.0, -43.05);

    glEnd();

    //jendela lantai belakang kiri tengah
       //depan
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(-43.0, 40.0, -23.05);
    glVertex3f(-38.0, 40.0, -23.05);

    glVertex3f(-39.0, 41.0, -23.05);
    glVertex3f(-28.0, 41.0, -23.05);

    glVertex3f(-34.0, 42.0, -23.05);
    glVertex3f(-36.0, 42.0, -23.05);

    glVertex3f(-40.0, 43.0, -23.05);
    glVertex3f(-43.0, 43.0, -23.05);

    glVertex3f(-36.0, 44.0, -23.05);
    glVertex3f(-34.0, 44.0, -23.05);

    glVertex3f(-27.0, 44.0, -23.05);
    glVertex3f(-24.0, 44.0, -23.05);

    glVertex3f(-40.0, 45.0, -23.05);
    glVertex3f(-30.0, 45.0, -23.05);

    glVertex3f(-43.0, 46.0, -23.05);
    glVertex3f(-38.0, 46.0, -23.05);
        //L2
    glVertex3f(-43.0, 56.0, -23.05);
    glVertex3f(-38.0, 56.0, -23.05);

    glVertex3f(-43.0, 57.0, -23.05);
    glVertex3f(-38.0, 57.0, -23.05);

    glVertex3f(-40.0, 58.0, -23.05);
    glVertex3f(-30.0, 58.0, -23.05);

    glVertex3f(-39.0, 59.0, -23.05);
    glVertex3f(-28.0, 59.0, -23.05);

    glVertex3f(-34.0, 60.0, -23.05);
    glVertex3f(-36.0, 60.0, -23.05);

    glVertex3f(-40.0, 60.0, -23.05);
    glVertex3f(-43.0, 60.0, -23.05);

    glVertex3f(-36.0, 61.0, -23.05);
    glVertex3f(-34.0, 61.0, -23.05);

    glVertex3f(-30.0, 62.0, -23.05);
    glVertex3f(-27.0, 62.0, -23.05);
        //L3
    glVertex3f(-43.0, 73.0, -23.05);
    glVertex3f(-38.0, 73.0, -23.05);

    glVertex3f(-40.0, 74.0, -23.05);
    glVertex3f(-30.0, 74.0, -23.05);

    glVertex3f(-34.0, 75.0, -23.05);
    glVertex3f(-36.0, 75.0, -23.05);

    glVertex3f(-36.0, 76.0, -23.05);
    glVertex3f(-34.0, 76.0, -23.05);

    glVertex3f(-39.0, 77.0, -23.05);
    glVertex3f(-28.0, 77.0, -23.05);

    glVertex3f(-40.0, 77.0, -23.05);
    glVertex3f(-43.0, 77.0, -23.05);

    glVertex3f(-30.0, 78.0, -23.05);
    glVertex3f(-27.0, 78.0, -23.05);

    glVertex3f(-43.0, 79.0, -23.05);
    glVertex3f(-38.0, 79.0, -23.05);

       //kiri
        //L1
    glVertex3f(-46.05, 40.0, -40.05);
    glVertex3f(-46.05, 40.0, -37.05);

    glVertex3f(-46.05, 41.0, -38.05);
    glVertex3f(-46.05, 41.0, -33.05);

    glVertex3f(-46.05, 42.0, -25.05);
    glVertex3f(-46.05, 42.0, -28.05);

    glVertex3f(-46.05, 43.0, -33.05);
    glVertex3f(-46.05, 43.0, -23.05);

    glVertex3f(-46.05, 44.0, -28.05);
    glVertex3f(-46.05, 44.0, -31.05);

    glVertex3f(-46.05, 44.0, -33.05);
    glVertex3f(-46.05, 44.0, -35.05);

    glVertex3f(-46.05, 45.0, -28.05);
    glVertex3f(-46.05, 45.0, -33.05);

    glVertex3f(-46.05, 46.0, -31.05);
    glVertex3f(-46.05, 46.0, -33.05);
        //L2
    glVertex3f(-46.05, 56.0, -38.05);
    glVertex3f(-46.05, 56.0, -41.05);

    glVertex3f(-46.05, 57.0, -39.05);
    glVertex3f(-46.05, 57.0, -28.05);

    glVertex3f(-46.05, 58.0, -26.05);
    glVertex3f(-46.05, 58.0, -28.05);

    glVertex3f(-46.05, 59.0, -28.05);
    glVertex3f(-46.05, 59.0, -33.05);

    glVertex3f(-46.05, 60.0, -26.05);
    glVertex3f(-46.05, 60.0, -29.05);

    glVertex3f(-46.05, 60.0, -34.05);
    glVertex3f(-46.05, 60.0, -36.05);

    glVertex3f(-46.05, 61.0, -31.05);
    glVertex3f(-46.05, 61.0, -25.05);

    glVertex3f(-46.05, 62.0, -41.05);
    glVertex3f(-46.05, 62.0, -35.05);

        //L3
    glVertex3f(-46.05, 73.0, -38.05);
    glVertex3f(-46.05, 73.0, -41.05);

    glVertex3f(-46.05, 74.0, -35.05);
    glVertex3f(-46.05, 74.0, -32.05);

    glVertex3f(-46.05, 75.0, -28.05);
    glVertex3f(-46.05, 75.0, -35.05);

    glVertex3f(-46.05, 75.0, -41.05);
    glVertex3f(-46.05, 75.0, -33.05);

    glVertex3f(-46.05, 76.0, -26.05);
    glVertex3f(-46.05, 76.0, -29.05);

    glVertex3f(-46.05, 77.0, -39.05);
    glVertex3f(-46.05, 77.0, -37.05);

    glVertex3f(-46.05, 78.0, -33.05);
    glVertex3f(-46.05, 78.0, -38.05);

    glVertex3f(-46.05, 79.0, -27.05);
    glVertex3f(-46.05, 79.0, -31.05);

       //belakang
        //L1
    glVertex3f(-43.0, 40.0, -43.05);
    glVertex3f(-38.0, 40.0, -43.05);

    glVertex3f(-39.0, 41.0, -43.05);
    glVertex3f(-28.0, 41.0, -43.05);

    glVertex3f(-34.0, 42.0, -43.05);
    glVertex3f(-36.0, 42.0, -43.05);

    glVertex3f(-40.0, 43.0, -43.05);
    glVertex3f(-43.0, 43.0, -43.05);

    glVertex3f(-36.0, 44.0, -43.05);
    glVertex3f(-34.0, 44.0, -43.05);

    glVertex3f(-27.0, 44.0, -43.05);
    glVertex3f(-24.0, 44.0, -43.05);

    glVertex3f(-40.0, 45.0, -43.05);
    glVertex3f(-30.0, 45.0, -43.05);

    glVertex3f(-43.0, 46.0, -43.05);
    glVertex3f(-38.0, 46.0, -43.05);
        //L2
    glVertex3f(-43.0, 56.0, -43.05);
    glVertex3f(-38.0, 56.0, -43.05);

    glVertex3f(-43.0, 57.0, -43.05);
    glVertex3f(-38.0, 57.0, -43.05);

    glVertex3f(-40.0, 58.0, -43.05);
    glVertex3f(-30.0, 58.0, -43.05);

    glVertex3f(-39.0, 59.0, -43.05);
    glVertex3f(-28.0, 59.0, -43.05);

    glVertex3f(-34.0, 60.0, -43.05);
    glVertex3f(-36.0, 60.0, -43.05);

    glVertex3f(-40.0, 60.0, -43.05);
    glVertex3f(-43.0, 60.0, -43.05);

    glVertex3f(-36.0, 61.0, -43.05);
    glVertex3f(-34.0, 61.0, -43.05);

    glVertex3f(-30.0, 62.0, -43.05);
    glVertex3f(-27.0, 62.0, -43.05);
        //L3
    glVertex3f(-43.0, 73.0, -43.05);
    glVertex3f(-38.0, 73.0, -43.05);

    glVertex3f(-40.0, 74.0, -43.05);
    glVertex3f(-30.0, 74.0, -43.05);

    glVertex3f(-34.0, 75.0, -43.05);
    glVertex3f(-36.0, 75.0, -43.05);

    glVertex3f(-36.0, 76.0, -43.05);
    glVertex3f(-34.0, 76.0, -43.05);

    glVertex3f(-39.0, 77.0, -43.05);
    glVertex3f(-28.0, 77.0, -43.05);

    glVertex3f(-40.0, 77.0, -43.05);
    glVertex3f(-43.0, 77.0, -43.05);

    glVertex3f(-30.0, 78.0, -43.05);
    glVertex3f(-27.0, 78.0, -43.05);

    glVertex3f(-43.0, 79.0, -43.05);
    glVertex3f(-38.0, 79.0, -43.05);

    glEnd();


    //bawag pendek
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-24.0, 20.0, -40.0);
    glVertex3f(-100.0, 20.0, -40.0);
    glVertex3f(-100.0, 20.0, 15.0);
    glVertex3f(-24.0, 20.0, 15.0);
    glEnd();
    //bawah pendek bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-24.0, -29.1, -40.0);
    glVertex3f(-100.0, -29.1, -40.0);
    glVertex3f(-100.0, -29.1, 15.0);
    glVertex3f(-24.0, -29.1, 15.0);
    glEnd();
    //bawah pendek depan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-100.0, 20.0, 15.0);
    glVertex3f(-100.0, -30.0, 15.0);
    glVertex3f(-100.0, -30.0, -40.0);
    glVertex3f(-100.0, 20.0, -40.0);
    glEnd();
    //bawah pendek kanan
     glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-44.0, -30.0, -40.0);
    glVertex3f(-44.0, 20.0, -40.0);
    glVertex3f(-100.0, 20.0, -40.0);
    glVertex3f(-100.0, -30.0, -40.0);
    glEnd();
    //bawah kiri
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-44.0, -30.0, 15.0);
    glVertex3f(-44.0, 20.0, 15.0);
    glVertex3f(-100.0, 20.0, 15.0);
    glVertex3f(-100.0, -30.0, 15.0);
    glEnd();

    //depan9
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-44.0, 90.0, -20.0);
    glVertex3f(-44.0, 160.0, -20.0);
    glVertex3f(-24.0, 160.0, -20.0);
    glVertex3f(-24.0, 90.0, -20.0);
    glEnd();
    //belakang9
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-44.0, 90.0, -40.0);
    glVertex3f(-44.0, 160.0, -40.0);
    glVertex3f(-24.0, 160.0, -40.0);
    glVertex3f(-24.0, 90.0, -40.0);
    glEnd();
    //kanan9
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-24.0, 160.0, -20.0);
    glVertex3f(-24.0, 90.0, -20.0);
    glVertex3f(-24.0, 90.0, -40.0);
    glVertex3f(-24.0, 160.0, -40.0);
    glEnd();
    //kiri9
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-44.0, 160.0, -20.0);
    glVertex3f(-44.0, 90.0, -20.0);
    glVertex3f(-44.0, 90.0, -40.0);
    glVertex3f(-44.0, 160.0, -40.0);
    glEnd();

    //atas bawah 9
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 158.0, -20.0);
    glVertex3f(-24.0, 158.0, -20.0);
    glVertex3f(-24.0, 158.0, -40.0);
    glVertex3f(-44.0, 158.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-44.0, 92.0, -20.0);
    glVertex3f(-24.0, 92.0, -20.0);
    glVertex3f(-24.0, 92.0, -40.0);
    glVertex3f(-44.0, 92.0, -40.0);
    glEnd();

    //sekat antar lantai belakang kiri atas
       //depan
    glLineWidth(1.0); //jarak per lantai 14 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(-44.05, 104.0, -20.05);
    glVertex3f(-23.95, 104.0, -20.05);

    glVertex3f(-44.05, 118.0, -20.05);
    glVertex3f(-23.95, 118.0, -20.05);

    glVertex3f(-44.05, 132.0, -20.05);
    glVertex3f(-23.95, 132.0, -20.05);

    glVertex3f(-44.05, 146.0, -20.05);
    glVertex3f(-23.95, 146.0, -20.05);

       //kiri
    glVertex3f(-44.05, 104.0, -40.05);
    glVertex3f(-44.05, 104.0, -20.05);

    glVertex3f(-44.05, 118.0, -40.05);
    glVertex3f(-44.05, 118.0, -20.05);

    glVertex3f(-44.05, 132.0, -40.05);
    glVertex3f(-44.05, 132.0, -20.05);

    glVertex3f(-44.05, 146.0, -40.05);
    glVertex3f(-44.05, 146.0, -20.05);
        //kanan
    glVertex3f(-24.05, 104.0, -40.05);
    glVertex3f(-24.05, 104.0, -20.05);

    glVertex3f(-24.05, 118.0, -40.05);
    glVertex3f(-24.05, 118.0, -20.05);

    glVertex3f(-24.05, 132.0, -40.05);
    glVertex3f(-24.05, 132.0, -20.05);

    glVertex3f(-24.05, 146.0, -40.05);
    glVertex3f(-24.05, 146.0, -20.05);
        //belakang
    glVertex3f(-44.05, 104.0, -40.05);
    glVertex3f(-23.95, 104.0, -40.05);

    glVertex3f(-44.05, 118.0, -40.05);
    glVertex3f(-23.95, 118.0, -40.05);

    glVertex3f(-44.05, 132.0, -40.05);
    glVertex3f(-23.95, 132.0, -40.05);

    glVertex3f(-44.05, 146.0, -40.05);
    glVertex3f(-23.95, 146.0, -40.05);

    glEnd();

      //jendela lantai belakang kiri atas
       //belakang
    glLineWidth(2.5); //jarak per lantai 16.5 y, jarak dr tembok 3 x jadi kanan+kiri = 6x
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(-43.0, 94.0, -40.05);
    glVertex3f(-38.0, 94.0, -40.05);

    glVertex3f(-39.0, 95.0, -40.05);
    glVertex3f(-28.0, 95.0, -40.05);

    glVertex3f(-34.0, 96.0, -40.05);
    glVertex3f(-36.0, 96.0, -40.05);

    glVertex3f(-40.0, 97.0, -40.05);
    glVertex3f(-43.0, 97.0, -40.05);

    glVertex3f(-36.0, 98.0, -40.05);
    glVertex3f(-34.0, 98.0, -40.05);

    glVertex3f(-27.0, 99.0, -40.05);
    glVertex3f(-24.0, 99.0, -40.05);

    glVertex3f(-40.0, 100.0, -40.05);
    glVertex3f(-30.0, 100.0, -40.05);

    glVertex3f(-43.0, 99.0, -40.05);
    glVertex3f(-38.0, 99.0, -40.05);
        //L2
    glVertex3f(-43.0, 108.0, -40.05);
    glVertex3f(-38.0, 108.0, -40.05);

    glVertex3f(-43.0, 109.0, -40.05);
    glVertex3f(-38.0, 109.0, -40.05);

    glVertex3f(-40.0, 110.0, -40.05);
    glVertex3f(-30.0, 110.0, -40.05);

    glVertex3f(-39.0, 111.0, -40.05);
    glVertex3f(-28.0, 111.0, -40.05);

    glVertex3f(-34.0, 112.0, -40.05);
    glVertex3f(-36.0, 112.0, -40.05);

    glVertex3f(-40.0, 113.0, -40.05);
    glVertex3f(-43.0, 113.0, -40.05);

    glVertex3f(-36.0, 114.0, -40.05);
    glVertex3f(-34.0, 114.0, -40.05);

    glVertex3f(-30.0, 109.0, -40.05);
    glVertex3f(-27.0, 109.0, -40.05);
        //L3
    glVertex3f(-43.0, 122.0, -40.05);
    glVertex3f(-38.0, 122.0, -40.05);

    glVertex3f(-40.0, 123.0, -40.05);
    glVertex3f(-30.0, 123.0, -40.05);

    glVertex3f(-34.0, 124.0, -40.05);
    glVertex3f(-36.0, 124.0, -40.05);

    glVertex3f(-36.0, 125.0, -40.05);
    glVertex3f(-34.0, 125.0, -40.05);

    glVertex3f(-39.0, 126.0, -40.05);
    glVertex3f(-28.0, 126.0, -40.05);

    glVertex3f(-40.0, 127.0, -40.05);
    glVertex3f(-43.0, 127.0, -40.05);

    glVertex3f(-30.0, 128.0, -40.05);
    glVertex3f(-27.0, 128.0, -40.05);

    glVertex3f(-43.0, 128.0, -40.05);
    glVertex3f(-38.0, 128.0, -40.05);
        //L4
    glVertex3f(-43.0, 136.0, -40.05);
    glVertex3f(-38.0, 136.0, -40.05);

    glVertex3f(-43.0, 137.0, -40.05);
    glVertex3f(-38.0, 137.0, -40.05);

    glVertex3f(-40.0, 138.0, -40.05);
    glVertex3f(-30.0, 138.0, -40.05);

    glVertex3f(-39.0, 139.0, -40.05);
    glVertex3f(-28.0, 139.0, -40.05);

    glVertex3f(-34.0, 140.0, -40.05);
    glVertex3f(-36.0, 140.0, -40.05);

    glVertex3f(-40.0, 141.0, -40.05);
    glVertex3f(-43.0, 141.0, -40.05);

    glVertex3f(-36.0, 142.0, -40.05);
    glVertex3f(-34.0, 142.0, -40.05);

    glVertex3f(-30.0, 136.0, -40.05);
    glVertex3f(-27.0, 136.0, -40.05);
        //L5
    glVertex3f(-43.0, 150.0, -40.05);
    glVertex3f(-38.0, 150.0, -40.05);

    glVertex3f(-40.0, 151.0, -40.05);
    glVertex3f(-30.0, 151.0, -40.05);

    glVertex3f(-34.0, 152.0, -40.05);
    glVertex3f(-36.0, 152.0, -40.05);

    glVertex3f(-36.0, 153.0, -40.05);
    glVertex3f(-34.0, 153.0, -40.05);

    glVertex3f(-39.0, 154.0, -40.05);
    glVertex3f(-28.0, 154.0, -40.05);

    glVertex3f(-40.0, 155.0, -40.05);
    glVertex3f(-43.0, 155.0, -40.05);

    glVertex3f(-30.0, 156.0, -40.05);
    glVertex3f(-27.0, 156.0, -40.05);

    glVertex3f(-43.0, 156.0, -40.05);
    glVertex3f(-38.0, 156.0, -40.05);
      //depan
       //L1
    glVertex3f(-43.0, 94.0, -20.05);
    glVertex3f(-38.0, 94.0, -20.05);

    glVertex3f(-39.0, 95.0, -20.05);
    glVertex3f(-28.0, 95.0, -20.05);

    glVertex3f(-34.0, 96.0, -20.05);
    glVertex3f(-36.0, 96.0, -20.05);

    glVertex3f(-40.0, 97.0, -20.05);
    glVertex3f(-43.0, 97.0, -20.05);

    glVertex3f(-36.0, 98.0, -20.05);
    glVertex3f(-34.0, 98.0, -20.05);

    glVertex3f(-27.0, 99.0, -20.05);
    glVertex3f(-24.0, 99.0, -20.05);

    glVertex3f(-40.0, 100.0, -20.05);
    glVertex3f(-30.0, 100.0, -20.05);

    glVertex3f(-43.0, 99.0, -20.05);
    glVertex3f(-38.0, 99.0, -20.05);
        //L2
    glVertex3f(-43.0, 108.0, -20.05);
    glVertex3f(-38.0, 108.0, -20.05);

    glVertex3f(-43.0, 109.0, -20.05);
    glVertex3f(-38.0, 109.0, -20.05);

    glVertex3f(-40.0, 110.0, -20.05);
    glVertex3f(-30.0, 110.0, -20.05);

    glVertex3f(-39.0, 111.0, -20.05);
    glVertex3f(-28.0, 111.0, -20.05);

    glVertex3f(-34.0, 112.0, -20.05);
    glVertex3f(-36.0, 112.0, -20.05);

    glVertex3f(-40.0, 113.0, -20.05);
    glVertex3f(-43.0, 113.0, -20.05);

    glVertex3f(-36.0, 114.0, -20.05);
    glVertex3f(-34.0, 114.0, -20.05);

    glVertex3f(-30.0, 109.0, -20.05);
    glVertex3f(-27.0, 109.0, -20.05);
        //L3
    glVertex3f(-43.0, 122.0, -20.05);
    glVertex3f(-38.0, 122.0, -20.05);

    glVertex3f(-40.0, 123.0, -20.05);
    glVertex3f(-30.0, 123.0, -20.05);

    glVertex3f(-34.0, 124.0, -20.05);
    glVertex3f(-36.0, 124.0, -20.05);

    glVertex3f(-36.0, 125.0, -20.05);
    glVertex3f(-34.0, 125.0, -20.05);

    glVertex3f(-39.0, 126.0, -20.05);
    glVertex3f(-28.0, 126.0, -20.05);

    glVertex3f(-40.0, 127.0, -20.05);
    glVertex3f(-43.0, 127.0, -20.05);

    glVertex3f(-30.0, 128.0, -20.05);
    glVertex3f(-27.0, 128.0, -20.05);

    glVertex3f(-43.0, 128.0, -20.05);
    glVertex3f(-38.0, 128.0, -20.05);
        //L4
    glVertex3f(-43.0, 136.0, -20.05);
    glVertex3f(-38.0, 136.0, -20.05);

    glVertex3f(-43.0, 137.0, -20.05);
    glVertex3f(-38.0, 137.0, -20.05);

    glVertex3f(-40.0, 138.0, -20.05);
    glVertex3f(-30.0, 138.0, -20.05);

    glVertex3f(-39.0, 139.0, -20.05);
    glVertex3f(-28.0, 139.0, -20.05);

    glVertex3f(-34.0, 140.0, -20.05);
    glVertex3f(-36.0, 140.0, -20.05);

    glVertex3f(-40.0, 141.0, -20.05);
    glVertex3f(-43.0, 141.0, -20.05);

    glVertex3f(-36.0, 142.0, -20.05);
    glVertex3f(-34.0, 142.0, -20.05);

    glVertex3f(-30.0, 136.0, -20.05);
    glVertex3f(-27.0, 136.0, -20.05);
        //L5
    glVertex3f(-43.0, 150.0, -20.05);
    glVertex3f(-38.0, 150.0, -20.05);

    glVertex3f(-40.0, 151.0, -20.05);
    glVertex3f(-30.0, 151.0, -20.05);

    glVertex3f(-34.0, 152.0, -20.05);
    glVertex3f(-36.0, 152.0, -20.05);

    glVertex3f(-36.0, 153.0, -20.05);
    glVertex3f(-34.0, 153.0, -20.05);

    glVertex3f(-39.0, 154.0, -20.05);
    glVertex3f(-28.0, 154.0, -20.05);

    glVertex3f(-40.0, 155.0, -20.05);
    glVertex3f(-43.0, 155.0, -20.05);

    glVertex3f(-30.0, 156.0, -20.05);
    glVertex3f(-27.0, 156.0, -20.05);

    glVertex3f(-43.0, 156.0, -20.05);
    glVertex3f(-38.0, 156.0, -20.05);
       //kiri
        //L1
    glVertex3f(-44.05, 94.0, -37.05);
    glVertex3f(-44.05, 94.0, -34.05);

    glVertex3f(-44.05, 95.0, -35.05);
    glVertex3f(-44.05, 95.0, -30.05);

    glVertex3f(-44.05, 96.0, -22.05);
    glVertex3f(-44.05, 96.0, -25.05);

    glVertex3f(-44.05, 97.0, -30.05);
    glVertex3f(-44.05, 97.0, -20.05);

    glVertex3f(-44.05, 98.0, -25.05);
    glVertex3f(-44.05, 98.0, -28.05);

    glVertex3f(-44.05, 99.0, -30.05);
    glVertex3f(-44.05, 99.0, -32.05);

    glVertex3f(-44.05, 100.0, -25.05);
    glVertex3f(-44.05, 100.0, -30.05);

    glVertex3f(-44.05, 96.0, -28.05);
    glVertex3f(-44.05, 96.0, -30.05);
        //L2
    glVertex3f(-44.05, 108.0, -35.05);
    glVertex3f(-44.05, 108.0, -38.05);

    glVertex3f(-44.05, 109.0, -36.05);
    glVertex3f(-44.05, 109.0, -25.05);

    glVertex3f(-44.05, 110.0, -23.05);
    glVertex3f(-44.05, 110.0, -25.05);

    glVertex3f(-44.05, 111.0, -25.05);
    glVertex3f(-44.05, 111.0, -30.05);

    glVertex3f(-44.05, 112.0, -23.05);
    glVertex3f(-44.05, 112.0, -26.05);

    glVertex3f(-44.05, 113.0, -31.05);
    glVertex3f(-44.05, 113.0, -33.05);

    glVertex3f(-44.05, 114.0, -28.05);
    glVertex3f(-44.05, 114.0, -22.05);

    glVertex3f(-44.05, 114.0, -38.05);
    glVertex3f(-44.05, 114.0, -32.05);

        //L3
    glVertex3f(-44.05, 122.0, -35.05);
    glVertex3f(-44.05, 122.0, -38.05);

    glVertex3f(-44.05, 123.0, -32.05);
    glVertex3f(-44.05, 123.0, -29.05);

    glVertex3f(-44.05, 124.0, -25.05);
    glVertex3f(-44.05, 124.0, -32.05);

    glVertex3f(-44.05, 125.0, -38.05);
    glVertex3f(-44.05, 125.0, -30.05);

    glVertex3f(-44.05, 126.0, -23.05);
    glVertex3f(-44.05, 126.0, -26.05);

    glVertex3f(-44.05, 127.0, -36.05);
    glVertex3f(-44.05, 127.0, -34.05);

    glVertex3f(-44.05, 128.0, -30.05);
    glVertex3f(-44.05, 128.0, -35.05);

    glVertex3f(-44.05, 122.0, -24.05);
    glVertex3f(-44.05, 122.0, -29.05);
        //L4
    glVertex3f(-44.05, 136.0, -25.05);
    glVertex3f(-44.05, 136.0, -30.05);

    glVertex3f(-44.05, 137.0, -35.05);
    glVertex3f(-44.05, 137.0, -38.05);

    glVertex3f(-44.05, 138.0, -25.05);
    glVertex3f(-44.05, 138.0, -38.05);

    glVertex3f(-44.05, 139.0, -23.05);
    glVertex3f(-44.05, 139.0, -30.05);

    glVertex3f(-44.05, 140.0, -27.05);
    glVertex3f(-44.05, 140.0, -23.05);

    glVertex3f(-44.05, 141.0, -26.05);
    glVertex3f(-44.05, 141.0, -30.05);

    glVertex3f(-44.05, 142.0, -38.05);
    glVertex3f(-44.05, 142.0, -36.05);

    glVertex3f(-44.05, 136.0, -33.05);
    glVertex3f(-44.05, 136.0, -27.05);
        //L5
    glVertex3f(-44.05, 150.0, -32.05);
    glVertex3f(-44.05, 150.0, -37.05);

    glVertex3f(-44.05, 151.0, -32.05);
    glVertex3f(-44.05, 151.0, -35.05);

    glVertex3f(-44.05, 152.0, -23.05);
    glVertex3f(-44.05, 152.0, -35.05);

    glVertex3f(-44.05, 151.0, -25.05);
    glVertex3f(-44.05, 151.0, -29.05);

    glVertex3f(-44.05, 153.0, -33.05);
    glVertex3f(-44.05, 153.0, -30.05);

    glVertex3f(-44.05, 154.0, -27.05);
    glVertex3f(-44.05, 154.0, -22.05);

    glVertex3f(-44.05, 155.0, -36.05);
    glVertex3f(-44.05, 155.0, -32.05);

    glVertex3f(-44.05, 156.0, -28.05);
    glVertex3f(-44.05, 156.0, -30.05);

    glEnd();


    //depan10
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, 90.0, -20.0);
    glVertex3f(25.0, 140.0, -20.0);
    glVertex3f(4.0, 140.0, -20.0);
    glVertex3f(4.0, 90.0, -20.0);
    glEnd();
    //belakang10
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, 90.0, -40.0);
    glVertex3f(25.0, 140.0, -40.0);
    glVertex3f(4.0, 140.0, -40.0);
    glVertex3f(4.0, 90.0, -40.0);
    glEnd();
    //kanan10
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(4.0, 140.0, -20.0);
    glVertex3f(4.0, 90.0, -20.0);
    glVertex3f(4.0, 90.0, -40.0);
    glVertex3f(4.0, 140.0, -40.0);
    glEnd();
    //kiri10
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, 140.0, -20.0);
    glVertex3f(25.0, 90.0, -20.0);
    glVertex3f(25.0, 90.0, -40.0);
    glVertex3f(25.0, 140.0, -40.0);
    glEnd();

    //atas bawah 10
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 138.0, -20.0);
    glVertex3f(4.0, 138.0, -20.0);
    glVertex3f(4.0, 138.0, -40.0);
    glVertex3f(25.0, 138.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 92.0, -20.0);
    glVertex3f(4.0, 92.0, -20.0);
    glVertex3f(4.0, 92.0, -40.0);
    glVertex3f(25.0, 92.0, -40.0);
    glEnd();

    //sekat antar lantai belakang kanan atas
           //depan
    glLineWidth(1.0); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.1, 106.5, -19.95);
    glVertex3f(25.0, 106.5, -19.95);

    glVertex3f(4.1, 123.0, -19.95);
    glVertex3f(25.0, 123.0, -19.95);

       //kanan
    glVertex3f(4.1, 106.5, -20.0);
    glVertex3f(4.1, 106.5, -40.0);

    glVertex3f(4.1, 123.0, -20.0);
    glVertex3f(4.1, 123.0, -40.0);

       //kiri
    glVertex3f(24.95, 106.5, -20.05);
    glVertex3f(24.95, 106.5, -40.05);

    glVertex3f(24.95, 123.0, -20.05);
    glVertex3f(24.95, 123.0, -40.05);

        //belakang
    glVertex3f(4.1, 106.5, -40.05);
    glVertex3f(25.0, 106.5, -40.05);

    glVertex3f(4.1, 123.0, -40.05);
    glVertex3f(25.0, 123.0, -40.05);

    glEnd();

    //jendela lantai belakang kanan atas
       //belakang
    glLineWidth(2.5); //jarak per lantai 16.5 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(13.1, 98.0, -40.05);
    glVertex3f(10.0, 98.0, -40.05);

    glVertex3f(9.1, 99.0, -40.05);
    glVertex3f(8.0, 99.0, -40.05);

    glVertex3f(9.1, 93.0, -40.05);
    glVertex3f(18.0, 93.0, -40.05);

    glVertex3f(10.1, 94.0, -40.05);
    glVertex3f(12.0, 94.0, -40.05);

    glVertex3f(15.1, 97.0, -40.05);
    glVertex3f(17.0, 97.0, -40.05);

    glVertex3f(12.1, 95.0, -40.05);
    glVertex3f(10.0, 95.0, -40.05);

    glVertex3f(20.1, 96.0, -40.05);
    glVertex3f(17.0, 96.0, -40.05);

    glVertex3f(8.1, 100.0, -40.05);
    glVertex3f(13.0, 100.0, -40.05);

    glVertex3f(16.1, 98.0, -40.05);
    glVertex3f(18.0, 98.0, -40.05);

    glVertex3f(15.1, 101.0, -40.05);
    glVertex3f(17.0, 101.0, -40.05);

    glVertex3f(12.1, 102.0, -40.05);
    glVertex3f(10.0, 102.0, -40.05);
        //L3
    glVertex3f(7.1, 128, -40.05);
    glVertex3f(10.0, 128, -40.05);

    glVertex3f(9.1, 129, -40.05);
    glVertex3f(15.0, 129, -40.05);

    glVertex3f(13.5, 130, -40.05);
    glVertex3f(15.5, 130, -40.05);

    glVertex3f(7.1, 131, -40.05);
    glVertex3f(22.0, 131, -40.05);

    glVertex3f(14.1, 132, -40.05);
    glVertex3f(22.0, 132, -40.05);

    glVertex3f(17.1, 133, -40.05);
    glVertex3f(13.0, 133, -40.05);
        //L2
    glVertex3f(8.1, 110.5, -40.05);
    glVertex3f(10.0, 110.5, -40.05);

    glVertex3f(10.1, 111.5, -40.05);
    glVertex3f(14.0, 111.5, -40.05);

    glVertex3f(14.1, 112.5, -40.05);
    glVertex3f(20.0, 112.5, -40.05);

    glVertex3f(10.1, 113.5, -40.05);
    glVertex3f(15.0, 113.5, -40.05);

    glVertex3f(12.1, 114.5, -40.05);
    glVertex3f(14.0, 114.5, -40.05);

    glVertex3f(10.1, 115.5, -40.05);
    glVertex3f(9.0, 115.5, -40.05);

    glVertex3f(12.1, 116.5, -40.05);
    glVertex3f(14.0, 116.5, -40.05);

    glVertex3f(10.1, 117.5,-40.05);
    glVertex3f(9.0, 117.5, -40.05);

       //kanan //ini belum bisa muncul di layar huhu :"
        //L1
    glVertex3f(4.1, 98.0, -37.05);
    glVertex3f(4.1, 98.0, -34.05);

    glVertex3f(4.05, 99.0, -35.05);
    glVertex3f(4.05, 99.0, -30.05);

    glVertex3f(4.05, 100.0, -22.05);
    glVertex3f(4.05, 100.0, -25.05);

    glVertex3f(4.05, 101.0, -30.05);
    glVertex3f(4.05, 101.0, -20.05);

    glVertex3f(4.05, 102.0, -25.05);
    glVertex3f(4.05, 102.0, -28.05);

    glVertex3f(4.05, 99.0, -30.05);
    glVertex3f(4.05, 99.0, -32.05);

    glVertex3f(4.05, 100.0, -25.05);
    glVertex3f(4.05, 100.0, -30.05);

    glVertex3f(4.05, 96.0, -28.05);
    glVertex3f(4.05, 96.0, -30.05);
        //L2
    glVertex3f(4.05, 108.0, -35.05);
    glVertex3f(4.05, 108.0, -38.05);

    glVertex3f(4.05, 109.0, -36.05);
    glVertex3f(4.05, 109.0, -25.05);

    glVertex3f(4.05, 110.0, -23.05);
    glVertex3f(4.05, 110.0, -25.05);

    glVertex3f(4.05, 111.0, -25.05);
    glVertex3f(4.05, 111.0, -30.05);

    glVertex3f(4.05, 112.0, -23.05);
    glVertex3f(4.05, 112.0, -26.05);

    glVertex3f(4.05, 113.0, -31.05);
    glVertex3f(4.05, 113.0, -33.05);

    glVertex3f(4.05, 114.0, -28.05);
    glVertex3f(4.05, 114.0, -22.05);

    glVertex3f(4.05, 114.0, -38.05);
    glVertex3f(4.05, 114.0, -32.05);

        //L3
    glVertex3f(4.05, 122.0, -35.05);
    glVertex3f(4.05, 122.0, -38.05);

    glVertex3f(4.05, 123.0, -32.05);
    glVertex3f(4.05, 123.0, -29.05);

    glVertex3f(4.05, 124.0, -25.05);
    glVertex3f(4.05, 124.0, -32.05);

    glVertex3f(4.05, 125.0, -38.05);
    glVertex3f(4.05, 125.0, -30.05);

    glVertex3f(4.05, 126.0, -23.05);
    glVertex3f(4.05, 126.0, -26.05);

    glVertex3f(4.05, 127.0, -36.05);
    glVertex3f(4.05, 127.0, -34.05);

    glVertex3f(4.05, 128.0, -30.05);
    glVertex3f(4.05, 128.0, -35.05);

    glVertex3f(4.05, 122.0, -24.05);
    glVertex3f(4.05, 122.0, -29.05);
    glEnd();


    //depan kotak 2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, -30.0, -20.0);
    glVertex3f(25.0, 30.0, -20.0);
    glVertex3f(4.0, 30.0, -20.0);
    glVertex3f(4.0, -30.0, -20.0);
    glEnd();
    //belakang11
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, -30.0, -40.0);
    glVertex3f(25.0, 30.0, -40.0);
    glVertex3f(4.0, 30.0, -40.0);
    glVertex3f(4.0, -30.0, -40.0);
    glEnd();
    //kanan11
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(4.0, 30.0, -20.0);
    glVertex3f(4.0, -30.0, -20.0);
    glVertex3f(4.0, -30.0, -40.0);
    glVertex3f(4.0, 30.0, -40.0);
    glEnd();
    //kiri11
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(25.0, 30.0, -20.0);
    glVertex3f(25.0, -30.0, -20.0);
    glVertex3f(25.0, -30.0, -40.0);
    glVertex3f(25.0, 30.0, -40.0);
    glEnd();
    //atas bawah 11 depan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 28.0, -20.0);
    glVertex3f(4.0, 28.0, -20.0);
    glVertex3f(4.0, 28.0, -40.0);
    glVertex3f(25.0, 28.0, -40.0);
    glEnd();

      //sekat antar lantai belakang kanan bawah
       //depan
    glLineWidth(1.0); //jarak per lantai 20 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.0, -1.0, -20.0);
    glVertex3f(25.0, -10.0, -20.0);

    glVertex3f(4.0, 10.0, -20.0);
    glVertex3f(25.0, 10.0, -20.0);

       //kanan
    glVertex3f(25.05, -18.0, -20.0);
    glVertex3f(25.05, -18.0, -40.0);

    glVertex3f(25.05, -6.0, -20.0);
    glVertex3f(25.05, -6.0, -40.0);

       //kiri
    glVertex3f(4.05, -18.0, -20.0);
    glVertex3f(4.05, -18.0, -40.0);

    glVertex3f(4.05, -6.0, -20.0);
    glVertex3f(4.05, -6.0, -40.0);

        //belakang
    glVertex3f(4.1, -18.0, -40.0);
    glVertex3f(25.0, -18.0, -40.0);

    glVertex3f(4.1, -6.0, -40.0);
    glVertex3f(25.0, -6.0, -40.0);



    glEnd();

      //jendela lantai belakang kanan bawah
       //belakang
    glLineWidth(2.5); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(8.1, -27.0, -40.05);
    glVertex3f(12.0, -27.0, -40.05);

    glVertex3f(10.1, -26.0, -40.05);
    glVertex3f(14.0, -26.0, -40.05);

    glVertex3f(10.1, -25.0, -40.05);
    glVertex3f(20.0, -25.0, -40.05);

    glVertex3f(7.1, -24.0, -40.05);
    glVertex3f(10.0, -24.0, -40.05);

    glVertex3f(12.1, -23.0, -40.05);
    glVertex3f(16.0, -23.0, -40.05);

    glVertex3f(19.1, -23.0, -40.05);
    glVertex3f(16.0, -23.0, -40.05);
        //L2
    glVertex3f(7.1, -14.0, -40.05);
    glVertex3f(10.0, -14.0, -40.05);

    glVertex3f(11.1, -14.0, -40.05);
    glVertex3f(7.0, -14.0, -40.05);

    glVertex3f(10.1, -13.0, -40.05);
    glVertex3f(14.0, -13.0, -40.05);

    glVertex3f(9.1, -12.0, -40.05);
    glVertex3f(18.0, -12.0, -40.05);

    glVertex3f(7.1, -11.0, -40.05);
    glVertex3f(12.0, -11.0, -40.05);

    glVertex3f(12.1, -10.0, -40.05);
    glVertex3f(14.0, -10.0, -40.05);
        //L3
    glVertex3f(8.1, -2.0, -40.05);
    glVertex3f(10.0, -2.0, -40.05);

    glVertex3f(10.1, -1.0, -40.05);
    glVertex3f(14.0, -1.0, -40.05);

    glVertex3f(14.1, -0.0, -40.05);
    glVertex3f(20.0, -0.0, -40.05);

    glVertex3f(10.1, 1.0, -40.05);
    glVertex3f(15.0, 1.0, -40.05);

    glVertex3f(12.1, 2.0, -40.05);
    glVertex3f(14.0, 2.0, -40.05);

    glVertex3f(10.1, 3.0, -40.05);
    glVertex3f(9.0, 3.0, -40.05);
        //L4
    glVertex3f(13.1, 10.0, -40.05);
    glVertex3f(10.0, 10.0, -40.05);

    glVertex3f(10.1, 11.0, -40.05);
    glVertex3f(14.0, 11.0, -40.05);

    glVertex3f(15.1, 12.0, -40.05);
    glVertex3f(20.0, 12.0, -40.05);

    glVertex3f(12.1, 12.0, -40.05);
    glVertex3f(10.0, 12.0, -40.05);

    glVertex3f(20.1, 13.0, -40.05);
    glVertex3f(17.0, 13.0, -40.05);

    glVertex3f(8.1, 13.0, -40.05);
    glVertex3f(13.0, 13.0, -40.05);

    glVertex3f(11.1, 14.0, -40.05);
    glVertex3f(14.0, 14.0, -40.05);

    glVertex3f(11.1, 15.0, -40.05);
    glVertex3f(8.0, 15.0, -40.05);
        //L5
    glVertex3f(13.1, 22.0, -40.05);
    glVertex3f(10.0, 22.0, -40.05);

    glVertex3f(9.1, 22.0, -40.05);
    glVertex3f(8.0, 22.0, -40.05);

    glVertex3f(9.1, 22.0, -40.05);
    glVertex3f(18.0, 22.0, -40.05);

    glVertex3f(10.1, 23.0, -40.05);
    glVertex3f(12.0, 23.0, -40.05);

    glVertex3f(15.1, 23.0, -40.05);
    glVertex3f(17.0, 23.0, -40.05);

    glVertex3f(12.1, 24.0, -40.05);
    glVertex3f(10.0, 24.0, -40.05);

    glVertex3f(20.1, 25.0, -40.05);
    glVertex3f(17.0, 25.0, -40.05);

    glVertex3f(8.1, 26.0, -40.05);
    glVertex3f(13.0, 26.0, -40.05);

    glVertex3f(16.1, 26.0, -40.05);
    glVertex3f(18.0, 26.0, -40.05);

       //kanan
        //L1
    glVertex3f(25.05, -27.0, -37.05);
    glVertex3f(25.05, -27.0, -34.05);

    glVertex3f(25.05, -26.0, -35.05);
    glVertex3f(25.05, -26.0, -30.05);

    glVertex3f(25.05, -25.0, -22.05);
    glVertex3f(25.05, -25.0, -25.05);

    glVertex3f(25.05, -24.0, -30.05);
    glVertex3f(25.05, -24.0, -20.05);

    glVertex3f(25.05, -23.0, -25.05);
    glVertex3f(25.05, -23.0, -28.05);

    glVertex3f(25.05, -23.0, -30.05);
    glVertex3f(25.05, -23.0, -32.05);

    glVertex3f(25.05, -22.0, -25.05);
    glVertex3f(25.05, -22.0, -30.05);

    glVertex3f(25.05, -21.0, -28.05);
    glVertex3f(25.05, -21.0, -30.05);
        //L2
    glVertex3f(25.05, -14.0, -35.05);
    glVertex3f(25.05, -14.0, -38.05);

    glVertex3f(25.05, -13.0, -36.05);
    glVertex3f(25.05, -13.0, -25.05);

    glVertex3f(25.05, -12.0, -23.05);
    glVertex3f(25.05, -12.0, -25.05);

    glVertex3f(25.05, -11.0, -25.05);
    glVertex3f(25.05, -11.0, -30.05);

    glVertex3f(25.05, -10.0, -23.05);
    glVertex3f(25.05, -10.0, -26.05);

    glVertex3f(25.05, -9.0, -31.05);
    glVertex3f(25.05, -9.0, -33.05);

    glVertex3f(25.05, -9.0, -28.05);
    glVertex3f(25.05, -9.0, -22.05);

    glVertex3f(25.05, -12.0, -38.05);
    glVertex3f(25.05, -12.0, -32.05);

        //L3
    glVertex3f(25.05, -2.0, -35.05);
    glVertex3f(25.05, -2.0, -38.05);

    glVertex3f(25.05, -1.0, -32.05);
    glVertex3f(25.05, -1.0, -29.05);

    glVertex3f(25.05, 0.0, -25.05);
    glVertex3f(25.05, 0.0, -32.05);

    glVertex3f(25.05, 1.0, -38.05);
    glVertex3f(25.05, 1.0, -30.05);

    glVertex3f(25.05, 2.0, -23.05);
    glVertex3f(25.05, 2.0, -26.05);

    glVertex3f(25.05, 3.0, -36.05);
    glVertex3f(25.05, 3.0, -34.05);

    glVertex3f(25.05, 3.0, -30.05);
    glVertex3f(25.05, 3.0, -35.05);

    glVertex3f(25.05, 4.0, -24.05);
    glVertex3f(25.05, 4.0, -29.05);
        //L4
    glVertex3f(25.05, 10.0, -32.05);
    glVertex3f(25.05, 10.0, -37.05);

    glVertex3f(25.05, 11.0, -32.05);
    glVertex3f(25.05, 11.0, -35.05);

    glVertex3f(25.05, 12.0, -23.05);
    glVertex3f(25.05, 12.0, -35.05);

    glVertex3f(25.05, 11.0, -25.05);
    glVertex3f(25.05, 11.0, -29.05);

    glVertex3f(25.05, 13.0, -33.05);
    glVertex3f(25.05, 13.0, -30.05);

    glVertex3f(25.05, 14.0, -27.05);
    glVertex3f(25.05, 14.0, -22.05);

    glVertex3f(25.05, 15.0, -36.05);
    glVertex3f(25.05, 15.0, -32.05);

    glVertex3f(25.05, 16.0, -28.05);
    glVertex3f(25.05, 16.0, -30.05);

        //L5
    glVertex3f(25.05, 22.0, -25.05);
    glVertex3f(25.05, 22.0, -30.05);

    glVertex3f(25.05, 23.0, -35.05);
    glVertex3f(25.05, 23.0, -38.05);

    glVertex3f(25.05, 24.0, -25.05);
    glVertex3f(25.05, 24.0, -38.05);

    glVertex3f(25.05, 25.0, -23.05);
    glVertex3f(25.05, 25.0, -30.05);

    glVertex3f(25.05, 26.0, -27.05);
    glVertex3f(25.05, 26.0, -23.05);

    glVertex3f(25.05, 26.0, -26.05);
    glVertex3f(25.05, 26.0, -30.05);

    glVertex3f(25.05, 27.0, -38.05);
    glVertex3f(25.05, 27.0, -36.05);

    glVertex3f(25.05, 22.0, -33.05);
    glVertex3f(25.05, 22.0, -27.05);

    glEnd();


    //depan bawah 1
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(26.0, 35.0, -23.0);
    glVertex3f(26.0, 85.0, -23.0);
    glVertex3f(4.1, 85.0, -23.0);
    glVertex3f(4.1, 35.0, -23.0);
    glEnd();
    //belakang12
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(26.0, 35.0, -43.0);
    glVertex3f(26.0, 85.0, -43.0);
    glVertex3f(4.1, 85.0, -43.0);
    glVertex3f(4.1, 35.0, -43.0);
    glEnd();
    //kanan12
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(4.1, 85.0, -23.0);
    glVertex3f(4.1, 35.0, -23.0);
    glVertex3f(4.1, 35.0, -43.0);
    glVertex3f(4.1, 85.0, -43.0);
    glEnd();
    //kiri12
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(26.0, 85.0, -23.0);
    glVertex3f(26.0, 35.0, -23.0);
    glVertex3f(26.0, 35.0, -43.0);
    glVertex3f(26.0, 85.0, -43.0);
    glEnd();
    //atas bawah 12
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(26.0, 83.0, -23.0);
    glVertex3f(4.0, 83.0, -23.0);
    glVertex3f(4.0, 83.0, -43.0);
    glVertex3f(26.0, 83.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(26.0, 37.0, -23.0);
    glVertex3f(4.0, 37.0, -23.0);
    glVertex3f(4.0, 37.0, -43.0);
    glVertex3f(26.0, 37.0, -43.0);
    glEnd();

      //sekat antar lantai belakang kanan tengah
       //depan
    glLineWidth(1.0); //jarak per lantai 20 y
    glBegin(GL_LINES);
    glColor3f(0.5019607843137255, 0.5019607843137255, 0.5019607843137255);

    glVertex3f(4.0, 51.5, -23.0);
    glVertex3f(25.0, 51.5, -23.0);

    glVertex3f(4.0, 68.0, -23.0);
    glVertex3f(25.0, 68.0, -23.0);

       //kanan
    glVertex3f(26.05, 51.5, -23.0);
    glVertex3f(26.05, 51.5, -43.0);

    glVertex3f(26.05, 68.0, -23.0);
    glVertex3f(26.05, 68.0, -43.0);

       //kiri
    glVertex3f(4.05, 51.5, -20.0);
    glVertex3f(4.05, 51.5, -40.0);

    glVertex3f(4.05, 68.0, -20.0);
    glVertex3f(4.05, 68.0, -40.0);

        //belakang
    glVertex3f(4.0, 51.5, -43.0);
    glVertex3f(25.0, 51.5, -43.0);

    glVertex3f(4.0, 68.0, -43.0);
    glVertex3f(25.0, 68.0, -43.0);

    glEnd();

      //jendela lantai belakang kanan tengah
       //belakang
    glLineWidth(2.5); //jarak per lantai 12 y
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        //L1
    glVertex3f(26.0, 35.0, -43.0);
    glVertex3f(26.0, 85.0, -43.0);
    glVertex3f(4.1, 85.0, -43.0);
    glVertex3f(4.1, 35.0, -43.0);
    glVertex3f(8.1, 40.0, -43.05);
    glVertex3f(12.0, 40.0, -43.05);

    glVertex3f(10.1, 41.0, -43.05);
    glVertex3f(14.0, 41.0, -43.05);

    glVertex3f(10.1, 42.0, -43.05);
    glVertex3f(20.0, 42.0, -43.05);

    glVertex3f(7.1, 43.0, -43.05);
    glVertex3f(10.0, 43.0, -43.05);

    glVertex3f(12.1, 44.0, -43.05);
    glVertex3f(16.0, 44.0, -43.05);

    glVertex3f(19.1, 45.0, -43.05);
    glVertex3f(16.0, 45.0, -43.05);
        //L2
    glVertex3f(7.1, 57.0, -43.05);
    glVertex3f(10.0, 57.0, -43.05);

    glVertex3f(11.1, 58.0, -43.05);
    glVertex3f(7.0, 58.0, -43.05);

    glVertex3f(10.1, 59.0, -43.05);
    glVertex3f(14.0, 59.0, -43.05);

    glVertex3f(9.1, 60.0, -43.05);
    glVertex3f(18.0, 60.0, -43.05);

    glVertex3f(7.1, 61.0, -43.05);
    glVertex3f(12.0, 61.0, -43.05);

    glVertex3f(12.1, 62.0, -43.05);
    glVertex3f(14.0, 62.0, -43.05);
        //L3
    glVertex3f(8.1, 73.0, -43.05);
    glVertex3f(10.0, 73.0, -43.05);

    glVertex3f(10.1, 74.0, -43.05);
    glVertex3f(14.0, 74.0, -43.05);

    glVertex3f(14.1, 75.0, -43.05);
    glVertex3f(20.0, 75.0, -43.05);

    glVertex3f(10.1, 76.0, -43.05);
    glVertex3f(15.0, 76.0, -43.05);

    glVertex3f(12.1, 77.0, -43.05);
    glVertex3f(14.0, 77.0, -43.05);

    glVertex3f(10.1, 78.0, -43.05);
    glVertex3f(9.0, 78.0, -43.05);

       //kanan
        //L1
    glVertex3f(26.05, 51.5, -23.0);
    glVertex3f(26.05, 51.5, -43.0);

    glVertex3f(26.05, 68.0, -23.0);
    glVertex3f(26.05, 68.0, -43.0);
    glVertex3f(26.05, 40.0, -40.05);
    glVertex3f(26.05, 40.0, -34.05);

    glVertex3f(26.05, 41.0, -35.05);
    glVertex3f(26.05, 41.0, -30.05);

    glVertex3f(26.05, 42.0, -27.05);
    glVertex3f(26.05, 42.0, -25.05);

    glVertex3f(26.05, 43.0, -30.05);
    glVertex3f(26.05, 43.0, -25.05);

    glVertex3f(26.05, 44.0, -25.05);
    glVertex3f(26.05, 44.0, -28.05);

    glVertex3f(26.05, 45.0, -30.05);
    glVertex3f(26.05, 45.0, -32.05);
        //L2
    glVertex3f(25.05, 57.0, -35.05);
    glVertex3f(25.05, 57.0, -38.05);

    glVertex3f(25.05, 58.0, -36.05);
    glVertex3f(25.05, 58.0, -25.05);

    glVertex3f(25.05, 59.0, -23.05);
    glVertex3f(25.05, 59.0, -25.05);

    glVertex3f(25.05, 60.0, -25.05);
    glVertex3f(25.05, 60.0, -30.05);

    glVertex3f(25.05, 61.0, -23.05);
    glVertex3f(25.05, 61.0, -26.05);

    glVertex3f(25.05, 62.0, -31.05);
    glVertex3f(25.05, 62.0, -33.05);
        //L3
    glVertex3f(25.05, -2.0, -35.05);
    glVertex3f(25.05, -2.0, -38.05);

    glVertex3f(25.05, -1.0, -32.05);
    glVertex3f(25.05, -1.0, -29.05);

    glVertex3f(25.05, 0.0, -25.05);
    glVertex3f(25.05, 0.0, -32.05);

    glVertex3f(25.05, 1.0, -38.05);
    glVertex3f(25.05, 1.0, -30.05);

    glVertex3f(25.05, 2.0, -23.05);
    glVertex3f(25.05, 2.0, -26.05);

    glVertex3f(25.05, 3.0, -36.05);
    glVertex3f(25.05, 3.0, -34.05);

    glEnd();


   //pondasi
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-100.0, -30.0, 50.0);
    glVertex3f(100.0, -30.0, 50.0);
    glVertex3f(100.0, -30.0, -80.0);
    glVertex3f(-100.0, -30.0, -80.0);
    glEnd();

    //depan2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-100.0, -30.0, 50.0);
    glVertex3f(100.0, -30.0, 50.0);
    glVertex3f(100.0, -35.0, 50.0);
    glVertex3f(-100.0, -35.0, 50.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-100.0, -30.0, -80.0);
    glVertex3f(100.0, -30.0, -80.0);
    glVertex3f(100.0, -35.0, -80.0);
    glVertex3f(-100.0, -35.0, -80.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, -30.0, 50.0);
    glVertex3f(100.0, -30.0, -80.0);
    glVertex3f(100.0, -35.0, -80.0);
    glVertex3f(100.0, -35.0, 50.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-100.0, -30.0, -80.0);
    glVertex3f(-100.0, -30.0, 50.0);
    glVertex3f(-100.0, -35.0, 50.0);
    glVertex3f(-100.0, -35.0, -80.0);
    glEnd();

    //bawahpondasi
    glBegin(GL_QUADS);
    glColor3f(0.50, 1.0, 0.0);
    glVertex3f(-160.0, -35.0, 150.0);
    glVertex3f(200.0, -35.0, 150.0);
    glVertex3f(200.0, -35.0, -200.0);
    glVertex3f(-160.0, -35.0, -200.0);
    glEnd();

    //tengah depan bawah kiri
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, -2.0);
    glVertex3f(32.0, -8.0, -2.0);
    glVertex3f(25.0, -8.0, -2.0);
    glVertex3f(25.0, -30.0, -2.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, 0.0);
    glVertex3f(32.0, -8.0, 0.0);
    glVertex3f(25.0, -8.0, 0.0);
    glVertex3f(25.0, -30.0, 0.0);
    glEnd();
    //tengah depan bawah kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, -24.0);
    glVertex3f(32.0, -8.0, -24.0);
    glVertex3f(25.0, -8.0, -24.0);
    glVertex3f(25.0, -30.0, -24.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, -22.0);
    glVertex3f(32.0, -8.0, -22.0);
    glVertex3f(25.0, -8.0, -22.0);
    glVertex3f(25.0, -30.0, -22.0);
    glEnd();
    //tutup depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, 0.0);
    glVertex3f(32.0, -8.0, 0.0);
    glVertex3f(32.0, -8.0, -2.0);
    glVertex3f(32.0, -30.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -8.0, 0.0);
    glVertex3f(25.0, -8.0, 0.0);
    glVertex3f(25.0, -8.0, -2.0);
    glVertex3f(32.0, -8.0, -2.0);
    glEnd();

    //tutup depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -30.0, -24.0);
    glVertex3f(32.0, -8.0, -24.0);
    glVertex3f(32.0, -8.0, -22.0);
    glVertex3f(32.0, -30.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, -8.0, -24.0);
    glVertex3f(25.0, -8.0, -24.0);
    glVertex3f(25.0, -8.0, -22.0);
    glVertex3f(32.0, -8.0, -22.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(29.0, -18.0, 00.0);
    glVertex3f(29.0, -8.0, 00.0);
    glVertex3f(29.0, -8.0, -22.0);
    glVertex3f(29.0, -18.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(31.0, -18.0, 00.0);
    glVertex3f(31.0, -8.0, 00.0);
    glVertex3f(31.0, -8.0, -22.0);
    glVertex3f(31.0, -18.0, -22.0);
    glEnd();
    //tutup atas, bawah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(31.0, -18.0, 00.0);
    glVertex3f(29.0, -8.0, 0.0);
    glVertex3f(29.0, -8.0, -22.0);
    glVertex3f(31.0, -18.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(31.0, -18.0, 00.0);
    glVertex3f(29.0, -18.0, 0.0);
    glVertex3f(29.0, -18.0, -22.0);
    glVertex3f(31.0, -18.0, -22.0);
    glEnd();
    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(29.0, -30.0, 00.0);
    glVertex3f(29.0, -18.0, 00.0);
    glVertex3f(29.0, -18.0, -22.0);
    glVertex3f(29.0, -30.0, -22.0);
    glEnd();
    //depan atas ketengah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(25.0, -10.0, 0.0);
    glVertex3f(29.0, -10.0, 0.0);
    glVertex3f(29.0, -10.0, -22.0);
    glVertex3f(25.0, -10.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -20.0);
    glVertex3f(12.0, -10.0, -20.0);
    glEnd();


    //tengah depan bawah kiri tengah ke 2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 25.0, -3.0);
    glVertex3f(27.0, 55.0, -3.0);
    glVertex3f(25.0, 55.0, -3.0);
    glVertex3f(25.0, 25.0, -3.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 25.0, -5.0);
    glVertex3f(27.0, 55.0, -5.0);
    glVertex3f(25.0, 55.0, -5.0);
    glVertex3f(25.0, 25.0, -5.0);
    glEnd();
    //tutup depan kiri kotak tengah 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 25.0, -5.0);
    glVertex3f(27.0, 55.0, -5.0);
    glVertex3f(27.0, 55.0, -3.0);
    glVertex3f(27.0, 25.0, -3.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 55.0, -5.0);
    glVertex3f(25.0, 55.0, -5.0);
    glVertex3f(25.0, 55.0, -3.0);
    glVertex3f(27.0, 55.0, -3.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(25.0, 55.0, -5.0);
    glVertex3f(25.0, 45.0, -5.0);
    glVertex3f(25.0, 45.0, -23.0);
    glVertex3f(25.0, 55.0, -23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 55.0, -5.0);
    glVertex3f(27.0, 45.0, -5.0);
    glVertex3f(27.0, 45.0, -23.0);
    glVertex3f(27.0, 55.0, -23.0);
    glEnd();
    //tutup atas, bawah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 55.0, -5.0);
    glVertex3f(27.0, 55.0, -5.0);
    glVertex3f(27.0, 55.0, -23.0);
    glVertex3f(25.0, 55.0, -23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 45.0, -5.0);
    glVertex3f(27.0, 45.0, -5.0);
    glVertex3f(27.0, 45.0, -23.0);
    glVertex3f(25.0, 45.0, -23.0);
    glEnd();
    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.1, 45.0, -5.0);
    glVertex3f(25.1, 50.0, -5.0);
    glVertex3f(25.1, 50.0, -23.0);
    glVertex3f(25.1, 45.0, -23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25.1, 55.0, -5.0);
    glVertex3f(25.1, 25.0, -5.0);
    glVertex3f(25.1, 25.0, -23.0);
    glVertex3f(25.1, 55.0, -23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(27.0, 37.1, -5.0);
    glVertex3f(27.0, 38.1, -5.0);
    glVertex3f(27.0, 38.1, -23.0);
    glVertex3f(27.0, 37.1, -23.0);
    glEnd();

    //depan atas ketengah kotak2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.0, 43.0, 0.0);
    glVertex3f(25.0, 43.0, 0.0);
    glVertex3f(25.0, 43.0, -23.0);
    glVertex3f(12.0, 43.0, -23.0);
    glEnd();


    //tengah depan bawah kiri tengah ke 3(atas)
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -2.0);
    glVertex3f(34.0, 70.0, -2.0);
    glVertex3f(25.0, 70.0, -2.0);
    glVertex3f(25.0, 125.0, -2.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -4.0);
    glVertex3f(34.0, 70.0, -4.0);
    glVertex3f(25.0, 70.0, -4.0);
    glVertex3f(25.0, 125.0, -4.0);
    glEnd();
    //tengah depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -27.0);
    glVertex3f(34.0, 70.0, -27.0);
    glVertex3f(25.0, 70.0, -27.0);
    glVertex3f(25.0, 125.0, -27.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -29.0);
    glVertex3f(34.0, 70.0, -29.0);
    glVertex3f(25.0, 70.0, -29.0);
    glVertex3f(25.0, 125.0, -29.0);
    glEnd();

    //tutup depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -4.0);
    glVertex3f(34.0, 70.0, -4.0);
    glVertex3f(34.0, 70.0, -2.0);
    glVertex3f(34.0, 125.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 70.0, -4.0);
    glVertex3f(25.0, 70.0, -4.0);
    glVertex3f(25.0, 70.0, -2.0);
    glVertex3f(34.0, 70.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -4.0);
    glVertex3f(25.0, 125.0, -4.0);
    glVertex3f(25.0, 125.0, -2.0);
    glVertex3f(34.0, 125.0, -2.0);
    glEnd();
    //tutup depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -27.0);
    glVertex3f(34.0, 70.0, -27.0);
    glVertex3f(34.0, 70.0, -29.0);
    glVertex3f(34.0, 125.0, -29.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 70.0, -27.0);
    glVertex3f(25.0, 70.0, -27.0);
    glVertex3f(25.0, 70.0, -29.0);
    glVertex3f(34.0, 70.0, -29.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 125.0, -27.0);
    glVertex3f(25.0, 125.0, -27.0);
    glVertex3f(25.0, 125.0, -29.0);
    glVertex3f(34.0, 125.0, -29.0);
    glEnd();
    //depan atas
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 113.0, -4.0);
    glVertex3f(34.0, 125.0, -4.0);
    glVertex3f(34.0, 125.0, -27.0);
    glVertex3f(34.0, 113.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(34.0, 113.0, -4.0);
    glVertex3f(34.0, 98.0, -4.0);
    glVertex3f(34.0, 98.0, -27.0);
    glVertex3f(34.0, 113.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 98.0, -4.0);
    glVertex3f(25.0, 98.0, -4.0);
    glVertex3f(25.0, 98.0, -27.0);
    glVertex3f(34.0, 98.0, -27.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 98.0, -4.0);
    glVertex3f(34.0, 96.0, -4.0);
    glVertex3f(34.0, 96.0, -27.0);
    glVertex3f(34.0, 98.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(34.1, 96.0, -4.1);
    glVertex3f(34.1, 83.0, -4.1);
    glVertex3f(34.1, 83.0, -27.1);
    glVertex3f(34.1, 96.0, -27.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(32.0, 98.0, -4.0);
    glVertex3f(32.0, 70.0, -4.0);
    glVertex3f(32.0, 70.0, -27.0);
    glVertex3f(32.0, 98.0, -27.0);
    glEnd();
    //tutup atas, bawah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 113.0, -4.0);
    glVertex3f(34.0, 113.0, -4.0);
    glVertex3f(34.0, 113.0, -27.0);
    glVertex3f(32.0, 113.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 98.0, -4.0);
    glVertex3f(34.0, 98.0, -4.0);
    glVertex3f(34.0, 98.0, -27.0);
    glVertex3f(32.0, 98.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 70.0, -4.0);
    glVertex3f(34.0, 70.0, -4.0);
    glVertex3f(34.0, 70.0, -27.0);
    glVertex3f(32.0, 70.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 72.0, -4.0);
    glVertex3f(34.0, 72.0, -4.0);
    glVertex3f(34.0, 72.0, -27.0);
    glVertex3f(32.0, 72.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 70.0, -4.0);
    glVertex3f(34.0, 72.0, -4.0);
    glVertex3f(34.0, 72.0, -27.0);
    glVertex3f(34.0, 70.0, -27.0);
    glEnd();
    //batas tengah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 83.0, -4.0);
    glVertex3f(34.0, 83.0, -4.0);
    glVertex3f(34.0, 83.0, -27.0);
    glVertex3f(32.0, 83.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 85.0, -4.0);
    glVertex3f(34.0, 85.0, -4.0);
    glVertex3f(34.0, 85.0, -27.0);
    glVertex3f(32.0, 85.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(34.0, 83.0, -4.0);
    glVertex3f(34.0, 85.0, -4.0);
    glVertex3f(34.0, 85.0, -27.0);
    glVertex3f(34.0, 83.0, -27.0);
    glEnd();

    //depan atas ketengah kotak2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(25.0, 111.0, -2.0);
    glVertex3f(32.0, 111.0, -2.0);
    glVertex3f(32.0, 111.0, -27.0);
    glVertex3f(25.0, 111.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.0, 111.0, -5.0);
    glVertex3f(25.0, 111.0, -5.0);
    glVertex3f(25.0, 111.0, -20.0);
    glVertex3f(12.0, 111.0, -20.0);
    glEnd();

    //samping kanan
    //kotak samping bawah kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 45.0, 10.0);
    glVertex3f(-20.0, 15.0, 10.0);
    glVertex3f(-20.0, 15.0, 23.0);
    glVertex3f(-20.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 45.0, 10.0);
    glVertex3f(-22.0, 15.0, 10.0);
    glVertex3f(-22.0, 15.0, 23.0);
    glVertex3f(-22.0, 45.0, 23.0);
    glEnd();
   //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 45.0, 10.0);
    glVertex3f(-3.0, 15.0, 10.0);
    glVertex3f(-3.0, 15.0, 23.0);
    glVertex3f(-3.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1.0, 45.0, 10.0);
    glVertex3f(-1.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 23.0);
    glVertex3f(-1.0, 45.0, 23.0);
    glEnd();

    //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 45.0, 10.0);
    glVertex3f(-22.0, 15.0, 10.0);
    glVertex3f(-20.0, 15.0, 23.0);
    glVertex3f(-20.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 15.0, 10.0);
    glVertex3f(-20.0, 15.0, 10.0);
    glVertex3f(-20.0, 15.0, 23.0);
    glVertex3f(-22.0, 15.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 45.0, 10.0);
    glVertex3f(-20.0, 45.0, 10.0);
    glVertex3f(-20.0, 45.0, 23.0);
    glVertex3f(-22.0, 45.0, 23.0);
    glEnd();
    //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 45.0, 10.0);
    glVertex3f(-3.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 23.0);
    glVertex3f(-1.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 23.0);
    glVertex3f(-3.0, 15.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 45.0, 10.0);
    glVertex3f(-1.0, 45.0, 10.0);
    glVertex3f(-1.0, 45.0, 23.0);
    glVertex3f(-3.0, 45.0, 23.0);
    glEnd();
    //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 45.0, 23.0);
    glVertex3f(-20.0, 35.0, 23.0);
    glVertex3f(-3.0, 35.0, 23.0);
    glVertex3f(-3.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 45.0, 21.0);
    glVertex3f(-20.0, 35.0, 21.0);
    glVertex3f(-3.0, 35.0, 21.0);
    glVertex3f(-3.0, 45.0, 21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 45.0, 21.0);
    glVertex3f(-3.0, 45.0, 21.0);
    glVertex3f(-3.0, 45.0, 23.0);
    glVertex3f(-20.0, 45.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 35.0, 21.0);
    glVertex3f(-3.0, 35.0, 21.0);
    glVertex3f(-3.0, 35.0, 23.0);
    glVertex3f(-20.0, 35.0, 23.0);
    glEnd();
    //depan bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 35.0, 21.0);
    glVertex3f(-20.0, 15.0, 21.0);
    glVertex3f(-3.0, 15.0, 21.0);
    glVertex3f(-3.0, 35.0, 21.0);
    glEnd();
    //garis
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 26.0, 21.1);
    glVertex3f(-20.0, 25.0, 21.1);
    glVertex3f(-3.0, 25.0, 21.1);
    glVertex3f(-3.0, 26.0, 21.1);
    glEnd();
    //bawah
     glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 17.0, 23.0);
    glVertex3f(-20.0, 15.0, 23.0);
    glVertex3f(-3.0, 15.0, 23.0);
    glVertex3f(-3.0, 17.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 17.0, 21.0);
    glVertex3f(-3.0, 17.0, 21.0);
    glVertex3f(-3.0, 17.0, 23.0);
    glVertex3f(-20.0, 17.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 15.0, 21.0);
    glVertex3f(-3.0, 15.0, 21.0);
    glVertex3f(-3.0, 15.0, 23.0);
    glVertex3f(-20.0, 15.0, 23.0);
    glEnd();
    //depan atas ketengah kotak2
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(12.0, 43.0, 0.0);
    glVertex3f(25.0, 43.0, 0.0);
    glVertex3f(25.0, 43.0, -23.0);
    glVertex3f(12.0, 43.0, -23.0);
    glEnd();



     //kotak samping tengah kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 55.0, 10.0);
    glVertex3f(-20.0, 98.0, 10.0);
    glVertex3f(-20.0, 98.0, 23.0);
    glVertex3f(-20.0, 55.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 55.0, 10.0);
    glVertex3f(-22.0, 98.0, 10.0);
    glVertex3f(-22.0, 98.0, 23.0);
    glVertex3f(-22.0, 55.0, 23.0);
    glEnd();

    //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 55.0, 10.0);
    glVertex3f(-3.0, 98.0, 10.0);
    glVertex3f(-3.0, 98.0, 23.0);
    glVertex3f(-3.0, 55.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1.0, 55.0, 10.0);
    glVertex3f(-1.0, 98.0, 10.0);
    glVertex3f(-1.0, 98.0, 23.0);
    glVertex3f(-1.0, 55.0, 23.0);
    glEnd();

     //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 55.0, 10.0);
    glVertex3f(-22.0, 98.0, 10.0);
    glVertex3f(-20.0, 98.0, 23.0);
    glVertex3f(-20.0, 55.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 98.0, 10.0);
    glVertex3f(-20.0, 98.0, 10.0);
    glVertex3f(-20.0, 98.0, 23.0);
    glVertex3f(-22.0, 98.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 55.0, 10.0);
    glVertex3f(-20.0, 55.0, 10.0);
    glVertex3f(-20.0, 55.0, 23.0);
    glVertex3f(-22.0, 55.0, 23.0);
    glEnd();

     //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 55.0, 10.0);
    glVertex3f(-3.0, 98.0, 10.0);
    glVertex3f(-1.0, 98.0, 23.0);
    glVertex3f(-1.0, 55.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 98.0, 10.0);
    glVertex3f(-1.0, 98.0, 10.0);
    glVertex3f(-1.0, 98.0, 23.0);
    glVertex3f(-3.0, 98.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 55.0, 10.0);
    glVertex3f(-1.0, 55.0, 10.0);
    glVertex3f(-1.0, 55.0, 23.0);
    glVertex3f(-3.0, 55.0, 23.0);
    glEnd();

    //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 98.0, 23.0);
    glVertex3f(-20.0, 85.0, 23.0);
    glVertex3f(-3.0, 85.0, 23.0);
    glVertex3f(-3.0, 98.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 98.0, 21.0);
    glVertex3f(-20.0, 85.0, 21.0);
    glVertex3f(-3.0, 85.0, 21.0);
    glVertex3f(-3.0, 98.0, 21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 98.0, 21.0);
    glVertex3f(-3.0, 98.0, 21.0);
    glVertex3f(-3.0, 98.0, 23.0);
    glVertex3f(-20.0, 98.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 85.0, 21.0);
    glVertex3f(-3.0, 85.0, 21.0);
    glVertex3f(-3.0, 85.0, 23.0);
    glVertex3f(-20.0, 85.0, 23.0);
    glEnd();

     //depan bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 85.0, 21.0);
    glVertex3f(-20.0, 55.0, 21.0);
    glVertex3f(-3.0, 55.0, 21.0);
    glVertex3f(-3.0, 85.0, 21.0);
    glEnd();
    //garis
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 76.0, 21.1);
    glVertex3f(-20.0, 75.0, 21.1);
    glVertex3f(-3.0, 75.0, 21.1);
    glVertex3f(-3.0, 76.0, 21.1);
    glEnd();
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 66.0, 21.1);
    glVertex3f(-20.0, 65.0, 21.1);
    glVertex3f(-3.0, 65.0, 21.1);
    glVertex3f(-3.0, 66.0, 21.1);
    glEnd();

    //bawah
     glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 57.0, 23.0);
    glVertex3f(-20.0, 55.0, 23.0);
    glVertex3f(-3.0, 55.0, 23.0);
    glVertex3f(-3.0, 57.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 57.0, 21.0);
    glVertex3f(-3.0, 57.0, 21.0);
    glVertex3f(-3.0, 57.0, 23.0);
    glVertex3f(-20.0, 57.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 55.0, 21.0);
    glVertex3f(-3.0, 55.0, 21.0);
    glVertex3f(-3.0, 55.0, 23.0);
    glVertex3f(-20.0, 55.0, 23.0);
    glEnd();


     //kotak samping atas kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 105.0, 10.0);
    glVertex3f(-20.0, 130.0, 10.0);
    glVertex3f(-20.0, 130.0, 23.0);
    glVertex3f(-20.0, 105.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 105.0, 10.0);
    glVertex3f(-22.0, 130.0, 10.0);
    glVertex3f(-22.0, 130.0, 23.0);
    glVertex3f(-22.0, 105.0, 23.0);
    glEnd();

    //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 105.0, 10.0);
    glVertex3f(-3.0, 130.0, 10.0);
    glVertex3f(-3.0, 130.0, 23.0);
    glVertex3f(-3.0, 105.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1.0, 105.0, 10.0);
    glVertex3f(-1.0, 130.0, 10.0);
    glVertex3f(-1.0, 130.0, 23.0);
    glVertex3f(-1.0, 105.0, 23.0);
    glEnd();

      //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 105.0, 10.0);
    glVertex3f(-22.0, 130.0, 10.0);
    glVertex3f(-20.0, 130.0, 23.0);
    glVertex3f(-20.0, 105.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 130.0, 10.0);
    glVertex3f(-20.0, 130.0, 10.0);
    glVertex3f(-20.0, 130.0, 23.0);
    glVertex3f(-22.0, 130.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 105.0, 10.0);
    glVertex3f(-20.0, 105.0, 10.0);
    glVertex3f(-20.0, 105.0, 23.0);
    glVertex3f(-22.0, 105.0, 23.0);
    glEnd();

     //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 105.0, 10.0);
    glVertex3f(-3.0, 130.0, 10.0);
    glVertex3f(-1.0, 130.0, 23.0);
    glVertex3f(-1.0, 105.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 130.0, 10.0);
    glVertex3f(-1.0, 130.0, 10.0);
    glVertex3f(-1.0, 130.0, 23.0);
    glVertex3f(-3.0, 130.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 105.0, 10.0);
    glVertex3f(-1.0, 105.0, 10.0);
    glVertex3f(-1.0, 105.0, 23.0);
    glVertex3f(-3.0, 105.0, 23.0);
    glEnd();
    //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 130.0, 23.0);
    glVertex3f(-20.0, 122.0, 23.0);
    glVertex3f(-3.0, 122.0, 23.0);
    glVertex3f(-3.0, 130.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 130.0, 21.0);
    glVertex3f(-20.0, 122.0, 21.0);
    glVertex3f(-3.0, 122.0, 21.0);
    glVertex3f(-3.0, 130.0, 21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 130.0, 21.0);
    glVertex3f(-3.0, 130.0, 21.0);
    glVertex3f(-3.0, 122.0, 23.0);
    glVertex3f(-20.0, 122.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 122.0, 21.0);
    glVertex3f(-3.0, 122.0, 21.0);
    glVertex3f(-3.0, 122.0, 23.0);
    glVertex3f(-20.0, 122.0, 23.0);
    glEnd();
    //depan bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 122.0, 21.0);
    glVertex3f(-20.0, 105.0, 21.0);
    glVertex3f(-3.0, 105.0, 21.0);
    glVertex3f(-3.0, 122.0, 21.0);
    glEnd();
    //garis
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 114.0, 21.1);
    glVertex3f(-20.0, 115.0, 21.1);
    glVertex3f(-3.0, 115.0, 21.1);
    glVertex3f(-3.0, 114.0, 21.1);
    glEnd();

    //kanan paling atas
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-18.0, 160.0, 10.1);
    glVertex3f(-18.0, 135.0, 10.1);
    glVertex3f(0.0, 135.0, 10.1);
    glVertex3f(0.0, 160.0, 10.1);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-18.0, 160.0, 10.2);
    glVertex3f(-18.0, 135.0, 10.2);
    glVertex3f(-17.0, 135.0, 10.2);
    glVertex3f(-17.0, 160.0, 10.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 160.0, 10.2);
    glVertex3f(0.0, 135.0, 10.2);
    glVertex3f(-1.0, 135.0, 10.2);
    glVertex3f(-1.0, 160.0, 10.2);
    glEnd();


    //samping kanan
    //kotak samping penyangga bawah kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, 10.0);
    glVertex3f(-20.0, -30.0, 10.0);
    glVertex3f(-20.0, -30.0, 25.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, 10.0);
    glVertex3f(-23.0, -30.0, 10.0);
    glVertex3f(-23.0, -30.0, 25.0);
    glVertex3f(-23.0, 10.0, 25.0);
    glEnd();
   //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, 10.0);
    glVertex3f(-3.0, -30.0, 10.0);
    glVertex3f(-3.0, -30.0, 25.0);
    glVertex3f(-3.0, 10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7 , 0.7);
    glVertex3f(0.0, 10.0, 10.0);
    glVertex3f(0.0, -30.0, 10.0);
    glVertex3f(0.0, -30.0, 25.0);
    glVertex3f(0.0, 10.0, 25.0);
    glEnd();

    //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, 10.0);
    glVertex3f(-23.0, -30.0, 10.0);
    glVertex3f(-20.0, -30.0, 25.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, -30.0, 10.0);
    glVertex3f(-20.0, -30.0, 10.0);
    glVertex3f(-20.0, -30.0, 25.0);
    glVertex3f(-23.0, -30.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, 10.0);
    glVertex3f(-20.0, 10.0, 10.0);
    glVertex3f(-20.0, 10.0, 25.0);
    glVertex3f(-23.0, 10.0, 25.0);
    glEnd();
    //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, 10.0);
    glVertex3f(-3.0, -30.0, 10.0);
    glVertex3f(0.0, -30.0, 25.0);
    glVertex3f(0.0, 10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, -30.0, 10.0);
    glVertex3f(0.0, -30.0, 10.0);
    glVertex3f(0.0, -30.0, 25.0);
    glVertex3f(-3.0, -30.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, 10.0);
    glVertex3f(0.0, 10.0, 10.0);
    glVertex3f(0.0, 10.0, 25.0);
    glVertex3f(-3.0, 10.0, 25.0);
    glEnd();

     //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, 25.0);
    glVertex3f(-20.0, 0.0, 25.0);
    glVertex3f(-3.0, 0.0, 25.0);
    glVertex3f(-3.0, 10.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, 22.0);
    glVertex3f(-20.0, 0.0, 22.0);
    glVertex3f(-3.0, 0.0, 22.0);
    glVertex3f(-3.0, 10.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, 22.0);
    glVertex3f(-3.0, 10.0, 22.0);
    glVertex3f(-3.0, 10.0, 25.0);
    glVertex3f(-23.0, 10.0, 25.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.8, 0.7);
    glVertex3f(-20.0, 0.0, 23.0);
    glVertex3f(-20.0, -10.0, 23.0);
    glVertex3f(-3.0, -10.0, 23.0);
    glVertex3f(-3.0, 0.0, 23.0);
    glEnd();

     //lantai jembatan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 36.0, 23.0);
    glVertex3f(30.0, 36.0, 10.0);
    glVertex3f(-1.0, 36.0, 10.0);
    glVertex3f(-1.0, 36.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 27.0, 23.0);
    glVertex3f(30.0, 27.0, 10.0);
    glVertex3f(-1.0, 27.0, 10.0);
    glVertex3f(-1.0, 27.0, 23.0);
    glEnd();
     //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 36.0, 23.0);
    glVertex3f(30.0, 36.0, 10.0);
    glVertex3f(30.0, -30.0, 10.0);
    glVertex3f(30.0, -30.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(32.0, 36.0, 23.0);
    glVertex3f(32.0, 36.0, 10.0);
    glVertex3f(32.0, -30.0, 10.0);
    glVertex3f(32.0, -30.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 36.0, 10.0);
    glVertex3f(30.0, -30.0, 10.0);
    glVertex3f(32.0, -30.0, 10.0);
    glVertex3f(32.0, 36.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 36.0, 23.0);
    glVertex3f(30.0, -30.0, 23.0);
    glVertex3f(32.0, -30.0, 23.0);
    glVertex3f(32.0, 36.0, 23.0);
    glEnd();
    //tutup depan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 27.0, 10.1);
    glVertex3f(30.0, 36.0, 10.1);
    glVertex3f(-1.0, 36.0, 10.1);
    glVertex3f(-1.0, 27.0, 10.1);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 27.0, 23.0);
    glVertex3f(30.0, 36.0, 23.0);
    glVertex3f(-1.0, 36.0, 23.0);
    glVertex3f(-1.0, 27.0, 23.0);
    glEnd();

    //lantai atas jembatan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 17.0, 23.0);
    glVertex3f(30.0, 17.0, 10.0);
    glVertex3f(-1.0, 17.0, 10.0);
    glVertex3f(-1.0, 17.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 15.0, 23.0);
    glVertex3f(30.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 10.0);
    glVertex3f(-1.0, 15.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 17.0, 23.0);
    glVertex3f(30.0, 15.0, 23.0);
    glVertex3f(-1.0, 15.0, 23.0);
    glVertex3f(-1.0, 17.0, 23.0);
    glEnd();
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30.0, 17.0, 23.0);
    glVertex3f(30.0, 23.0, 23.0);
    glVertex3f(-1.0, 23.0, 23.0);
    glVertex3f(-1.0, 17.0, 23.0);
    glEnd();

     //lantai ke2 jembatan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 5.0, 23.0);
    glVertex3f(30.0, 5.0, 10.0);
    glVertex3f(0.0, 5.0, 10.0);
    glVertex3f(0.0, 5.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 7.0, 23.0);
    glVertex3f(30.0, 7.0, 10.0);
    glVertex3f(0.0, 7.0, 10.0);
    glVertex3f(0.0, 7.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, 5.0, 23.0);
    glVertex3f(30.0, 7.0, 23.0);
    glVertex3f(0.0, 7.0, 23.0);
    glVertex3f(0.0, 5.0, 23.0);
    glEnd();
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30.0, 7.0, 23.0);
    glVertex3f(30.0, 12.0, 23.0);
    glVertex3f(0.0, 12.0, 23.0);
    glVertex3f(0.0, 7.0, 23.0);
    glEnd();

     //lantai ke3 jembatan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, -10.0, 23.0);
    glVertex3f(30.0, -10.0, 10.0);
    glVertex3f(0.0, -10.0, 10.0);
    glVertex3f(0.0, -10.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, -12.0, 23.0);
    glVertex3f(30.0, -12.0, 10.0);
    glVertex3f(0.0, -12.0, 10.0);
    glVertex3f(0.0, -12.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(30.0, -12.0, 23.0);
    glVertex3f(30.0, -10.0, 23.0);
    glVertex3f(0.0, -10.0, 23.0);
    glVertex3f(0.0, -12.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30.0, -10.0, 23.0);
    glVertex3f(30.0, -5.0, 23.0);
    glVertex3f(0.0, -5.0, 23.0);
    glVertex3f(0.0, -10.0, 23.0);
    glEnd();

    //penyangga
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(13.5, 36.0, 22.0);
    glVertex3f(13.5, 36.0, 23.0);
    glVertex3f(13.5, -30.0, 23.0);
    glVertex3f(13.5, -30.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(15.5, 36.0, 22.0);
    glVertex3f(15.5, 36.0, 23.0);
    glVertex3f(15.5, -30.0, 23.0);
    glVertex3f(15.5, -30.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(15.5, 36.0, 22.0);
    glVertex3f(15.5, -30.0, 22.0);
    glVertex3f(13.5, -30.0, 22.0);
    glVertex3f(13.5, 36.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(15.5, 36.0, 23.1);
    glVertex3f(15.5, -30.0, 23.1);
    glVertex3f(13.5, -30.0, 23.1);
    glVertex3f(13.5, 36.0, 23.1);
    glEnd();

    //gedung kecil depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50.0, 25.0, 23.0);
    glVertex3f(50.0, 25.0, 5.0);
    glVertex3f(50.0, -30.0, 5.0);
    glVertex3f(50.0, -30.0, 23.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, 23.0, 5.0);
    glVertex3f(50.0, 23.0, 5.0);
    glVertex3f(50.0, 23.0, 23.0);
    glVertex3f(32.0, 23.0, 23.0);
    glEnd();
     //depan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50.0, -30.0, 23.0);
    glVertex3f(50.0, 25.0, 23.0);
    glVertex3f(32.0, 25.0, 23.0);
    glVertex3f(32.0, -30.0, 23.0);
    glEnd();
    //belakang
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50.0, -30.0, 5.0);
    glVertex3f(50.0, 25.0, 5.0);
    glVertex3f(32.0, 25.0, 5.0);
    glVertex3f(32.0, -30.0, 5.0);
    glEnd();
    //dedung dpn bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(32.0, 33.0, -43.0);
    glVertex3f(32.0, 33.0, 5.0);
    glVertex3f(32.0, -30.0, 5.0);
    glVertex3f(32.0, -30.0, -43.0);
    glEnd();

    //lantai jendela
     glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(50.1, 35.0, 10.0);
    glVertex3f(50.1, 5.0, 10.0);
    glVertex3f(50.1, 5.0, 23.0);
    glVertex3f(50.1, 35.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 35.0, 10.0);
    glVertex3f(52.0, 5.0, 10.0);
    glVertex3f(52.0, 5.0, 23.0);
    glVertex3f(52.0, 35.0, 23.0);
    glEnd();
    //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.5, .5, 0.5);
    glVertex3f(65.0, 35.0, 10.0);
    glVertex3f(65.0, 5.0, 10.0);
    glVertex3f(65.0, 5.0, 23.0);
    glVertex3f(65.0, 35.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(67.0, 35.0, 10.0);
    glVertex3f(67.0, 5.0, 10.0);
    glVertex3f(67.0, 5.0, 23.0);
    glVertex3f(67.0, 35.0, 23.0);
    glEnd();
    //tutup kiri
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(50.0, 35.0, 23.0);
    glVertex3f(50.0, 5.0, 23.0);
    glVertex3f(52.0, 5.0, 23.0);
    glVertex3f(52.0, 35.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(50.0, 35.0, 10.0);
    glVertex3f(50.0, 5.0, 10.0);
    glVertex3f(52.0, 5.0, 10.0);
    glVertex3f(52.0, 35.0, 10.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(50.0, 35.0, 10.0);
    glVertex3f(52.0, 35.0, 10.0);
    glVertex3f(52.0, 35.0, 23.0);
    glVertex3f(50.0, 35.0, 23.0);
    glEnd();
    //tutup kanan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(65.0, 35.0, 23.0);
    glVertex3f(65.0, 5.0, 23.0);
    glVertex3f(67.0, 5.0, 23.0);
    glVertex3f(67.0, 35.0, 23.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(65.0, 35.0, 10.0);
    glVertex3f(65.0, 5.0, 10.0);
    glVertex3f(67.0, 5.0, 10.0);
    glVertex3f(67.0, 35.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(65.0, 35.0, 10.0);
    glVertex3f(67.0, 35.0, 10.0);
    glVertex3f(67.0, 35.0, 23.0);
    glVertex3f(65.0, 35.0, 23.0);
    glEnd();

    //depan atas
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 35.0, 23.0);
    glVertex3f(52.0, 25.0, 23.0);
    glVertex3f(65.0, 25.0, 23.0);
    glVertex3f(65.0, 35.0, 23.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 35.0, 21.0);
    glVertex3f(52.0, 25.0, 21.0);
    glVertex3f(65.0, 25.0, 21.0);
    glVertex3f(65.0, 35.0, 21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 35.0, 23.0);
    glVertex3f(65.0, 35.0, 23.0);
    glVertex3f(65.0, 35.0, 21.0);
    glVertex3f(52.0, 35.0, 21.0);
    glEnd();
    //bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 5.0, 21.0);
    glVertex3f(52.0, 25.0, 21.0);
    glVertex3f(65.0, 25.0, 21.0);
    glVertex3f(65.0, 5.0, 21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 5.0, 23.0);
    glVertex3f(65.0, 5.0, 23.0);
    glVertex3f(65.0, 5.0, 21.0);
    glVertex3f(52.0, 5.0, 21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 7.0, 23.0);
    glVertex3f(65.0, 7.0, 23.0);
    glVertex3f(65.0, 7.0, 21.0);
    glVertex3f(52.0, 7.0, 21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(52.0, 7.0, 23.0);
    glVertex3f(52.0, 5.0, 23.0);
    glVertex3f(65.0, 5.0, 23.0);
    glVertex3f(65.0, 7.0, 23.0);
    glEnd();

    //gedung kecil depan bawah2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(50.0, -8.0, 23.0);
    glVertex3f(50.0, -8.0, 5.0);
    glVertex3f(50.0, -30.0, 5.0);
    glVertex3f(50.0, -30.0, 23.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(67.0, -8.0, 5.0);
    glVertex3f(50.0, -8.0, 5.0);
    glVertex3f(50.0, -8.0, 23.0);
    glVertex3f(67.0, -8.0, 23.0);
    glEnd();
     //depan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(50.0, -30.0, 23.0);
    glVertex3f(50.0, -8.0, 23.0);
    glVertex3f(67.0, -8.0, 23.0);
    glVertex3f(67.0, -30.0, 23.0);
    glEnd();
    //kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -30.0, 5.0);
    glVertex3f(67.0, -8.0, 5.0);
    glVertex3f(67.0, -8.0, 23.0);
    glVertex3f(67.0, -30.0, 23.0);
    glEnd();
    //belakang
     glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(50.0, -30.0, 5.0);
    glVertex3f(50.0, -8.0, 5.0);
    glVertex3f(67.0, -8.0, 5.0);
    glVertex3f(67.0, -30.0, 5.0);
    glEnd();
    //penyangga1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(63.5, 5.0, 22.0);
    glVertex3f(63.5, 5.0, 23.0);
    glVertex3f(63.5, -8.0, 23.0);
    glVertex3f(63.5, -8.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 22.0);
    glVertex3f(65.5, 5.0, 23.0);
    glVertex3f(65.5, -8.0, 23.0);
    glVertex3f(65.5, -8.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 22.0);
    glVertex3f(65.5, -8.0, 22.0);
    glVertex3f(63.5, -8.0, 22.0);
    glVertex3f(63.5, 5.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 23.0);
    glVertex3f(65.5, -8.0, 23.0);
    glVertex3f(63.5, -8.0, 23.0);
    glVertex3f(63.5, 5.0, 23.0);
    glEnd();
     //penyangga2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(63.5, 5.0, 10.0);
    glVertex3f(63.5, 5.0, 11.0);
    glVertex3f(63.5, -8.0, 11.0);
    glVertex3f(63.5, -8.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 10.0);
    glVertex3f(65.5, 5.0, 11.0);
    glVertex3f(65.5, -8.0, 11.0);
    glVertex3f(65.5, -8.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 10.0);
    glVertex3f(65.5, -8.0, 10.0);
    glVertex3f(63.5, -8.0, 10.0);
    glVertex3f(63.5, 5.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65.5, 5.0, 11.0);
    glVertex3f(65.5, -8.0, 11.0);
    glVertex3f(63.5, -8.0, 11.0);
    glVertex3f(63.5, 5.0, 11.0);
    glEnd();

    //dedung dpn bawah
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(83.0, 33.0, -31.0);
    glVertex3f(83.0, 33.0, 5.0);
    glVertex3f(83.0, -30.0, 5.0);
    glVertex3f(83.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(81.0, 33.0, -31.0);
    glVertex3f(81.0, 33.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glVertex3f(81.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(81.0, 33.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glVertex3f(83.0, -30.0, 5.0);
    glVertex3f(83.0, 33.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(81.0, 33.0, -31.0);
    glVertex3f(81.0, -30.0, -31.0);
    glVertex3f(83.0, -30.0, -31.0);
    glVertex3f(83.0, 33.0, -31.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(67.0, -17.0, 5.0);
    glVertex3f(67.0, -30.0, 5.0);
    glVertex3f(67.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -30.0, -31.0);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, -31.0);
    glVertex3f(81.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -30.0, 5.0);
    glVertex3f(67.0, -17.0, 5.0);
    glVertex3f(81.0, -17.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, 5.0);
    glVertex3f(67.0, -17.0, 5.0);
    glEnd();
    //tutupatas depan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(83.0, 33.0, -31.0);
    glVertex3f(32.0, 33.0, -31.0);
    glVertex3f(32.0, 33.0, 5.0);
    glVertex3f(83.0, 33.0, 5.0);
    glEnd();

    //gedung hall depan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -21.0);
    glVertex3f(75.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -21.0);
    glVertex3f(95.0, -30.0, -21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -39.0);
    glVertex3f(75.0, 27.0, -39.0);
    glVertex3f(95.0, 27.0, -39.0);
    glVertex3f(95.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(95.0, -30.0, -21.0);
    glVertex3f(95.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -39.0);
    glVertex3f(95.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -21.0);
    glVertex3f(75.0, 27.0, -21.0);
    glVertex3f(75.0, 27.0, -39.0);
    glVertex3f(75.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -39.0);
    glVertex3f(75.0, 27.0, -39.0);
    glEnd();

    //gedung hall depan2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -30.0, -21.0);
    glVertex3f(32.0, 33.0, -21.0);
    glVertex3f(52.0, 33.0, -21.0);
    glVertex3f(52.0, -30.0, -21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -30.0, -39.0);
    glVertex3f(32.0, 33.0, -39.0);
    glVertex3f(52.0, 33.0, -39.0);
    glVertex3f(52.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(52.0, -30.0, -21.0);
    glVertex3f(52.0, 33.0, -21.0);
    glVertex3f(52.0, 33.0, -39.0);
    glVertex3f(52.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.1, -30.0, -21.0);
    glVertex3f(32.1, 33.0, -21.0);
    glVertex3f(32.1, 33.0, -39.0);
    glVertex3f(32.1, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, 33.1, -21.0);
    glVertex3f(52.0, 33.1, -21.0);
    glVertex3f(52.0, 33.1, -39.0);
    glVertex3f(32.0, 33.1, -39.0);
    glEnd();

    //lantai halll depan1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, -12.0, -21.0);
    glVertex3f(85.0, -12.0, -21.0);
    glVertex3f(85.0, -12.0, 5.0);
    glVertex3f(32.0, -12.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, -15.0, -21.0);
    glVertex3f(85.0, -15.0, -21.0);
    glVertex3f(85.0, -15.0, 5.0);
    glVertex3f(32.0, -15.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(52.0, -15.0, -21.0);
    glVertex3f(52.0, -12.0, -21.0);
    glVertex3f(75.0, -12.0, -21.0);
    glVertex3f(75.0, -15.0, -21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, -15.0, 5.0);
    glVertex3f(32.0, -12.0, 5.0);
    glVertex3f(85.0, -12.0, 5.0);
    glVertex3f(85.0, -15.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(85.0, -15.0, 5.0);
    glVertex3f(85.0, -12.0, 5.0);
    glVertex3f(85.0, -12.0, -21.0);
    glVertex3f(85.0, -15.0, -21.0);
    glEnd();

    //lantai halll depan3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 13.0, -21.0);
    glVertex3f(85.0, 13.0, -21.0);
    glVertex3f(85.0, 13.0, 5.0);
    glVertex3f(32.0, 13.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 10.0, -21.0);
    glVertex3f(85.0, 10.0, -21.0);
    glVertex3f(85.0, 10.0, 5.0);
    glVertex3f(32.0, 10.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(52.0, 10.0, -21.0);
    glVertex3f(52.0, 13.0, -21.0);
    glVertex3f(75.0, 13.0, -21.0);
    glVertex3f(75.0, 10.0, -21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 10.0, 5.0);
    glVertex3f(32.0, 13.0, 5.0);
    glVertex3f(85.0, 13.0, 5.0);
    glVertex3f(85.0, 10.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(85.0, 10.0, 5.0);
    glVertex3f(85.0, 13.0, 5.0);
    glVertex3f(85.0, 13.0, -21.0);
    glVertex3f(85.0, 10.0, -21.0);
    glEnd();


    //lantai halll depan2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, -3.0, -21.0);
    glVertex3f(85.0, -3.0, -21.0);
    glVertex3f(85.0, -3.0, 5.0);
    glVertex3f(32.0, -3.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 0.0, -21.0);
    glVertex3f(85.0, 0.0, -21.0);
    glVertex3f(85.0, 0.0, 5.0);
    glVertex3f(32.0, 0.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(52.0, 0.0, -21.0);
    glVertex3f(52.0, -3.0, -21.0);
    glVertex3f(75.0, -3.0, -21.0);
    glVertex3f(75.0, 0.0, -21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 0.0, 5.0);
    glVertex3f(32.0, -3.0, 5.0);
    glVertex3f(85.0, -3.0, 5.0);
    glVertex3f(85.0, 0.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(85.0, 0.0, 5.0);
    glVertex3f(85.0, -3.0, 5.0);
    glVertex3f(85.0, -3.0, -21.0);
    glVertex3f(85.0, 0.0, -21.0);
    glEnd();

     //lantai halll depan4 atas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 22.0, -21.0);
    glVertex3f(85.0, 22.0, -21.0);
    glVertex3f(85.0, 22.0, 5.0);
    glVertex3f(32.0, 22.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 25.0, -21.0);
    glVertex3f(85.0, 25.0, -21.0);
    glVertex3f(85.0, 25.0, 5.0);
    glVertex3f(32.0, 25.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(52.0, 22.0, -21.0);
    glVertex3f(52.0, 25.0, -21.0);
    glVertex3f(75.0, 25.0, -21.0);
    glVertex3f(75.0, 22.0, -21.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(32.0, 22.0, 5.0);
    glVertex3f(32.0, 25.0, 5.0);
    glVertex3f(85.0, 25.0, 5.0);
    glVertex3f(85.0, 22.0, 5.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(85.0, 22.0, 5.0);
    glVertex3f(85.0, 25.0, 5.0);
    glVertex3f(85.0, 25.0, -21.0);
    glVertex3f(85.0, 22.0, -21.0);
    glEnd();

    //gentig atas depan hall
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(83.0, 33.0, 9.0);
    glVertex3f(90.0, 33.0 - 3.0, 9.0);
    glVertex3f(90.0, 33.0 - 3.0, -35.0);
    glVertex3f(83.0, 33.0, -35.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(52.0, 33.0, -31.0);
    glVertex3f(83.0, 33.0, -31.0);
    glVertex3f(83.0, 33.0, -35.0);
    glVertex3f(52.0, 33.0, -35.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(2.0, 33.0, 5.0);
    glVertex3f(83.0, 33.0, 5.0);
    glVertex3f(83.0, 33.0, 9.0);
    glVertex3f(2.0, 33.0, 9.0);
    glEnd();
    //samping depan 3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-25.0, 10.0, 10.0);
    glVertex3f(-25.0, -30.0, 10.0);
    glVertex3f(-25.0, -30.0, 25.0);
    glVertex3f(-25.0, 10.0, 25.0);
    glEnd();
    //samping depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-43.0, 10.0, 10.0);
    glVertex3f(-43.0, -30.0, 10.0);
    glVertex3f(-43.0, -30.0, 25.0);
    glVertex3f(-43.0, 10.0, 25.0);
    glEnd();
    //tutup samping
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-43.0, 8.0, 10.0);
    glVertex3f(-25.0, 8.0, 10.0);
    glVertex3f(-25.0, 8.0, 25.0);
    glVertex3f(-43.0, 8.0, 25.0);
    glEnd();
    //samping depannya
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-43.0, -30.0, 25.0);
    glVertex3f(-43.0, 10.0, 25.0);
    glVertex3f(-25.0, 10.0, 25.0);
    glVertex3f(-25.0, -30.0, 25.0);
    glEnd();
    //taingkatan atas kanan
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, 20.0, 10.0);
    glVertex3f(-45.0, 15.0, 10.0);
    glVertex3f(-45.0, 15.0, 25.0);
    glVertex3f(-45.0, 20.0, 25.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 20.0, 10.0);
    glVertex3f(-47.0, 15.0, 10.0);
    glVertex3f(-47.0, 15.0, 25.0);
    glVertex3f(-47.0, 20.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 20.0, 15.0);
    glVertex3f(-45.0, 20.0, 15.0);
    glVertex3f(-45.0, 20.0, 25.0);
    glVertex3f(-47.0, 20.0, 25.0);
    glEnd();
    //tingkatan atas kiri
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-55.0, 20.0, 10.0);
    glVertex3f(-55.0, 15.0, 10.0);
    glVertex3f(-55.0, 15.0, 25.0);
    glVertex3f(-55.0, 20.0, 25.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 20.0, 10.0);
    glVertex3f(-57.0, 15.0, 10.0);
    glVertex3f(-57.0, 15.0, 25.0);
    glVertex3f(-57.0, 20.0, 25.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 20.0, 15.0);
    glVertex3f(-55.0, 20.0, 15.0);
    glVertex3f(-55.0, 20.0, 25.0);
    glVertex3f(-57.0, 20.0, 25.0);
    glEnd();
    //depan
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 15.0, 25.0);
    glVertex3f(-57.0, 20.0, 25.0);
    glVertex3f(-45.0, 20.0, 25.0);
    glVertex3f(-45.0, 15.0, 25.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 15.0, 10.0);
    glVertex3f(-45.0, 15.0, 10.0);
    glVertex3f(-45.0, 15.0, 25.0);
    glVertex3f(-57.0, 15.0, 25.0);
    glEnd();
    //taingkatan atas kanan 2
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, 13.0, 10.0);
    glVertex3f(-45.0, 7.0, 10.0);
    glVertex3f(-45.0, 7.0, 25.0);
    glVertex3f(-45.0, 13.0, 25.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 13.0, 10.0);
    glVertex3f(-47.0, 7.0, 10.0);
    glVertex3f(-47.0, 7.0, 25.0);
    glVertex3f(-47.0, 13.0, 25.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 13.0, 15.0);
    glVertex3f(-45.0, 13.0, 15.0);
    glVertex3f(-45.0, 13.0, 25.0);
    glVertex3f(-47.0, 13.0, 25.0);
    glEnd();
    //tingkatan atas kiri2
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-55.0, 13.0, 10.0);
    glVertex3f(-55.0, 7.0, 10.0);
    glVertex3f(-55.0, 7.0, 25.0);
    glVertex3f(-55.0, 13.0, 25.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 13.0, 10.0);
    glVertex3f(-57.0, 7.0, 10.0);
    glVertex3f(-57.0, 7.0, 25.0);
    glVertex3f(-57.0, 13.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 13.0, 10.0);
    glVertex3f(-55.0, 13.0, 10.0);
    glVertex3f(-55.0, 13.0, 25.0);
    glVertex3f(-57.0, 13.0, 25.0);
    glEnd();
    //depan 2
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 13.0, 25.0);
    glVertex3f(-57.0, 7.0, 25.0);
    glVertex3f(-45.0, 7.0, 25.0);
    glVertex3f(-45.0, 13.0, 25.0);
    glEnd();
    //alas 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 7.0, 10.0);
    glVertex3f(-45.0, 7.0, 10.0);
    glVertex3f(-45.0, 7.0, 25.0);
    glVertex3f(-57.0, 7.0, 25.0);
    glEnd();
    //taingkatan atas kanan 3
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, 5.0, 10.0);
    glVertex3f(-45.0, 0.0, 10.0);
    glVertex3f(-45.0, 0.0, 25.0);
    glVertex3f(-45.0, 5.0, 25.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 5.0, 10.0);
    glVertex3f(-47.0, 0.0, 10.0);
    glVertex3f(-47.0, 0.0, 25.0);
    glVertex3f(-47.0, 5.0, 25.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, 5.0, 15.0);
    glVertex3f(-45.0, 5.0, 15.0);
    glVertex3f(-45.0, 5.0, 25.0);
    glVertex3f(-47.0, 5.0, 25.0);
    glEnd();
    //tingkatan atas kiri3
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-55.0, 5.0, 10.0);
    glVertex3f(-55.0, 0.0, 10.0);
    glVertex3f(-55.0, 0.0, 25.0);
    glVertex3f(-55.0, 5.0, 25.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 5.0, 10.0);
    glVertex3f(-57.0, 0.0, 10.0);
    glVertex3f(-57.0, 0.0, 25.0);
    glVertex3f(-57.0, 5.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 5.0, 10.0);
    glVertex3f(-55.0, 5.0, 10.0);
    glVertex3f(-55.0, 5.0, 25.0);
    glVertex3f(-57.0, 5.0, 25.0);
    glEnd();
     //depan 3
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 5.0, 25.0);
    glVertex3f(-57.0, 0.0, 25.0);
    glVertex3f(-45.0, 0.0, 25.0);
    glVertex3f(-45.0, 5.0, 25.0);
    glEnd();
    //alas 3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, 0.0, 10.0);
    glVertex3f(-45.0, 0.0, 10.0);
    glVertex3f(-45.0, 0.0, 25.0);
    glVertex3f(-57.0, 0.0, 25.0);
    glEnd();
    //taingkatan atas kanan 4
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, -2.0, 10.0);
    glVertex3f(-45.0, -7.0, 10.0);
    glVertex3f(-45.0, -7.0, 25.0);
    glVertex3f(-45.0, -2.0, 25.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, -2.0, 10.0);
    glVertex3f(-47.0, -7.0, 10.0);
    glVertex3f(-47.0, -7.0, 25.0);
    glVertex3f(-47.0, -2.0, 25.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, -2.0, 15.0);
    glVertex3f(-45.0, -2.0, 15.0);
    glVertex3f(-45.0, -2.0, 25.0);
    glVertex3f(-47.0, -2.0, 25.0);
    glEnd();
    //tingkatan atas kiri 4
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-55.0, -2.0, 10.0);
    glVertex3f(-55.0, -7.0, 10.0);
    glVertex3f(-55.0, -7.0, 25.0);
    glVertex3f(-55.0, -2.0, 25.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -2.0, 10.0);
    glVertex3f(-57.0, -7.0, 10.0);
    glVertex3f(-57.0, -7.0, 25.0);
    glVertex3f(-57.0, -2.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -2.0, 10.0);
    glVertex3f(-55.0, -2.0, 10.0);
    glVertex3f(-55.0, -2.0, 25.0);
    glVertex3f(-57.0, -2.0, 25.0);
    glEnd();
    //depan 4
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -2.0, 25.0);
    glVertex3f(-57.0, -7.0, 25.0);
    glVertex3f(-45.0, -7.0, 25.0);
    glVertex3f(-45.0, -2.0, 25.0);
    glEnd();
    //alas 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -7.0, 10.0);
    glVertex3f(-45.0, -7.0, 10.0);
    glVertex3f(-45.0, -7.0, 25.0);
    glVertex3f(-57.0, -7.0, 25.0);
    glEnd();
    //taingkatan atas kanan 5
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, -13.0, 10.0);
    glVertex3f(-45.0, -18.0, 10.0);
    glVertex3f(-45.0, -18.0, 25.0);
    glVertex3f(-45.0, -13.0, 25.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, -13.0, 10.0);
    glVertex3f(-47.0, -18.0, 10.0);
    glVertex3f(-47.0, -18.0, 25.0);
    glVertex3f(-47.0, -13.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-47.0, -13.0, 15.0);
    glVertex3f(-45.0, -13.0, 15.0);
    glVertex3f(-45.0, -13.0, 25.0);
    glVertex3f(-47.0, -13.0, 25.0);
    glEnd();
    //tingkatan atas kiri 5
      glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-55.0, -13.0, 10.0);
    glVertex3f(-55.0, -18.0, 10.0);
    glVertex3f(-55.0, -18.0, 25.0);
    glVertex3f(-55.0, -13.0, 25.0);
    glEnd();
        glBegin(GL_QUADS);
     glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -13.0, 10.0);
    glVertex3f(-57.0, -18.0, 10.0);
    glVertex3f(-57.0, -18.0, 25.0);
    glVertex3f(-57.0, -13.0, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -13.0, 10.0);
    glVertex3f(-55.0, -13.0, 10.0);
    glVertex3f(-55.0, -13.0, 25.0);
    glVertex3f(-57.0, -13.0, 25.0);
    glEnd();
    //depan 4
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 9.9);
    glVertex3f(-57.0, -13.0, 25.0);
    glVertex3f(-57.0, -18.0, 25.0);
    glVertex3f(-45.0, -18.0, 25.0);
    glVertex3f(-45.0, -13.0, 25.0);
    glEnd();
    //alas 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-57.0, -18.0, 10.0);
    glVertex3f(-45.0, -18.0, 10.0);
    glVertex3f(-45.0, -18.0, 25.0);
    glVertex3f(-57.0, -18.0, 25.0);
    glEnd();

    //dedung dpn bawah1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(83.0, 33.0, -31.0);
    glVertex3f(83.0, 33.0, 5.0);
    glVertex3f(83.0, -30.0, 5.0);
    glVertex3f(83.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(81.0, 33.0, -31.0);
    glVertex3f(81.0, 33.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glVertex3f(81.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(81.0, 33.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glVertex3f(83.0, -30.0, 5.0);
    glVertex3f(83.0, 33.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(81.0, 33.0, -31.0);
    glVertex3f(81.0, -30.0, -31.0);
    glVertex3f(83.0, -30.0, -31.0);
    glVertex3f(83.0, 33.0, -31.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(67.0, -17.0, 5.0);
    glVertex3f(67.0, -30.0, 5.0);
    glVertex3f(67.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -30.0, -31.0);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, -31.0);
    glVertex3f(81.0, -30.0, -31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -30.0, 5.0);
    glVertex3f(67.0, -17.0, 5.0);
    glVertex3f(81.0, -17.0, 5.0);
    glVertex3f(81.0, -30.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, -31.0);
    glVertex3f(81.0, -17.0, 5.0);
    glVertex3f(67.0, -17.0, 5.0);
    glEnd();
    //tutupatas depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(83.0, 33.0, -31.0);
    glVertex3f(32.0, 33.0, -31.0);
    glVertex3f(32.0, 33.0, 5.0);
    glVertex3f(83.0, 33.0, 5.0);
    glEnd();


    //gedung hall depan2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -21.0);
    glVertex3f(75.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -21.0);
    glVertex3f(95.0, -30.0, -21.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -39.0);
    glVertex3f(75.0, 27.0, -39.0);
    glVertex3f(95.0, 27.0, -39.0);
    glVertex3f(95.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(95.0, -30.0, -21.0);
    glVertex3f(95.0, 27.0, -21.0);
    glVertex3f(95.0, 27.0, -39.0);
    glVertex3f(95.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -21.0);
    glVertex3f(75.0, 27.0, -21.0);
    glVertex3f(75.0, 27.0, -39.0);
    glVertex3f(75.0, -30.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(75.0, 25.0, -21.0);
    glVertex3f(95.0, 25.0, -21.0);
    glVertex3f(95.0, 25.0, -39.0);
    glVertex3f(75.0, 25.0, -39.0);
    glEnd();
      //gedung hall depan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -50.0);
    glVertex3f(75.0, 27.0, -50.0);
    glVertex3f(95.0, 27.0, -50.0);
    glVertex3f(95.0, -30.0, -50.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -68.0);
    glVertex3f(75.0, 27.0, -68.0);
    glVertex3f(95.0, 27.0, -68.0);
    glVertex3f(95.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(95.0, -30.0, -50.0);
    glVertex3f(95.0, 27.0, -50.0);
    glVertex3f(95.0, 27.0, -68.0);
    glVertex3f(95.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -30.0, -50.0);
    glVertex3f(75.0, 27.0, -50.0);
    glVertex3f(75.0, 27.0, -68.0);
    glVertex3f(75.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(75.0, 25.0, -50.0);
    glVertex3f(95.0, 25.0, -50.0);
    glVertex3f(95.0, 25.0, -68.0);
    glVertex3f(75.0, 25.0, -68.0);
    glEnd();
    //gedung hall depankiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -35.0, -80.1);
    glVertex3f(75.0, 27.0, -80.1);
    glVertex3f(95.0, 27.0, -80.1);
    glVertex3f(95.0, -35.0, -80.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -35.0, -98.0);
    glVertex3f(75.0, 27.0, -98.0);
    glVertex3f(95.0, 27.0, -98.0);
    glVertex3f(95.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(95.0, -35.0, -80.0);
    glVertex3f(95.0, 27.0, -80.0);
    glVertex3f(95.0, 27.0, -98.0);
    glVertex3f(95.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(75.0, -35.0, -80.0);
    glVertex3f(75.0, 27.0, -80.0);
    glVertex3f(75.0, 27.0, -98.0);
    glVertex3f(75.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(75.0, 25.0, -80.0);
    glVertex3f(95.0, 25.0, -80.0);
    glVertex3f(95.0, 25.0, -98.0);
    glVertex3f(75.0, 25.0, -98.0);
    glEnd();
      //gedung hall depan2 kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -30.0, -50.0);
    glVertex3f(32.0, 33.0, -50.0);
    glVertex3f(32.0, 33.0, -68.0);
    glVertex3f(32.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -30.0, -68.0);
    glVertex3f(32.0, 33.0, -68.0);
    glVertex3f(52.0, 33.0, -68.0);
    glVertex3f(52.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(52.0, -30.0, -50.0);
    glVertex3f(52.0, 33.0, -50.0);
    glVertex3f(52.0, 33.0, -68.0);
    glVertex3f(52.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.1, -30.0, -50.0);
    glVertex3f(32.1, 33.0, -50.0);
    glVertex3f(52.1, 33.0, -50.0);
    glVertex3f(52.1, -30.0, -50.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 31.1, -50.0);
    glVertex3f(52.0, 31.1, -50.0);
    glVertex3f(52.0, 31.1, -68.0);
    glVertex3f(32.0, 31.1, -68.0);
    glEnd();
    //gedung hall depan2 kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -35.0, -80.0);
    glVertex3f(32.0, 33.0, -80.0);
    glVertex3f(32.0, 33.0, -98.0);
    glVertex3f(32.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -35.0, -98.0);
    glVertex3f(32.0, 33.0, -98.0);
    glVertex3f(52.0, 33.0, -98.0);
    glVertex3f(52.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(52.0, -35.0, -80.0);
    glVertex3f(52.0, 33.0, -80.0);
    glVertex3f(52.0, 33.0, -98.0);
    glVertex3f(52.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.1, -35.0, -80.0);
    glVertex3f(32.1, 33.0, -80.0);
    glVertex3f(52.1, 33.0, -80.0);
    glVertex3f(52.1, -35.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(32.0, 31.1, -80.0);
    glVertex3f(52.0, 31.1, -80.0);
    glVertex3f(52.0, 31.1, -98.0);
    glVertex3f(32.0, 31.1, -98.0);
    glEnd();

       //gedung hall depan4 kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.0, -35.0, -80.0);
    glVertex3f(18.0, 33.0, -80.0);
    glVertex3f(18.0, 33.0, -103.0);
    glVertex3f(18.0, -35.0, -103.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.0, -35.0, -103.0);
    glVertex3f(18.0, 33.0, -103.0);
    glVertex3f(32.0, 33.0, -103.0);
    glVertex3f(32.0, -35.0, -103.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(32.0, -35.0, -80.0);
    glVertex3f(32.0, 33.0, -80.0);
    glVertex3f(32.0, 33.0, -103.0);
    glVertex3f(32.0, -35.0, -103.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.1, -35.0, -80.0);
    glVertex3f(18.1, 33.0, -80.0);
    glVertex3f(32.1, 33.0, -80.0);
    glVertex3f(32.1, -35.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, 31.1, -80.0);
    glVertex3f(32.0, 31.1, -80.0);
    glVertex3f(32.0, 31.1, -103.0);
    glVertex3f(18.0, 31.1, -103.0);
    glEnd();
    //gedung hall depan5 kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.0, -35.0, -80.0);
    glVertex3f(18.0, 33.0, -80.0);
    glVertex3f(18.0, 33.0, -98.0);
    glVertex3f(18.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.0, -35.0, -98.0);
    glVertex3f(18.0, 33.0, -98.0);
    glVertex3f(2.0, 33.0, -98.0);
    glVertex3f(2.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(2.0, -35.0, -80.0);
    glVertex3f(2.0, 33.0, -80.0);
    glVertex3f(2.0, 33.0, -98.0);
    glVertex3f(2.0, -35.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(18.1, -35.0, -80.0);
    glVertex3f(18.1, 33.0, -80.0);
    glVertex3f(2.1, 33.0, -80.0);
    glVertex3f(2.1, -35.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, 31.1, -80.0);
    glVertex3f(2.0, 31.1, -80.0);
    glVertex3f(2.0, 31.1, -98.0);
    glVertex3f(18.0, 31.1, -98.0);
    glEnd();





    //depan
    //gedung hall kiri3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(25.0, -30.0, -72.0);
    glVertex3f(25.0, 33.0, -72.0);
    glVertex3f(2.0, 33.0, -72.0);
    glVertex3f(2.0, -30.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(25.0, -30.0, -55.1);
    glVertex3f(25.0, 33.0, -55.1);
    glVertex3f(2.0, 33.0, -55.1);
    glVertex3f(2.0, -30.0, -55.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(2.0, -30.0, -72.0);
    glVertex3f(2.0, 33.0, -72.0);
    glVertex3f(2.0, 33.0, -55.1);
    glVertex3f(2.0, -30.0, -55.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(25.1, -30.0, -72.0);
    glVertex3f(25.1, 33.0, -72.0);
    glVertex3f(25.1, 33.0, -55.1);
    glVertex3f(25.1, -30.0, -55.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(25.0, 31.1, -72.0);
    glVertex3f(2.0, 31.1, -72.0);
    glVertex3f(2.0, 31.1, -55.1);
    glVertex3f(25.0, 31.1, -55.1);
    glEnd();

 //gedung hall kiri2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18.0, -30.0, -40.0);
    glVertex3f(18.0, 33.0, -40.0);
    glVertex3f(2.0, 33.0, -40.0);
    glVertex3f(2.0, -30.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18.0, -30.0, -55.0);
    glVertex3f(18.0, 33.0, -55.0);
    glVertex3f(2.0, 33.0, -55.0);
    glVertex3f(2.0, -30.0, -55.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(2.0, -30.0, -40.0);
    glVertex3f(2.0, 33.0, -40.0);
    glVertex3f(2.0, 33.0, -55.0);
    glVertex3f(2.0, -30.0, -55.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18.1, -30.0, -40.0);
    glVertex3f(18.1, 33.0, -40.0);
    glVertex3f(18.1, 33.0, -55.0);
    glVertex3f(18.1, -30.0, -55.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, 31.1, -40.0);
    glVertex3f(2.0, 31.1, -40.0);
    glVertex3f(2.0, 31.1, -55.0);
    glVertex3f(18.0, 31.1, -55.0);
    glEnd();
    //kiri
    //kotak  penyangga bawah kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, -30.0);
    glVertex3f(-20.0, -30.0, -30.0);
    glVertex3f(-20.0, -30.0, -45.0);
    glVertex3f(-20.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, -30.0);
    glVertex3f(-23.0, -30.0, -30.0);
    glVertex3f(-23.0, -30.0, -45.0);
    glVertex3f(-23.0, 10.0, -45.0);
    glEnd();
   //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(-3.0, -30.0, -30.0);
    glVertex3f(-3.0, -30.0, -45.0);
    glVertex3f(-3.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0.0, 10.0, -30.0);
    glVertex3f(0.0, -30.0, -30.0);
    glVertex3f(0.0, -30.0, -45.0);
    glVertex3f(0.0, 10.0, -45.0);
    glEnd();

    //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, -30.0);
    glVertex3f(-23.0, -30.0, -30.0);
    glVertex3f(-20.0, -30.0, -45.0);
    glVertex3f(-20.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, -30.0, -30.0);
    glVertex3f(-20.0, -30.0, -30.0);
    glVertex3f(-20.0, -30.0, -45.0);
    glVertex3f(-23.0, -30.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -45.0);
    glVertex3f(-23.0, 10.0, -45.0);
    glEnd();
    //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(-3.0, -30.0, -30.0);
    glVertex3f(0.0, -30.0, -45.0);
    glVertex3f(0.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, -30.0, -30.0);
    glVertex3f(0.0, -30.0, -30.0);
    glVertex3f(0.0, -30.0, -45.0);
    glVertex3f(-3.0, -30.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(0.0, 10.0, -30.0);
    glVertex3f(0.0, 10.0, -45.0);
    glVertex3f(-3.0, 10.0, -45.0);
    glEnd();
      //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, -45.0);
    glVertex3f(-20.0, 0.0, -45.0);
    glVertex3f(-3.0, 0.0, -45.0);
    glVertex3f(-3.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, -42.0);
    glVertex3f(-20.0, 0.0, -42.0);
    glVertex3f(-3.0, 0.0, -42.0);
    glVertex3f(-3.0, 10.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 10.0, -42.0);
    glVertex3f(-3.0, 10.0, -42.0);
    glVertex3f(-3.0, 10.0, -45.0);
    glVertex3f(-23.0, 10.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-23.0, 0.0, -42.0);
    glVertex3f(-3.0, 0.0, -42.0);
    glVertex3f(-3.0, 0.0, -45.0);
    glVertex3f(-23.0, 0.0, -45.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-20.0, 0.0, -42.0);
    glVertex3f(-20.0, -6.0, -42.0);
    glVertex3f(-3.0, -6.0, -42.0);
    glVertex3f(-3.0, 0.0, -42.0);
    glEnd();

    //samping kiri no 2 atas penyangga
    //kotak samping tengah kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 53.0, -30.0);
    glVertex3f(-20.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -43.0);
    glVertex3f(-20.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 53.0, -30.0);
    glVertex3f(-22.0, 10.0, -30.0);
    glVertex3f(-22.0, 10.0, -43.0);
    glVertex3f(-22.0, 53.0, -43.0);
    glEnd();

    //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 53.0, -30.0);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(-3.0, 10.0, -43.0);
    glVertex3f(-3.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1.0, 53.0, -30.0);
    glVertex3f(-1.0, 10.0, -30.0);
    glVertex3f(-1.0, 10.0, -43.0);
    glVertex3f(-1.0, 53.0, -43.0);
    glEnd();
      //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 53.0, -30.0);
    glVertex3f(-22.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -43.0);
    glVertex3f(-20.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -30.0);
    glVertex3f(-20.0, 10.0, -43.0);
    glVertex3f(-22.0, 10.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 53.0, -30.0);
    glVertex3f(-20.0, 53.0, -30.0);
    glVertex3f(-20.0, 53.0, -43.0);
    glVertex3f(-22.0, 53.0, -43.0);
    glEnd();

     //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 53.0, -30.0);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(-1.0, 10.0, -43.0);
    glVertex3f(-1.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 10.0, -30.0);
    glVertex3f(-1.0, 10.0, -30.0);
    glVertex3f(-1.0, 10.0, -43.0);
    glVertex3f(-3.0, 10.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 53.0, -30.0);
    glVertex3f(-1.0, 53.0, -30.0);
    glVertex3f(-1.0, 53.0, -43.0);
    glVertex3f(-3.0, 53.0, -43.0);
    glEnd();

    //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 53.0, -43.0);
    glVertex3f(-20.0, 40.0, -43.0);
    glVertex3f(-3.0, 40.0, -43.0);
    glVertex3f(-3.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 53.0, -41.0);
    glVertex3f(-20.0, 40.0, -41.0);
    glVertex3f(-3.0, 40.0, -41.0);
    glVertex3f(-3.0, 53.0, -41.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 53.0, -41.0);
    glVertex3f(-3.0, 53.0, -41.0);
    glVertex3f(-3.0, 53.0, -43.0);
    glVertex3f(-20.0, 53.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 40.0, -41.0);
    glVertex3f(-3.0, 40.0, -41.0);
    glVertex3f(-3.0, 40.0, -43.0);
    glVertex3f(-20.0, 40.0, -43.0);
    glEnd();

     //depan bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 40.0, -41.0);
    glVertex3f(-20.0, 10.0, -41.0);
    glVertex3f(-3.0, 10.0, -41.0);
    glVertex3f(-3.0, 40.0, -41.0);
    glEnd();
    //garis
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 30.0, -41.1);
    glVertex3f(-20.0, 31.0, -41.1);
    glVertex3f(-3.0, 31.0, -41.1);
    glVertex3f(-3.0, 30.0, -41.1);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 20.0, -41.1);
    glVertex3f(-20.0, 21.0, -41.1);
    glVertex3f(-3.0, 21.0, -41.1);
    glVertex3f(-3.0, 20.0, -41.1);
    glEnd();

    //bawah
     glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, -43.0);
    glVertex3f(-20.0, 8.0, -43.0);
    glVertex3f(-3.0, 8.0, -43.0);
    glVertex3f(-3.0, 10.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 10.0, -41.0);
    glVertex3f(-3.0, 10.0, -41.0);
    glVertex3f(-3.0, 10.0, -43.0);
    glVertex3f(-20.0, 10.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 8.0, -41.0);
    glVertex3f(-3.0, 8.0, -41.0);
    glVertex3f(-3.0, 8.0, -43.0);
    glVertex3f(-20.0, 8.0, -43.0);
    glEnd();
    //samping kiri kotak lantai ke3
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 62.0, -30.0);
    glVertex3f(-20.0, 90.0, -30.0);
    glVertex3f(-20.0, 90.0, -43.0);
    glVertex3f(-20.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 62.0, -30.0);
    glVertex3f(-22.0, 90.0, -30.0);
    glVertex3f(-22.0, 90.0, -43.0);
    glVertex3f(-22.0, 62.0, -43.0);
    glEnd();

    //depan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 62.0, -30.0);
    glVertex3f(-3.0, 90.0, -30.0);
    glVertex3f(-3.0, 90.0, -43.0);
    glVertex3f(-3.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1.0, 62.0, -30.0);
    glVertex3f(-1.0, 90.0, -30.0);
    glVertex3f(-1.0, 90.0, -43.0);
    glVertex3f(-1.0, 62.0, -43.0);
    glEnd();

     //tutup depan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 62.0, -30.0);
    glVertex3f(-22.0, 90.0, -30.0);
    glVertex3f(-20.0, 90.0, -43.0);
    glVertex3f(-20.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 90.0, -30.0);
    glVertex3f(-20.0, 90.0, -30.0);
    glVertex3f(-20.0, 90.0, -43.0);
    glVertex3f(-22.0, 90.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-22.0, 62.0, -30.0);
    glVertex3f(-20.0, 62.0, -30.0);
    glVertex3f(-20.0, 62.0, -43.0);
    glVertex3f(-22.0, 62.0, -43.0);
    glEnd();

     //tutup depan kanan2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 62.0, -30.0);
    glVertex3f(-3.0, 90.0, -30.0);
    glVertex3f(-1.0, 90.0, -43.0);
    glVertex3f(-1.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 90.0, -30.0);
    glVertex3f(-1.0, 90.0, -30.0);
    glVertex3f(-1.0, 90.0, -43.0);
    glVertex3f(-3.0, 90.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, 62.0, -30.0);
    glVertex3f(-1.0, 62.0, -30.0);
    glVertex3f(-1.0, 62.0, -43.0);
    glVertex3f(-3.0, 62.0, -43.0);
    glEnd();

    //depan atas kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 90.0, -43.0);
    glVertex3f(-20.0, 78.0, -43.0);
    glVertex3f(-3.0, 78.0, -43.0);
    glVertex3f(-3.0, 90.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 90.0, -41.0);
    glVertex3f(-20.0, 78.0, -41.0);
    glVertex3f(-3.0, 78.0, -41.0);
    glVertex3f(-3.0, 90.0, -41.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 90.0, -41.0);
    glVertex3f(-3.0, 90.0, -41.0);
    glVertex3f(-3.0, 90.0, -43.0);
    glVertex3f(-20.0, 90.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, 78.0, -41.0);
    glVertex3f(-3.0, 78.0, -41.0);
    glVertex3f(-3.0, 78.0, -43.0);
    glVertex3f(-20.0, 78.0, -43.0);
    glEnd();

     //depan bawah
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 78.0, -41.0);
    glVertex3f(-20.0, 62.0, -41.0);
    glVertex3f(-3.0, 62.0, -41.0);
    glVertex3f(-3.0, 78.0, -41.0);
    glEnd();
    //garis
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-20.0, 72.0, -41.1);
    glVertex3f(-20.0, 71.0, -41.1);
    glVertex3f(-3.0, 71.0, -41.1);
    glVertex3f(-3.0, 72.0, -41.1);
    glEnd();

    //bawah
     glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-20.0, 62.0, -43.0);
    glVertex3f(-20.0, 64.0, -43.0);
    glVertex3f(-3.0, 64.0, -43.0);
    glVertex3f(-3.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-20.0, 62.0, -41.0);
    glVertex3f(-3.0, 62.0, -41.0);
    glVertex3f(-3.0, 62.0, -43.0);
    glVertex3f(-20.0, 62.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-20.0, 64.0, -41.0);
    glVertex3f(-3.0, 64.0, -41.0);
    glVertex3f(-3.0, 64.0, -43.0);
    glVertex3f(-20.0, 64.0, -43.0);
    glEnd();

    //samping kiri paling atas panjang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-20.0, 90.0, -30.1);
    glVertex3f(-20.0, 160.0, -30.1);
    glVertex3f(-1.0, 160.0, -30.1);
    glVertex3f(-1.0, 90.0, -30.1);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.0, 90.0, -30.2);
    glVertex3f(-2.0, 160.0, -30.2);
    glVertex3f(-1.0, 160.0, -30.2);
    glVertex3f(-1.0, 90.0, -30.2);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 90.0, -30.2);
    glVertex3f(-20.0, 160.0, -30.2);
    glVertex3f(-19.0, 160.0, -30.2);
    glVertex3f(-19.0, 90.0, -30.2);
    glEnd();

    //tulisan BINUS 2
     //B
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.4, 152.0, -30.3);
    glVertex3f(-1.4, 160.0, -30.3);
    glVertex3f(-5, 160.0, -30.3);
    glVertex3f(-5, 152.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-2.4, 156.75, -30.35);
    glVertex3f(-2.4, 159.0, -30.35);
    glVertex3f(-4, 159.0, -30.35);
    glVertex3f(-4, 156.75, -30.35);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-2.4, 153, -30.35);
    glVertex3f(-2.4, 155.25, -30.35);
    glVertex3f(-4, 155.25, -30.35);
    glVertex3f(-4, 153, -30.35);
    glEnd();
     //I
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.5, 152.0, -30.3);
    glVertex3f(-5.5, 160.0, -30.3);
    glVertex3f(-6.5, 160.0, -30.3);
    glVertex3f(-6.5, 152.0, -30.3);
    glEnd();
     //N
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-7, 152.0, -30.3);
    glVertex3f(-7, 160.0, -30.3);
    glVertex3f(-8, 160.0, -30.3);
    glVertex3f(-8, 152.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-8, 160.0, -30.3);
    glVertex3f(-8, 158.0, -30.3);
    glVertex3f(-10, 152.0, -30.3);
    glVertex3f(-10, 154.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10, 152.0, -30.3);
    glVertex3f(-10, 160.0, -30.3);
    glVertex3f(-11, 160.0, -30.3);
    glVertex3f(-11, 152.0, -30.3);
    glEnd();
     //U
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-11.5, 152.0, -30.3);
    glVertex3f(-11.5, 160.0, -30.3);
    glVertex3f(-12.5, 160.0, -30.3);
    glVertex3f(-12.5, 152.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-12, 152.0, -30.3);
    glVertex3f(-12, 153.0, -30.3);
    glVertex3f(-14, 153.0, -30.3);
    glVertex3f(-14, 152.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14, 152.0, -30.3);
    glVertex3f(-14, 160.0, -30.3);
    glVertex3f(-15, 160.0, -30.3);
    glVertex3f(-15, 152.0, -30.3);
    glEnd();
     //S
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.5, 159.0, -30.3);
    glVertex3f(-15.5, 160.0, -30.3);
    glVertex3f(-18.9, 160.0, -30.3);
    glVertex3f(-18.9, 159.0, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.5, 160, -30.3);
    glVertex3f(-15.5, 155.5, -30.3);
    glVertex3f(-16.5, 155.5, -30.3);
    glVertex3f(-16.5, 160, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.5, 155.5, -30.3);
    glVertex3f(-15.5, 156.5, -30.3);
    glVertex3f(-18.9, 156.5, -30.3);
    glVertex3f(-18.9, 155.5, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-17.9, 152, -30.3);
    glVertex3f(-17.9, 155.5, -30.3);
    glVertex3f(-18.9, 155.5, -30.3);
    glVertex3f(-18.9, 152, -30.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.5, 152, -30.3);
    glVertex3f(-15.5, 153, -30.3);
    glVertex3f(-18.9, 153, -30.3);
    glVertex3f(-18.9, 152, -30.3);
    glEnd();

    //teras samping kiri depan tengah bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, -6.0, -55.0);
    glVertex3f(-3.0, -6.0, -55.0);
    glVertex3f(-3.0, -6.0, -42.0);
    glVertex3f(-20.0, -6.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-20.0, -8.0, -55.0);
    glVertex3f(-3.0, -8.0, -55.0);
    glVertex3f(-3.0, -8.0, -42.0);
    glVertex3f(-20.0, -8.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-20.0, -8.0, -55.0);
    glVertex3f(-20.0, -6.0, -55.0);
    glVertex3f(-3.0, -6.0, -55.0);
    glVertex3f(-3.0, -8.0, -55.0);
    glEnd();

    //tiang 2
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-17.0, -30.0, -55.0);
    glVertex3f(-17.0, -8.0, -55.0);
    glVertex3f(-16.0, -8.0, -55.0);
    glVertex3f(-16.0, -30.0, -55.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-17.0, -30.0, -54.0);
    glVertex3f(-17.0, -8.0, -54.0);
    glVertex3f(-16.0, -8.0, -54.0);
    glVertex3f(-16.0, -30.0, -54.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-16.0, -30.0, -55.0);
    glVertex3f(-16.0, -8.0, -55.0);
    glVertex3f(-16.0, -8.0, -54.0);
    glVertex3f(-16.0, -30.0, -54.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-17.0, -30.0, -55.0);
    glVertex3f(-17.0, -8.0, -55.0);
    glVertex3f(-17.0, -8.0, -54.0);
    glVertex3f(-17.0, -30.0, -54.0);
    glEnd();
    //Tiang1
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-5.0, -30.0, -55.0);
    glVertex3f(-5.0, -8.0, -55.0);
    glVertex3f(-6.0, -8.0, -55.0);
    glVertex3f(-6.0, -30.0, -55.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-5.0, -30.0, -54.0);
    glVertex3f(-5.0, -8.0, -54.0);
    glVertex3f(-6.0, -8.0, -54.0);
    glVertex3f(-6.0, -30.0, -54.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-6.0, -30.0, -55.0);
    glVertex3f(-6.0, -8.0, -55.0);
    glVertex3f(-6.0, -8.0, -54.0);
    glVertex3f(-6.0, -30.0, -54.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-5.0, -30.0, -55.0);
    glVertex3f(-5.0, -8.0, -55.0);
    glVertex3f(-5.0, -8.0, -54.0);
    glVertex3f(-5.0, -30.0, -54.0);
    glEnd();
     //teras kiri bawah tengah smping kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, -6.0, -155.0);
    glVertex3f(3.0, -6.0, -155.0);
    glVertex3f(3.0, -6.0, -42.0);
    glVertex3f(-3.0, -6.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, -8.0, -155.0);
    glVertex3f(3.0, -8.0, -155.0);
    glVertex3f(3.0, -8.0, -42.0);
    glVertex3f(-3.0, -8.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-3.0, -8.0, -155.0);
    glVertex3f(-3.0, -6.0, -155.0);
    glVertex3f(-3.0, -6.0, -42.0);
    glVertex3f(-3.0, -8.0, -42.0);
    glEnd();

    //tiang 3 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -65.0);
    glVertex3f(-2.0, -8.0, -65.0);
    glVertex3f(-1.0, -8.0, -65.0);
    glVertex3f(-1.0, -30.0, -65.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -64.0);
    glVertex3f(-2.0, -8.0, -64.0);
    glVertex3f(-1.0, -8.0, -64.0);
    glVertex3f(-1.0, -30.0, -64.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -30.0, -65.0);
    glVertex3f(-1.0, -8.0, -65.0);
    glVertex3f(-1.0, -8.0, -64.0);
    glVertex3f(-1.0, -30.0, -64.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -65.0);
    glVertex3f(-2.0, -8.0, -65.0);
    glVertex3f(-2.0, -8.0, -64.0);
    glVertex3f(-2.0, -30.0, -64.0);
    glEnd();

    //tiang 4 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -75.0);
    glVertex3f(-2.0, -8.0, -75.0);
    glVertex3f(-1.0, -8.0, -75.0);
    glVertex3f(-1.0, -30.0, -75.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -74.0);
    glVertex3f(-2.0, -8.0, -74.0);
    glVertex3f(-1.0, -8.0, -74.0);
    glVertex3f(-1.0, -30.0, -74.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -30.0, -75.0);
    glVertex3f(-1.0, -8.0, -75.0);
    glVertex3f(-1.0, -8.0, -74.0);
    glVertex3f(-1.0, -30.0, -74.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -30.0, -75.0);
    glVertex3f(-2.0, -8.0, -75.0);
    glVertex3f(-2.0, -8.0, -74.0);
    glVertex3f(-2.0, -30.0, -74.0);
    glEnd();
    //tiang 5 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -85.0);
    glVertex3f(-2.0, -8.0, -85.0);
    glVertex3f(-1.0, -8.0, -85.0);
    glVertex3f(-1.0, -35.0, -85.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -84.0);
    glVertex3f(-2.0, -8.0, -84.0);
    glVertex3f(-1.0, -8.0, -84.0);
    glVertex3f(-1.0, -35.0, -84.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -85.0);
    glVertex3f(-1.0, -8.0, -85.0);
    glVertex3f(-1.0, -8.0, -84.0);
    glVertex3f(-1.0, -35.0, -84.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -85.0);
    glVertex3f(-2.0, -8.0, -85.0);
    glVertex3f(-2.0, -8.0, -84.0);
    glVertex3f(-2.0, -35.0, -84.0);
    glEnd();
    //tiang 6 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -95.0);
    glVertex3f(-2.0, -8.0, -95.0);
    glVertex3f(-1.0, -8.0, -95.0);
    glVertex3f(-1.0, -35.0, -95.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -94.0);
    glVertex3f(-2.0, -8.0, -94.0);
    glVertex3f(-1.0, -8.0, -94.0);
    glVertex3f(-1.0, -35.0, -94.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -95.0);
    glVertex3f(-1.0, -8.0, -95.0);
    glVertex3f(-1.0, -8.0, -94.0);
    glVertex3f(-1.0, -35.0, -94.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -95.0);
    glVertex3f(-2.0, -8.0, -95.0);
    glVertex3f(-2.0, -8.0, -94.0);
    glVertex3f(-2.0, -35.0, -94.0);
    glEnd();
     //tiang 7 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -105.0);
    glVertex3f(-2.0, -8.0, -105.0);
    glVertex3f(-1.0, -8.0, -105.0);
    glVertex3f(-1.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -104.0);
    glVertex3f(-2.0, -8.0, -104.0);
    glVertex3f(-1.0, -8.0, -104.0);
    glVertex3f(-1.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -105.0);
    glVertex3f(-1.0, -8.0, -105.0);
    glVertex3f(-1.0, -8.0, -104.0);
    glVertex3f(-1.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -105.0);
    glVertex3f(-2.0, -8.0, -105.0);
    glVertex3f(-2.0, -8.0, -104.0);
    glVertex3f(-2.0, -35.0, -104.0);
    glEnd();
     //tiang 8 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -115.0);
    glVertex3f(-2.0, -8.0, -115.0);
    glVertex3f(-1.0, -8.0, -115.0);
    glVertex3f(-1.0, -35.0, -115.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -114.0);
    glVertex3f(-2.0, -8.0, -114.0);
    glVertex3f(-1.0, -8.0, -114.0);
    glVertex3f(-1.0, -35.0, -114.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -115.0);
    glVertex3f(-1.0, -8.0, -115.0);
    glVertex3f(-1.0, -8.0, -114.0);
    glVertex3f(-1.0, -35.0, -114.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -115.0);
    glVertex3f(-2.0, -8.0, -115.0);
    glVertex3f(-2.0, -8.0, -114.0);
    glVertex3f(-2.0, -35.0, -114.0);
    glEnd();

  //tiang 9 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -125.0);
    glVertex3f(-2.0, -8.0, -125.0);
    glVertex3f(-1.0, -8.0, -125.0);
    glVertex3f(-1.0, -35.0, -125.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -124.0);
    glVertex3f(-2.0, -8.0, -124.0);
    glVertex3f(-1.0, -8.0, -124.0);
    glVertex3f(-1.0, -35.0, -124.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -125.0);
    glVertex3f(-1.0, -8.0, -125.0);
    glVertex3f(-1.0, -8.0, -124.0);
    glVertex3f(-1.0, -35.0, -124.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -125.0);
    glVertex3f(-2.0, -8.0, -125.0);
    glVertex3f(-2.0, -8.0, -124.0);
    glVertex3f(-2.0, -35.0, -124.0);
    glEnd();
    //tiang kiri lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -135.0);
    glVertex3f(-2.0, -8.0, -135.0);
    glVertex3f(-1.0, -8.0, -135.0);
    glVertex3f(-1.0, -35.0, -135.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -134.0);
    glVertex3f(-2.0, -8.0, -134.0);
    glVertex3f(-1.0, -8.0, -134.0);
    glVertex3f(-1.0, -35.0, -134.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -135.0);
    glVertex3f(-1.0, -8.0, -135.0);
    glVertex3f(-1.0, -8.0, -134.0);
    glVertex3f(-1.0, -35.0, -134.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -135.0);
    glVertex3f(-2.0, -8.0, -135.0);
    glVertex3f(-2.0, -8.0, -134.0);
    glVertex3f(-2.0, -35.0, -134.0);
    glEnd();
    //tiang kiri lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -145.0);
    glVertex3f(-2.0, -8.0, -145.0);
    glVertex3f(-1.0, -8.0, -145.0);
    glVertex3f(-1.0, -35.0, -145.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -144.0);
    glVertex3f(-2.0, -8.0, -144.0);
    glVertex3f(-1.0, -8.0, -144.0);
    glVertex3f(-1.0, -35.0, -144.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -145.0);
    glVertex3f(-1.0, -8.0, -145.0);
    glVertex3f(-1.0, -8.0, -144.0);
    glVertex3f(-1.0, -35.0, -144.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -145.0);
    glVertex3f(-2.0, -8.0, -145.0);
    glVertex3f(-2.0, -8.0, -144.0);
    glVertex3f(-2.0, -35.0, -144.0);
    glEnd();
    //tiang kiri lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -155.0);
    glVertex3f(-2.0, -8.0, -155.0);
    glVertex3f(-1.0, -8.0, -155.0);
    glVertex3f(-1.0, -35.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -154.0);
    glVertex3f(-2.0, -8.0, -154.0);
    glVertex3f(-1.0, -8.0, -154.0);
    glVertex3f(-1.0, -35.0, -154.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1.0, -35.0, -155.0);
    glVertex3f(-1.0, -8.0, -155.0);
    glVertex3f(-1.0, -8.0, -154.0);
    glVertex3f(-1.0, -35.0, -154.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-2.0, -35.0, -155.0);
    glVertex3f(-2.0, -8.0, -155.0);
    glVertex3f(-2.0, -8.0, -154.0);
    glVertex3f(-2.0, -35.0, -154.0);
    glEnd();

  //tiang 10 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -125.0);
    glVertex3f(18.0, -8.0, -125.0);
    glVertex3f(17.0, -8.0, -125.0);
    glVertex3f(17.0, -35.0, -125.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -124.0);
    glVertex3f(18.0, -8.0, -124.0);
    glVertex3f(17.0, -8.0, -124.0);
    glVertex3f(17.0, -35.0, -124.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -125.0);
    glVertex3f(18.0, -8.0, -125.0);
    glVertex3f(18.0, -8.0, -124.0);
    glVertex3f(18.0, -35.0, -124.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -125.0);
    glVertex3f(17.0, -8.0, -125.0);
    glVertex3f(17.0, -8.0, -124.0);
    glVertex3f(17.0, -35.0, -124.0);
    glEnd();
    //tiang kiri lanjtan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -135.0);
    glVertex3f(18.0, -8.0, -135.0);
    glVertex3f(17.0, -8.0, -135.0);
    glVertex3f(17.0, -35.0, -135.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -134.0);
    glVertex3f(18.0, -8.0, -134.0);
    glVertex3f(17.0, -8.0, -134.0);
    glVertex3f(17.0, -35.0, -134.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -135.0);
    glVertex3f(18.0, -8.0, -135.0);
    glVertex3f(18.0, -8.0, -134.0);
    glVertex3f(18.0, -35.0, -134.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -135.0);
    glVertex3f(17.0, -8.0, -135.0);
    glVertex3f(17.0, -8.0, -134.0);
    glVertex3f(17.0, -35.0, -134.0);
    glEnd();
    //tiang lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -145.0);
    glVertex3f(18.0, -8.0, -145.0);
    glVertex3f(17.0, -8.0, -145.0);
    glVertex3f(17.0, -35.0, -145.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -144.0);
    glVertex3f(18.0, -8.0, -144.0);
    glVertex3f(17.0, -8.0, -144.0);
    glVertex3f(17.0, -35.0, -144.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -145.0);
    glVertex3f(18.0, -8.0, -145.0);
    glVertex3f(18.0, -8.0, -144.0);
    glVertex3f(18.0, -35.0, -144.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -145.0);
    glVertex3f(17.0, -8.0, -145.0);
    glVertex3f(17.0, -8.0, -144.0);
    glVertex3f(17.0, -35.0, -144.0);
    glEnd();
    //tiang kiri lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -155.0);
    glVertex3f(18.0, -8.0, -155.0);
    glVertex3f(17.0, -8.0, -155.0);
    glVertex3f(17.0, -35.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -154.0);
    glVertex3f(18.0, -8.0, -154.0);
    glVertex3f(17.0, -8.0, -154.0);
    glVertex3f(17.0, -35.0, -154.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -155.0);
    glVertex3f(18.0, -8.0, -155.0);
    glVertex3f(18.0, -8.0, -154.0);
    glVertex3f(18.0, -35.0, -154.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -155.0);
    glVertex3f(17.0, -8.0, -155.0);
    glVertex3f(17.0, -8.0, -154.0);
    glVertex3f(17.0, -35.0, -154.0);
    glEnd();


    //tiang 11 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -115.0);
    glVertex3f(18.0, -8.0, -115.0);
    glVertex3f(17.0, -8.0, -115.0);
    glVertex3f(18.0, -35.0, -115.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -114.0);
    glVertex3f(18.0, -8.0, -114.0);
    glVertex3f(17.0, -8.0, -114.0);
    glVertex3f(17.0, -35.0, -114.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -115.0);
    glVertex3f(18.0, -8.0, -115.0);
    glVertex3f(18.0, -8.0, -114.0);
    glVertex3f(18.0, -35.0, -114.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -115.0);
    glVertex3f(17.0, -8.0, -115.0);
    glVertex3f(17.0, -8.0, -114.0);
    glVertex3f(17.0, -35.0, -114.0);
    glEnd();
    //tiang 12 kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -105.0);
    glVertex3f(18.0, -8.0, -105.0);
    glVertex3f(17.0, -8.0, -105.0);
    glVertex3f(17.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -104.0);
    glVertex3f(18.0, -8.0, -104.0);
    glVertex3f(17.0, -8.0, -104.0);
    glVertex3f(17.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(18.0, -35.0, -105.0);
    glVertex3f(18.0, -8.0, -105.0);
    glVertex3f(18.0, -8.0, -104.0);
    glVertex3f(18.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(17.0, -35.0, -105.0);
    glVertex3f(17.0, -8.0, -105.0);
    glVertex3f(17.0, -8.0, -104.0);
    glVertex3f(17.0, -35.0, -104.0);
    glEnd();
     //tiang 13 kiri tengah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(14.0, -35.0, -158.0);
    glVertex3f(14.0, -8.0, -158.0);
    glVertex3f(13.0, -8.0, -158.0);
    glVertex3f(13.0, -35.0, -158.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(14.0, -35.0, -157.0);
    glVertex3f(14.0, -8.0, -157.0);
    glVertex3f(13.0, -8.0, -157.0);
    glVertex3f(13.0, -35.0, -157.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(14.0, -35.0, -158.0);
    glVertex3f(14.0, -8.0, -158.0);
    glVertex3f(14.0, -8.0, -157.0);
    glVertex3f(14.0, -35.0, -157.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(13.0, -35.0, -158.0);
    glVertex3f(13.0, -8.0, -158.0);
    glVertex3f(13.0, -8.0, -157.0);
    glVertex3f(13.0, -35.0, -157.0);
    glEnd();
     //tiang 14 kiri tengah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(3.0, -35.0, -158.0);
    glVertex3f(3.0, -8.0, -158.0);
    glVertex3f(2.0, -8.0, -158.0);
    glVertex3f(2.0, -35.0, -158.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(3.0, -35.0, -157.0);
    glVertex3f(3.0, -8.0, -157.0);
    glVertex3f(2.0, -8.0, -157.0);
    glVertex3f(2.0, -35.0, -157.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(3.0, -35.0, -158.0);
    glVertex3f(3.0, -8.0, -158.0);
    glVertex3f(3.0, -8.0, -157.0);
    glVertex3f(3.0, -35.0, -157.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(2.0, -35.0, -158.0);
    glVertex3f(2.0, -8.0, -158.0);
    glVertex3f(2.0, -8.0, -157.0);
    glVertex3f(2.0, -35.0, -157.0);
    glEnd();
    //tiang 15 kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -65.0);
    glVertex3f(-21.0, -8.0, -65.0);
    glVertex3f(-22.0, -8.0, -65.0);
    glVertex3f(-22.0, -30.0, -65.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -64.0);
    glVertex3f(-21.0, -8.0, -64.0);
    glVertex3f(-22.0, -8.0, -64.0);
    glVertex3f(-22.0, -30.0, -64.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -65.0);
    glVertex3f(-21.0, -8.0, -65.0);
    glVertex3f(-21.0, -8.0, -64.0);
    glVertex3f(-21.0, -30.0, -64.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-22.0, -30.0, -65.0);
    glVertex3f(-22.0, -8.0, -65.0);
    glVertex3f(-22.0, -8.0, -64.0);
    glVertex3f(-22.0, -30.0, -64.0);
    glEnd();
    //tiang 16 kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -75.0);
    glVertex3f(-21.0, -8.0, -75.0);
    glVertex3f(-22.0, -8.0, -75.0);
    glVertex3f(-22.0, -30.0, -75.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -74.0);
    glVertex3f(-21.0, -8.0, -74.0);
    glVertex3f(-22.0, -8.0, -74.0);
    glVertex3f(-22.0, -30.0, -74.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -30.0, -75.0);
    glVertex3f(-21.0, -8.0, -75.0);
    glVertex3f(-21.0, -8.0, -74.0);
    glVertex3f(-21.0, -30.0, -74.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-22.0, -30.0, -75.0);
    glVertex3f(-22.0, -8.0, -75.0);
    glVertex3f(-22.0, -8.0, -74.0);
    glVertex3f(-22.0, -30.0, -74.0);
    glEnd();
    //tiang 17 kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -85.0);
    glVertex3f(-21.0, -8.0, -85.0);
    glVertex3f(-22.0, -8.0, -85.0);
    glVertex3f(-22.0, -35.0, -85.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -84.0);
    glVertex3f(-21.0, -8.0, -84.0);
    glVertex3f(-22.0, -8.0, -84.0);
    glVertex3f(-22.0, -35.0, -84.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -85.0);
    glVertex3f(-21.0, -8.0, -85.0);
    glVertex3f(-21.0, -8.0, -84.0);
    glVertex3f(-21.0, -35.0, -84.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-22.0, -35.0, -85.0);
    glVertex3f(-22.0, -8.0, -85.0);
    glVertex3f(-22.0, -8.0, -84.0);
    glVertex3f(-22.0, -35.0, -84.0);
    glEnd();
     //tiang 18 kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -95.0);
    glVertex3f(-21.0, -8.0, -95.0);
    glVertex3f(-22.0, -8.0, -95.0);
    glVertex3f(-22.0, -35.0, -95.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -94.0);
    glVertex3f(-21.0, -8.0, -94.0);
    glVertex3f(-22.0, -8.0, -94.0);
    glVertex3f(-22.0, -35.0, -94.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -95.0);
    glVertex3f(-21.0, -8.0, -95.0);
    glVertex3f(-21.0, -8.0, -94.0);
    glVertex3f(-21.0, -35.0, -94.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-22.0, -35.0, -95.0);
    glVertex3f(-22.0, -8.0, -95.0);
    glVertex3f(-22.0, -8.0, -94.0);
    glVertex3f(-22.0, -35.0, -94.0);
    glEnd();
    //tiang 19 kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -105.0);
    glVertex3f(-21.0, -8.0, -105.0);
    glVertex3f(-22.0, -8.0, -105.0);
    glVertex3f(-22.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -104.0);
    glVertex3f(-21.0, -8.0, -104.0);
    glVertex3f(-22.0, -8.0, -104.0);
    glVertex3f(-22.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-21.0, -35.0, -105.0);
    glVertex3f(-21.0, -8.0, -105.0);
    glVertex3f(-21.0, -8.0, -104.0);
    glVertex3f(-21.0, -35.0, -104.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-22.0, -35.0, -105.0);
    glVertex3f(-22.0, -8.0, -105.0);
    glVertex3f(-22.0, -8.0, -104.0);
    glVertex3f(-22.0, -35.0, -104.0);
    glEnd();
    //teras tiap lantai 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-5.0, -1.0, -82.0);
    glVertex3f(2.0, -1.0, -82.0);
    glVertex3f(2.0, -1.0, -45.0);
    glVertex3f(-5.0, -1.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 2.0, -82.0);
    glVertex3f(2.0, 2.0, -82.0);
    glVertex3f(2.0, 2.0, -45.0);
    glVertex3f(-5.0, 2.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 2.0, -82.0);
    glVertex3f(-5.0, -1.0, -82.0);
    glVertex3f(-5.0, -1.0, -45.0);
    glVertex3f(-5.0, 2.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 2.0, -82.0);
    glVertex3f(-5.0, -1.0, -82.0);
    glVertex3f(2.0, -1.0, -82.0);
    glVertex3f(2.0, 2.0, -82.0);
    glEnd();
    //pagar teras lantai1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 8.0, -82.0);
    glVertex3f(-5.0, 2.0, -82.0);
    glVertex3f(2.0, 2.0, -82.0);
    glVertex3f(2.0, 8.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 8.0, -82.0);
    glVertex3f(-5.0, 2.0, -82.0);
    glVertex3f(-5.0, 2.0, -42.0);
    glVertex3f(-5.0, 8.0, -42.0);
    glEnd();

    //teras lantai2
    //teras tiap lantai 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 12.0, -82.0);
    glVertex3f(2.0, 12.0, -82.0);
    glVertex3f(2.0, 12.0, -45.0);
    glVertex3f(-5.0, 12.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 15.0, -82.0);
    glVertex3f(2.0, 15.0, -82.0);
    glVertex3f(2.0, 15.0, -45.0);
    glVertex3f(-5.0, 15.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 12.0, -82.0);
    glVertex3f(-5.0, 15.0, -82.0);
    glVertex3f(-5.0, 15.0, -45.0);
    glVertex3f(-5.0, 12.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 12.0, -82.0);
    glVertex3f(-5.0, 15.0, -82.0);
    glVertex3f(2.0, 15.0, -82.0);
    glVertex3f(2.0, 12.0, -82.0);
    glEnd();
    //pagar teras lantai2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 21.0, -82.0);
    glVertex3f(-5.0, 15.0, -82.0);
    glVertex3f(2.0, 15.0, -82.0);
    glVertex3f(2.0, 21.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 21.0, -82.0);
    glVertex3f(-5.0, 15.0, -82.0);
    glVertex3f(-5.0, 15.0, -42.0);
    glVertex3f(-5.0, 21.0, -42.0);
    glEnd();
    //lantai teras3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 26.0, -82.0);
    glVertex3f(2.0, 26.0, -82.0);
    glVertex3f(2.0, 26.0, -45.0);
    glVertex3f(-5.0, 26.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 29.0, -82.0);
    glVertex3f(2.0, 29.0, -82.0);
    glVertex3f(2.0, 29.0, -45.0);
    glVertex3f(-5.0, 29.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 26.0, -82.0);
    glVertex3f(-5.0, 29.0, -82.0);
    glVertex3f(-5.0, 29.0, -45.0);
    glVertex3f(-5.0, 26.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-5.0, 26.0, -82.0);
    glVertex3f(-5.0, 29.0, -82.0);
    glVertex3f(2.0, 29.0, -82.0);
    glVertex3f(2.0, 26.0, -82.0);
    glEnd();
     //pagar teras lantai3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 29.0, -82.0);
    glVertex3f(-5.0, 35.0, -82.0);
    glVertex3f(2.0, 35.0, -82.0);
    glVertex3f(2.0, 29.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 29.0, -82.0);
    glVertex3f(-5.0, 35.0, -82.0);
    glVertex3f(-5.0, 35.0, -42.0);
    glVertex3f(-5.0, 29.0, -42.0);
    glEnd();



    //teras hall bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20.0, -6.0, -155.0);
    glVertex3f(3.0, -6.0, -155.0);
    glVertex3f(3.0, -6.0, -98.0);
    glVertex3f(20.0, -6.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20.0, -8.0, -155.0);
    glVertex3f(3.0, -8.0, -155.0);
    glVertex3f(3.0, -8.0, -98.0);
    glVertex3f(20.0, -8.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20.0, -8.0, -155.0);
    glVertex3f(20.0, -6.0, -155.0);
    glVertex3f(20.0, -6.0, -98.0);
    glVertex3f(20.0, -8.0, -98.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20.0, -8.0, -155.0);
    glVertex3f(20.0, -6.0, -155.0);
    glVertex3f(-3.0, -6.0, -155.0);
    glVertex3f(-3.0, -8.0, -155.0);
    glEnd();

    //teras sampping kiri bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-20.0, -6.0, -110.0);
    glVertex3f(-26.0, -6.0, -110.0);
    glVertex3f(-26.0, -6.0, -42.0);
    glVertex3f(-20.0, -6.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, -8.0, -110.0);
    glVertex3f(-26.0, -8.0, -110.0);
    glVertex3f(-26.0, -8.0, -42.0);
    glVertex3f(-20.0, -8.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, -8.0, -110.0);
    glVertex3f(-20.0, -6.0, -110.0);
    glVertex3f(-20.0, -6.0, -42.0);
    glVertex3f(-20.0, -8.0, -42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, -8.0, -110.0);
    glVertex3f(-20.0, -6.0, -110.0);
    glVertex3f(-26.0, -6.0, -110.0);
    glVertex3f(-26.0, -8.0, -110.0);
    glEnd();

    //lantai teras kanan1
    //teras tiap lantai 1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, -1.0, -82.0);
    glVertex3f(-27.0, -1.0, -82.0);
    glVertex3f(-27.0, -1.0, -45.0);
    glVertex3f(-20.0, -1.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 2.0, -82.0);
    glVertex3f(-27.0, 2.0, -82.0);
    glVertex3f(-27.0, 2.0, -45.0);
    glVertex3f(-20.0, 2.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 2.0, -82.0);
    glVertex3f(-20.0, -1.0, -82.0);
    glVertex3f(-20.0, -1.0, -45.0);
    glVertex3f(-20.0, 2.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 2.0, -82.0);
    glVertex3f(-20.0, -1.0, -82.0);
    glVertex3f(-27.0, -1.0, -82.0);
    glVertex3f(-27.0, 2.0, -82.0);
    glEnd();
    //pagar teras lantai1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 8.0, -82.0);
    glVertex3f(-20.0, 2.0, -82.0);
    glVertex3f(-27.0, 2.0, -82.0);
    glVertex3f(-27.0, 8.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 8.0, -82.0);
    glVertex3f(-20.0, 2.0, -82.0);
    glVertex3f(-20.0, 2.0, -42.0);
    glVertex3f(-20.0, 8.0, -42.0);
    glEnd();

      //teras tiap kiri lantai 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 12.0, -82.0);
    glVertex3f(-27.0, 12.0, -82.0);
    glVertex3f(-27.0, 12.0, -45.0);
    glVertex3f(-20.0, 12.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 15.0, -82.0);
    glVertex3f(-27.0, 15.0, -82.0);
    glVertex3f(-27.0, 15.0, -45.0);
    glVertex3f(-20.0, 15.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 12.0, -82.0);
    glVertex3f(-20.0, 15.0, -82.0);
    glVertex3f(-20.0, 15.0, -45.0);
    glVertex3f(-20.0, 12.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 12.0, -82.0);
    glVertex3f(-20.0, 15.0, -82.0);
    glVertex3f(-27.0, 15.0, -82.0);
    glVertex3f(-27.0, 12.0, -82.0);
    glEnd();
    //pagar teras kiri lantai2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 21.0, -82.0);
    glVertex3f(-20.0, 15.0, -82.0);
    glVertex3f(-27.0, 15.0, -82.0);
    glVertex3f(-27.0, 21.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 21.0, -82.0);
    glVertex3f(-20.0, 15.0, -82.0);
    glVertex3f(-20.0, 15.0, -42.0);
    glVertex3f(-20.0, 21.0, -42.0);
    glEnd();
    //teras kiri lantai 3
     //lantai teras3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 26.0, -82.0);
    glVertex3f(-27.0, 26.0, -82.0);
    glVertex3f(-27.0, 26.0, -45.0);
    glVertex3f(-20.0, 26.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 29.0, -82.0);
    glVertex3f(-27.0, 29.0, -82.0);
    glVertex3f(-27.0, 29.0, -45.0);
    glVertex3f(-20.0, 29.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 26.0, -82.0);
    glVertex3f(-20.0, 29.0, -82.0);
    glVertex3f(-20.0, 29.0, -45.0);
    glVertex3f(-20.0, 26.0, -45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20.0, 26.0, -82.0);
    glVertex3f(-20.0, 29.0, -82.0);
    glVertex3f(-27.0, 29.0, -82.0);
    glVertex3f(-27.0, 26.0, -82.0);
    glEnd();
     //pagar teras lantai3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 29.0, -82.0);
    glVertex3f(-20.0, 35.0, -82.0);
    glVertex3f(-27.0, 35.0, -82.0);
    glVertex3f(-27.0, 29.0, -82.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 29.0, -82.0);
    glVertex3f(-20, 35.0, -82.0);
    glVertex3f(-20, 35.0, -42.0);
    glVertex3f(-20.0, 29.0, -42.0);
    glEnd();


    //lantai jembatan antar lantai atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 26.0, -80.0);
    glVertex3f(3.0, 26.0, -80.0);
    glVertex3f(3.0, 26.0, -68.0);
    glVertex3f(95.0, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 29.0, -80.0);
    glVertex3f(3.0, 29.0, -80.0);
    glVertex3f(3.0, 29.0, -68.0);
    glVertex3f(95.0, 29.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 26.0, -80.0);
    glVertex3f(95.0, 29.0, -80.0);
    glVertex3f(95.0, 29.0, -68.0);
    glVertex3f(95.0, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 26.0, -68.0);
    glVertex3f(95.0, 29.0, -68.0);
    glVertex3f(3.0, 29.0, -68.0);
    glVertex3f(3.0, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 26.0, -80.0);
    glVertex3f(95.0, 29.0, -80.0);
    glVertex3f(3.0, 29.0, -80.0);
    glVertex3f(3.0, 26.0, -80.0);
    glEnd();

    //jembatan ke depan atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 26.0, -20.0);
    glVertex3f(75.0, 26.0, -20.0);
    glVertex3f(75.0, 26.0, -68.0);
    glVertex3f(52.0, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 29.0, -20.0);
    glVertex3f(75.0, 29.0, -20.0);
    glVertex3f(75.0, 29.0, -68.0);
    glVertex3f(52.0, 29.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.1, 26.0, -20.0);
    glVertex3f(52.1, 29.0, -20.0);
    glVertex3f(52.1, 29.0, -68.0);
    glVertex3f(52.1, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75.1, 26.0, -20.0);
    glVertex3f(75.1, 29.0, -20.0);
    glVertex3f(75.1, 29.0, -68.0);
    glVertex3f(75.1, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 26.0, -68.0);
    glVertex3f(52.0, 29.0, -68.0);
    glVertex3f(75.0, 29.0, -68.0);
    glVertex3f(75.0, 26.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 26.0, -20.0);
    glVertex3f(52.0, 29.0, -20.0);
    glVertex3f(75.0, 29.0, -20.0);
    glVertex3f(75.0, 26.0, -20.0);
    glEnd();
     //lantai jembatan antar lantai 4ke depan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 12.0, -20.0);
    glVertex3f(75.0, 12.0, -20.0);
    glVertex3f(75.0, 12.0, -68.0);
    glVertex3f(52.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 15.0, -20.0);
    glVertex3f(75.0, 15.0, -20.0);
    glVertex3f(75.0, 15.0, -68.0);
    glVertex3f(52.0, 15.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(72.0, 12.0, -20.0);
    glVertex3f(72.0, 15.0, -20.0);
    glVertex3f(72.0, 15.0, -68.0);
    glVertex3f(72.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 12.0, -68.0);
    glVertex3f(52.0, 15.0, -68.0);
    glVertex3f(75.0, 15.0, -68.0);
    glVertex3f(75.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 12.0, -20.0);
    glVertex3f(52.0, 15.0, -20.0);
    glVertex3f(75.0, 15.0, -20.0);
    glVertex3f(75.0, 12.0, -20.0);
    glEnd();
    //pagar4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75.1, 21.0, -20.0);
    glVertex3f(75.1, 15.0, -20.0);
    glVertex3f(75.1, 15.0, -68.0);
    glVertex3f(75.1, 21.0, -68.0);
    glEnd();

     //lantai jembatan antar lantai 3ke depan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 2.0, -20.0);
    glVertex3f(75.0, 2.0, -20.0);
    glVertex3f(75.0, 2.0, -68.0);
    glVertex3f(52.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -1.0, -20.0);
    glVertex3f(75.0, -1.0, -20.0);
    glVertex3f(75.0, -1.0, -68.0);
    glVertex3f(52.0, -1.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(72.0, 2.0, -20.0);
    glVertex3f(72.0, -1.0, -20.0);
    glVertex3f(72.0, -1.0, -68.0);
    glVertex3f(72.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 2.0, -68.0);
    glVertex3f(52.0, -1.0, -68.0);
    glVertex3f(75.0, -1.0, -68.0);
    glVertex3f(75.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, 2.0, -20.0);
    glVertex3f(52.0, -1.0, -20.0);
    glVertex3f(75.0, -1.0, -20.0);
    glVertex3f(75.0, 2.0, -20.0);
    glEnd();
    //pagar3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75.1, 2.0, -20.0);
    glVertex3f(75.1, 8.0, -20.0);
    glVertex3f(75.1, 8.0, -68.0);
    glVertex3f(75.1, 2.0, -68.0);
    glEnd();

     //lantai jembatan antar lantai 2ke depan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -11.0, -20.0);
    glVertex3f(75.0, -11.0, -20.0);
    glVertex3f(75.0, -11.0, -68.0);
    glVertex3f(52.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -14.0, -20.0);
    glVertex3f(75.0, -14.0, -20.0);
    glVertex3f(75.0, -14.0, -68.0);
    glVertex3f(52.0, -14.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(72.0, -11.0, -20.0);
    glVertex3f(72.0, -14.0, -20.0);
    glVertex3f(72.0, -14.0, -68.0);
    glVertex3f(72.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -11.0, -68.0);
    glVertex3f(52.0, -14.0, -68.0);
    glVertex3f(75.0, -14.0, -68.0);
    glVertex3f(75.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -11.0, -20.0);
    glVertex3f(52.0, -14.0, -20.0);
    glVertex3f(75.0, -14.0, -20.0);
    glVertex3f(75.0, -11.0, -20.0);
    glEnd();
    //pagar2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75.1, -11.0, -20.0);
    glVertex3f(75.1, -5.0, -20.0);
    glVertex3f(75.1, -5.0, -68.0);
    glVertex3f(75.1, -11.0, -68.0);
    glEnd();

    //jembatan ke depan atas
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -30.1, -20.0);
    glVertex3f(75.0, -30.1, -20.0);
    glVertex3f(75.0, -30.1, -68.0);
    glVertex3f(52.0, -30.1, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -27.0, -20.0);
    glVertex3f(75.0, -27.0, -20.0);
    glVertex3f(75.0, -27.0, -68.0);
    glVertex3f(52.0, -27.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.1, -30.0, -20.0);
    glVertex3f(52.1, -27.0, -20.0);
    glVertex3f(52.1, -27.0, -68.0);
    glVertex3f(52.1, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(75.1, -30.0, -20.0);
    glVertex3f(75.1, -27.0, -20.0);
    glVertex3f(75.1, -27.0, -68.0);
    glVertex3f(75.1, -20.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -30.0, -68.0);
    glVertex3f(52.0, -27.0, -68.0);
    glVertex3f(75.0, -27.0, -68.0);
    glVertex3f(75.0, -30.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(52.0, -30.0, -20.0);
    glVertex3f(52.0, -27.0, -20.0);
    glVertex3f(75.0, -27.0, -20.0);
    glVertex3f(75.0, -30.0, -20.0);
    glEnd();


    //lantai jembatan antar lantai 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 12.0, -80.0);
    glVertex3f(3.0, 12.0, -80.0);
    glVertex3f(3.0, 12.0, -68.0);
    glVertex3f(95.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 15.0, -80.0);
    glVertex3f(3.0, 15.0, -80.0);
    glVertex3f(3.0, 15.0, -68.0);
    glVertex3f(95.0, 15.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 12.0, -80.0);
    glVertex3f(95.0, 15.0, -80.0);
    glVertex3f(95.0, 15.0, -68.0);
    glVertex3f(95.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 12.0, -68.0);
    glVertex3f(95.0, 15.0, -68.0);
    glVertex3f(3.0, 15.0, -68.0);
    glVertex3f(3.0, 12.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 12.0, -80.0);
    glVertex3f(95.0, 15.0, -80.0);
    glVertex3f(3.0, 15.0, -80.0);
    glVertex3f(3.0, 12.0, -80.0);
    glEnd();
    //pagar4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 21.0, -80.0);
    glVertex3f(52.0, 15.0, -80.0);
    glVertex3f(78.0, 15.0, -80.0);
    glVertex3f(78.0, 21.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 21.0, -80.0);
    glVertex3f(95.0, 15.0, -80.0);
    glVertex3f(95.0, 15.0, -68.0);
    glVertex3f(95.0, 21.0, -68.0);
    glEnd();

    //lantai jembatan antar lantai 3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 2.0, -80.0);
    glVertex3f(3.0, 2.0, -80.0);
    glVertex3f(3.0, 2.0, -68.0);
    glVertex3f(95.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -1.0, -80.0);
    glVertex3f(3.0, -1.0, -80.0);
    glVertex3f(3.0, -1.0, -68.0);
    glVertex3f(95.0, -1.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 2.0, -80.0);
    glVertex3f(95.0, -1.0, -80.0);
    glVertex3f(95.0, -1.0, -68.0);
    glVertex3f(95.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 2.0, -68.0);
    glVertex3f(95.0, -1.0, -68.0);
    glVertex3f(3.0, -1.0, -68.0);
    glVertex3f(3.0, 2.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, 2.0, -80.0);
    glVertex3f(95.0, -1.0, -80.0);
    glVertex3f(3.0, -1.0, -80.0);
    glVertex3f(3.0, 2.0, -80.0);
    glEnd();
    //pagar3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, 2.0, -80.0);
    glVertex3f(52.0, 8.0, -80.0);
    glVertex3f(78.0, 8.0, -80.0);
    glVertex3f(78.0, 2.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, 2.0, -80.0);
    glVertex3f(95.0, 8.0, -80.0);
    glVertex3f(95.0, 8.0, -68.0);
    glVertex3f(95.0, 2.0, -68.0);
    glEnd();

     //lantai jembatan antar lantai 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -11.0, -80.0);
    glVertex3f(3.0, -11.0, -80.0);
    glVertex3f(3.0, -11.0, -68.0);
    glVertex3f(95.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -14.0, -80.0);
    glVertex3f(3.0, -14.0, -80.0);
    glVertex3f(3.0, -14.0, -68.0);
    glVertex3f(95.0, -14.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -11.0, -80.0);
    glVertex3f(95.0, -14.0, -80.0);
    glVertex3f(95.0, -14.0, -68.0);
    glVertex3f(95.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -11.0, -68.0);
    glVertex3f(95.0, -14.0, -68.0);
    glVertex3f(3.0, -14.0, -68.0);
    glVertex3f(3.0, -11.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -11.0, -80.0);
    glVertex3f(95.0, -14.0, -80.0);
    glVertex3f(3.0, -14.0, -80.0);
    glVertex3f(3.0, -11.0, -80.0);
    glEnd();
    //pagar2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(52.0, -11.0, -80.0);
    glVertex3f(52.0, -5.0, -80.0);
    glVertex3f(78.0, -5.0, -80.0);
    glVertex3f(78.0, -11.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.0, -11.0, -80.0);
    glVertex3f(95.0, -5.0, -80.0);
    glVertex3f(95.0, -5.0, -68.0);
    glVertex3f(95.0, -11.0, -68.0);
    glEnd();

    //lantai1
     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -27.0, -80.0);
    glVertex3f(3.0, -27.0, -80.0);
    glVertex3f(3.0, -27.0, -68.0);
    glVertex3f(95.0, -27.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -30.1, -80.0);
    glVertex3f(3.0, -30.1, -80.0);
    glVertex3f(3.0, -30.1, -68.0);
    glVertex3f(95.0, -30.1, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -27.0, -80.0);
    glVertex3f(95.0, -30.1, -80.0);
    glVertex3f(95.0, -30.1, -68.0);
    glVertex3f(95.0, -27.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -27.0, -68.0);
    glVertex3f(95.0, -30.1, -68.0);
    glVertex3f(3.0, -30.1, -68.0);
    glVertex3f(3.0, -27.0, -68.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95.0, -27.0, -80.0);
    glVertex3f(95.0, -30.1, -80.0);
    glVertex3f(3.0, -30.1, -80.0);
    glVertex3f(3.0, -27.0, -80.0);
    glEnd();





     //gedung bawah belakang1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -40.1);
    glVertex3f(-27.0, 33.0, -40.1);
    glVertex3f(-27.0, 33.0, -58.0);
    glVertex3f(-27.0, -35.0, -58.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -40.1);
    glVertex3f(-27.0, 33.0, -40.1);
    glVertex3f(-43.0, 33.0, -40.1);
    glVertex3f(-43.0, -35.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-43.0, -35.0, -58.0);
    glVertex3f(-43.0, 33.0, -58.0);
    glVertex3f(-43.0, 33.0, -40.0);
    glVertex3f(-43.0, -35.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-27.0, -35.0, -58.0);
    glVertex3f(-27.0, 33.0, -58.0);
    glVertex3f(-43.0, 33.0, -58.0);
    glVertex3f(-43.0, -35.0, -58.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-43.0, 31.1, -40.0);
    glVertex3f(-27.0, 31.1, -40.0);
    glVertex3f(-27.0, 31.1, -58.0);
    glVertex3f(-43.0, 31.1, -58.0);
    glEnd();

     //gedung bawah belakang2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-27.0, -35.0, -72.1);
    glVertex3f(-27.0, 33.0, -72.1);
    glVertex3f(-27.0, 33.0, -58.1);
    glVertex3f(-27.0, -35.0, -58.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-27.0, -35.0, -58.1);
    glVertex3f(-27.0, 33.0, -58.1);
    glVertex3f(-45.0, 33.0, -58.1);
    glVertex3f(-45.0, -35.0, -58.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-45.0, -35.0, -58.0);
    glVertex3f(-45.0, 33.0, -58.0);
    glVertex3f(-45.0, 33.0, -72.0);
    glVertex3f(-45.0, -35.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-27.0, -35.0, -72.0);
    glVertex3f(-27.0, 33.0, -72.0);
    glVertex3f(-45.0, 33.0, -72.0);
    glVertex3f(-45.0, -35.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, 31.1, -72.0);
    glVertex3f(-27.0, 31.1, -72.0);
    glVertex3f(-27.0, 31.1, -58.0);
    glVertex3f(-45.0, 31.1, -58.0);
    glEnd();


     //gedung bawah belakang3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -80.0);
    glVertex3f(-27.0, 33.0, -80.0);
    glVertex3f(-27.0, 33.0, -105.0);
    glVertex3f(-27.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -80.0);
    glVertex3f(-27.0, 33.0, -80.0);
    glVertex3f(-45.0, 33.0, -80.0);
    glVertex3f(-45.0, -35.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-45.0, -35.0, -80.0);
    glVertex3f(-45.0, 33.0, -80.0);
    glVertex3f(-45.0, 33.0, -105.0);
    glVertex3f(-45.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -105.0);
    glVertex3f(-27.0, 33.0, -105.0);
    glVertex3f(-45.0, 33.0, -105.0);
    glVertex3f(-45.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, 31.1, -80.0);
    glVertex3f(-27.0, 31.1, -80.0);
    glVertex3f(-27.0, 31.1, -105.0);
    glVertex3f(-45.0, 31.1, -105.0);
    glEnd();

    //gedung depan panjang
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-27.0, 5.0, -105.0);
    glVertex3f(-45.0, 5.0, -105.0);
    glVertex3f(-45.0, 5.0, -170.0);
    glVertex3f(-27.0, 5.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-27.0, 9.0, -105.0);
    glVertex3f(-45.0, 9.0, -105.0);
    glVertex3f(-45.0, 9.0, -170.0);
    glVertex3f(-27.0, 9.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-27.0, 9.0, -105.0);
    glVertex3f(-27.0, 5.0, -105.0);
    glVertex3f(-45.0, 5.0, -105.0);
    glVertex3f(-45.0, 9.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-27.0, 9.0, -105.0);
    glVertex3f(-27.0, 5.0, -105.0);
    glVertex3f(-27.0, 5.0, -170.0);
    glVertex3f(-27.0, 9.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, 9.0, -105.0);
    glVertex3f(-45.0, 5.0, -105.0);
    glVertex3f(-45.0, 5.0, -170.0);
    glVertex3f(-45.0, 9.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, 9.0, -170.0);
    glVertex3f(-45.0, 5.0, -170.0);
    glVertex3f(-27.0, 5.0, -170.0);
    glVertex3f(-27.0, 9.0, -170.0);
    glEnd();
    //atasnya
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.0, 9.0, -105.0);
    glVertex3f(-29.0, 12.0, -105.0);
    glVertex3f(-29.0, 12.0, -168.0);
    glVertex3f(-29.0, 9.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-29.5, 16.0, -105.0);
    glVertex3f(-29.5, 12.0, -105.0);
    glVertex3f(-29.5, 12.0, -168.0);
    glVertex3f(-29.5, 16.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-42.5, 16.0, -105.0);
    glVertex3f(-42.5, 12.0, -105.0);
    glVertex3f(-42.5, 12.0, -168.0);
    glVertex3f(-42.5, 16.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-29.5, 16.0, -168.0);
    glVertex3f(-29.5, 12.0, -168.0);
    glVertex3f(-42.5, 12.0, -168.0);
    glVertex3f(-42.5, 16.0, -168.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-30.0, 9.0, -105.0);
    glVertex3f(-30.0, 12.0, -105.0);
    glVertex3f(-30.0, 12.0, -167.0);
    glVertex3f(-30.0, 9.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.0, 12.0, -105.0);
    glVertex3f(-30.0, 12.0, -105.0);
    glVertex3f(-30.0, 12.0, -167.0);
    glVertex3f(-29.0, 12.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-43.0, 9.0, -105.0);
    glVertex3f(-43.0, 12.0, -105.0);
    glVertex3f(-42.0, 12.0, -167.0);
    glVertex3f(-42.0, 9.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-43.0, 9.0, -105.0);
    glVertex3f(-43.0, 12.0, -105.0);
    glVertex3f(-43.0, 12.0, -168.0);
    glVertex3f(-43.0, 9.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-43.0, 12.0, -105.0);
    glVertex3f(-42.0, 12.0, -105.0);
    glVertex3f(-42.0, 12.0, -167.0);
    glVertex3f(-43.0, 12.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.0, 9.0, -168.0);
    glVertex3f(-29.0, 12.0, -168.0);
    glVertex3f(-43.0, 12.0, -168.0);
    glVertex3f(-43.0, 9.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.0, 9.0, -167.0);
    glVertex3f(-29.0, 12.0, -167.0);
    glVertex3f(-43.0, 12.0, -167.0);
    glVertex3f(-43.0, 9.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.0, 12.0, -168.0);
    glVertex3f(-29.0, 12.0, -168.0);
    glVertex3f(-43.0, 12.0, -167.0);
    glVertex3f(-43.0, 12.0, -167.0);
    glEnd();
    //kotak pojok depan lantai
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.5, 9.0, -167.0);
    glVertex3f(-29.5, -8.0, -167.0);
    glVertex3f(-42.5, -8.0, -167.0);
    glVertex3f(-42.5, 9.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.5, 9.0, -150.0);
    glVertex3f(-29.5, -8.0, -150.0);
    glVertex3f(-42.5, -8.0, -150.0);
    glVertex3f(-42.5, 9.0, -150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-29.5, 9.0, -167.0);
    glVertex3f(-29.5, -8.0, -167.0);
    glVertex3f(-29.5, -8.0, -150.0);
    glVertex3f(-29.5, 9.0, -150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-42.5, 9.0, -167.0);
    glVertex3f(-42.5, -8.0, -167.0);
    glVertex3f(-42.5, -8.0, -150.0);
    glVertex3f(-42.5, 9.0, -150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-29.5, -1.0, -105.0);
    glVertex3f(-29.5, -8.0, -105.0);
    glVertex3f(-29.5, -8.0, -150.0);
    glVertex3f(-29.5, -1.0, -150.0);
    glEnd();


     //gedung depan panjang lantai
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-27.0, -12.0, -105.0);
    glVertex3f(-45.0, -12.0, -105.0);
    glVertex3f(-45.0, -12.0, -170.0);
    glVertex3f(-27.0, -12.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-27.0, -8.0, -105.0);
    glVertex3f(-45.0, -8.0, -105.0);
    glVertex3f(-45.0, -8.0, -170.0);
    glVertex3f(-27.0, -8.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-27.0, -12.0, -105.0);
    glVertex3f(-27.0, -8.0, -105.0);
    glVertex3f(-45.0, -8.0, -105.0);
    glVertex3f(-45.0, -12.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-27.0, -12.0, -105.0);
    glVertex3f(-27.0, -8.0, -105.0);
    glVertex3f(-27.0, -8.0, -170.0);
    glVertex3f(-27.0, -12.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, -12.0, -105.0);
    glVertex3f(-45.0, -8.0, -105.0);
    glVertex3f(-45.0, -8.0, -170.0);
    glVertex3f(-45.0, -12.0, -170.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, -12.0, -170.0);
    glVertex3f(-45.0, -8.0, -170.0);
    glVertex3f(-27.0, -8.0, -170.0);
    glVertex3f(-27.0, -12.0, -170.0);
    glEnd();
    //bawahnya
     glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-29.0, -15.0, -105.0);
    glVertex3f(-29.0, -12.0, -105.0);
    glVertex3f(-29.0, -12.0, -168.0);
    glVertex3f(-29.0, -15.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-43.0, -15.0, -105.0);
    glVertex3f(-43.0, -12.0, -105.0);
    glVertex3f(-43.0, -12.0, -168.0);
    glVertex3f(-43.0, -15.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-43.0, -15.0, -105.0);
    glVertex3f(-42.0, -15.0, -105.0);
    glVertex3f(-42.0, -15.0, -167.0);
    glVertex3f(-43.0, -15.0, -167.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-29.0, -15.0, -168.0);
    glVertex3f(-29.0, -12.0, -168.0);
    glVertex3f(-43.0, -12.0, -168.0);
    glVertex3f(-43.0, -15.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-29.0, -15.0, -105.0);
    glVertex3f(-43.0, -15.0, -105.0);
    glVertex3f(-43.0, -15.0, -168.0);
    glVertex3f(-29.0, -15.0, -168.0);
    glEnd();
    //tiang penyangga1
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -168.0);
    glVertex3f(-30.0, -35.0, -168.0);
    glVertex3f(-33.0, -35.0, -168.0);
    glVertex3f(-33.0, -15.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -165.0);
    glVertex3f(-30.0, -35.0, -165.0);
    glVertex3f(-33.0, -35.0, -165.0);
    glVertex3f(-33.0, -15.0, -165.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-33.0, -15.0, -165.0);
    glVertex3f(-33.0, -35.0, -165.0);
    glVertex3f(-33.0, -35.0, -168.0);
    glVertex3f(-33.0, -15.0, -168.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -165.0);
    glVertex3f(-30.0, -35.0, -165.0);
    glVertex3f(-30.0, -35.0, -168.0);
    glVertex3f(-30.0, -15.0, -168.0);
    glEnd();

    //tiang penyangga2
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-39.0, -15.0, -168.0);
    glVertex3f(-39.0, -35.0, -168.0);
    glVertex3f(-42.0, -35.0, -168.0);
    glVertex3f(-42.0, -15.0, -168.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-39.0, -15.0, -165.0);
    glVertex3f(-39.0, -35.0, -165.0);
    glVertex3f(-42.0, -35.0, -165.0);
    glVertex3f(-42.0, -15.0, -165.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-39.0, -15.0, -165.0);
    glVertex3f(-39.0, -35.0, -165.0);
    glVertex3f(-39.0, -35.0, -168.0);
    glVertex3f(-39.0, -15.0, -168.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-42.0, -15.0, -165.0);
    glVertex3f(-42.0, -35.0, -165.0);
    glVertex3f(-42.0, -35.0, -168.0);
    glVertex3f(-42.0, -15.0, -168.0);
    glEnd();

     //tiang penyangga3
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-40.0, -15.0, -138.0);
    glVertex3f(-40.0, -35.0, -138.0);
    glVertex3f(-42.0, -35.0, -138.0);
    glVertex3f(-42.0, -15.0, -138.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-40.0, -15.0, -136.0);
    glVertex3f(-40.0, -35.0, -136.0);
    glVertex3f(-42.0, -35.0, -136.0);
    glVertex3f(-42.0, -15.0, -136.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-40.0, -15.0, -136.0);
    glVertex3f(-40.0, -35.0, -136.0);
    glVertex3f(-40.0, -35.0, -138.0);
    glVertex3f(-40.0, -15.0, -138.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-42.0, -15.0, -136.0);
    glVertex3f(-42.0, -35.0, -136.0);
    glVertex3f(-42.0, -35.0, -138.0);
    glVertex3f(-42.0, -15.0, -138.0);
    glEnd();

     //tiang penyangga4
     glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -138.0);
    glVertex3f(-30.0, -35.0, -138.0);
    glVertex3f(-32.0, -35.0, -138.0);
    glVertex3f(-32.0, -15.0, -138.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -136.0);
    glVertex3f(-30.0, -35.0, -136.0);
    glVertex3f(-32.0, -35.0, -136.0);
    glVertex3f(-32.0, -15.0, -136.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-30.0, -15.0, -136.0);
    glVertex3f(-30.0, -35.0, -136.0);
    glVertex3f(-30.0, -35.0, -138.0);
    glVertex3f(-30.0, -15.0, -138.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-32.0, -15.0, -136.0);
    glVertex3f(-32.0, -35.0, -136.0);
    glVertex3f(-32.0, -35.0, -138.0);
    glVertex3f(-32.0, -15.0, -138.0);
    glEnd();

    //gedung paling depan sisi blkng
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, -35.0, -180.0);
    glVertex3f(-10.0, 3.0, -180.0);
    glVertex3f(45.0, 3.0, -180.0);
    glVertex3f(45.0, -35.0, -180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, -35.0, -155.0);
    glVertex3f(-10.0, -32.0, -155.0);
    glVertex3f(45.0, -32.0, -155.0);
    glVertex3f(45.0, -35.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, 3.0, -155.0);
    glVertex3f(-10.0, -8.0, -155.0);
    glVertex3f(30.0, -8.0, -155.0);
    glVertex3f(30.0, 3.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(45.0, 3.0, -155.1);
    glVertex3f(45.0, -35.0, -155.1);
    glVertex3f(38.0, -35.0, -155.1);
    glVertex3f(38.0, 3.0, -155.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(45.0, -35.0, -180.0);
    glVertex3f(45.0, 3.0, -180.0);
    glVertex3f(45.0, 3.0, -155.0);
    glVertex3f(45.0, -35.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, -35.0, -180.0);
    glVertex3f(-10.0, 3.0, -180.0);
    glVertex3f(-10.0, 3.0, -155.0);
    glVertex3f(-10.0, -35.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, 3.0, -180.0);
    glVertex3f(45.0, 3.0, -180.0);
    glVertex3f(45.0, 3.0, -155.0);
    glVertex3f(-10.0, 3.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-10.0, -32.0, -180.0);
    glVertex3f(45.0, -32.0, -180.0);
    glVertex3f(45.0, -32.0, -155.0);
    glVertex3f(-10.0, -32.0, -155.0);
    glEnd();
    //genting gedung depan bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, 3.0, -180.0);
    glVertex3f(49.0, 3.0, -180.0);
    glVertex3f(49.0, 3.0-1, -185.0);
    glVertex3f(-14.0, 3.0-1, -185.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, 3.0-1, -150.0);
    glVertex3f(49.0, 3.0-1, -150.0);
    glVertex3f(49.0, 3.0, -155.0);
    glVertex3f(-14.0, 3.0, -155.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, 3.0-1, -185.0);
    glVertex3f(-10.0, 3.0, -185.0);
    glVertex3f(-10.0, 3.0, -150.0);
    glVertex3f(-14.0, 3.0-1, -150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(44.0, 3.0, -185.0);
    glVertex3f(49.0, 3.0-1, -185.0);
    glVertex3f(49.0, 3.0-1, -150.0);
    glVertex3f(44.0, 3.0, -150.0);
    glEnd();
    //gedung bawah belakang4
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -80.0);
    glVertex3f(-46.0, 27.0, -80.0);
    glVertex3f(-46.0, 27.0, -100.0);
    glVertex3f(-46.0, -30.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -80.0);
    glVertex3f(-46.0, 27.0, -80.0);
    glVertex3f(-64.0, 27.0, -80.0);
    glVertex3f(-64.0, -30.0, -80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-64.0, -35.0, -80.0);
    glVertex3f(-64.0, 27.0, -80.0);
    glVertex3f(-64.0, 27.0, -100.0);
    glVertex3f(-64.0, -35.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -35.0, -100.0);
    glVertex3f(-46.0, 27.0, -100.0);
    glVertex3f(-64.0, 27.0, -100.0);
    glVertex3f(-64.0, -35.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-64.0, 25.1, -80.0);
    glVertex3f(-46.0, 25.1, -80.0);
    glVertex3f(-46.0, 25.1, -100.0);
    glVertex3f(-64.0, 25.1, -100.0);
    glEnd();
    //gedung bawah belakang5
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-64.0, -30.0, -72.0);
    glVertex3f(-64.0, 27.0, -72.0);
    glVertex3f(-64.0, 27.0, -105.0);
    glVertex3f(-64.0, -30.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-64.0, -30.0, -72.0);
    glVertex3f(-64.0, 27.0, -72.0);
    glVertex3f(-90.0, 27.0, -72.0);
    glVertex3f(-90.0, -30.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-90.0, -35.0, -72.0);
    glVertex3f(-90.0, 27.0, -72.0);
    glVertex3f(-90.0, 27.0, -105.0);
    glVertex3f(-90.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-64.0, -35.0, -105.0);
    glVertex3f(-64.0, 27.0, -105.0);
    glVertex3f(-90.0, 27.0, -105.0);
    glVertex3f(-90.0, -35.0, -105.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-90.0, 25.1, -72.0);
    glVertex3f(-64.0, 25.1, -72.0);
    glVertex3f(-64.0, 25.1, -105.0);
    glVertex3f(-90.0, 25.1, -105.0);
    glEnd();
     //gedung bawah belakang6
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -30.0, -80.0);
    glVertex3f(-27.0, 27.0, -80.0);
    glVertex3f(-27.0, 27.0, -72.0);
    glVertex3f(-27.0, -30.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -30.0, -79.0);
    glVertex3f(-27.0, 27.0, -79.0);
    glVertex3f(-64.0, 27.0, -79.0);
    glVertex3f(-64.0, -30.0, -79.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-64.0, -35.0, -80.0);
    glVertex3f(-64.0, 27.0, -80.0);
    glVertex3f(-64.0, 27.0, -72.0);
    glVertex3f(-64.0, -35.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-27.0, -35.0, -72.0);
    glVertex3f(-27.0, 27.0, -72.0);
    glVertex3f(-64.0, 27.0, -72.0);
    glVertex3f(-64.0, -35.0, -72.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-64.0, 25.1, -80.0);
    glVertex3f(-27.0, 25.1, -80.0);
    glVertex3f(-27.0, 25.1, -72.0);
    glVertex3f(-64.0, 25.1, -72.0);
    glEnd();
    //gedung bawah belakang7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -71.0);
    glVertex3f(-46.0, 27.0, -71.0);
    glVertex3f(-46.0, 27.0, -57.0);
    glVertex3f(-46.0, -30.0, -57.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -71.0);
    glVertex3f(-46.0, 27.0, -71.0);
    glVertex3f(-80.0, 27.0, -71.0);
    glVertex3f(-80.0, -30.0, -71.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-80.0, -35.0, -57.0);
    glVertex3f(-80.0, 27.0, -57.0);
    glVertex3f(-80.0, 27.0, -71.0);
    glVertex3f(-80.0, -35.0, -71.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -35.0, -57.0);
    glVertex3f(-46.0, 27.0, -57.0);
    glVertex3f(-80.0, 27.0, -57.0);
    glVertex3f(-80.0, -35.0, -57.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-80.0, 25.1, -57.0);
    glVertex3f(-46.0, 25.1, -57.0);
    glVertex3f(-46.0, 25.1, -71.0);
    glVertex3f(-80.0, 25.1, -71.0);
    glEnd();
    //gedung bawah belakang8
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -57.0);
    glVertex3f(-46.0, 30.0, -57.0);
    glVertex3f(-46.0, 30.0, -40.0);
    glVertex3f(-46.0, -30.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -30.0, -40.0);
    glVertex3f(-46.0, 30.0, -40.0);
    glVertex3f(-70.0, 30.0, -40.0);
    glVertex3f(-70.0, -30.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-70.0, -35.0, -57.0);
    glVertex3f(-70.0, 30.0, -57.0);
    glVertex3f(-70.0, 30.0, -40.0);
    glVertex3f(-70.0, -35.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-46.0, -35.0, -57.0);
    glVertex3f(-46.0, 30.0, -57.0);
    glVertex3f(-70.0, 30.0, -57.0);
    glVertex3f(-70.0, -35.0, -57.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-70.0, 28.1, -57.0);
    glVertex3f(-46.0, 28.1, -57.0);
    glVertex3f(-46.0, 28.1, -40.0);
    glVertex3f(-70.0, 28.1, -40.0);
    glEnd();
    //gedung bawah belakang9
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-71.0, -30.0, -57.0);
    glVertex3f(-71.0, 30.0, -57.0);
    glVertex3f(-71.0, 30.0, -40.0);
    glVertex3f(-71.0, -30.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-71.0, -30.0, -40.0);
    glVertex3f(-71.0, 30.0, -40.0);
    glVertex3f(-95.0, 30.0, -40.0);
    glVertex3f(-95.0, -30.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-95.0, -35.0, -57.0);
    glVertex3f(-95.0, 30.0, -57.0);
    glVertex3f(-95.0, 30.0, -40.0);
    glVertex3f(-95.0, -35.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-71.0, -35.0, -57.0);
    glVertex3f(-71.0, 30.0, -57.0);
    glVertex3f(-95.0, 30.0, -57.0);
    glVertex3f(-95.0, -35.0, -57.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-95.0, 28.1, -57.0);
    glVertex3f(-71.0, 28.1, -57.0);
    glVertex3f(-71.0, 28.1, -40.0);
    glVertex3f(-95.0, 28.1, -40.0);
    glEnd();

    //Jalan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, -34.1, -155.0);
    glVertex3f(200.0, -34.1, -155.0);
    glVertex3f(200.0, -34.1, -110.0);
    glVertex3f(10.0, -34.1, -110.0);

    glVertex3f(135.0, -34.1, -165.0);
    glVertex3f(160.0, -34.1, -165.0);
    glVertex3f(160.0, -34.1, -55.0);
    glVertex3f(135.0, -34.1, -55.0);

    glVertex3f(100.0, -34.1, -80.0);
    glVertex3f(135.0, -34.1, -80.0);
    glVertex3f(135.0, -34.1, -55.0);
    glVertex3f(100.0, -34.1, -55.0);

    //jalanmiring
    glVertex3f(175.0, -34.1, -135.0);
    glVertex3f(200.0, -34.1, -115.0);
    glVertex3f(110.0, -34.1, 150.0);
    glVertex3f(130.0, -34.1, 150.0);
glEnd();

   glBegin(GL_QUADS);
    glColor3f(0.60, 0.40, 0.10);
    //parkiran
    glVertex3f(45.0, -34.1, -195.0);
    glVertex3f(195.0, -34.1, -195.0);
    glVertex3f(195.0, -34.1, -160.0);
    glVertex3f(45.0, -34.1, -160.0);

    //parkiran2
    glVertex3f(-10.0, -34.1, 55.0);
    glVertex3f(145.0, -34.1, 55.0);
    glVertex3f(110.0, -34.1, 150.0);
    glVertex3f(-10.0, -34.1, 150.0);

    glVertex3f(105.0, -34.1, 5.0);
    glVertex3f(160.0, -34.1, 5.0);
    glVertex3f(145.0, -34.1, 55.0);
    glVertex3f(105.0, -34.1, 55.0);
    glEnd();
    //taman
        glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(40.0, -33.4, -143.0);
    glVertex3f(60.0, -33.4, -143.0);
    glVertex3f(60.0, -33.4, -123.0);
    glVertex3f(40.0, -33.4, -123.0);

    glVertex3f(90.0, -33.4, -135.0);
    glVertex3f(135.0, -33.4, -135.0);
    glVertex3f(135.0, -33.4, -130.0);
    glVertex3f(90.0, -33.4, -130.0);

    glVertex3f(160.0, -33.4, -135.0);
    glVertex3f(190.0, -33.4, -135.0);
    glVertex3f(190.0, -33.4, -130.0);
    glVertex3f(160.0, -33.4, -130.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case 'q':
    case 'Q':
        ymov += 3.0;
        break;
    case 'e':
    case 'E':
        ymov -= 3.0;
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
