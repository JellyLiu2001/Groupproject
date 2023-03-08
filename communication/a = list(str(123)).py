a = 789

b1 = a%10
b2 =(int(a/10))%10
b3 =(int(a/100))%10

print("{}的个位数字为{}".format(a,b1))
print("{}的十位数字为{}".format(a,b2))
print("{}的百位数字为{}".format(a,b3))
