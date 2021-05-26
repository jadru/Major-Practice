from tkinter import *
from tkinter.messagebox import showinfo
import random as ra

cnt = 0

def random():
    while(True):
        i1 = ra.randrange(0, 10)
        i2 = ra.randrange(0, 10)
        cal = ra.choice(['+', '-'])
        if cal == '-':
            if i1 < i2:
                continue
        return str(i1) + cal + str(i2)


def calculate(event=''):
    global cnt
    result = eval(cal_result)
    user = en_2.get()
    if int(result) == int(user) :
        cnt += 1
        showinfo(message = "You got it! {} times solved".format(cnt))
        rerandom()
    else:
        showinfo(message = "Not an answer, try again {} times solved".format(cnt))


def rerandom():
    global cal_result
    en_1.delete(0, END)
    en_2.delete(0, END)
    cal_result = random()
    en_1.insert(0, cal_result)

top = Tk()
top.title("덧셈 및 뺼셈 학습 클래스 ed")
en_1 = Entry(top)
cal_result = random()
en_1.insert(0, cal_result)

en_2 = Entry(top)
en_2.bind('<Return>', calculate)
btn = Button(top, text="Enter", command=calculate)

en_1.pack()
en_2.pack()
btn.pack()

top.mainloop()