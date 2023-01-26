import QtQuick 2.0

Item  {
    // ID is both a name of the element in the form designer as well as the way to reference
    // properties of this object. See below, where we reference the rpmPercent property using the slider id.
    id: slider
    width: 1024
    height: 80

    // Setup an externally accessablie property called `rpmPercent` of type int with a default value 10.
    // It can be used in this file (see below) and can be passed in from the parent (see main.qml)
    property int rpm: 10
    property int maxRpm: 14000

    // This rectangle is the black background. It's rendered below because it's above in the order. Kinda backwards but whatever.
    Rectangle {
        id: background
        width: parent.width  // Set it's width and height to that of the parent in case the design changes later
        height: parent.height
        color: "#00000000"
        border.color: "#ffffff"  // Configures the border for the widget
        border.width: 2
    }

    // This rectangle is the white cover that makes up the main part of the slider
    Rectangle {
        id: cover
        anchors.left: parent.left  // Pins it to the left
        anchors.leftMargin: 0  // Makes sure it's left edge starts all the way left
        color: "#ffffff"
        width: parent.width * (rpm / maxRpm)  // Sets the width to the correct percent. This is a javascript expression, using the rpmPercent from above
        height: parent.height
    }
}
