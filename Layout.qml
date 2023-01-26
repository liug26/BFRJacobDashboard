import QtQuick 2.0
import QtQuick.Controls
import com.cobular.CanHandler 1.0

Rectangle {
    id: rectangle
    width: 1024
    height: 600
    color: dataObj.alert ? "red" : "#00ffffff"

    QtObject {
        id: dataObj
        property bool alert: false;
        property int maxRPM: 14000
    }

    CanHandler {
        id: canhandler
    }

    // Creates an instance of the slider component we just made in RPMSliderComponent.qml
    RPMSliderComponent {
        id: sliderComponent
        rpm: slider.value  // Here we set the custom property we defined to be the value of the below slider.
        // You'll see when this is ran that it is linked, so changing the slider position is reflected in the rpm slider, controlled through this property binding
        maxRpm: dataObj.maxRPM
    }

    // This is just for testing, it's a slider that we can use to test our component
    Slider {
        id: slider
        // To figure out these properties, I googled for it and found an example in the QT documentation.
        from: 0
        value: 25
        to: dataObj.maxRPM
        width: parent.width
    }

    Button {
        id: alertButton
        y: 100
        text: canhandler.userName
        onClicked: () => dataObj.alert = !dataObj.alert
    }

    GearComponent {
        anchors.bottom: parent.bottom
        rpm: slider.value
        alert: dataObj.alert
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 0
    }

//    CoolantTemp {

//    }
}
