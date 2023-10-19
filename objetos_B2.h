//**************************************************************************
// Práctica 2 
// Alumno: Sergio Zapata De la Hoz
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void 	asignar_gama_colores();
void 	draw(_modo modo, float r, float g, float b, float grosor);


vector<_vertex3i> caras;
vector<_vertex3f> colores_caras; 
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};

//*************************************************************************
// clase rombo 3D
//*************************************************************************


class _rombo3D: public _triangulos3D
{
public:

	_rombo3D(float tam=0.5, float al=1.0);
};



//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
    _rotacion();
       
	void  parametros(vector<_vertex3f> perfil, int num, int tapa_in, int tapa_su, int tipo); // tapa inferior y superior
	// todo añadir parametro tipo: tipo0 revolucion normal , 1 esfera, 2 cono
	void asignar_gama_random_colores(int num_caras);
	void asignar_gama_colores(int num_caras);
};


//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};

class _cilindro: public _rotacion
{
public:
       _cilindro(float radio, float altura, int lados);
};

class _cono: public _rotacion
{
public:
       _cono(float radio, float altura, int lados);
};

class _esfera: public _rotacion
{
public:
       _esfera(float radio, int lados);
};





