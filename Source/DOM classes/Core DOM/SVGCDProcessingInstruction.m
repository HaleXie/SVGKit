//
//  ProcessingInstruction.m
//  SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SVGCDProcessingInstruction.h"

@interface SVGCDProcessingInstruction()
@property(nonatomic,strong,readwrite) NSString* target;
@property(nonatomic,strong,readwrite) NSString* data;
@end

@implementation SVGCDProcessingInstruction

@synthesize target;
@synthesize data;

-(id) initProcessingInstruction:(NSString*) t value:(NSString*) d
{
    self = [super initType:SVGCD_DOMNodeType_PROCESSING_INSTRUCTION_NODE name:t value:d];
    if (self) {
		self.target = t;
		self.data = d;
    }
    return self;
}

@end
