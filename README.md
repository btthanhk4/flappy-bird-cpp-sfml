[[English]](README_en.md)

# Flappy Bird - Thanh Edition

- Trải nghiệm game: 
- Phá đảo game: 

# Giới thiệu game

Flappy Bird là một game thuộc thể loại endless runner. Người chơi điều khiển chú chim bay qua các chướng ngại vật để ghi điểm cao nhất có thể. Hãy cố gắng giữ chú chim bay càng lâu càng tốt mà không va chạm vào ống.

- [0. Cách tải game](#0-cách-tải-game)
    * [a. Cách 1: Không bao gồm code.](#a-cách-1-không-bao-gồm-code)
    * [b. Cách 2: Bao gồm code và có thể biên dịch.](#b-cách-2-bao-gồm-code-và-có-thể-biên-dịch)
- [1. Bắt đầu game](#1-bắt-đầu-game)
- [2. Chọn level](#2-chọn-level)
- [3. Các thành phần trong game](#3-các-thành-phần-trong-game)
- [4. Cách chơi](#4-cách-chơi)
    * [a. Cách điều khiển](#a-cách-điều-khiển)
    * [b. Các loại chướng ngại vật](#b-các-loại-chướng-ngại-vật)
- [5. Chiến thắng và thất bại](#5-chiến-thắng-và-thất-bại)
- [Về đồ họa của game](#về-đồ-họa-của-game)
- [Về source code game](#về-source-code-game)

# 0. Cách tải game

## a. Cách 1: Không bao gồm code.

Tải game (được nén thành .zip) tại link sau: [Link tải game](https://github.com/YourRepo/FlappyBird/releases/tag/published) <br/>
Giải nén game vào một thư mục và bật flappybird.exe lên và chơi.

## b. Cách 2: Bao gồm code và có thể biên dịch.

**Bước 1:** Clone repo này về: `git clone https://github.com/YourRepo/FlappyBird.git` hoặc chọn Code -> Download Zip.

**Bước 2:** Cài đặt môi trường phát triển, bao gồm các công cụ như gcc/g++, make.

**Bước 3:** Mở terminal trong thư mục chứa Makefile và gõ lệnh `make`.

**Bước 4:** Bật flappybird.exe và chơi.

# 1. Bắt đầu game

Chờ một chút rồi click vào nút “START” để bắt đầu chơi game.
<div style="text-align: center;">

![start](resources/start_screen.png)

</div>

Khi vào game lần đầu, người chơi hãy nhấn phím hoặc click chuột để bắt đầu.

<div style="text-align: center;">

![game](resources/game_screen.png)

</div>

# 2. Chọn level

Game này không có các level truyền thống mà bạn sẽ chơi liên tục để ghi điểm cao nhất.

# 3. Các thành phần trong game:

- **Chim**: Đây là nhân vật chính mà bạn sẽ điều khiển.
- **Ống**: Các chướng ngại vật mà bạn cần tránh.
- **Điểm số**: Hiển thị số điểm bạn đạt được.

<div style="text-align: center;">

![components](resources/components.png)

</div>

# 4. Cách chơi

Điều khiển chú chim bay qua các ống mà không va chạm vào chúng.

## a. Cách điều khiển

Nhấn phím hoặc click chuột để làm chú chim bay lên. Nếu không nhấn, chú chim sẽ rơi xuống.

## b. Các loại chướng ngại vật

Các chướng ngại vật chính là các ống xanh. Khoảng cách giữa các ống sẽ thay đổi ngẫu nhiên để tăng độ khó.

# 5. Chiến thắng và thất bại

- Bạn sẽ tiếp tục chơi cho đến khi chú chim va chạm vào ống hoặc rơi xuống đất.

<div style="text-align: center;">

![gameover](resources/gameover.png)

</div>

---

### Về đồ họa của game:

[[Cách làm hiệu ứng trong game]](about_graphics.md)

### Về source code game:

- **Folder src**: Chứa tất cả các mã nguồn của game.
- **Folder resources**: Chứa các tài nguyên như hình ảnh, âm thanh.
- **game.cpp**: Hàm main() của trò chơi.
