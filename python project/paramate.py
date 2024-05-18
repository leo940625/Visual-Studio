import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 定義參數範圍
u = np.linspace(0, np.pi, 100)
v = np.linspace(0, 2*np.pi, 100)

# 建立網格
U, V = np.meshgrid(u, v)

# 定義參數式方程
X = np.sin(U)*np.cos(V)
Y = np.sin(U)*np.sin(V)
Z = np.cos(U)

# 創建圖形
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 繪製曲面
ax.plot_surface(X, Y, Z, cmap='viridis')

# 設置標題和標籤
ax.set_title('Parametric Surface: Paraboloid')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# 顯示圖形
plt.show()