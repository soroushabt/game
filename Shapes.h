
#ifndef SHAPES_H
#define SHAPES_H

#include<vector>
#include<QVector>

class Shapegenerator;

class Shapes
{
    QVector<double> m_distances;
    double m_mindist;
    Shapegenerator* m_data;
public:
    Shapes(Shapegenerator* data);
    bool isonline(double xmouse, double ymouse, int lvl);
    QVector<double> distances() const;
    double mindist() const;
    void setMindist(double newMindist);
};

#endif // SHAPES_H
