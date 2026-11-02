# 📚 Hệ Thống Quản Lý Thư Viện (Library Management System) - PBL1

> Dự án lập trình hướng đối tượng bằng C++ quản lý toàn bộ quy trình vận hành thư viện, được phát triển như một cột mốc đồ án học tập đầu tay (PBL1).

---

## 👥 Nhóm Thực Hiện
* **Trần Lê Xuân Phúc** – Sinh viên lớp 25VDT
* **Dương Hoàng Phát** – Sinh viên lớp 25VDT
* **Đơn vị:** Khoa Điện tử và Trí tuệ Nhân tạo, Trường Đại học Bách Khoa – ĐH Đà Nẵng.

---

## 👨‍🏫 Lời Cảm Ơn
Trước khi đến với báo cáo chi tiết, chúng em xin gửi lời cảm ơn chân thành nhất đến **Thầy Nguyễn Duy Nhật Viễn** cùng các thầy cô bộ môn PBL1 – Khoa Điện tử và Trí tuệ Nhân tạo. Thầy đã tận tình hướng dẫn, hỗ trợ cả về mặt lý thuyết lẫn thực hành trong suốt quá trình thực hiện đề tài, giúp chúng em rèn luyện tư duy phân tích, kỹ năng lập trình và khả năng chịu áp lực trong công việc.

Chúng em cũng xin gửi lời cảm ơn đặc biệt đến anh **Đông Trà** (lớp 24VDT) vì những kinh nghiệm quý báu và sự hỗ trợ nhiệt tình giúp nhóm vượt qua các khó khăn trong quá trình hoàn thiện đề tài.

Mặc dù đã nỗ lực hết mình, đồ án đầu tay này khó tránh khỏi những thiếu sót.

---

## 🎥 Demo Sản Phẩm
👉 **Video Demo Hệ Thống:** [Xem tại YouTube](https://youtu.be/jCcx40x3eQk?si=IFqlcl2QxF06QgPX)

---

## ⚙️ Công Nghệ & Kỹ Thuật Sử Dụng
* **Ngôn ngữ lập trình:** C++
* **Mô hình thiết kế:** Lập trình Hướng Đối Tượng (Object-Oriented Programming - OOP)
* **Cấu trúc dữ liệu:** Sử dụng `std::vector` để quản lý danh sách tài khoản khách hàng và kho sách linh hoạt, tối ưu hóa việc thêm/xóa dữ liệu động.

---

## 🌟 Các Tính Năng & Điểm Nhấn Của Dự Án

### 1. Phân quyền và Quản lý Hệ thống
* **Dành cho Quản trị viên (Manager):** 
  * Quản lý toàn bộ kho sách (Thêm, xóa, cập nhật thông tin sách).
  * Kiểm soát lịch sử mượn – trả sách của người đọc.
* **Dành cho Người đọc (Reader):** 
  * Tra cứu thông tin sách dễ dàng, trực quan.
  * Thực hiện quy trình mượn và trả sách thuận tiện, nhanh chóng.

### 2. Điểm Mạnh Về Kỹ Thuật (Technical Highlights)
* **Ứng dụng triệt để Lập trình Hướng Đối Tượng (OOP):** Tận dụng tối đa các tính chất cốt lõi như **Tính đóng gói (Encapsulation)** để đảm bảo bảo mật dữ liệu, **Tính kế thừa** và **Đa hình** giúp mã nguồn mở rộng dễ dàng, cấu trúc rõ ràng.
* **Quản lý tài khoản thông minh với `std::vector`:** Đề tài sử dụng mảng động `std::vector` của C++ để lưu trữ và quản lý thông tin khách hàng, giúp việc truy xuất, tìm kiếm và cập nhật trạng thái tài khoản diễn ra mượt mà, hạn chế lãng phí bộ nhớ so với mảng tĩnh truyền thống.