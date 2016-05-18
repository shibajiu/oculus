#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Vertex{//vertex
	float x;
	float y;
	float z;
	Vertex(){}
	Vertex(float a, float b, float c){
		x = a;
		y = b;
		z = c;
	}
	void set(float xf, float yf, float zf){
		this->x = xf;
		this->y = yf;
		this->z = zf;
	}

	float getMax(){
		return max(max(this->x, this->y), max(this->y, this->z));
	}

	float getMin(){
		return min(min(this->x, this->y), min(this->y, this->z));
	}

	void init(){
		this->set(0, 0, 0);
	}

	void setX(float xf){
		this->x = xf;
	}

	void setY(float yf){
		this->y = yf;
	}

	void setZ(float zf){
		this->z = zf;
	}

	/**
	use to find the view volume
	**/
	void findMaxAbs(Vertex cmp){
		if (abs(this->x)<abs(cmp.x))
			this->setX(cmp.x);
		if (abs(this->y)<abs(cmp.y))
			this->setY(cmp.y);
		if (abs(this->z)<abs(cmp.z))
			this->setZ(cmp.z);
	}

	/**
	use to find the view volume
	**/
	void findMinAbs(Vertex cmp){
		if (abs(this->x)>abs(cmp.x))
			this->setX(cmp.x);
		if (abs(this->y)>abs(cmp.y))
			this->setY(cmp.y);
		if (abs(this->z)>abs(cmp.z))
			this->setZ(cmp.z);
	}
};

struct FaceIndex{//face index
	int a;
	int b;
	int c;
	FaceIndex(){}
	FaceIndex(int x, int y, int z) :a(x), b(y), c(z){}
};

struct Normal{//normal
	float x;
	float y;
	float z;
	Normal(){}
	Normal(float a, float b, float c) :x(a), y(b), z(c){}
};

struct Face{
	Vertex a;
	Vertex b;
	Vertex c;
	Face(){}
	void set(vector<Vertex> ver, FaceIndex ind){
		this->a = ver[ind.a - 1];
		this->b = ver[ind.b - 1];
		this->c = ver[ind.c - 1];
	}
};


int Obj_Load(string ObjPath, vector<Face> *obj);
vector<Face> Obj_Load(string ObjPath);
	void getMaxXYZ(float *x, float *y, float *z);
	void getMinXYZ(float *x, float *y, float *z);


static	vector<Vertex> Vertices;	
static	vector<FaceIndex> Indexs;
static	vector<Normal> Normals;
static	vector<Face> Faces;
static	Face facetemp;
static	Normal normaltemp;
static	FaceIndex faceindextemp;
static	Vertex vertextemp, MaxPoint, MinPoint;