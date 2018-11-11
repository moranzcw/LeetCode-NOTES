import re
import os
import tkinter
import tkinter.messagebox

def get_title(title):
    num = re.search('[0-9]{1,4}(?=\.\ )', title)
    if num == None:
        return None
    num = num.group(0)
    title = re.search('(?<=\.\ ).*', title)
    if title == None:
        return None
    title = title.group(0)
    return num + '.' + title.replace(' ','-')

def save(title,code):
    if not os.path.exists('./Algorithms'):
        os.mkdir('./Algorithms')
    if not os.path.exists('./Algorithms/'+title):
        os.mkdir('./Algorithms/'+title)
    f = open('Algorithms/'+title+'/solution.cpp','w')
    f.write(code)
    f.close()
    return

def pop_up_box():
    """
    使用tkinter弹出输入框输入数字, 具有确定输入和清除功能, 可在函数内直接调用num(文本框的值)使用
    """
    def inputstr():
        nonlocal title
        nonlocal code
        title = get_title(entry.get())
        if title == None:
            tkinter.messagebox.showinfo(title='更新失败',message='更新失败')
            return
        code = text.get('0.0',tkinter.END)
        save(title,code)
        mess = '粘贴到readme:\n'+'['+title+'](Algorithms/'+title+'/solution.cpp)'
        tkinter.messagebox.showinfo(title='更新完成',message=mess)  # return ok

    def clearstr():
        entry.delete(0,tkinter.END)
        text.delete('0.0',tkinter.END)
        pass

    title = ''
    code = ''
    root = tkinter.Tk(className='输入代码')  # 弹出框框名
    root.geometry('500x400')     # 设置弹出框的大小 w x h

    entry = tkinter.Entry(root)
    entry.pack()   # 将entry"打上去"

    text = tkinter.Text(root, height=15)   # 这即是输入框中的内容
    text.pack()

    btn1 = tkinter.Button(root, text='Input', command=inputstr)     # 按下此按钮(Input), 触发inputint函数
    btn2 = tkinter.Button(root, text='Clear', command=clearstr) 
    # 按钮定位
    btn1.pack(side='bottom')
    btn2.pack(side='bottom')

    # 上述完成之后, 开始真正弹出弹出框
    root.mainloop()
    
pop_up_box()
