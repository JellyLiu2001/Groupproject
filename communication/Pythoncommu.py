# coding:utf-8

import serial.tools.list_ports
import time
plist = list(serial.tools.list_ports.comports())

if len(plist) <= 0:
        print("没有发现端口!")
else:
        plist_0 = list(plist[0])
        serialName = plist_0[0]
        serialFd = serial.Serial(serialName, 9600, timeout=60)
        print("可用端口名>>>", serialFd.name)
        while 1:
                serialFd.write("o".encode())
                time.sleep(1)
                serialFd.write("c.encode())
                time.sleep(1)
