/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSStyleSheet
 
 interface CSSStyleSheet : stylesheets::StyleSheet {
 readonly attribute CSSRule          ownerRule;
 readonly attribute CSSRuleList      cssRules;
 unsigned long      insertRule(in DOMString rule,
 in unsigned long index)
 raises(DOMException);
 void               deleteRule(in unsigned long index)
 raises(DOMException);
 */
#import <Foundation/Foundation.h>

#import "SVGCDCSSRule.h"
#import "SVGCDCSSRuleList.h"

@interface SVGCDCSSStyleSheet : NSObject


@property(nonatomic,strong) SVGCDCSSRule* ownerRule;
@property(nonatomic,strong) SVGCDCSSRuleList* cssRules;

-(long) insertRule:(NSString*) rule index:(unsigned long) index;
-(void) deleteRule:(unsigned long) index;

#pragma mark - methods needed for ObjectiveC implementation

- (id)initWithString:(NSString*) styleSheetBody;

@end
