import requests
import re
import tkinter as tk # GUI

root = tk.Tk()
root.geometry('500x350')
root.title('MarsWalker')
l1 = tk.Label(root, text = 'play channel: ', font = 12)
l1.grid(row=0, column=0)

one = 'great'
two = 'awsome'

var = tk.StringVar()
rb1 = tk.Radiobutton(root, text = 'rbtn1', variable=var, value=one)
rb1.grid(row=1, column=1)

rb2 = tk.Radiobutton(root, text = 'rbtn2', variable=var, value=two)
rb2.grid(row=2, column=1)

l2 = tk.Label(root, text = 'input link: ', font=12)
l2.grid(row=4, column=0)

l3 = tk.Entry(root, text = '', font=12, width=30)
l3.grid(row=4, column=1)

b1 = tk.Button(root, text = 'btn', width=8)
b1.grid(row=5, column=1)


root.mainloop()




# https://www.youtube.com/watch?v=J5MraU_JIxU
# pyinstaller -F -w demo.py