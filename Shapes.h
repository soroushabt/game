
#ifndef SHAPES_H
#define SHAPES_H

#include<vector>
#include<QVector>

class Shapegenerator;

class Shapes
{
    QVector<double> m_distances;
    Shapegenerator* m_data;
public:
    Shapes(Shapegenerator* data);
    bool isonline(double xmouse, double ymouse);
};

#endif // SHAPES_H
