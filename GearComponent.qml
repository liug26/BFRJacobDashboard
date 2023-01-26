import QtQuick 2.0

AlertRectangle {
    id: rectangle
    width: 440
    height: 519
    border.color: "#ffffff"
    border.width: 5
    componentName: "GearComponent"

    property int rpm: 16666
    property alias alert: rectangle.alert
    property alias alertTarget: rectangle.alertTarget

    function parseGear(rpm) {
        if (rpm > 1000 && rpm < 2000)
            return "1";
        else if (rpm > 2000 && rpm < 3000)
            return "2";
        else if (rpm > 3000 && rpm < 4000)
            return "3";
        else
            return "N";
    }

    Text {
        id: gearTextBox
        y: 8
        width: 384
        height: 556
        color: "#ffffff"
        text: parseGear(rpm)
        horizontalAlignment: Text.AlignHCenter
        lineHeight: 0
        wrapMode: Text.NoWrap
        anchors.horizontalCenter: parent.horizontalCenter
        renderType: Text.QtRendering
        textFormat: Text.AutoText
        font.pointSize: 360
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
    D{i:0;height:519;width:384}
}
##^##*/
