import QtQuick 2.0

Item {
    width: 300
    height: 14

    property string canStatusMessage: "NO MESSAGE"
    property string socketCanStatusMessage: "NO MESSAGE"
    property int canCountProp: -1
    property string col: "#0900ff"

    Row {
        id: row
        width: 200
        height: 400

        Text {
            id: canStatusPrefix
            color: col
            text: qsTr("CAN Status:  ")
            font.pixelSize: 12
        }

        Text {
            id: canStatus
            color: col
            text: canStatusMessage
            font.pixelSize: 12
        }

        Text {
            id: socketcanStatusPrefix
            color: col
            text: qsTr("SocketCAN Status:  ")
            font.pixelSize: 12
        }

        Text {
            id: socketcanStatus
            color: col
            text: socketCanStatusMessage
            font.pixelSize: 12
        }

        Text {
            id: canCountPrefix
            color: col
            text: qsTr("    CAN Count:  ")
            font.pixelSize: 12
        }

        Text {
            id: canCount
            color: col
            text: canCountProp
            font.pixelSize: 12
        }
    }



}
