import os
import shutil
import time
from datetime import datetime, timedelta

# Define the paths
source_folder = '/path/to/source/folder'
organized_folder = '/path/to/organized/folder'
reminder_days = 180  # Number of days to remind for unused files

# Create organized folders if they don't exist
folders = ['Documents', 'Images', 'Videos', 'Others']
for folder in folders:
    os.makedirs(os.path.join(organized_folder, folder), exist_ok=True)

# Function to get file type
def get_file_type(file):
    if file.endswith(('.txt', '.pdf', '.docx')):
        return 'Documents'
    elif file.endswith(('.jpg', '.jpeg', '.png', '.gif')):
        return 'Images'
    elif file.endswith(('.mp4', '.mkv', '.avi')):
        return 'Videos'
    else:
        return 'Others'

# Function to organize files
def organize_files():
    for root, _, files in os.walk(source_folder):
        for file in files:
            file_path = os.path.join(root, file)
            file_type = get_file_type(file)
            dest_folder = os.path.join(organized_folder, file_type)
            shutil.move(file_path, dest_folder)

# Function to remind for old files
def remind_old_files():
    now = time.time()
    for root, _, files in os.walk(organized_folder):
        for file in files:
            file_path = os.path.join(root, file)
            last_access_time = os.path.getatime(file_path)
            if now - last_access_time > reminder_days * 86400:
                print(f"Reminder: The file '{file}' in '{root}' has not been used for {reminder_days} days. Consider deleting it.")

# Organize files and remind for old files
organize_files()
remind_old_files()