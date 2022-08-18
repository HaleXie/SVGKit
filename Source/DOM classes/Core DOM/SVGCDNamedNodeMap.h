/*
 From SVG-DOM, via Core-DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1780488922
 
 interface NamedNodeMap {
 Node               getNamedItem(in DOMString name);
 Node               setNamedItem(in Node arg)
 raises(DOMException);
 Node               removeNamedItem(in DOMString name)
 raises(DOMException);
 Node               item(in unsigned long index);
 readonly attribute unsigned long    length;
 // Introduced in DOM Level 2:
 Node               getNamedItemNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 Node               setNamedItemNS(in Node arg)
 raises(DOMException);
 // Introduced in DOM Level 2:
 Node               removeNamedItemNS(in DOMString namespaceURI, 
 in DOMString localName)
 raises(DOMException);
 };

 */

#import <Foundation/Foundation.h>

@class SVGCDNode;
#import "SVGCDNode.h"

@interface SVGCDNamedNodeMap : NSObject </** needed so we can output SVG text in the [Node appendToXML:..] methods */ NSCopying>

-(SVGCDNode*) getNamedItem:(NSString*) name;
-(SVGCDNode*) setNamedItem:(SVGCDNode*) arg;
-(SVGCDNode*) removeNamedItem:(NSString*) name;
-(SVGCDNode*) item:(unsigned long) index;

@property(readonly) unsigned long length;

// Introduced in DOM Level 2:
-(SVGCDNode*) getNamedItemNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(SVGCDNode*) setNamedItemNS:(SVGCDNode*) arg;

// Introduced in DOM Level 2:
-(SVGCDNode*) removeNamedItemNS:(NSString*) namespaceURI localName:(NSString*) localName;

#pragma mark - MISSING METHOD FROM SVG Spec, without which you cannot parse documents (don't understand how they intended you to fulfil the spec without this method)

-(SVGCDNode*) setNamedItemNS:(SVGCDNode*) arg inNodeNamespace:(NSString*) nodesNamespace;

@end
