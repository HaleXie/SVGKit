#import "SVGCDCSSValueList.h"
#import "SVGCDCSSValue_ForSubclasses.h"
#import "SVGKDefine_Private.h"

@interface SVGCDCSSValueList()

@property(nonatomic,strong) NSArray* internalArray;

@end

@implementation SVGCDCSSValueList

@synthesize internalArray;


- (id)init
{
    self = [super initWithUnitType:SVGCD_CSS_VALUE_LIST];
    if (self) {
        self.internalArray = [NSArray array];
    }
    return self;
}

-(unsigned long)length
{
	return self.internalArray.count;
}

-(SVGCDCSSValue*) item:(unsigned long) index
{
	return [self.internalArray objectAtIndex:index];
}

#pragma mark - non DOM spec methods needed to implement Objective-C code for this class

-(void)setCssText:(NSString *)newCssText
{
	_cssText = newCssText;
	
	/** the css text value has been set, so we need to split the elements up and save them in the internal array */
	SVGKitLogVerbose(@"[%@] received new CSS Text, need to split this and save as CSSValue instances: %@", [self class], _cssText);
	
	self.internalArray = [_cssText componentsSeparatedByString:@" "];
}

@end
