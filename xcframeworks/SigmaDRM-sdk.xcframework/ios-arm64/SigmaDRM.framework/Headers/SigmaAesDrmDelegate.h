//
//  SigmaAesDrmDelegate.h
//  SigmaDRM
//
//  Resource loader delegate cho HLS AES-128 chuẩn.
//  Tương đương ResolvingDataSource của Android ExoPlayer:
//    - Chặn playlist request → fetch manifest → rewrite key URI (http →
//    akey://)
//    - Chặn key request → fetch key bytes + "Authorization: Bearer <token>"
//    header
//    - AVPlayer tự giải mã AES-128 segment sau khi nhận key bytes (tương đương
//    JCE software decryption)
//
//  KHÔNG sử dụng DRM SDK C++ (SmDrm, DrmSession, v.v.)
//  KHÔNG gọi SigmaDRMDelegate (public protocol) — luồng này không cần callback
//  ra ngoài.
//

#import <AVFoundation/AVAsset.h>
#import <AVFoundation/AVAssetResourceLoader.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SigmaAesDrmDelegate : NSObject <AVAssetResourceLoaderDelegate>

/// Block tùy chỉnh để nhận diện key request.
@property(nonatomic, copy, nullable) BOOL (^keyRequestFilter)(NSURL *url);

/// Danh sách headers tùy chỉnh cho key request.
@property(nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *keyRequestHeaders;

/// Tạo AVURLAsset với scheme đã rewrite cho AES-128:
+ (AVURLAsset *)assetFromUrl:(NSString *)url;

/// Huỷ các network task đang chạy. Gọi trước khi dừng phát hoặc chuyển nội
/// dung.
- (void)cleanupResources;

@end

NS_ASSUME_NONNULL_END
