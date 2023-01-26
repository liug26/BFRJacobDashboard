import QtQuick 2.0

AlertRectangle {
    id: rectangle
    width: 440
    height: 496
    border.color: "#ffffff"
    border.width: 5
    componentName: "GearComponent"

    property int rpm: -1
    property int gear: -1
    property alias alert: rectangle.alert
    property alias alertTarget: rectangle.alertTarget


    Text {
        id: gearTextBox
        y: 25
        width: 384
        height: 556
        color: "#ffffff"
        text: gear.toString()
        horizontalAlignment: Text.AlignHCenter
        lineHeight: 0
        wrapMode: Text.NoWrap
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        renderType: Text.QtRendering
        textFormat: Text.AutoText
        font.pointSize: 340
        font.family: "Verdana"
    }


    Text {
        id: rpmTextBox
        y: -17
        width: 384
        height: 154
        color: "#ffffff"
        text: ("000000" + rpm.toString()).slice(-5)
        horizontalAlignment: Text.AlignHCenter
        lineHeight: 0
        wrapMode: Text.NoWrap
        anchors.horizontalCenter: parent.horizontalCenter
        renderType: Text.QtRendering
        textFormat: Text.AutoText
        font.pointSize: 100
        font.family: "Verdana"
    }
}

/*##^##
Designer {
    D{i:0;height:496;width:440}D{i:1}D{i:2}
}
##^##*/
