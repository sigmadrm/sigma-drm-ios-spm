# sigma-drm-ios-spm

Swift Package Manager cho **SigmaDRM** trên iOS, cùng kiểu cấu trúc với [sigma-multidrm-spm](https://github.com/sigmadrm/sigma-multidrm-spm): `binaryTarget` trỏ tới `.xcframework` + target Swift mỏng.

## Chuẩn bị XCFramework

Build từ repo `player-drm-ios`:

```bash
cd SigmaDRM_iOS
./build.sh
```

Copy kết quả vào thư mục này (xem `xcframeworks/README.md`).

## Dùng trong Xcode / project khác

1. *File → Add Package Dependencies…*
2. Chọn *Add Local…* và trỏ tới thư mục `sigma-drm-ios-spm`, hoặc dùng URL Git sau khi push.

Thêm product **SigmaDRM** vào app target.

## Lưu ý tích hợp (giống dùng static lib trực tiếp)

- App **Objective‑C / mixed** thường cần **`Other Linker Flags: -ObjC`** (và các framework hệ thống như `AVFoundation` nếu chưa có) vì binary là static archive trong XCFramework.
- Header công khai của slice nằm trong XCFramework; nếu cần thêm API Swift bọc ObjC, bổ sung trong `Sources/SigmaDRM/`.

## Đổi tên / nhiều biến thể

- Đổi đường dẫn XCFramework: sửa `path:` của target `SigmaDRMNative` trong `Package.swift`.
- Đổi tên product hoặc target Swift: giữ đồng bộ `products` và `targets`.
