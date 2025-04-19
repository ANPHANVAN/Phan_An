from selenium import webdriver
from selenium.webdriver.common.by import By
import time

url = "https://www.google.com/maps/place/Dam+Sen+Cultural+Park/@10.7547734,106.632844,7430m/data=!3m1!1e3!4m6!3m5!1s0x31752e9747f2686b:0xd9b909a86e926ccb!8m2!3d10.766098!4d106.6418936!16s%2Fm%2F06608vy?entry=ttu&g_ep=EgoyMDI1MDMzMC4wIKXMDSoJLDEwMjExNjQwSAFQAw%3D%3D"

options = webdriver.ChromeOptions()
options.add_argument("--headless")  # Chạy không hiển thị trình duyệt
driver = webdriver.Chrome(options=options)
driver.get(url)

time.sleep(5)  # Chờ tải trang

# Tìm và lấy nội dung review
reviews = driver.find_elements(By.CLASS_NAME, "wiI7pd")
for review in reviews:
    print(review.text)

driver.quit()
