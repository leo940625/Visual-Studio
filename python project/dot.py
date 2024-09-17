# -*- coding: utf-8 -*-
import requests

def download_images_from_webpage(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()  # 確保響應狀態碼為 200
        print(response.text)  # 打印響應內容以確認是否正常
    except requests.exceptions.RequestException as e:
        print(f"An error occurred: {e}")

# 測試
download_images_from_webpage("https://bingfong.com/thread-1914981-1-1.html")