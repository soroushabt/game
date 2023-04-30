
#include "Shapes.h"
#include<Shapegenerator.h>
#include<iostream>
#include<random>

Shapes::Shapes(Shapegenerator* data)
    :m_data(data)
{

}

bool Shapes::isonline(double xmouse, double ymouse)
{
    //    std::cerr << "log" << std::endl;
    QVector<int> temp;
    QVector<double> temp2;
    bool flag=false;
    double distance=0;
    temp = m_data->xy();
    temp.prepend(200);
    temp.prepend(0);

//        for(auto &item : temp)
//        {
//            std::cerr << item << "temp"<< std::endl;
//        }
    //    for(auto &item : m_numbers)
    //    {
    //        std::cerr << item << "m_numbers" << std::endl;
    //    }
    //    std::cerr << temp.size() << " ----size" << std::endl;

    int linewidth=4;
    for(int i=0 ; i<27 ; i+=2)
    {
        // Calculate the equation of the line in the form y = mx + b
        auto m = (double)((temp[i+3] - temp[i+1])) / (temp[i+2] - temp[i+0]);
        //        std::cerr << i <<  "slope" << m << std::endl;
        auto b = temp[i+1] - m * temp[i+0];
        //        std::cerr << "arz az mabdae "<< b << std::endl;

        // Calculate the area around the line within which a point is considered to be on the line
        //        auto rectX = std::min(temp[i+0], temp[i+2]) - linewidth / 2;
        //        auto rectY = std::min(temp[i+1], temp[i+3]) - linewidth / 2;
        //        auto rectWidth = std::abs(temp[i+2] - temp[i+0]) + linewidth;
        //        auto rectHeight = std::abs(temp[i+3] - temp[i+1]) + linewidth;


        distance = std::abs((ymouse - m * xmouse - b) / std::sqrt(1 + m * m));
        temp2.append(distance);

        if(distance <= linewidth / 2)
            return true;


        // Check if the point (x, y) lies within the rectangular area centered around the line equation
        //        if (xmouse >= rectX && xmouse <= rectX + rectWidth && ymouse >= rectY && ymouse <= rectY + rectHeight)
        //        {
        //        }
        //        else if(flag)
        //        {
        //            m_distances.append(distance);
        //            std::cerr << "distance: " << lastdistance << std::endl;
        //        }
    }

    auto minmumdistance = *std::min_element(temp2.begin(),temp2.end());
//    for(auto&item : temp2)
//    {
//        std::cerr << item << std::endl;
//    }
    std::cerr << minmumdistance<< std::endl;
    m_distances.append(minmumdistance);


    return false;
}

