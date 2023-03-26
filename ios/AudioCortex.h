#ifdef __cplusplus
#import "react-native-audio-cortex.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNAudioCortexSpec.h"

@interface AudioCortex : NSObject <NativeAudioCortexSpec>
#else
#import <React/RCTBridgeModule.h>

@interface AudioCortex : NSObject <RCTBridgeModule>
#endif

@end
