/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-412266927
 
 interface DocumentType : Node {
 readonly attribute DOMString        name;
 readonly attribute NamedNodeMap     entities;
 readonly attribute NamedNodeMap     notations;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        publicId;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        systemId;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        internalSubset;
 };
*/
#import <Foundation/Foundation.h>

#import "SVGCDNode.h"
#import "SVGCDNamedNodeMap.h"

@interface SVGCDDocumentType : SVGCDNode

@property(nonatomic,strong,readonly) NSString* name;
@property(nonatomic,strong,readonly) SVGCDNamedNodeMap* entities;
@property(nonatomic,strong,readonly) SVGCDNamedNodeMap* notations;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* publicId;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* systemId;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* internalSubset;


@end
