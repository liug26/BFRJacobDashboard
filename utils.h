#ifndef UTILS_H
#define UTILS_H

#include <qbytearray.h>
#include <QString>
#include <QCanBus>
#include "external_libs/aemnet_definitions.h"

using aemnet_utils::msg_t;

namespace Utils {
    union floatData {
        float f;
        unsigned char fBuff[sizeof(float)];
    };

    union int32Data {
      qint32 i;
      unsigned char iBuff[sizeof(qint32)];
    };

    union int16Data {
      qint16 i;
      unsigned char iBuff[sizeof(qint16)];
    };


    float makeFloat(QByteArray arr);
    qint32 makeInt32(QByteArray arr);
    qint16 makeInt16(QByteArray arr);

    // CAN frame unpacking
    QString framePayloadString(const QCanBusFrame &frame);
    qlonglong framePayloadUint(const QCanBusFrame &frame);
    float framePayloadFloat(const QCanBusFrame &frame);
    msg_t* framePayloadMessage(const QCanBusFrame &frame);

    // CAN frame individual datum unpacking
    // See https://github.com/bruinracingelectronics/TeensyCanSender/blob/13dfaee2fabc16a8e0eaf0d0b694aad699c29417/src/main.cpp
    // for examples of how these are to be used.
    float fixed_u16_2_float(uint16_t val, float scale, float offset);
    float fixed_u8_2_float(uint8_t val, float scale, float offset);
    float fixed_s8_2_float(int8_t val, float scale, float offset);
    uint16_t swap_bytes(uint16_t a);
//    uint16_t swap_bytes_short(unsigned short a);
}


#endif // UTILS_H
