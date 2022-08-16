/**
 Makes the writable properties all package-private, effectively
 */
#import "SVGCDNode.h"

@interface SVGCDNode()
@property(nonatomic,strong,readwrite) NSString* nodeName;
@property(nonatomic,strong,readwrite) NSString* nodeValue;

@property(nonatomic,readwrite) SVGCDDOMNodeType nodeType;
@property(nonatomic,weak,readwrite) SVGCDNode* parentNode;
@property(nonatomic,strong,readwrite) SVGCDNodeList* childNodes;
@property(nonatomic,strong,readwrite) SVGCDNamedNodeMap* attributes;

@property(nonatomic,weak,readwrite) SVGCDDocument* ownerDocument;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* namespaceURI;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* prefix;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* localName;

@end
