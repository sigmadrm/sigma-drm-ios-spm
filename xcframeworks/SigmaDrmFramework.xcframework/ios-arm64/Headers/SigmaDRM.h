//
//  SigmaDRM.h
//  SigmaDRM
//
//  Created by NguyenVanSao on 12/21/17.
//  Copyright © 2017 NguyenVanSao. All rights reserved.
//

#import <AVFoundation/AVAsset.h>
#import <AVFoundation/AVAssetResourceLoader.h>
#import <Foundation/Foundation.h>

/**
 * Block cho phép tùy chỉnh việc nhận diện request lấy key AES-128.
 */
typedef BOOL (^SigmaKeyRequestFilter)(NSURL *_Nonnull url);
    /**
     * Phương thức mã hoá nội dung được SigmaDRM hỗ trợ.
     * - SigmaEncryptionMethodNone: nội dung không mã hoá, không gắn resource
     * loader delegate.
     * - SigmaEncryptionMethodAES_128: HLS AES-128 chuẩn, AVPlayer tự xử lý key,
     * không cần delegate của Sigma.
     * - SigmaEncryptionMethodSigma: mã hoá theo chuẩn Sigma DRM (mặc định), sử
     * dụng SigmaDrmDelegate.
     */
    typedef NS_ENUM(NSInteger, SigmaEncryptionMethod) {
      SigmaEncryptionMethodNone = 0,
      SigmaEncryptionMethodAES_128 = 1,
      SigmaEncryptionMethodSigma = 2,
    };

@protocol SigmaDRMDelegate <NSObject>
@optional
- (void)onSigmaStatus:(NSInteger)status;
- (void)onSigmaData:(NSDictionary *_Nullable)info;
- (void)onProgressLoad:(NSString *_Nullable)progressName status:(NSString *_Nullable)error;
@end
@interface SigmaDRM : NSObject

#pragma mark - Core
@property(nonatomic, weak) id<SigmaDRMDelegate> delegate;
+ (SigmaDRM *_Nullable)getInstance;
- (AVURLAsset *_Nullable)assetWithUrl:(NSString *_Nullable)url;
- (AVURLAsset *_Nullable)assset;

#pragma mark - Encryption Control
/**
 * Thiết lập phương thức mã hoá cho phiên phát hiện tại.
 */
- (void)setEncryptionMethod:(SigmaEncryptionMethod)method;
- (SigmaEncryptionMethod)encryptionMethod;
- (BOOL)isEncryptionMethodSupported:(SigmaEncryptionMethod)method;

#pragma mark - 1. AES-128 Configuration (Standard HLS)
/** Custom filter để nhận diện key request cho AES-128 */
@property(nonatomic, copy, nullable) SigmaKeyRequestFilter keyRequestFilter;
/** Custom headers gửi kèm khi lấy key AES-128 */
@property(nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *keyRequestHeaders;

#pragma mark - 2. Sigma DRM Configuration (Proprietary)
@property(nonatomic, copy, nullable) NSString *appId;
@property(nonatomic, copy, nullable) NSString *merchantId;
@property(nonatomic, copy, nullable) NSString *authToken;
@property(nonatomic, copy, nullable) NSString *userId;
@property(nonatomic, copy, nullable) NSString *sessionId;
@property(nonatomic, strong, nullable) NSArray *drmList;

/** Chỉ dành riêng cho Sigma DRM */
- (NSMutableDictionary *_Nullable) getCustomData;

#pragma mark - Utilities
- (void)destroy;
- (void)logging:(NSString *_Nullable)progress
         status:(NSString *_Nullable)status;

@end
