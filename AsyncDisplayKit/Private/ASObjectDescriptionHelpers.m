//
//  ASObjectDescriptions.m
//  AsyncDisplayKit
//
//  Created by Adlai Holler on 9/7/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#import "ASObjectDescriptionHelpers.h"

NSString *ASObjectDescriptionMake(id object, NSArray<NSDictionary *> *propertyGroups) {
  NSMutableString *str = [NSMutableString stringWithFormat:@"<%@: %p; ", [object class], object];

  NSMutableArray *components = [NSMutableArray array];
  for (NSDictionary *properties in propertyGroups) {
    [properties enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
      [components addObject:[NSString stringWithFormat:@"%@ = %@", key, obj]];
    }];
  }
  [str appendString:[components componentsJoinedByString:@"; "]];
  [str appendString:@">"];
  return str;
}

NSString *ASObjectGetTinyDescription(id object) {
  return [NSString stringWithFormat:@"<%@: %p>", [object class], object];
}

NSString *ASStringWithQuotesIfMultiword(NSString *baseString) {
  if (baseString == nil) {
    return @"(null)";
  }

  if ([baseString rangeOfCharacterFromSet:[NSCharacterSet whitespaceCharacterSet]].location != NSNotFound) {
    return [NSString stringWithFormat:@"\"%@\"", baseString];
  } else {
    return baseString;
  }
}

// e.g. (0 0; 50 50)
NSString *ASCGRectGetTinyDescription(CGRect rect) {
  return [NSString stringWithFormat:@"(%f %f; %f %f)", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];
}
