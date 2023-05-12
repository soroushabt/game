
#ifndef SHAPES_H
#define SHAPES_H

#include<vector>
#include<QVector>
#include<functional>

class Shapegenerator;

class Shapes
{
    QVector<double> m_distances;
    double m_mindist;
    Shapegenerator* m_data;
    std::function<void(double)> m_getmindist;
public:
    Shapes(Shapegenerator* data);
    bool isonline(double xmouse, double ymouse, int lvl);
    QVector<double> distances() const;
    double mindist() const;
    void setMindist(double newMindist);
    void callbackmethod(std::function<void(double)> f);
};

#endif // SHAPES_H
