import serial
import time

ser = serial.Serial('COM5', 9600)  # 根据你的Arduino串口进行调整
while (1):
    data = input('输入要发送的数据：') 
    ser.write(data.encode('utf-8'))
    time.sleep(0.5)  # 等待一秒钟，确保Arduino有足够的时间处理串口数据
ser.close()  # 关闭串口连接
#
