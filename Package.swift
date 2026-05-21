// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SigmaDrmFramework",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "SigmaDrmFramework",
            targets: ["SigmaDrmFramework"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDrmFramework",
            path: "xcframeworks/SigmaDrmFramework.xcframework"
        ),
        .target(
            name: "SigmaDrmFramework"
        ),
    ]
)
