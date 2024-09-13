#pragma once
#ifndef IMPORTER_3D_H
#define IMPORTER_3D_H

#include <string>


void openFile(std::string fileName);

namespace rem1
{
    struct vertex
    {
        double X;
        double Y;
        double Z;

        vertex(double x, double y, double z)
        {
            X = x; Y = y; Z = z;
        }
    };
}

void oFile();


#endif // IMPORTER_3D