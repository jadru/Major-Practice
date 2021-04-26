import random as ra

a = input()
com = ra.choice(('가위', '바위', '보'))
print("사용자 :", a, '컴퓨터 :', com)
if a == '가위':
    if com == '가위':
        print('비겼습니다!')
    if com == '바위':
        print('사용자가 졌습니다!')
    if com == '보':
        print('사용자가 이겼습니다!')
if a == '바위':
    if com == '가위':
        print('사용자가 이겼습니다!')
    if com == '바위':
        print('비겼습니다!')
    if com == '보':
        print('사용자가 졌습니다!')
if a == '보':
    if com == '가위':
        print('사용자가 졌습니다!')
    if com == '바위':
        print('사용자가 이겼습니다!')
    if com == '보':
        print('비겼습니다!')