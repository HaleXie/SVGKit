#import "SVGCDStyleSheetList.h"
#import "SVGCDStyleSheetList+Mutable.h"

@implementation SVGCDStyleSheetList

@synthesize internalArray;

- (id)init
{
    self = [super init];
    if (self) {
        self.internalArray = [NSMutableArray array];
    }
    return self;
}


-(unsigned long)length
{
	return self.internalArray.count;
}

-(SVGCDStyleSheet*) item:(unsigned long) index
{
	return [self.internalArray objectAtIndex:index];
}

@end
