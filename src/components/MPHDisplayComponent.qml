import QtQuick 2.0

Item {

    property int mph: 101
    width: 112

    Text {
        id: mphUnitsLabel
        text: "MPH"
        font.pixelSize: 34
        font.bold: true
        rotation: 90
        y: 21
        x: 56
    }

    function parseIntToString(num) {
        var out = String(num % 100);
        while (out.length < 2) {
            out = "0" + out;
        }
        return out;
    }

    Text {
        id: mphValue
        text: parent.mph.toString()
        font.pixelSize: 72
        x: 0
        y: -4
        color: "#808080"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:2}
}
##^##*/
