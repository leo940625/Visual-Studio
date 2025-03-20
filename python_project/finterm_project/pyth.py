import os
import hashlib
from collections import defaultdict
import time
import psutil
from PIL import Image, ImageTk
import tkinter as tk
from tkinter import filedialog
import filetype

def calculate_file_hash(file_path, hash_algo=hashlib.sha256):
    """計算檔案的哈希值"""
    hash_func = hash_algo()
    try:
        with open(file_path, 'rb') as f:
            while chunk := f.read(8192):
                hash_func.update(chunk)
        return hash_func.hexdigest()
    except (FileNotFoundError, PermissionError):
        return None

def find_duplicates(directory):
    """找到指定目錄中的重複檔案"""
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
            print(f"\n哈希值: {hash_val}")
            for file in files:
                print(f"  {file}")

if __name__ == "__main__":
    directory = filedialog.askdirectory()
    if os.path.isdir(directory):
        duplicates = find_duplicates(directory)
        print_duplicates(duplicates)
    else:
        print("無效的目錄路徑。")