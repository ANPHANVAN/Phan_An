import sqlite3

# Kết nối hoặc tạo mới file database
conn = sqlite3.connect('sports.db')
c = conn.cursor()

# Tạo bảng với 3 cột: STT, name, sport
c.execute('''
    CREATE TABLE IF NOT EXISTS registaints (
        STT INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        sport TEXT NOT NULL
    )
''')

# Lưu thay đổi và đóng kết nối
conn.commit()
conn.close()

print("Database và bảng đã được tạo thành công!")
