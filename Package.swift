// swift-tools-version:5.3
// Swift Package bọc XCFramework static SigmaDRM (tạo từ player-drm-ios / SigmaDRM_iOS/build.sh).
// Target Swift phải tên khác 'SigmaDRM' để không trùng sigma-multidrm-spm trong cùng package graph.

import PackageDescription

let package = Package(
    name: "SigmaDRMIOS",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "SigmaDRM",
            targets: ["SigmaDRMIOSKit", "SigmaDRMNative"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDRMNative",
            path: "xcframeworks/SigmaDRM-sdk.xcframework"
        ),
        .target(
            name: "SigmaDRMIOSKit"
        ),
    ]
)
