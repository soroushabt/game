import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.0
import QtQuick.Layouts
import QtQuick.Shapes
import Viewmodels 1.0
import Shapegenrators 1.0


Window {
    property Viewmodel mymodel: mainviewmodel
    property Shapegenrator shapeone: shapegenratorcontext


    minimumWidth: 600
    minimumHeight: 600
    maximumHeight: 600
    maximumWidth: 600
    visible: true
    title: qsTr("Soroush Game")
    color: "#ECEDEE"


    Item{
        id: maincontainer
        width: parent.width-50
        height: parent.height -50
        anchors.centerIn: parent
        //        PaddedRectangle: 10
        Rectangle
        {
            id: clientdata
            anchors.fill: maincontainer.top
            height: 100
            width: maincontainer.width
            border.width: 0
            color: "#C9E7FB"

            RowLayout{
                anchors.centerIn: parent
                //  anchors.fill: parent
                TextField{

                    placeholderText: "name"
                }
                TextField{
                    placeholderText: "family"
                }

                ComboBox
                {
                    model: ["easy","medium","hard"]
                    onCurrentIndexChanged:
                    {
                        mymodel.lvlgame = currentIndex
                    }
                }
                Button
                {
                        background: Rectangle {
                            color: "green"
                            radius: 6
                        }
                        contentItem: Text {
                            text: "start"
                            color: "white"
                            font: control.font
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }

                        onClicked:
                        {
                            var test = shapeone.pathline()
                            console.log(test[0])
                        }
                }
            }
        }
        Rectangle
        {
            anchors.top: clientdata.bottom
            anchors.topMargin: 5
            height: 450
            width: maincontainer.width
            Shape {
//               ListModel {
//                    id: myPositions
//                }

                function createPathLineElements(shapePath)
                {

//                    myPositions.append({"x":myX, "y":getRandomInt(0,30)})

                    var pathElements = []
                    for (var i = 0; i < 20; i++)
                    {
//                        var pos = myPositions.get(i)
                        var pathLine = Qt.createQmlObject('import QtQuick 2.15; PathLine {}',
                                                          shapePath);
                        pathLine.x = (shapeone.pathline().begin()+i).key()
                        pathLine.y = (shapeone.pathline().begin()+i).value()
                        pathElements.push(pathLine)
                    }

                    return pathElements
                }

                ShapePath {
                    id: myPath

                    strokeColor: "black"
                    strokeWidth: 1
                    fillColor: "transparent"

                    startX: 0
                    startY: 0

                    pathElements: createPathLineElements(myPath)
                }
            }
        }
    }
}

