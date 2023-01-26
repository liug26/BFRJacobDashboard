import QtQuick 2.0

Item {
    id: number

    enum NumberAlignment {
        LEFT_JUSTIFY,
        CENTER,
        RIGHT_JUSTIFY
    }

    property int alignment: NumberAlignment.CENTER
    property int fontheight: 44
    property int value: 0

    width: 1024
    height: 80

    function digitName(digit) {
        switch (digit) {
            case 0: return "zero";
            case 1: return "one";
            case 2: return "two";
            case 3: return "three";
            case 4: return "four";
            case 5: return "five";
            case 6: return "six";
            case 7: return "seven";
            case 8: return "eight";
            case 9: return "nine";
        }
    }

    function getDigitPath(digit) {
        return "/media/outlined_digits/" + digitName(digit);
    }

    function getAlignmentOffset() {
        switch (number.alignment) {
            case BlackOnWhiteOutlinedNumber.NumberAlignment.RIGHT_JUSTIFY: return -number.fontheight * 3 / 4;
            default: throw new UnsupportedOperationException();
        }
    }

    function getInitAlignmentOffset() {
        switch (number.alignment) {
            case BlackOnWhiteOutlinedNumber.NumberAlignment.RIGHT_JUSTIFY: return -number.fontheight * 27 / 40;
            default: throw new UnsupportedOperationException();
        }
    }

    Image {
        id: digitImage
        height: number.fontheight
        width: number.fontheight * 3 / 4
        x: getAlignmentOffset()
        source: getDigitPath(number.value % 10)
        fillMode: Image.PreserveAspectFit
        sourceSize.height: digitImage.width
        sourceSize.width: digitImage.height
    }

    Item {
        id: init
        x: getInitAlignmentOffset()
        Loader {
            Component.onCompleted: {
                var params = {
                    value: Math.floor(number.value / 10),
                    fontheight: number.fontheight,
                    alignment: number.alignment
                }
                var qml = (params.value) ? "BlackOnWhiteOutlinedNumber.qml" : "EmptyComponent.qml";
                setSource( qml, params );
            }
        }
    }
}
