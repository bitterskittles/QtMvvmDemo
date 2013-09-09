import QtQuick 2.0
import Controls 1.0
import "../Controls/"

Rectangle {
    width: 360
    height: 360

    Grid  {
        columns: 1
        spacing: 5

        Text {
            text: dataContext.displayName
        }

        Button {
            text: "add new item"
            onClicked: dataContext.addItem()
        }

        Grid {
            rows: 5; columns: 5; spacing: 10

            Repeater {
                model: dataContext.items
                delegate: ContentControl {
                    model: modelData
                }
            }
        }
    }
}
