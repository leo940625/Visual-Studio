import os
import time
import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
def display_image(image_path):
    try:
        img = Image.open(image_path)
        img = img.resize((200, 200), Image.LANCZOS)
        img_tk = ImageTk.PhotoImage(img)
        image_label.config(image=img_tk)
        image_label.image = img_tk
    except Exception as e:
        messagebox.showerror("Error", f"Failed to display image: {e}")

def on_file_select(event):
    selected_file = files_listbox.get(files_listbox.curselection())
    display_image(selected_file)

def get_idle_files(directory, days_idle):
    current_time = time.time()
    idle_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            file_mtime = os.path.getmtime(file_path)
            file_idle_time = (current_time - file_mtime) / (24 * 3600)
            if file_idle_time > days_idle:
                idle_files.append(file_path)
    return idle_files


def select_directory():
    directory = filedialog.askdirectory()
    if directory:
        directory_var.set(directory)


def scan_files():
    directory = directory_var.get()
    try:
        days_idle = int(days_var.get())
        if not directory:
            messagebox.showerror("Error", "Please select a directory.")
            return
        if days_idle <= 0:
            messagebox.showerror("Error", "Idle days must be a positive number.")
            return

        idle_files = get_idle_files(directory, days_idle)
        files_listbox.delete(0, tk.END)
        if idle_files:
            for file in idle_files:
                files_listbox.insert(tk.END, file)
            messagebox.showinfo("Scan Complete", f"Found {len(idle_files)} idle files.")
        else:
            messagebox.showinfo("No Files Found", f"No files idle for more than {days_idle} days.")
    except ValueError:
        messagebox.showerror("Error", "Idle days must be a valid number.")


def delete_files():
    files = files_listbox.get(0, tk.END)
    if not files:
        messagebox.showinfo("No Files", "No files to delete.")
        return

    confirm = messagebox.askyesno("Delete Files", "Are you sure you want to delete all listed files?")
    if confirm:
        for file in files:
            try:
                os.remove(file)
                files_listbox.delete(0, tk.END)
                messagebox.showinfo("Delete Complete", "All files deleted successfully.")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to delete {file}: {e}")


root = tk.Tk()
root.title("Idle File Cleaner")
root.geometry("600x500")  # 增大高度以適應刪除按鈕

# 目錄選擇
tk.Label(root, text="Directory:").pack(anchor="w", padx=10, pady=5)
directory_var = tk.StringVar()
tk.Entry(root, textvariable=directory_var, width=50).pack(anchor="w", padx=10, pady=5)
tk.Button(root, text="Browse", command=select_directory).pack(anchor="w", padx=10)

# 閒置天數
tk.Label(root, text="Idle Days:").pack(anchor="w", padx=10, pady=5)
days_var = tk.StringVar()
tk.Entry(root, textvariable=days_var, width=10).pack(anchor="w", padx=10, pady=5)

# 掃描按鈕
tk.Button(root, text="Scan Files", command=scan_files).pack(pady=10)

# 檔案列表
tk.Label(root, text="Idle Files:").pack(anchor="w", padx=10, pady=5)
files_listbox = tk.Listbox(root, width=80, height=10)
files_listbox.pack(padx=10, pady=5)

image_label = tk.Label(root)
image_label.pack()

# 刪除按鈕
tk.Button(root, text="Delete Files", command=delete_files).pack(pady=10)

root.mainloop()
