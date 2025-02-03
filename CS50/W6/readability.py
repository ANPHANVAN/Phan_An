# Nhập văn bản từ người dùng
try:
    text = input("Text: ")
except ValueError:
    pass    

# Khởi tạo số lượng chữ cái, từ và câu
letters = 0
words = 1  # Ban đầu là 1 vì các từ cách nhau bằng khoảng trắng
sentences = 0

# Duyệt từng ký tự trong đoạn văn
for char in text:
    if char.isalpha():  # Nếu là chữ cái
        letters += 1
    elif char == ' ':  # Nếu là khoảng trắng (tính từ)
        words += 1
    elif char in ['.', '!', '?']:  # Nếu là dấu kết thúc câu
        sentences += 1

# Tính L và S theo công thức
L = (letters / words) * 100
S = (sentences / words) * 100

# Tính chỉ số đọc hiểu
index = round(0.0588 * L - 0.296 * S - 15.8)

# In kết quả theo quy tắc đề bài
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
