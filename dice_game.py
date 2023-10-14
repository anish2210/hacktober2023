from tkinter import *
import random 

box=Tk()
box.configure(bg="purple")
box.geometry("800x600")
box.title("Die Roller")
label = Label(box, font=("times", 250),
              bg="purple", fg="black")
def roll():
    dots = ['\u2680','\u2681','\u2682','\u2683','\u2684','\u2685']
    label.configure(text=f'{random.choice(dots)}{random.choice(dots)}')
    label.pack()
btn = Button(box, text="Roll!",
                     width=10, height=2,
                     font=15, bg="aqua",
                     bd=2, command=roll)
btn.pack(padx=10, pady=15)  
box.mainloop()