import os
import time
import psutil
from PIL import Image, ImageTk
import tkinter as tk
from tkinter import filedialog
import filetype

def get_idle_files(directory, days_idle):
    """
    獲取指定目錄中閒置時間超過指定天數的文件。
    參數:
    directory (str): 要搜索的目錄路徑。
    days_idle (int): 文件閒置的天數閾值。
    返回:
    list: 閒置時間超過指定天數的文件路徑列表。
    """
    current_time = time.time()#取得現在的時間
    idle_files = []
    # 遍歷目錄樹並找出閒置時間超過指定天數的檔案
    for root, dirs, files in os.walk(directory):
        # 遍歷當前目錄中的所有檔案
        for file in files:
            # 取得檔案的完整路徑
            file_path = os.path.join(root, file)
            # 獲取檔案的最後修改時間（以秒為單位的時間戳）
            file_mtime = os.path.getmtime(file_path)
            # 計算檔案的閒置時間（單位為天數）
            # current_time 是當前的時間戳（需事先定義）
            file_idle_time = (current_time - file_mtime) / (24 * 3600)  # 24 * 3600 將秒數轉換為天數
            # 如果檔案的閒置時間超過了指定的天數
            if file_idle_time > days_idle:
                # 將該檔案的完整路徑加入閒置檔案清單
                idle_files.append(file_path)
    return idle_files

def show_image(image_path):
    # 創建新的窗口
    top = tk.Toplevel()
    top.title("Image Viewer")

    # 加載圖片
    img = Image.open(image_path)

    # 獲取螢幕的大小
    screen_width = top.winfo_screenwidth()
    screen_height = top.winfo_screenheight()

    # 獲取圖片的原始尺寸
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

    # 設置窗口位置為螢幕中心
    x_offset = (screen_width - new_width) // 2
    y_offset = (screen_height - new_height) // 2
    top.geometry(f"+{x_offset}+{y_offset}")

    # 設置延遲關閉，5秒後自動關閉
    top.after(5000, top.destroy)

def main():
    root = tk.Tk()
    root.title('Auto file system')
    root.withdraw()  # 隱藏主視窗
    directory = filedialog.askdirectory()
    days_idle = tk.simpledialog.askinteger("Input", "Enter the number of idle days:")
    idle_files = get_idle_files(directory, days_idle)
    if idle_files:
        print("Files idle for more than {} days:".format(days_idle))
        for file in idle_files:
            print(file)
        answer = tk.messagebox.askyesno("Confirmation", "Do you want to delete all files?")
        if answer:
            for file in idle_files:
                os.remove(file)
        else:
            for file in idle_files:
                kind = filetype.guess(file) #抽出File類型
                if kind.mime == 'image/jpeg':
                    show_image(file)
                ans = tk.messagebox.askyesno("Confirmation", "Do you want to delete this file?")
                if ans:
                    os.remove(file)
    else:
        print("No files found that are idle for more than {} days.".format(days_idle))
    root.mainloop()

if __name__ == "__main__":
    main()