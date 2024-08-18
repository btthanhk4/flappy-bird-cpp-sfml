## **Giáo viên hướng dẫn: TS. Lê Đức Trọng**

## **Sinh viên: Bùi Tiến Thành - 22027547**

---

### **Trải nghiệm game**

Flappy Bird mang đến một trải nghiệm hoàn toàn mới với những cải tiến đặc biệt, bao gồm việc chuyển đổi giữa các bản đồ sáng và tối, sự xuất hiện ngẫu nhiên của các vật phẩm đặc biệt giúp thay đổi tốc độ, điểm số và khả năng phòng thủ của người chơi.

---

## **Mục lục**
- [Giới thiệu game](#giới-thiệu-game)
- [Cách tải game](#cách-tải-game)
  - [Bao gồm code và có thể biên dịch](#bao-gồm-code-và-có-thể-biên-dịch)
- [Bắt đầu game](#bắt-đầu-game)
- [Các thành phần trong game](#các-thành-phần-trong-game)
- [Cách chơi](#cách-chơi)
  - [Cách điều khiển](#cách-điều-khiển)
  - [Các loại chướng ngại vật](#các-loại-chướng-ngại-vật)
  - [Điều thú vị của game](#điều-thú-vị-của-game)
- [Chiến thắng và thất bại](#chiến-thắng-và-thất-bại)
- [Về source code game](#về-source-code-game)

---

## **Giới thiệu game**

Flappy Bird là một game thuộc thể loại endless runner. Người chơi điều khiển chú chim bay qua các chướng ngại vật để ghi điểm cao nhất có thể. Game đã được cải tiến với nhiều tính năng đặc biệt như chuyển đổi giữa các bản đồ sáng và tối, xuất hiện các vật phẩm ngẫu nhiên giúp tăng điểm, tăng tốc độ hoặc cung cấp khiên chắn để né tránh chướng ngại vật.

---

## **Cách tải game**

### **Bao gồm code và có thể biên dịch**

1. Tải project bản zip về máy:
   <div style="text-align: center;">
     <img src="https://github.com/user-attachments/assets/fb59a041-97e1-486b-9d8a-ebad40a22d8d" alt="download" width="300">
   </div>

2. Cài đặt môi trường phát triển bao gồm các công cụ như gcc/g++, và thư viện SFML.
3. Mở dự án bằng Visual Studio 2022 rồi build và chạy dự án.

---

## **Bắt đầu game**

1. Chạy trò chơi và chờ đến màn hình chính.
2. Click vào nút “START” để bắt đầu chơi.

   <div style="text-align: center;">
     <img src="https://github.com/user-attachments/assets/0c6ab891-f448-4375-86ab-3b18c4b6e7b0" alt="start" width="300">
   </div>

3. Khi vào game, nhấn phím hoặc click chuột để điều khiển chú chim.

   <div style="text-align: center;">
     <img src="https://github.com/user-attachments/assets/d35c9a98-58ba-4874-8e55-4a9765669120" alt="game" width="300">
   </div>

---

## **Các thành phần trong game**

- **Chim**: Nhân vật chính mà bạn sẽ điều khiển.
  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/9cd9fb46-ab82-4fff-ac2e-38b4954d1f24" alt="bird" width="150">
  </div>

- **Ống**: Chướng ngại vật bạn cần tránh.
  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/e929b92f-6a27-4393-b951-d19e0dce0cb8" alt="PipeUp" width="150" style="margin-right: 20px;">
    <img src="https://github.com/user-attachments/assets/f391f031-45a8-4841-a216-349cf11a0ffc" alt="PipeDown" width="150" style="margin-left: 20px;">
  </div>

- **Điểm số**: Hiển thị điểm của bạn.
  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/f1fcbbd0-7265-4a6a-93c4-988ab66647cb" alt="score" width="150">
  </div>

- **Vật phẩm đặc biệt**:
  - **Vật phẩm tăng điểm**: Khi ăn, điểm của bạn sẽ được cộng thêm 5 điểm.
    <div style="text-align: center;">
      <img src="https://github.com/user-attachments/assets/a06162cb-fcd8-4904-ac39-1c80ac1fb8e4" alt="DoubleScore" width="150">
    </div>
  
  - **Vật phẩm tăng tốc độ**: Khi ăn, tốc độ di chuyển của các cột sẽ tăng lên, đồng thời khoảng cách giữa các cột sẽ bị rút ngắn.
    <div style="text-align: center;">
      <img src="https://github.com/user-attachments/assets/f72f172b-79a9-4efb-a65d-db18b0f71862" alt="SpeedUp" width="150">
    </div>

  - **Khiên chắn**: Cho phép bạn tránh được một quả bom mà không mất điểm.
    <div style="text-align: center;">
      <img src="https://github.com/user-attachments/assets/b4762931-c960-4ab1-9c42-88c8df82c5d2" alt="Shield" width="150">
    </div>

  - **Bom**: Giảm điểm số của bạn nếu không có khiên chắn.
    <div style="text-align: center;">
      <img src="https://github.com/user-attachments/assets/f87b5d05-43e7-41b4-9b7c-be54133621d8" alt="Boom" width="150">
    </div>

  - **Phần âm nhạc và thu thập vật phẩm khiên**: Bạn có thể vừa nghe nhạc vừa chơi game, rất thú vị phải không? Bên cạnh đó còn hiển thị số lượng khiên chắn bạn đang có.
    <div style="text-align: center;">
      <img src="https://github.com/user-attachments/assets/2ddf5391-4bd9-4a6d-8324-4928af68ad22" alt="Music" width="150">
    </div>

---

## **Cách chơi**

Điều khiển chú chim bay qua các ống mà không va chạm vào chúng, đồng thời ăn các vật phẩm để tăng điểm hoặc tăng tốc độ. Khi ăn khiên, bạn sẽ có khả năng tránh được một quả bom mà không bị mất điểm.

### **Cách điều khiển**

- Nhấn phím hoặc click chuột để làm chú chim bay lên.
- Nếu không nhấn, chú chim sẽ rơi xuống và bạn sẽ thua.

### **Các loại chướng ngại vật**

- Các ống xanh là các chướng ngại vật chính.
- Khoảng cách giữa các ống thay đổi ngẫu nhiên để tăng độ khó.

### **Điều thú vị của game**

- Khi bạn đạt điểm mốc nhất định, game sẽ tự động chuyển đổi giữa các bản đồ sáng và tối.
  
  **Map ban ngày:**
  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/39c8ddba-fffd-4187-b244-a2ad3e6e559b" alt="day_map" width="300">
  </div>

  **Map ban đêm:**
  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/aa113059-912b-46f6-88a7-cf9b26db25f8" alt="night_map" width="300">
  </div>

---

## **Chiến thắng và thất bại**

- **Chiến thắng**: Nếu bạn có thể đạt được 100000 điểm, bạn sẽ nhận được phần quà bí ẩn.
- **Thất bại**: Nếu chú chim va chạm vào ống hoặc rơi xuống đất, bạn sẽ thua cuộc và nhận được thông báo "Game Over". Bạn có thể chơi lại để cải thiện điểm số.

  <div style="text-align: center;">
    <img src="https://github.com/user-attachments/assets/f1fcbbd0-7265-4a6a-93c4-988ab66647cb" alt="game_over" width="300">
  </div>

---

## **Về source code game**

- **SFML Template**: Chứa mã nguồn của trò chơi.
- **Resources**: Chứa các tài nguyên như hình ảnh, âm thanh.
- **main.cpp**: Hàm `main()` của trò chơi.
