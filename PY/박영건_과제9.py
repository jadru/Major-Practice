from tkinter import *
import random as ra

def event_1():
    com = ra.choice(('가위', '바위', '보'))
    label1.config(text='사용자 : ' + '가위')
    label3.config(text='컴퓨터 : ' + com)

    if com == '가위':
        label2.config(text='비겼습니다!')
    elif com == '바위':
        label2.config(text='사용자가 졌습니다!')
    elif com == '보':
        label2.config(text='사용자가 이겼습니다!')

def event_2():
    com = ra.choice(('가위', '바위', '보'))
    label1.config(text='사용자 : ' + '바위')
    label3.config(text='컴퓨터 : ' + com)
    
    if com == '가위':
        label2.config(text='사용자가 이겼습니다!')
    elif com == '바위':
        label2.config(text='비겼습니다!')
    elif com == '보':
        label2.config(text='사용자가 졌습니다!')
def event_3():
    com = ra.choice(('가위', '바위', '보'))
    label1.config(text='사용자 : ' + '보')
    label3.config(text='컴퓨터 : ' + com)
    
    if com == '가위':
        label2.config(text='사용자가 졌습니다!')
    elif com == '바위':
        label2.config(text='사용자가 이겼습니다!')
    elif com == '보':
        label2.config(text='비겼습니다!')

w = Tk()

w.title('가위 바위 보 게임')

label1 = Label(w, text='사용자 : ')
label2 = Label(w, text='결과는?', fg='green', font=("Helcetica", 30))
label3 = Label(w, text='컴퓨터 : ')

btn_1 = Button(w, text='가위', command = event_1, bg='yellow')
btn_2 = Button(w, text='바위', command = event_2, bg='yellow')
btn_3 = Button(w, text='보', command = event_3, bg='yellow')

label1.grid(row=0, column=0, ipadx=100, ipady=100)
label2.grid(row=0, column=1, ipadx=100, ipady=100)
label3.grid(row=0, column=2, ipadx=100, ipady=100)
btn_1.grid(row=1, column=0, ipadx=100, ipady=20)
btn_2.grid(row=1, column=1, ipadx=100, ipady=20)
btn_3.grid(row=1, column=2, ipadx=100, ipady=20)

w.mainloop()
