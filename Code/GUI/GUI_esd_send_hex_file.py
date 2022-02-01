# /****************************************************************************
#  * @file GUI_esd_send_hec_file.py : 
#  * @brief : This file implements GUI application for sending Hex file over 
#  *          WiFi
#  * 
#  * @date : Nov 22,2021
#  * @author: Rajat Chaple and Dhiraj Bennadi
#  ****************************************************************************/
 
import tkinter as tk
from tkinter import Frame, ttk, Tk, Label, Entry, StringVar
from tkinter import filedialog as fd
from tkinter.constants import RIDGE, SOLID, SUNKEN
from tkinter.messagebox import showinfo
import socket

# global labelText_ip, labelText_port
# create the root window
root = tk.Tk()
root.title('Flashing utility')
root.resizable(False, False)
root.geometry('500x300')
filename = ""

def connect_tcp():
    global labelText_ip, labelText_port, s
    print("connecting to:")
    print(tcp_ip_text_var.get())
    print(tcp_port_text_var.get())
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((tcp_ip_text_var.get(), int(tcp_port_text_var.get())))
    print("Connected to "+ tcp_ip_text_var.get() + ":" + tcp_port_text_var.get())
    connect_button.config(text="Connected")

labelDir_ip=Label(root, text="Remote Program utility for 8051", height=5, font= 20)
labelDir_ip.grid(row=1,column=1, columnspan=2)

frame_tcp=Frame(root, borderwidth=1,relief=SUNKEN)
frame_tcp.grid(row=2,column=1)

frame_program=Frame(root, borderwidth=1, relief=SUNKEN)
frame_program.grid(row=2,column=2)

def select_file():
    global filename
    filetypes = (
        ('text files', '*.hex'),
        ('All files', '*.*')
    )

    filename = fd.askopenfilename(
        title='Open a file',
        initialdir='/',
        filetypes=filetypes)

    print(filename)
    # showinfo(
    #     title='Selected File',
    #     message=filename
    # )

def send_file():
    global s, filename
    print("sending file")
    connect_tcp()
    print(filename)
    file = open(filename,'r')
    for each in file:
        each = "$$$" + each
        s.send(each[:-1].encode())
        
    #data = s.recv(BUFFER_SIZE)
    s.send("###".encode())
    # file.write("###")
    s.close()
    file.close()

labelText_ip=StringVar()
labelText_ip.set("TCP IP: ")
labelDir_ip=Label(frame_tcp, textvariable=labelText_ip, height=4)
labelDir_ip.grid(row=1,column=1, padx= 30)

tcp_ip_text_var=StringVar(None)
tcp_ip_text=Entry(frame_tcp,textvariable=tcp_ip_text_var,width=30)
tcp_ip_text.grid(row=1,column=2,padx= 10)


labelText_port=StringVar()
labelText_port.set("TCP Port: ")
labelDir_port=Label(frame_tcp, textvariable=labelText_port, height=4)
labelDir_port.grid(row=2,column=1, padx= 30)

tcp_port_text_var=StringVar(None)
tcp_port_text=Entry(frame_tcp,textvariable=tcp_port_text_var,width=30)
tcp_port_text.grid(row=2,column=2, padx= 10)


# open button
connect_button = ttk.Button(
    frame_tcp,
    text='Connect',
    command=connect_tcp
)

# open_button.pack(expand=True)
connect_button.grid(row=3,column=2, padx= 30, pady = 8)


# open button
open_button = ttk.Button(
    frame_program,
    text='Open a File',
    command=select_file
)

# open_button.pack(expand=True)
open_button.grid(row=4,column=1, padx= 50, pady = 32)


label_selected_file_var=StringVar()
label_selected_file_var.set("Selected file ")
label_selected_file=Label(frame_program, textvariable=label_selected_file_var, height=4)
label_selected_file.grid(row=4,column=2)


# Program button
Program_button = ttk.Button(
    frame_program,
    text='Program',
    command=send_file
)

# open_button.pack(expand=True)
Program_button.grid(row=5,column=1, padx= 50, pady = 30)



# run the application
root.mainloop()