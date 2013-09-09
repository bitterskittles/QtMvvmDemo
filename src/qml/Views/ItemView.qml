import QtQuick 2.0

Rectangle {
    width: 70;
    height: 70
    color: "lightgreen"

    Text {
        text: dataContext.id
        font.pointSize: 30
        anchors.centerIn: parent
    }
}
