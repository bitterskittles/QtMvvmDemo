import QtQuick 2.0

Item {
    id: button
    width: 200
    height: 20
    property string text
    signal clicked

    Rectangle {
        id: buttonLayout
        width: button.width
        height: button.height
        radius: 6
        smooth: true

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#a8a8a8"
            }

            GradientStop {
                position: 1
                color: "#4f4f4f"
            }
        }

        Text {
            id: text
            text: button.text
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        MouseArea {
            anchors.fill: parent
            onClicked: button.clicked()
        }
    }
}
