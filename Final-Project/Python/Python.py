from tkinter import ttk
import tkinter as tk 
from tkinter import filedialog
from tkinter import messagebox
import subprocess
from subprocess import Popen, PIPE
from tkinter import * 
from tkinter.filedialog import askopenfile
from tkinter.ttk import Style
#from PIL import ImageTk

global Control_screen
global file_path2
root = Tk() 
file_path2=StringVar()
root.geometry('500x300')
root.resizable(False,False)
root.title("Initialization System")
default=""
learner=""

#img = ImageTk.PhotoImage(Image.open("logo.jpg"))
#panel = Label(root, image = img)
#panel.pack(side = TOP, fill = "both", expand = "yes")

l1=Label(root, text="Learning DVFA \n \t Teacher system", font = "Cambria 16 bold italic",anchor=CENTER)
l2=Label(root,  text="System helps the learner by answering membership queries\nand eqivalnce queries.",fg ="navy",font = "Cambria 12",justify=LEFT)
l1.pack()
l2.place(x=0, y=90,anchor = NW)

btnBrowseD = Button(root, text ='Browse default automaton',justify=CENTER,activebackground="light blue" ,command = lambda:open_file())
btnBrowseD.place(relx = 0.25, rely = 0.55, anchor = CENTER)
e1=Entry(root, textvariable=file_path2,relief=tk.SUNKEN, width=40)
e1.place(relx = 0.65, rely = 0.55, anchor = CENTER)
btnInitialize = Button(root, text ='Initialize', command = lambda:Initialze(),state=DISABLED)
btnInitialize.place(relx = 0.5, rely = 0.7, anchor = CENTER)

exitButton = Button(root, text="Exit",foreground="red", background="white", command = lambda:close_window(root))
exitButton.place(x=450, y=250)



def Initialze():
    global file_path
    global BtnRun
    file_path=StringVar();

    Control_screen = Toplevel(root)
    Control_screen.resizable(False,False)
    Control_screen.title("DVFA queries")
    Control_screen.geometry("500x300")
    Label(Control_screen, text="Learning DVFA \n \t Teacher system",font = "Cambria 16 bold italic",anchor=CENTER).pack()
    
    btnBrowseL = Button(Control_screen, text ='Browse learner automaton',justify=CENTER,activebackground="light blue" , command = lambda:open_file2())
    btnBrowseL.place(relx = 0.25, rely = 0.5, anchor = CENTER)
    Learner_path = Entry(Control_screen, textvariable=file_path,width=40)
    Learner_path.place(relx = 0.65, rely = 0.5, anchor = CENTER)
    
    BtnRun = Button(Control_screen, text ='Execute Algorithm', command = lambda:RunAlg(),state=DISABLED)
    BtnRun.place(relx = 0.5, rely = 0.7, anchor = CENTER) 

    exitButton = Button(Control_screen, text="Exit",foreground="red", background="white", command = lambda:close_window(Control_screen))
    exitButton.place(x=450, y=250)
 
    
    root.withdraw();


    
def RunAlg():
    
    global default
    global learner
    program="Final-Project.exe"
    arguments1=default
    argument2=learner
    #subprocess.call([program, arguments])
    p = Popen([program, arguments1,argument2], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate(b"input data that is passed to subprocess' stdin")
    rc = p.returncode

    messagebox.showinfo( "Result", output)
        
def open_file(): 
    global default
    file = askopenfile(mode ='r', filetypes =[('text Files', '*.txt')]) 
    if file is not None:  
        print(file.name)
        default=file.name 
    btnInitialize['state']='normal'
    file_path2.set(default)

def open_file2(): 
    
    global learner
    file = askopenfile(mode ='r',title = "Select A File",filetypes =[('Text Files', '*.txt')]) 
    if file is not None:  
        print(file.name)
        learner=file.name 
    file_path.set(learner)
    BtnRun['state']='normal'

def close_window(wnd): 
    wnd.destroy()
    wnd.quit()

mainloop() 
        
