// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SigmaDrmSpm",
    platforms: [.iOS(.v9), .tvOS(.v9)],
    products: [
        .library(
            name: "SigmaDrmSpm",
            targets: ["SigmaDRM", "SigmaDrmFramework"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "SigmaDrmFramework",
            path: "xcframeworks/SigmaDRM.xcframework"
        ),
        .target(
            name: "SigmaDRM"
        ),
    ]
)