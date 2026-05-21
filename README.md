# sigma-drm-ios-spm

Swift Package phân phối **SigmaDRM** cho iOS (iOS 12+).

## Thêm vào app

1. Xcode → **File → Add Package Dependencies…**
2. Chọn **Add Local…** (hoặc URL Git của repo này).
3. Thêm product **`SigmaDrmFramework`** vào app target.

## Dùng trong code

**Swift:**

```swift
import SigmaDrmFramework
```

**Objective‑C:**

```objc
@import SigmaDrmFramework;
```

API chính nằm trong header `SigmaDRM` (class `SigmaDRM`, delegate, …).

## Cấu hình app

Trong **Build Settings** của app target:

- **Other Linker Flags:** thêm `-ObjC`
- **Linked Frameworks:** đảm bảo có `Foundation`, `AVFoundation` (và các framework app bạn đã dùng khi tích hợp SigmaDRM trước đây)

## Lưu ý

- Package ship **binary** — không cần build source SigmaDRM trong app.
- Hiện chỉ hỗ trợ **thiết bị iOS thật (arm64)**. Build trên **Simulator** có thể không được nếu XCFramework chưa có slice simulator.
