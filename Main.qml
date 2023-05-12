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

    //    Button
    //    {
    //        anchors.centerIn: parent
    //        text: "click"
    //        z:10
    //        onClicked:
    //        {
    //            console.log(mymodel.mindsit)

    //        }
    //    }

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

            pathLine.x = shapeone.xy[2*i]
            pathLine.y = shapeone.xy[2*i+1]

            pathElements.push(pathLine)
        }

        return pathElements
    }

    id:root
    minimumWidth: 1150
    minimumHeight: 500
    maximumWidth: 1150
    maximumHeight: 500
    visible: true
    title: qsTr("Soroush Game")
    color: "#CACACA"

    RoundButton
    {
        id: startkey
        enabled:
        {
            if(mymodel.currentstauts==="green")
                return true
            else
                return false
        }

        height: 50
        width: 50
        radius: 50
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 280
        anchors.leftMargin: 2
        z:10

        background: Rectangle{
            color:
            {
                if(enabled)
                    return "green"
                else
                    return "gray"
            }

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

            shapeone.makeline()
            console.log("start" , shapeone.xy)
            myPath.pathElements = createPathLineElements(myPath)
            shapecontainer.visible = true
            combo.enabled = false
            mymodel.sendname()
            //            startkey.enabled = false;
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
        anchors.topMargin: 280
        anchors.rightMargin: 3
        z:1

        background: Rectangle{
            color: "#00A1F2"
            radius: endkey.radius

        }
        contentItem: Text {
            text: "end"
            color: "white"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter


        }

    }

    ColumnLayout
    {
        id:socketstatus
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 20
        anchors.topMargin: 40

        RoundButton
        {
            height: 2
            width:  2
            radius: 50
            background: Rectangle{
                color: mymodel.currentstauts
                radius: startkey.radius
            }
        }
    }



    Item{
        id: maincontainer
        width: parent.width-100
        height: parent.height
        anchors.centerIn: parent

        Rectangle
        {
            id: clientdata
            anchors.top: maincontainer.top
            height: 100
            width: maincontainer.width
            border.width: 0
            color: "#136597"

            RowLayout{
                anchors.centerIn: parent
                //  anchors.fill: parent
                TextField{

                    placeholderText: "name"
                    onTextChanged:
                    {
                        mymodel.myname = text
                    }
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
                        if(combo.currentIndex===0)
                            myPath.strokeWidth=8
                        else if(combo.currentIndex===1)
                            myPath.strokeWidth=4

                        mymodel.lvlgame = myPath.strokeWidth

                        //                        console.log("index",currentIndex)
                        //                        console.log("tickness",myPath.strokeWidth)
                    }
                }

            }
        }


        Rectangle
        {
            id:shapecontainer
            visible: true
            anchors.top: clientdata.bottom
            anchors.topMargin: 6
            height: 400
            width: maincontainer.width

            MouseArea
            {
                id : mousearea
                hoverEnabled: false
                anchors.fill: parent
                onPositionChanged:
                {
                    mymodel.isonline(mouseX,mouseY)
                    mymodel.send(Date.now())
                }


            }

            Shape {
                id:shapes
                antialiasing: enabled
                //                enabled: false

                ShapePath {
                    id: myPath
                    strokeColor: "#00A1F2"
                    fillColor: "transparent"

                    startX: 0
                    startY: 200
                }
            }

            //            Item
            //            {
            //                id:footer
            //                z:10
            //                width: 100
            //                height: 100
            //                anchors.leftMargin:200
            //                anchors.bottom: parent.bottom
            //                anchors.left: parent.left


            //    //            anchors.centerIn: parent
            //                Shape
            //                {


            //    //                anchors.bottom: footer.bottom
            //                    anchors.centerIn: footer
            //                    ShapePath{

            //                        fillColor: "black"
            //                        strokeColor: "black"
            //                        strokeWidth: 3

            //                        PathSvg {

            //                            path: "M754.053,41.894V-23.854c0-4.466-2.39-6.72-7.148-6.72H-142.5c-4.735,0-7.148,2.233-7.148,6.72V41.894ZM-147.2,39.615v-63.3c0-2.255,2.429-4.157,4.705-4.157H746.769c2.253,0,4.979,1.9,4.979,4.157v63.3Z"
            //                        }
            //                    }
            //                }
            //            }

            Rectangle {
                id:footer
                width: parent.width
                height: 100
                color: "#136597"
                RowLayout{
                    spacing: 100
                    anchors.centerIn: parent
                    Rectangle{
                        height: 100
                        width: parent.width
                        color:"transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: mymodel.mindsit
                            font.pixelSize: 37
                            color: "white"
                        }
                    }
                }
                anchors.bottom:parent.bottom
            }

        }
    }
}





