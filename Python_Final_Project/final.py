import tkinter as tk
import os
import time
import psutil
import filetype
import hashlib
from tkinter import messagebox
from tkinter import filedialog
from PIL import Image, ImageTk
from collections import defaultdict

##以下為比較重複檔案部分
def calculate_file_hash(file_path, hash_algo=hashlib.sha256):
    """計算檔案的hash value"""
    hashfunction = hash_algo()
    try:
        with open(file_path, 'rb') as f:
            while chunk := f.read(8192):
                hashfunction.update(chunk)
        return hashfunction.hexdigest()
    except (FileNotFoundError, PermissionError):
        return None

def find_duplicates(directory):
    """找到指定資料夾中的重複檔案"""
    hashes = defaultdict(list)
    for root, _, files in os.walk(directory):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            file_hash = calculate_file_hash(file_path)
            if file_hash:
                hashes[file_hash].append(file_path)
    duplicates = {hash_val: paths for hash_val, paths in hashes.items() if len(paths) > 1}
    return duplicates

def print_duplicates(duplicates):
    """輸出重複檔案的資訊"""
    if not duplicates:
        print("沒有發現重複的檔案。")
    else:
        print("發現以下重複的檔案:")
        for hash_val, files in duplicates.items():
            print(f"\nHash value: {hash_val}")
            for file in files:
                print(f"  {file}")
##以上為比較重複檔案部分
##以下為找出所有檔名包含指定字串的檔案。
def find_files_with_string(directory, target_string):
    matching_files = []

    for root, _, files in os.walk(directory):
        for file in files:
            if target_string in file:
                matching_files.append(os.path.join(root, file))

    return matching_files
##以上為找出所有檔名包含指定字串的檔案。
##以下為處理閒置檔案。
def get_idle_files(directory, days_idle):
    current_time = time.time()#取得現在的時間
    idle_files = []
    # 遍歷資料夾並找出閒置時間超過指定天數的檔案
    for root, dirs, files in os.walk(directory):
        # 遍歷當前資料夾中的所有檔案
        for file in files:
            # 取得檔案的完整路徑
            file_path = os.path.join(root, file)
            # 獲取檔案的最後修改時間（以秒為單位的時間戳）
            file_mtime = os.path.getmtime(file_path)
            # 計算檔案的閒置時間（單位為天數）
            file_idle_time = (current_time - file_mtime) / (24 * 3600)  # 24 * 3600 將秒數轉換為天數
            # 如果檔案的閒置時間超過了指定的天數
            if file_idle_time > days_idle:
                # 將該檔案的完整路徑加入閒置檔案清單
                idle_files.append(file_path)
    return idle_files

def show_image(image_path):
    top = tk.Toplevel()
    top.title("Image Viewer")
    img = Image.open(image_path)
    screen_width = top.winfo_screenwidth()
    screen_height = top.winfo_screenheight()
    img_width, img_height = img.size

    # 計算縮放比例，使圖片不超過螢幕
    scale_factor = min(screen_width / img_width, screen_height / img_height)

    # 計算縮放後的圖片尺寸
    new_width = int(img_width * scale_factor)
    new_height = int(img_height * scale_factor)

    # 重新調整圖片大小
    img = img.resize((new_width, new_height), Image.Resampling.LANCZOS)

    # 將圖片轉換為 tkinter 可以顯示的格式
    tk_image = ImageTk.PhotoImage(img)

    # 顯示圖片
    label = tk.Label(top, image=tk_image)
    label.image = tk_image  # 保持對圖片的引用
    label.pack()

    # 設置位置為螢幕中心
    x_offset = (screen_width - new_width) // 2
    y_offset = (screen_height - new_height) // 2
    top.geometry(f"+{x_offset}+{y_offset}")
    # 設置延遲關閉，5秒後自動關閉
    top.after(5000, top.destroy)
##以上為處理閒置檔案。

# 建立主視窗
root = tk.Tk()
root.title("Auto File System")
root.geometry("400x200")
root.resizable(False, False)

# 標題文字
label = tk.Label(root, text="自動文件管理系統", font=("Arial", 16))
label.pack(pady=10)

# 按鈕功能
def find_files():
    search_directory = filedialog.askdirectory()
    search_string = tk.simpledialog.askstring("Input", "請輸入要搜尋的字串: ")
    result = find_files_with_string(search_directory, search_string)
    if result:
        print("找到以下檔案:")
        for file_path in result:
            print(file_path)
    else:
        print("未找到符合條件的檔案。")

def handle_idle_files():
    root = tk.Toplevel()
    root.title('Auto file system')
    root.withdraw()
    directory = filedialog.askdirectory()
    days_idle = tk.simpledialog.askinteger("Input", "輸入閒置天數:")
    idle_files = get_idle_files(directory, days_idle)
    if idle_files:
        print("Files idle for more than {} days:".format(days_idle))
        for file in idle_files:
            print(file)
        answer = tk.messagebox.askyesno("Confirmation", "你要刪除全部的檔案嗎?")
        if answer:
            for file in idle_files:
                os.remove(file)
        else:
            for file in idle_files:
                kind = filetype.guess(file) #抽出File類型
                if kind.mime == 'image/jpeg':##如果檔案是jpg則可以預覽
                    show_image(file)
                ans = tk.messagebox.askyesno("Confirmation", "你要刪除此檔案嗎?")
                if ans:
                    os.remove(file)
    else:
        print("No files found that are idle for more than {} days.".format(days_idle))
    root.mainloop()

def compare_duplicate_files():
    folder = filedialog.askfolder()
    if os.path.isdir(folder):
        duplicates = find_duplicates(folder)
        print_duplicates(duplicates)
    else:
        print("無效的路徑。")

# 建立按鈕
btn_find_files = tk.Button(root, text="尋找檔案", width=20, command=find_files)
btn_find_files.pack(pady=5)

btn_handle_idle = tk.Button(root, text="處理閒置檔案", width=20, command=handle_idle_files)
btn_handle_idle.pack(pady=5)

btn_compare_duplicates = tk.Button(root, text="比較重複檔案", width=20, command=compare_duplicate_files)
btn_compare_duplicates.pack(pady=5)

# 啟動主迴圈
root.mainloop()
