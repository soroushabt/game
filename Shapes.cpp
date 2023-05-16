
#include "Shapes.h"
#include<Shapegenerator.h>
#include<iostream>
#include<random>

Shapes::Shapes(Shapegenerator* data)
    :m_data(data)
    ,m_mindist(0)
{
}
double Shapes::mindist() const
{
    return m_mindist;
}

void Shapes::setMindist(double newMindist)
{
    m_mindist = newMindist;
    m_getmindist(newMindist);
}

void Shapes::callbackmethod(std::function<void(double)> f)
{
    m_getmindist=f;
}


QVector<double> Shapes::distances() const
{
    return m_distances;
}


bool Shapes::isonline(double xmouse, double ymouse, int lvl)
{
    QVector<int> temp;
    QVector<double> temp2;
    double distance = 0;
    temp = m_data->xy();
    temp.prepend(200);
    temp.prepend(0);

    int linewidth = lvl;
    for (int i = 0; i < 26; i += 2) {
        // Get the endpoints of the line segment
        double x1 = temp[i];
        double y1 = temp[i + 1];
        double x2 = temp[i + 2];
        double y2 = temp[i + 3];

        // Calculate the length and direction of the line segment
        double dx = x2 - x1;
        double dy = y2 - y1;
        double segmentLength = std::sqrt(dx * dx + dy * dy);
        double segmentDirectionX = dx / segmentLength;
        double segmentDirectionY = dy / segmentLength;

        // Calculate the projection of the point onto the line segment
        double segmentProjection = (xmouse - x1) * segmentDirectionX + (ymouse - y1) * segmentDirectionY;
        double segmentProjectionX = x1 + segmentProjection * segmentDirectionX;
        double segmentProjectionY = y1 + segmentProjection * segmentDirectionY;

        // Check if the projection lies within the segment
        if (segmentProjection >= 0 && segmentProjection <= segmentLength) {
            // Calculate the distance between the point and the projection
            distance = std::sqrt((xmouse - segmentProjectionX) * (xmouse - segmentProjectionX) + (ymouse - segmentProjectionY) * (ymouse - segmentProjectionY));
            temp2.append(distance);

            // Check if the distance is within the line width
            if (distance <= linewidth / 2) {
                setMindist(0);
                return true;
            }
        }
        else {
            // If the projection does not lie within the segment, calculate the distances to the endpoints of the segment
            double distance1 = std::sqrt((xmouse - x1) * (xmouse - x1) + (ymouse - y1) * (ymouse - y1));
            double distance2 = std::sqrt((xmouse - x2) * (xmouse - x2) + (ymouse - y2) * (ymouse - y2));
            temp2.append(std::min(distance1, distance2));

            // Check if either of the distances is within the line width
            if (distance1 <= linewidth / 2 || distance2 <= linewidth / 2) {
                setMindist(0);
                return true;
            }
        }
    }

    // Calculate the distance between the point and the first line segment of the polygon
    auto m = (double)((temp[3] - temp[1])) / (temp[2] - temp[0]);
    auto b = temp[1] - m * temp[0];
    distance = std::abs((ymouse - m * xmouse - b) / std::sqrt(1 + m * m));
    temp2.append(distance);

    auto minmumdistance = *std::min_element(temp2.begin(), temp2.end());
    setMindist(minmumdistance);
    std::cerr << minmumdistance << std::endl;
    m_distances.append(minmumdistance);

    return false;
}

