// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SigmaDrmFramework",
    version: "2.1.0",
    platforms: [.iOS(.v12)],
    products: [
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
