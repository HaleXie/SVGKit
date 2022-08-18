/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSRuleList
 
 interface CSSRuleList {
 readonly attribute unsigned long    length;
 CSSRule            item(in unsigned long index);
 */
#import <Foundation/Foundation.h>

#import "SVGCDCSSRule.h"

@interface SVGCDCSSRuleList : NSObject

@property(nonatomic,readonly) unsigned long length;

-(SVGCDCSSRule*) item:(unsigned long) index;

@end
