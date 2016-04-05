//
//  ARTRealtimePresence.h
//  ably
//
//  Created by Ricardo Pereira on 12/11/15.
//  Copyright © 2015 Ably. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ARTRestPresence.h"
#import "ARTDataQuery.h"
#import "ARTEventEmitter.h"

@class ARTRealtimeChannel;

ART_ASSUME_NONNULL_BEGIN

@interface ARTRealtimePresenceQuery : ARTPresenceQuery

@property (readwrite, nonatomic) BOOL waitForSync;

@end

@interface ARTRealtimePresence : ARTRestPresence

@property (readonly, getter=getSyncComplete) BOOL syncComplete;

- (instancetype)initWithChannel:(ARTRealtimeChannel *)channel;

- (void)get:(void (^)(__GENERIC(NSArray, ARTPresenceMessage *) *__art_nullable result, ARTErrorInfo *__art_nullable error))callback;
- (void)get:(ARTRealtimePresenceQuery *)query callback:(void (^)(__GENERIC(NSArray, ARTPresenceMessage *) *__art_nullable result, ARTErrorInfo *__art_nullable error))callback;

- (void)enter:(id __art_nullable)data;
- (void)enter:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (void)update:(id __art_nullable)data;
- (void)update:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (void)leave:(id __art_nullable)data;
- (void)leave:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (void)enterClient:(NSString *)clientId data:(id __art_nullable)data;
- (void)enterClient:(NSString *)clientId data:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (void)updateClient:(NSString *)clientId data:(id __art_nullable)data;
- (void)updateClient:(NSString *)clientId data:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (void)leaveClient:(NSString *)clientId data:(id __art_nullable)data;
- (void)leaveClient:(NSString *)clientId data:(id __art_nullable)data callback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))cb;

- (__GENERIC(ARTEventListener, ARTPresenceMessage *) *__art_nullable)subscribe:(void (^)(ARTPresenceMessage *message))callback;
- (__GENERIC(ARTEventListener, ARTPresenceMessage *) *__art_nullable)subscribeWithAttachCallback:(art_nullable void (^)(ARTErrorInfo *__art_nullable))onAttach callback:(void (^)(ARTPresenceMessage *message))cb;
- (__GENERIC(ARTEventListener, ARTPresenceMessage *) *__art_nullable)subscribe:(ARTPresenceAction)action callback:(void (^)(ARTPresenceMessage *message))cb;
- (__GENERIC(ARTEventListener, ARTPresenceMessage *) *__art_nullable)subscribe:(ARTPresenceAction)action onAttach:(art_nullable void (^)(ARTErrorInfo *__art_nullable))onAttach callback:(void (^)(ARTPresenceMessage *message))cb;

- (void)unsubscribe;
- (void)unsubscribe:(__GENERIC(ARTEventListener, ARTPresenceMessage *) *)listener;
- (void)unsubscribe:(ARTPresenceAction)action listener:(__GENERIC(ARTEventListener, ARTPresenceMessage *) *)listener;

- (void)history:(void(^)(__GENERIC(ARTPaginatedResult, ARTPresenceMessage *) *__art_nullable result, ARTErrorInfo *__art_nullable error))callback;
- (BOOL)history:(art_nullable ARTRealtimeHistoryQuery *)query callback:(void(^)(__GENERIC(ARTPaginatedResult, ARTPresenceMessage *) *__art_nullable result, ARTErrorInfo *__art_nullable error))callback error:(NSError *__art_nullable *__art_nullable)errorPtr;

@end

ART_ASSUME_NONNULL_END
