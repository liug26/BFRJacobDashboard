import QtQuick 2.0

Rectangle {
    id: rectangle
    // If alert is true and if this is the target, go transparent otherwise read otherwise transparent
    color: alert ? alertTarget === componentName ? "#000000" : "red" : "#00ffffff"

    property bool alert: false
    property string alertTarget: "GearComponent"
    required property string componentName
}
