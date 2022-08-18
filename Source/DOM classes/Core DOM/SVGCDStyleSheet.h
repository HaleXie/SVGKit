/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/stylesheets.html#StyleSheets-StyleSheet
 
 interface StyleSheet {
 readonly attribute DOMString        type;
 attribute boolean          disabled;
 readonly attribute Node             ownerNode;
 readonly attribute StyleSheet       parentStyleSheet;
 readonly attribute DOMString        href;
 readonly attribute DOMString        title;
 readonly attribute MediaList        media;
 */

#import <Foundation/Foundation.h>

@class SVGCDNode;
@class SVGCDMediaList;

@interface SVGCDStyleSheet : NSObject

@property(nonatomic,strong) NSString* type;
@property(nonatomic) BOOL disabled;
@property(nonatomic,strong) SVGCDNode* ownerNode;
@property(nonatomic,strong) SVGCDStyleSheet* parentStyleSheet;
@property(nonatomic,strong) NSString* href;
@property(nonatomic,strong) NSString* title;
@property(nonatomic,strong) SVGCDMediaList* media;

@end
