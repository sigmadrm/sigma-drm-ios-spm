// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SigmaDrmFramework",
    platforms: [.iOS(.v12)],
    products: [
        // Chỉ ship binary — tránh target Swift trùng tên module `SigmaDrmFramework`
        // (khiến `import SigmaDrmFramework` không thấy class ObjC `SigmaDRM`).
        .library(
            name: "SigmaDrmFramework",
            targets: ["SigmaDrmFrameworkBinary"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDrmFrameworkBinary",
            path: "xcframeworks/SigmaDrmFramework.xcframework"
        ),
    ]
)
