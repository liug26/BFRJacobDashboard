import QtQuick 2.12
import QtQuick.Window 2.12
import "src"
import "src/components"

// Window is the class for an overall window, so that's what we want for now.
Window {
    width: 1024  // Setting overal window size. Matches the size of the screen we'll eventually use.
    height: 574
    visible: true
    color: "#000000"  // Set background color
    title: "Hello World"  // and the window title

    Layout {

    }


    Item {
        id: fpsCorner
        enabled: visible

        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 5
            text: counter.fps + " FPS"
            font.pixelSize: 26
            color: "white"
        }

        FpsCounter {
            id: counter
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:3}D{i:4}D{i:2}
}
##^##*/
