//
//  ASObjectDescriptions.h
//  AsyncDisplayKit
//
//  Created by Adlai Holler on 9/7/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AsyncDisplayKit/ASBaseDefines.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Your base class should conform to this and override `-debugDescription`
 * to call `[self propertiesForDebugDescription]` and use `ASObjectDescriptionMake`
 * to return a string. Subclasses of this base class just need to override
 * `propertiesForDebugDescription`, call super, and modify the result as needed.
 */
@protocol ASDebugDescriptionProvider
@required
- (NSMutableArray<NSMutableDictionary *> *)propertiesForDebugDescription;
@end

/**
 * Your base class should conform to this and override `-description`
 * to call `[self propertiesForDescription]` and use `ASObjectDescriptionMake`
 * to return a string. Subclasses of this base class just need to override
 * `propertiesForDescription`, call super, and modify the result as needed.
 */
@protocol ASDescriptionProvider
@required
- (NSMutableArray<NSMutableDictionary *> *)propertiesForDescription;
@end

ASDISPLAYNODE_EXTERN_C_BEGIN

/// Like ASObjectDescriptionMake except you can specify multiple dictionaries to control the order of properties.
NSString *ASObjectDescriptionMake(id object, NSArray<NSDictionary *> *propertyGroups);

NSString *ASObjectGetTinyDescription(id object);

NSString *ASStringWithQuotesIfMultiword(NSString * _Nullable baseString);

// e.g. (0 0; 50 50). This matches UIKit's rect description format
NSString *ASCGRectGetTinyDescription(CGRect rect);

ASDISPLAYNODE_EXTERN_C_END

NS_ASSUME_NONNULL_END
