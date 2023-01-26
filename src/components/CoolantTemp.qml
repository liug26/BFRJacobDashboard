import QtQuick 2.0

AbstractImageTextComponent {
    id: coolantRectangle
    width: 250
    height: 113
    color: "#FFFFFF"

    componentName: "Coolant"
    image_path: "/media/coolant"

    property double temp: -1
    value: temp.toFixed(1)

    property alias alert: coolantRectangle.alert
    property alias alertTarget: coolantRectangle.alertTarget
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/
