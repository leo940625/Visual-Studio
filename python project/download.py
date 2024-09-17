# -*- coding: utf-8 -*-
import requests
from bs4 import BeautifulSoup
import os
import re

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

def download_image(url, folder):
    try:
        response = requests.get(url, headers=headers, stream=True)
        if response.status_code == 200:
            filename = os.path.join(folder, url.split("/")[-1])
            with open(filename, 'wb') as f:
                f.write(response.content)
            print(f"Image saved as {filename}")
        else:
            print(f"Failed to download image from {url}")
    except Exception as e:
        print(f"An error occurred while downloading {url}: {e}")

def download_images_from_webpage(webpage_url, folder):
    if not os.path.exists(folder):
        os.makedirs(folder)

    try:
        response = requests.get(webpage_url, headers=headers)
        if response.status_code != 200:
            print(f"Failed to retrieve the webpage: {webpage_url}")
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
            if not img_url.startswith(('http:', 'https:')):
                img_url = base_url + img_url
            download_image(img_url, folder)
    except Exception as e:
        print(f"An error occurred: {e}")

webpage_url = 'https://bingfong.com/thread-1914981-1-1.html'
folder = 'downloaded_images'
download_images_from_webpage(webpage_url, folder)