import QtQuick 2.0

Item {
    id: label
    width: parent.width
    height: 80

    property int maxRpm: 14000
    property int value: 24000

    function centerx() {
        return label.width * label.value / parent.maxRpm;
    }

    BlackOnWhiteOutlinedNumber {
        x: centerx() - 6
        y: 36
        alignment: BlackOnWhiteOutlinedNumber.NumberAlignment.RIGHT_JUSTIFY
        fontheight: 38
        value: label.value / 1000
    }

    Rectangle {
        x: centerx() - 4
        y: 13
        width: 8
        height: 64
        color: "#ffffff"
    }
    Rectangle {
        x: centerx() - 2
        y: 15
        width: 4
        height: 60
        color: "#000000"
    }
}
