import QtQuick 2.0

AbstractImageTextComponent {
    id: coolantRectangle
    width: 250
    height: 133

    componentName: "Brake"
    image_path: "/media/brake"
    suffix: "%"

    property double max: -1
    value: Number.parseFloat(max).toFixed(1)

    property alias alert: coolantRectangle.alert
    property alias alertTarget: coolantRectangle.alertTarget

}
