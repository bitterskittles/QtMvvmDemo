import QtQuick 2.0

Rectangle {
    width: 60;
    height: 80
    color: "lightblue"

    Text {
        text: dataContext.id
        font.pointSize: 30
        anchors.centerIn: parent
    }
}
