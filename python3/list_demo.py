subet1='9.202.16.0/20'
subnet2='11.171.42.0/25'
subnet3='9.202.28.0/25'
print(subnet3.split(';'))
b=[subet1,subnet2] +subnet3.split(';')

print(b)