//
//  NSDate+ARTUtil.m
//  ably-ios
//
//  Created by Jason Choy on 09/12/2014.
//  Copyright (c) 2014 Ably. All rights reserved.
//

#import "ARTNSDate+ARTUtil.h"

@implementation NSDate (ARTUtil)

+ (instancetype)artDateFromIntegerMs:(NSInteger)ms {
    NSTimeInterval intervalSince1970 = ms / 1000.0;
    return [NSDate dateWithTimeIntervalSince1970:intervalSince1970];
}

+ (instancetype)artDateFromNumberMs:(NSNumber *)number {
    return [self artDateFromIntegerMs:[number integerValue]];
}

- (NSNumber *)artToNumberMs {
    return [NSNumber numberWithInteger:[self artToIntegerMs]];
}

- (NSInteger)artToIntegerMs {
    return (NSInteger)round([self timeIntervalSince1970] * 1000.0);
}

@end
