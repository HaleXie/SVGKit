/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSValueList
 
 interface CSSValueList : CSSValue {
 readonly attribute unsigned long    length;
 CSSValue           item(in unsigned long index);
 */

#import "SVGCDCSSValue.h"

@interface SVGCDCSSValueList : SVGCDCSSValue

@property(nonatomic,readonly) unsigned long length;

-(SVGCDCSSValue*) item:(unsigned long) index;

@end
