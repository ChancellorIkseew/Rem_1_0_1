#ifndef IMPORTER_3D_CPP
#define IMPORTER_3D_CPP

#include "importer_3d.h"

#include <windows.h>
#include <gl/gl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>



#include <list>





void openFile(std::string fileName)
{
	std::ifstream fin;


	fin.open(fileName);



	if (fin.is_open())
	{
		char c;

		do
		{
			fin.get(c);
			if (c == 'v')
			{
				float v1, v2, v3;

				fin >> v1 >> v2 >> v3;
			}

		} while (c != '$');
		
		


	}
	fin.close();
}

void oFile()
{
    std::ifstream file("3d_models/cube.obj");
    std::string line;
    std::vector<rem1::vertex> vertices;
    std::vector<std::tuple<int, int, int>> polygons;

    while (std::getline(file, line)) 
    {
        if (line[0] == 'v') 
        {
            std::istringstream iss(line);
            char ch;
            double x, y, z;
            iss >> ch >> x >> y >> z;
            vertices.emplace_back(x, y, z);
        }
        else if (line[0] == 'f') 
        {
            std::istringstream iss(line);
            char ch;
            int v1, v2, v3;
            iss >> ch >> v1 >> v2 >> v3;
            polygons.emplace_back(v1, v2, v3);
        }
    }

    // Пример работы с этими данными
    std::cout << vertices[4].X << "; " << vertices[4].Y << "; " << vertices[4].Z << std::endl;
    std::cout << std::get<0>(polygons[2]) << "; " << std::get<1>(polygons[2]) << "; " << std::get<2>(polygons[2]) << std::endl;


	return;
}

//int arr[];

//std::list<arr*> vertexList;



#endif // IMPORTER_3D_CPP