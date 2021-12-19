#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Material
{
	int drawp, start, meshid;
};
class ModelData
{
public:
	ModelData(string path);
	float* vertex;
	int* index;
	Material* material;
	int vertexsize = 0;
	int indexsize = 0;
	int materialsize = 0;
private:

};

ModelData::ModelData(string path)
{
	ifstream file(path, ios::binary);
	if (file.is_open())
	{
		cout << "文件打开成功" << endl;
	}
	else {
		cout << "文件打开失败" << endl;
	}
	
	file.read((char*)&vertexsize, sizeof(int));
	vertex = new float[vertexsize];
	file.read((char*)vertex, vertexsize * sizeof(float));
	
	file.read((char*)&indexsize, sizeof(int));
	index = new int[indexsize];
	file.read((char*)index, sizeof(int) * indexsize);

	file.read((char*)&materialsize, sizeof(int));
	material = new Material[materialsize];
	file.read((char*)material, sizeof(Material) * materialsize);

	file.close();
}
