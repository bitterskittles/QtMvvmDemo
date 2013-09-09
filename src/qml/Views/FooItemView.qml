import QtQuick 2.0

Rectangle {
    width: 80;
    height: 60
    color: "orange"

    Text {
        text: dataContext.id
        font.pointSize: 30
        anchors.centerIn: parent
    }
}
