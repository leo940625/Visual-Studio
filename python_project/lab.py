import PyPDF2 

# 打開PDF文件
pdfFileObj = open('python.pdf', 'rb') 

# 使用 PdfReader（新版PyPDF2）
pdfReader = PyPDF2.PdfReader(pdfFileObj) 

# 打印 PDF 頁數
print(len(pdfReader.pages))  # 正確的方式是使用 pdfReader.pages

# 獲取第一頁
pageObj = pdfReader.pages[0]  # 使用 pages 列表來獲取頁面

# 提取並打印第一頁的文本
print(pageObj.extract_text())  # 注意是 extract_text()，而不是 extractText()

# 關閉文件
pdfFileObj.close()
