/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSPrimitiveValue
 
 interface CSSPrimitiveValue : CSSValue {
 
 // UnitTypes
 const unsigned short      CSS_UNKNOWN                    = 0;
 const unsigned short      CSS_NUMBER                     = 1;
 const unsigned short      CSS_PERCENTAGE                 = 2;
 const unsigned short      CSS_EMS                        = 3;
 const unsigned short      CSS_EXS                        = 4;
 const unsigned short      CSS_PX                         = 5;
 const unsigned short      CSS_CM                         = 6;
 const unsigned short      CSS_MM                         = 7;
 const unsigned short      CSS_IN                         = 8;
 const unsigned short      CSS_PT                         = 9;
 const unsigned short      CSS_PC                         = 10;
 const unsigned short      CSS_DEG                        = 11;
 const unsigned short      CSS_RAD                        = 12;
 const unsigned short      CSS_GRAD                       = 13;
 const unsigned short      CSS_MS                         = 14;
 const unsigned short      CSS_S                          = 15;
 const unsigned short      CSS_HZ                         = 16;
 const unsigned short      CSS_KHZ                        = 17;
 const unsigned short      CSS_DIMENSION                  = 18;
 const unsigned short      CSS_STRING                     = 19;
 const unsigned short      CSS_URI                        = 20;
 const unsigned short      CSS_IDENT                      = 21;
 const unsigned short      CSS_ATTR                       = 22;
 const unsigned short      CSS_COUNTER                    = 23;
 const unsigned short      CSS_RECT                       = 24;
 const unsigned short      CSS_RGBCOLOR                   = 25;
 
 readonly attribute unsigned short   primitiveType;
 void               setFloatValue(in unsigned short unitType,
 in float floatValue)
 raises(DOMException);
 float              getFloatValue(in unsigned short unitType)
 raises(DOMException);
 void               setStringValue(in unsigned short stringType,
 in DOMString stringValue)
 raises(DOMException);
 DOMString          getStringValue()
 raises(DOMException);
 Counter            getCounterValue()
 raises(DOMException);
 Rect               getRectValue()
 raises(DOMException);
 RGBColor           getRGBColorValue()
 raises(DOMException);
 */
#import "SVGCDCSSValue.h"

typedef enum CSSPrimitiveType
{
	SVGCD_CSS_UNKNOWN                    = 0,
    SVGCD_CSS_NUMBER                     = 1,
	SVGCD_CSS_PERCENTAGE                 = 2,
	SVGCD_CSS_EMS                        = 3,
	SVGCD_CSS_EXS                        = 4,
	SVGCD_CSS_PX                         = 5,
	SVGCD_CSS_CM                         = 6,
	SVGCD_CSS_MM                         = 7,
	SVGCD_CSS_IN                         = 8,
	SVGCD_CSS_PT                         = 9,
	SVGCD_CSS_PC                         = 10,
	SVGCD_CSS_DEG                        = 11,
	SVGCD_CSS_RAD                        = 12,
	SVGCD_CSS_GRAD                       = 13,
	SVGCD_CSS_MS                         = 14,
	SVGCD_CSS_S                          = 15,
	SVGCD_CSS_HZ                         = 16,
	SVGCD_CSS_KHZ                        = 17,
	SVGCD_CSS_DIMENSION                  = 18,
	SVGCD_CSS_STRING                     = 19,
	SVGCD_CSS_URI                        = 20,
	SVGCD_CSS_IDENT                      = 21,
	SVGCD_CSS_ATTR                       = 22,
	SVGCD_CSS_COUNTER                    = 23,
	SVGCD_CSS_RECT                       = 24,
	SVGCD_CSS_RGBCOLOR                   = 25
} SVGCDCSSPrimitiveType;

@interface SVGCDCSSPrimitiveValue : SVGCDCSSValue

@property(nonatomic) SVGCDCSSPrimitiveType primitiveType;

-(void) setFloatValue:(SVGCDCSSPrimitiveType) unitType floatValue:(float) floatValue;

-(float) getFloatValue:(SVGCDCSSPrimitiveType) unitType;

-(void) setStringValue:(SVGCDCSSPrimitiveType) stringType stringValue:(NSString*) stringValue;

-(NSString*) getStringValue;

-(/* FIXME: have to add this type: Counter*/ void) getCounterValue;

-(/* FIXME: have to add this type: Rect*/ void) getRectValue;

-(/* FIXME: have to add this type: RGBColor*/ void) getRGBColorValue;

@end
