from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

def convert_to_grayscale(input_image_path, output_image_path):
    # 開啟檔案
    image = Image.open(input_image_path)

    # 將檔案轉換成灰階、CMYK及黑白
    cmyk_image = image.convert('CMYK')
    BW_image = image.convert('1')
    grayscale_image = image.convert('L')
    
    #儲存灰階圖片檔案
    grayscale_image.save(output_image_path)

    # 輸出四張圖片的像素
    original_pixels = np.array(image)
    grayscale_pixels = np.array(grayscale_image)
    cmyk_pixels = np.array(cmyk_image)
    BW_pixels = np.array(BW_image)

    print("Original Image Pixel Values:")
    print(original_pixels)

    print("\nGrayscale Image Pixel Values:")
    print(grayscale_pixels)

    print("\ncmyk Image Pixel Values:")
    print(cmyk_pixels)

    print("\nBW Image Pixel Values:")
    print(BW_pixels)
    
    #將四張圖片顯示出來
    plt.subplot(2, 2, 1)
    plt.imshow(original_pixels)
    plt.title("Original Image")
    plt.axis("off")

    plt.subplot(2, 2, 2)
    plt.imshow(cmyk_image)
    plt.title("CMYK_image")
    plt.axis("off")

    plt.subplot(2, 2, 3)
    plt.imshow(grayscale_pixels, cmap='gray')
    plt.title("Grayscale Image")
    plt.axis("off")

    plt.subplot(2, 2, 4)
    plt.imshow(BW_image)
    plt.title("BW_image")
    plt.axis("off")

    plt.show()

if __name__ == "__main__":
    # 指定圖片的位置
    input_image_path = "IMG_0368.JPG"

    # 指定圖片的儲存位置
    output_image_path = "convert_image.JPG"

    # 轉換圖片並顯示出來
    convert_to_grayscale(input_image_path, output_image_path)