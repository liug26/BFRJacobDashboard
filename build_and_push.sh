#!/usr/bin/env bash

/home/bruinracing/rpi/qt5.15/bin/qmake
make
scp BruinFormulaDashQt5_15 pi@100.122.3.94:/home/pi
