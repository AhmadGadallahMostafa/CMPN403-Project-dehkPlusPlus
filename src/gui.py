import sys
from time import sleep
import tkinter as tk
import tkinter.ttk as ttk
import os
# get file name from command line
if len(sys.argv) < 1:
    print("Usage: python3 gui.py <filename>")
    sys.exit(1)

#get file name from command line
filename = sys.argv[1]

window = tk.Tk()

frame = tk.Frame(master=window, width=150, height=150)
frame.pack()

text_box = tk.Text( height=45)
text_box.place(x=0,y=0)
#text_box.pack()
#frame1 = tk.Frame(master=window, width=5000, height=500, bg="red")
#frame1.pack()

def submitFunction() :
    with open(filename, 'w') as f:
        f.write(text_box.get("1.0",tk.END))
    os.system('"d7k.exe "' + filename + '"')
    sleep(2)
    with open(filename, 'r') as f:
        z=f.read()
    text_box1 = tk.Text(height=45,bg="grey")
    text_box1.insert("1.0",z)
    text_box1.place(x=700,y=0)

button = tk.Button(
    text="Compile!",
    width=9,
    height=3,
    bg="blue",
    fg="yellow",
    command=submitFunction
)
button.place(x=570,y=730)


window.mainloop()