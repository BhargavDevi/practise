bd={'anj':'july','manja':'jan','gujjar':'feb'}
print('Enter the number of trials you want to enter')
num=int(input())
for i in range(num):
          print('Enter your name  :')
          nmae=input()
          print('Enter your date of birth')
          db=input()
          bd[nmae]=db
          print ('prossid .............')
print('Enterd birth days are ')
for i in bd.values():
          print(i)
print('Entered names are')
for v in bd.keys():
          print(v)
print('we have the birthday of'+str(bd.get('anil','non')+ 'here'))
