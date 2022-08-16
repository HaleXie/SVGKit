/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-DocumentCSS
 
 interface DocumentCSS : stylesheets::DocumentStyle {
 CSSStyleDeclaration getOverrideStyle(in Element elt,
 in DOMString pseudoElt);
 */
#import <Foundation/Foundation.h>
#import "SVGCDDocumentStyle.h"

#import "SVGCDCSSStyleDeclaration.h"

@class SVGCDElement;

@protocol SVGCDDocumentCSS <SVGCDDocumentStyle>

-(SVGCDCSSStyleDeclaration *)getOverrideStyle:(SVGCDElement *)element pseudoElt:(NSString *)pseudoElt;

@end
