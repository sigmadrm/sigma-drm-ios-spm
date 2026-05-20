# XCFramework

Đặt file gói từ `player-drm-ios` tại đây, **đúng tên** mà `Package.swift` tham chiếu:

- `SigmaDRM-sdk.xcframework` — mặc định do `SigmaDRM_iOS/build.sh` sinh ra (`OUTPUT` mặc định: `xcframeworks/SigmaDRM-sdk.xcframework`).

Sao chép ví dụ:

```bash
cp -R /path/to/player-drm-ios/SigmaDRM_iOS/xcframeworks/SigmaDRM-sdk.xcframework \
  /path/to/sigma-drm-ios-spm/xcframeworks/
```

Sau đó trong repo SPM:

```bash
swift package describe
```

Nếu đổi tên file `.xcframework`, cập nhật `path:` trong `Package.swift` (target `SigmaDRMNative`).
