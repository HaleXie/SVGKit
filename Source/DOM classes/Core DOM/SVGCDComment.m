//
//  Comment.m
//  SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SVGCDComment.h"

@implementation SVGCDComment

- (id)initWithValue:(NSString*) v
{
    self = [super initType:SVGCD_DOMNodeType_COMMENT_NODE name:@"#comment" value:v];
    if (self) {
    }
    return self;
}

@end