import matplotlib.pyplot as plt
import numpy as np
import pandas as pddadad
import gdown

url = "https://drive.google.com/u/1/uc?id=1GVsoe5eOsH2f22rWWUEZu8ScDXcEFoDl"
output = "udemy_dataset.csv"
gdown.download(url, output)
df = pd.read_csv(output)
m, n = df.shape
print(f"Size of dataset: {m}")
print(f"Number of Features: {n}")
df.head()