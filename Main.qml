import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes
import Viewmodels 1.0
import Shapegenerators 1.0


Window {
    property Viewmodel mymodel: mainviewmodel
    property Shapegenerator shapeone: Shapgenratorcontext
    property bool checkit: false


    function createPathLineElements(shapePath)
    {
        console.log("shape:" , shapeone.xy)

        var pathElements = []
        for (var i = 0; i < 14; i++)
        {
            var even = 2*i
            var odd  = 2*i+1
            var pathLine = Qt.createQmlObject('import QtQuick 2.15; PathLine {}',
                                              shapePath);
            var PathArc = Qt.createQmlObject('import QtQuick 2.15; PathArc {}',
                                             shapePath);
            if(combo.currentIndex===0)
            {
                pathLine.x = shapeone.xy[2*i]
                pathLine.y = shapeone.xy[2*i+1]
                pathElements.push(pathLine)
            }
            //                    else if(combo.currentIndex===1)
            //                    {
            //                        if(i<=7)
            //                        {
            //                            pathLine.x = shapeone.numbers[(2*i)]
            //                            pathLine.y = shapeone.numbers[2*i+1]
            //                        }
            //                        else
            //                        {
            //                            PathArc.x = shapeone.numbers[2*i]
            //                            PathArc.y = shapeone.numbers[2*i+1]
            //                        }

            //                    if(mousearea.mouseX>shapeone.numbers[2*i])
            //                    {

            //                    }
            pathElements.push(pathLine)
        }

        return pathElements
    }

    minimumWidth: 1100
    minimumHeight: 500
    maximumWidth: 1100
    maximumHeight: 500
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
            anchors.top: maincontainer.top
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
                    id: combo
                    model: ["easy","hard"]
                    onCurrentIndexChanged:
                    {
                        mymodel.lvlgame = currentIndex
                    }
                }

            }
        }

        RoundButton
        {
            id: startkey
            height: 50
            width: 50
            radius: 50
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 285
            anchors.leftMargin: -20
            z:10

            background: Rectangle{
                color: "green"
                radius: startkey.radius

            }
            contentItem: Text {
                text: "start"
                color: "white"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            onClicked:
            {
                if(combo.currentIndex===0)
                    shapeone.makeline(0)
                else
                    shapeone.makeline(1)


                console.log("start" , shapeone.xy)
                myPath.pathElements = createPathLineElements(myPath)
                shapecontainer.visible = true
            }
        }

        Rectangle
        {
            id:shapecontainer
            visible: false
            anchors.top: clientdata.bottom
            anchors.topMargin: 5
            height: 345
            width: maincontainer.width

            MouseArea
            {
                id : mousearea
                hoverEnabled: false
                anchors.fill: parent
                onMouseXChanged:
                {
                    var isonline = mymodel.isonline(mouseX,mouseY)
                    //                    var dist = shapeone.distances
                    console.log(isonline)
                    //                    console.log(dist)
                    console.log(mouseX)
                    console.log(mouseY)
                }

            }


            RoundButton
            {
                id: endkey
                visible: true
                height: 50
                width: 50
                radius: 50
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 172.5
                anchors.rightMargin: -20
                z:1

                background: Rectangle{
                    color: "green"
                    radius: endkey.radius

                }
                contentItem: Text {
                    text: "end"
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

                onClicked:
                {

                }
            }
            //            Myshapes{}
            Shape {
                id:shapes
                antialiasing: enabled
                enabled: false

                ShapePath {
                    id: myPath

                    strokeColor: "red"
                    strokeWidth: 4
                    fillColor: "transparent"

                    startX: 0
                    startY: 200

                    //                    property bool runCreatePathLineElements: false

                    //                    onRunCreatePathLineElementsChanged: {
                    //                        if (startkey.pressed) {
                    //                            pathElements = shapes.createPathLineElements(myPath)
                    //                        }
                    //                    }
                    //                    onPathElementsChanged:
                    //                    {
                    //                        if(checkit)
                    //                        return shapes.createPathLineElements(myPath)
                    //                    }

                    //                    pathElements:
                    //                    {
                    //                        if(checkit)
                    //                        return shapes.createPathLineElements(myPath)
                    //                    }


                }
            }
        }
    }
}

