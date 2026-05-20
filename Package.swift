// swift-tools-version:5.10

import PackageDescription

let package = Package(
    name: "SigmaDRMIOSKit",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "SigmaDRMIOSKit",
            targets: ["SigmaDRMIOSKit"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "SigmaDRMIOSKit",
            path: "SigmaDRMIOSKit.xcframework"
        )
    ]
)