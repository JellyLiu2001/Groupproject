import serial

serialPort = "COM5"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(serialPort, baudRate, timeout=0.5)
print("参数设置：串口=%s ，波特率=%d" % (serialPort, baudRate))
demo1=b"0"#将0转换为ASCII码方便发送
demo2=b"1"#同理
ser.write(demo1)#ser.write在于向串口中写入数据