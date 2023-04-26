import QtQuick
import QtQuick.Shapes


Shape {
    anchors.centerIn: parent
    ShapePath
    {
        strokeWidth: 3
        strokeColor: "red"
//        fillColor: "lightGray"
        startX: 0; startY: 0
        PathLine
        {
            x: 0
            y: 0
        }
    }
}


