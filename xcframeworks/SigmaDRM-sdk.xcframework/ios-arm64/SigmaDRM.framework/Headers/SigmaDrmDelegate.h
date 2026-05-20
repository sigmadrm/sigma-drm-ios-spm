//
//  SigmaDrmDelegate.h
//  AVARLDelegateDemo
//
//  Created by NguyenVanSao on 12/20/17.
//  Copyright © 2017 rajiv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVAssetResourceLoader.h>
#import <AVFoundation/AVAsset.h>

@interface SigmaDrmDelegate : NSObject <AVAssetResourceLoaderDelegate>
+(AVURLAsset *)assetFromUrl:(NSString *)url;
- (void) cleanupDrmResources;

@end
