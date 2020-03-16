from tkinter import *
from tkinter import ttk
from tkinter import filedialog
from tkinter import messagebox

class Root(Tk):
    def __init__(self):
        super(Root, self).__init__()
        self.title("Initialization System")
        self.minsize(300, 300)
        self.labelMain = ttk.Label(self, text = "DVFA")
        self.labelMain.grid(column = 0, row = 0,padx=20,pady=20)
        self.labelFrame = ttk.LabelFrame(self, text = "Open File")
        self.labelFrame.grid(column = 1, row = 1, sticky='NS')
        

        self.buttonBrowse()
        self.buttonRunAlg()


    def buttonBrowse(self):
        self.button = ttk.Button(self.labelFrame, text = "Browse A File",command = self.fileDialog)
        self.button.grid(column = 1, row = 1)
    
    def RunAlg(self):
        messagebox.showinfo( "Run", "In processes...")

    def buttonRunAlg(self):
        self.button = ttk.Button(self, text = "Run",command =self.RunAlg)
        #self.button = ttk.Button(self, text = "Run",command =self.open_file)
        self.button.place(relx=0.5, rely=0.5, anchor=S)
        
    def open_file(self): 
        fileToOpen = open(self.filename, 'r')
        print(fileToOpen)

    def fileDialog(self):

        self.filename = filedialog.askopenfilename(initialdir =  "/", title = "Select A File", filetype =
        (("Text files","*.txt"),("all files","*.*")) )
        self.label = ttk.Label(self.labelFrame, text = "")
        self.label.grid(column = 1, row = 2)
        self.label.configure(text = self.filename)


root = Root()
root.mainloop()