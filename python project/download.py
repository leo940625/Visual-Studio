# -*- coding: utf-8 -*-
import requests
from bs4 import BeautifulSoup
import os
import re
import urllib.parse

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

def clean_filename(filename):
    return re.sub(r'[<>:"/\\|?*]', '', filename)

def download_image(url, folder):
    try:
        response = requests.get(url, headers=headers, stream=True)
        response.raise_for_status()  # 將 HTTP 錯誤代碼引發為例外
        if response.status_code == 200:
            filename = os.path.join(folder, clean_filename(url.split("/")[-1].split('?')[0]))
            with open(filename, 'wb') as f:
                f.write(response.content)
            print(f"Image saved as {filename}")
        else:
            print(f"Failed to download image from {url}. Status code: {response.status_code}")
    except requests.exceptions.RequestException as e:
        print(f"An error occurred while downloading {url}: {e}")

def download_images_from_webpage(webpage_url, folder):
    if not os.path.exists(folder):
        os.makedirs(folder)

    try:
        response = requests.get(webpage_url, headers=headers)
        response.raise_for_status()  # 將 HTTP 錯誤代碼引發為例外
        if response.status_code != 200:
            print(f"Failed to retrieve the webpage: {webpage_url}. Status code: {response.status_code}")
            return

        soup = BeautifulSoup(response.text, 'html.parser')
        img_tags = soup.find_all('img')
        img_urls = [img['src'] for img in img_tags if 'src' in img.attrs]

        base_url = re.match(r'(https?://.*?)(/.*)?$', webpage_url)
        if base_url:
            base_url = base_url.group(1)
        else:
            print("Failed to parse base URL")
            return

        for img_url in img_urls:
            if img_url.startswith(('http:', 'https:')):
                full_img_url = img_url
            else:
                full_img_url = urllib.parse.urljoin(base_url, img_url)
            download_image(full_img_url, folder)
    except requests.exceptions.RequestException as e:
        print(f"An error occurred while retrieving the webpage: {e}")

webpage_url = 'https://bingfong.com/forum.php?mod=viewthread&tid=1973036&highlight=%E6%9E%97%E5%B2%B1%E7%B8%88'
folder = 'downloaded_images'
download_images_from_webpage(webpage_url, folder)