// swift-tools-version:5.10

import PackageDescription

let package = Package(
    name: "SigmaDrmFramework",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "SigmaDrmFramework",
            targets: ["SigmaDrmFramework"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "SigmaDrmFramework",
            path: "SigmaDrmFramework.xcframework"
        )
    ]
)