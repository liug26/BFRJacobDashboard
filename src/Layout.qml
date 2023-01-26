import QtQuick 2.0
import QtQuick.Controls 2.0
import com.cobular.CanHandler 1.0
import "components"

Rectangle {
    id: rectangle
    width: 1024
    height: 576
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
        rpm: canhandler.rpmData // Here we set the custom property we defined to be the value of the below slider.
        // You'll see when this is ran that it is linked, so changing the slider position is reflected in the rpm slider, controlled through this property binding
        maxRpm: dataObj.maxRPM
    }

    RPMSliderLabels {
        id: sliderLabels
        maxRpm: dataObj.maxRPM
        width: sliderComponent.width - 4
        height: sliderComponent.height
        x: sliderComponent.x
        y: sliderComponent.y
    }

    MPHDisplayComponent {
        id: mphCounter
        height: sliderComponent.height
        mph: canhandler.speedData
    }

    AFRDisplayComponent {
        id: afrCounter
        x: 796
        y: 86
        width: 200
        height: 80
        afr: canhandler.afrData
    }

    GearComponent {
        id: gearComponent
        anchors.bottom: parent.bottom
        rpm: canhandler.rpmData
        gear: canhandler.gearData
        alert: dataObj.alert
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 0
    }

    CoolantTemp {
        x: 12
        y: 80
        width: 274
        height: 113

        temp: canhandler.coolantData

    }

    BatteryVoltage {
        x: 4
        y: 459
        width: 282
        height: 133
        voltage: canhandler.voltageData

    }

    BrakeRatio {
        x: 738
        y: 468
        width: 286
        height: 133
        max: canhandler.biasData
    }
    
    CanDebugInfo {
        y: 578
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        canCountProp: canhandler.numberFramesWritten
        canStatusMessage: canhandler.canStatusMessage
        socketCanStatusMessage: canhandler.socketCanStatus
    }
}






