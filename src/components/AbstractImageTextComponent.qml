import QtQuick 2.0
import QtQuick.Layouts 1.15

AlertRectangle {
    id: alertRectangle
    width: 250
    height: 113

    property string image_path: ""
    property string value: "50.5"
    property string suffix: ""
    property alias componentName: alertRectangle.componentName
    property alias alert: alertRectangle.alert
    property alias alertTarget: alertRectangle.alertTarget
    property string color: "white"

    RowLayout {
        anchors.fill: parent


        Image {
            id: image
            source: image_path
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 90
            Layout.preferredWidth: 90
            fillMode: Image.PreserveAspectFit
        }

        Text {
            font.pointSize: 90
            color: alertRectangle.color
            text: value
            verticalAlignment: Text.AlignVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            fontSizeMode: Text.Fit
            Layout.preferredHeight: 130
        }

        Text {
            font.pointSize: 75
            text: suffix
            color: alertRectangle.color
            verticalAlignment: Text.AlignVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            fontSizeMode: Text.Fit
        }


    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:2}D{i:3}D{i:4}D{i:1}
}
##^##*/
