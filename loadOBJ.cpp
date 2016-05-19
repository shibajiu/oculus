#include "loadObj.h"

int Obj_Load(string ObjPath, vector<Face> *obj)
{
	obj->clear();
	char buffer[256];
	float f1, f2, f3;
	int i1, i2, i0;
	fstream objFile;
	objFile.open(ObjPath, ios::in);
	if (!objFile.is_open())
		return 0;
	while (!objFile.eof()) {//get vertices,faces,normals
		objFile.getline(buffer, 256, '\n');
		if (buffer[0] == 'v' && (buffer[1] == ' ' || buffer[1] == 32)){
			if (sscanf_s(buffer, "v %f %f %f", &f1, &f2, &f3) == 3){
				Vertices.push_back(Vertex(f1, f2, f3));
			}
			else{
				fprintf(stderr, "ERROR: vertex not in wanted format in OBJLoader\n");
				exit(0);
			}
		}
		else if (buffer[0] == 'f' && (buffer[1] == ' ' || buffer[1] == 32)){
			if (sscanf_s(buffer, "f %d %d %d", &i0, &i1, &i2) == 3){
				Indexs.push_back(FaceIndex(i0, i1, i2));
			}
			else{
				fprintf(stderr, "ERROR: FaceIndex not in wanted format in OBJLoader\n");
				exit(0);
			}
		}
	}
	objFile.close();//close file

	int len = Indexs.size();
	for (int i = 0; i<len; ++i){
		facetemp.set(Vertices, Indexs[i]);
		obj->push_back(facetemp);
	}

	return 1;
}

vector<Face> Obj_Load(string ObjPath)
{
	vector<Face> obj;
	Obj_Load(ObjPath, &obj);
	return obj;
}



void getMaxXYZ(float *x, float *y, float *z)
{
	*x = MaxPoint.x;
	*y = MaxPoint.y;
	*z = MaxPoint.z;
}

void getMinXYZ(float *x, float *y, float *z)
{
	*x = MinPoint.x;
	*y = MinPoint.y;
	*z = MinPoint.z;
}
