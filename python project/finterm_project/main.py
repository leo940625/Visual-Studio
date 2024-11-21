import os
import time

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

def main():
    directory = input("Enter the directory to scan: ")
    days_idle = int(input("Enter the number of idle days: "))
    idle_files = get_idle_files(directory, days_idle)
    if idle_files:
        print("Files idle for more than {} days:".format(days_idle))
        for file in idle_files:
            print(file)
            answer = input("Do you wants delete all files(1/0)?")
            os.remove(file)
    else:
        print("No files found that are idle for more than {} days.".format(days_idle))

if __name__ == "__main__":
    main()