from tkinter import ttk
import tkinter as tk 
from tkinter import filedialog
from tkinter import messagebox
import subprocess
from subprocess import Popen, PIPE
from tkinter import * 
from tkinter.filedialog import askopenfile
global Control_screen
global file_path2
root = Tk() 
file_path2=StringVar();
root.geometry('500x300')
default=""
learner=""
btn = Button(root, text ='Browse default automaton',width=10, height=1, command = lambda:open_file()) 
btnRunAlg = Button(root, text ='Initialze', command = lambda:Initialze(),state=DISABLED)
root.title("Initialization System")


Label(root, text="Learning DVFA \n \t Teacher system", font = "Helvetica 16 bold italic",anchor=CENTER).pack()
Label(root,  text="System helps the learner by answering membership queries\nand eqivalnce queries.",fg = "red",font = "Times 14",justify=LEFT).pack()
Entry(root, textvariable=file_path2).pack()
btn.pack(side=TOP,pady = 10) 
btnRunAlg.pack()






def Initialze():
    global file_path
    global BtnRun
    file_path=StringVar();

    Control_screen = Toplevel(root)

    Control_screen.title("Mellanox AutoAgent")
    Control_screen.geometry("500x300")
    Label(Control_screen, text="Learning DVFA \n \t Teacher system").pack()
    btn2 = Button(Control_screen, text ='Browse learner automaton', command = lambda:open_file2()).place(x=0,y=20)
    #btn2.pack(side = TOP, pady = 20) 
    BtnRun = Button(Control_screen, text ='Execute Algorithm', command = lambda:RunAlg(),state=DISABLED)
    BtnRun.pack(side = TOP, pady = 20) 

    
 
    username_login_entry = Entry(Control_screen, textvariable=file_path)

    Label(Control_screen, text="RMA case number:").pack()
    username_login_entry.pack()
    root.withdraw();



def buttonBrowse(self):
    self.button = ttk.Button(self.labelFrame, text = "Browse A File",command = self.fileDialog)
    self.button.grid(column = 1, row = 1)
    
def RunAlg():
    
    global default
    global learner
    program="Final-Project.exe"
    arguments1=default
    argument2=learner;
    #subprocess.call([program, arguments])
    p = Popen([program, arguments1,argument2], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output, err = p.communicate(b"input data that is passed to subprocess' stdin")
    rc = p.returncode

    messagebox.showinfo( "Result", output)

def buttonRunAlg(self):
    self.button = ttk.Button(self, text = "Run",command =self.RunAlg)
    #self.button = ttk.Button(self, text = "Run",command =self.open_file)
    self.button.place(relx=0.5, rely=0.5, anchor=S)
        
def open_file(): 
    global default
    file = askopenfile(mode ='r', filetypes =[('Python Files', '*.txt')]) 
    if file is not None:  
        print(file.name)
        default=file.name 
    btnRunAlg['state']='normal'
    file_path2.set(default)

def open_file2(): 
    
    global learner
    file = askopenfile(mode ='r', filetypes =[('Python Files', '*.txt')]) 
    if file is not None:  
        print(file.name)
        learner=file.name 
    file_path.set(learner)
    BtnRun['state']='normal'

def fileDialog(self):
    global Files
    self.Files = filedialog.askopenfilename(initialdir =  "/", title = "Select A File", filetype =
    (("Text files","*.txt"),("all files","*.*")) )
    self.label = ttk.Label(self.labelFrame, text = "")
    self.label.grid(column = 1, row = 2)
    self.label.configure(text = self.filename)

mainloop() 
        
