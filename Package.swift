// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SigmaDrmSPM",
    platforms: [.iOS(.v10)],
    products: [
        .library(
            name: "SigmaDrmFramework",
            targets: ["SigmaDummy", "SigmaDrmBinaryFramework"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDrmBinaryFramework",
            path: "xcframeworks/SigmaDRM.xcframework"
        ),
        .target(
            name: "SigmaDummy"
        ),
    ]
)