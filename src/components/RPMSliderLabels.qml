import QtQuick 2.0

Item {
    id: labels

    property int maxRpm: 14000

    SingleRPMSliderLabel { value: 2000 }
    SingleRPMSliderLabel { value: 4000 }
    SingleRPMSliderLabel { value: 6000 }
    SingleRPMSliderLabel { value: 8000 }
    SingleRPMSliderLabel { value: 10000 }
    SingleRPMSliderLabel { value: 12000 }
    SingleRPMSliderLabel { value: 14000 }
    SingleRPMSliderLabel { value: 16000 }
    SingleRPMSliderLabel { value: 18000 }
    SingleRPMSliderLabel { value: 20000 }

}
