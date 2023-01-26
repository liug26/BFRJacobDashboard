#include "utils.h"

namespace Utils {
    float makeFloat(QByteArray arr)
    {
        floatData data;
        data.fBuff[0] = arr[0];
        data.fBuff[1] = arr[1];
        data.fBuff[2] = arr[2];
        data.fBuff[3] = arr[3];
        return data.f;
    }

    qint32 makeInt32(QByteArray arr) {
        int32Data data;
        data.iBuff[0] = arr[0];
        data.iBuff[1] = arr[1];
        data.iBuff[2] = arr[2];
        data.iBuff[3] = arr[3];
        return data.i;
    }

    qint16 makeInt16(QByteArray arr){
        int16Data data;
        data.iBuff[0] = arr[0];
        data.iBuff[1] = arr[1];
        return data.i;
    }


    QString framePayloadString(const QCanBusFrame &frame) {
        return QString::fromStdString(frame.payload().toHex(':').toStdString());
    }

    qlonglong framePayloadUint(const QCanBusFrame &frame) {
        return makeInt32(frame.payload());
    }

    float framePayloadFloat(const QCanBusFrame &frame) {
        return makeFloat(frame.payload());
    }

    msg_t* framePayloadMessage(const QCanBusFrame &frame) {
        const char * bytes =  frame.payload().constData();
        msg_t* msg = (msg_t *)(bytes);
        return msg;
    }

    float fixed_u16_2_float(uint16_t val, float scale, float offset) {
        float internal_val = val;
        internal_val *= scale;
        internal_val += offset;
        return internal_val;
    }

    float fixed_u8_2_float(uint8_t val, float scale, float offset) {
        float internal_val = val;
        internal_val *= scale;
        internal_val += offset;
        return internal_val;
    }

    float fixed_s8_2_float(int8_t val, float scale, float offset) {
        float internal_val = val;
        internal_val *= scale;
        internal_val += offset;
        return internal_val;
    }

    uint16_t swap_bytes(uint16_t a) {
        return (a >> 8) | (a << 8);
    }

//    uint16_t swap_bytes_short(unsigned short a) {
//        return (a >> 8) | (a << 8);
//    }
}

