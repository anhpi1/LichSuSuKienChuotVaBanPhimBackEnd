# 📌 Hướng dẫn sử dụng & Cấu trúc dự án
Dự án này được tổ chức theo mô hình **MVC (Model – View – Controller)** nhằm tối ưu hoá khả năng mở rộng và bảo trì mã nguồn.
---
## 🗂️ Cấu trúc thư mục
| Thư mục        | Mô tả                                      |
| -------------- | ------------------------------------------ |
| **Controller** | Chứa logic xử lý chính của chương trình    |
| **Model**      | Chứa toàn bộ hàm thao tác với SQL Database |
| **View**       | Chứa các hàm dùng để hiển thị dữ liệu      |
| **README.md**  | Tài liệu mô tả dự án                       |


> ✨ Mỗi phần chỉ làm đúng vai trò của nó — không viết lẫn logic sai vị trí.
---
## ✅ Quy tắc đặt tên trong dự án
| Thành phần | Quy tắc | Ví dụ |
|----------|--------|------|
| **Macro** | Viết IN HOA, cách bởi `_` | `DAY_LA_MOT_MAU` |
| **Tên biến** | Viết kiểu CamelCase, mỗi từ viết hoa chữ cái đầu | `DayLaMotMau` |
| **Include** | `#include` để trong file `.h`, hạn chế include trực tiếp trong `.cpp` | `#include "Model/UserModel.h"` |
---
## 🏗️ Quy trình xây dựng 1 đối tượng (Struct / Class)
Mỗi đối tượng phải có tối thiểu 4 hàm:
1️⃣ Hàm khởi tạo dữ liệu  
2️⃣ Hàm thêm dữ liệu  
3️⃣ Hàm hiển thị dữ liệu  
4️⃣ Hàm xóa dữ liệu  
> Trong phiên bản học tập này sử dụng `struct` để dễ tiếp cận.  
> Khi áp dụng vào dự án thực tế → sử dụng `class` để quản lý tốt hơn.
---
## 👥 Quy định làm việc nhóm
- Ai tạo file nào → đặt tên file theo tên người đó  
- Mục đích giúp quản lý và sửa lỗi đúng người phụ trách
📌 Ví dụ:
HaiAnh_MouseModel.h
HaiAnh_MouseModel.cpp
> Không tự ý sửa code của người khác nếu không có trao đổi trước.
---
## 📦 Quy định dữ liệu
- Với danh sách cấu trúc hoặc chuỗi dữ liệu:
✅ **Phải sử dụng `std::vector`**
- 🚫 Không dùng mảng tĩnh để lưu nhiều phần tử
---
## 🎯 Mục tiêu chất lượng
| Mục tiêu | Lợi ích |
|--------|--------|
| Tách rõ các tầng MVC | Dễ bảo trì |
| Chuẩn hóa code | Tránh lỗi và dễ đọc |
| Vector thay mảng tĩnh | Linh hoạt & mở rộng tốt |
| Quản lý file theo người làm | Tối ưu sửa lỗi & phân công |
---

💡 Nếu có quy ước mới trong nhóm → cập nhật tại đây để mọi thành viên tuân theo.

class (đối tượng)
 - hàm khởi tạo
 - hàm hàm locgic
 - hàm xóa phần tử
 - hàm xem phần tử
---

✍️ Hãy góp ý để Readme này hoàn thiện hơn!
