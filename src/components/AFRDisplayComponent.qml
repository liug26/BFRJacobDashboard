import QtQuick 2.0

Item {

    property double afr: 240.98

    Text {
        id: afrUnitsLabel
        text: "AFR"
        color: "#ffffff"
        font.pixelSize: 34
        rotation: -90
        y: 21
        x: 0
    }

    Text {
        id: afrValue
        text: parent.afr.toFixed(1)
        color: "#ffffff"
        font.pixelSize: 72
        x: 55
        y: -4
    }
}
