/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSStyleRule
 
 interface CSSStyleRule : CSSRule {
 attribute DOMString        selectorText;
 // raises(DOMException) on setting
 
 readonly attribute CSSStyleDeclaration  style;
 */
#import <Foundation/Foundation.h>

#import "SVGCDCSSRule.h"
#import "SVGCDCSSStyleDeclaration.h"

@interface SVGCDCSSStyleRule : SVGCDCSSRule

@property(nonatomic,strong) NSString* selectorText;
@property(nonatomic,strong) SVGCDCSSStyleDeclaration* style;

#pragma mark - methods needed for ObjectiveC implementation

- (id)initWithSelectorText:(NSString*) selector styleText:(NSString*) styleText;

@end
