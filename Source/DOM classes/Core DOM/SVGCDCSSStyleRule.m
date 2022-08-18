
#import "SVGCDCSSStyleRule.h"

@implementation SVGCDCSSStyleRule

@synthesize selectorText;
@synthesize style;


- (id)init
{
	NSAssert(FALSE, @"Can't be init'd, use the right method, idiot");
	return nil;
}

#pragma mark - methods needed for ObjectiveC implementation

- (id)initWithSelectorText:(NSString*) selector styleText:(NSString*) styleText;
{
    self = [super init];
    if (self) {
        self.selectorText = selector;
		
		SVGCDCSSStyleDeclaration* styleDeclaration = [[SVGCDCSSStyleDeclaration alloc] init];
		styleDeclaration.cssText = styleText;
		
		self.style = styleDeclaration;
    }
    return self;
}

-(NSString *)description
{
	return [NSString stringWithFormat:@"%@ : { %@ }", self.selectorText, self.style ];
}

@end
