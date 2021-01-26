'''
creating a file and read and write those file

Writer : Bapon kar
Last Update : 26/01/2021

'''

f = open('data.txt','w')
f.write('This is the data inside of the file')
f.close()

f1 = open('data.txt')
data=f1.read()
print(data)
f1.close()
