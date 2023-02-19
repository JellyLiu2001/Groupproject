import serial

serialPort = "COM8"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(serialPort, baudRate, timeout=0.5)
print("参数设置：串口=%s ，波特率=%d" % (serialPort, baudRate))

demo1=b"0"#将0转换为ASCII码方便发送
demo2=b"1"#同理
while 1:
    val = ser.readline().decode('utf-8')
    # ser.readline() 读取窗串口中的数据以二进制的形式展示需要使用.decode('utf-8')进行解码
    print(val)
    c=input('请输入指令:')
    c=ord(c)#将c转换为UTF-8标准数字
    if(c==48):
        ser.write(demo1)#ser.write在于向串口中写入数据
    if(c==49):
        ser.write(demo2)