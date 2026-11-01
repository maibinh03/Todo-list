# 📝 C Todo List

Một ứng dụng quản lý công việc đơn giản được viết bằng C, cho phép người dùng tạo và quản lý danh sách công việc trực tiếp trên terminal.

Dự án sử dụng `struct` để tổ chức dữ liệu và cấp phát bộ nhớ động để quản lý danh sách công việc.  
Đây cũng là một bài thực hành về con trỏ, mảng động và thao tác với bộ nhớ trong C.

## ✨ Features

- **Add:** Thêm công việc mới.  
- **List:** Hiển thị danh sách công việc và trạng thái hoàn thành.  
- **Complete:** Đánh dấu công việc đã hoàn thành.  
- **Edit:** Chỉnh sửa nội dung công việc.  
- **Delete:** Xóa công việc khỏi danh sách.  
- **Memory Management:** Sử dụng `malloc`, `realloc` và `free` để quản lý bộ nhớ động.  

## 🛠 Tech Stack

**C** – Sử dụng `struct`, pointers, dynamic memory allocation.  
Các thư viện chuẩn như `stdio.h`, `stdlib.h`, `string.h`.

## 🚀 Getting Started

Biên dịch bằng GCC:

```bash
gcc main.c -o todo_list
```

Chạy ứng dụng:

```bash
./todo_list
```

Trên Windows:

```powershell
.\todo_list.exe
```

## 💡 What I Learned

Thông qua dự án này, mình thực hành cách sử dụng `struct` để quản lý dữ liệu, thao tác với con trỏ, cấp phát và giải phóng bộ nhớ động.  
Ngoài ra, dự án giúp hiểu rõ hơn cách triển khai các thao tác CRUD trên một danh sách dữ liệu bằng ngôn ngữ C.
