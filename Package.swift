// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "NielsenAppApi",
    products: [
        .library(
            name: "NielsenAppApi",
            targets: ["NielsenAppApi"])
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(name: "NielsenAppApi", path: "products/NielsenAppApi.xcframework")
    ]
)
