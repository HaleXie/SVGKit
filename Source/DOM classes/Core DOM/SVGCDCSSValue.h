/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSValue
 
 interface CSSValue {
 
 // UnitTypes
 const unsigned short      CSS_INHERIT                    = 0;
 const unsigned short      CSS_PRIMITIVE_VALUE            = 1;
 const unsigned short      CSS_VALUE_LIST                 = 2;
 const unsigned short      CSS_CUSTOM                     = 3;
 
 attribute DOMString        cssText;
 // raises(DOMException) on setting
 
 readonly attribute unsigned short   cssValueType;
 */
#import <Foundation/Foundation.h>

typedef enum SVGCDCSSUnitType
{
	SVGCD_CSS_INHERIT                    = 0,
	SVGCD_CSS_PRIMITIVE_VALUE            = 1,
	SVGCD_CSS_VALUE_LIST                 = 2,
	SVGCD_CSS_CUSTOM                     = 3
} SVGCDCSSUnitType;

@interface SVGCDCSSValue : NSObject
{
	NSString* _cssText; // for subclasses to manually set
}

@property(nonatomic,strong) NSString* cssText;
@property(nonatomic) SVGCDCSSUnitType cssValueType;

@end
