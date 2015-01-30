# -*- coding: utf-8 -*-
"""
Editor de Spyder

Este archivo temporal se encuentra aquí:
/home/mario/.spyder2/.temp.py
"""


import sys, traceback, Ice

Ice.loadSlice("Ultrasound.ice")
import RoboCompUltrasound

sensor="mario"
status = 0
ic = None
try:
    # Create a communicator
    #
    ic = Ice.initialize(sys.argv)

    # Create a proxy for the root directory
    #
    obj = ic.stringToProxy("Ultrasound:tcp -h 192.168.1.102 -p 10000")
    print obj
    proxy = RoboCompUltrasound.UltrasoundPrx.checkedCast(obj)
    if not proxy:
        raise RuntimeError("Invalid Proxy")
#    proxy.printString("cara culo");
    print(proxy.getSensorDistance(sensor))
except:
    traceback.print_exc()
    status = 1

if ic:
    try:
        ic.destroy()
    except:
        traceback.print_exc()
        status = 1

sys.exit(status)
