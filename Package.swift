// swift-tools-version:5.3
// Swift Package bọc XCFramework static SigmaDRM (tạo từ player-drm-ios / SigmaDRM_iOS/build.sh).

import PackageDescription

let package = Package(
    name: "SigmaDRM",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "SigmaDRM",
            targets: ["SigmaDRM", "SigmaDRMNative"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDRMNative",
            path: "xcframeworks/SigmaDRM-sdk.xcframework"
        ),
        .target(
            name: "SigmaDRM"
        ),
    ]
)
