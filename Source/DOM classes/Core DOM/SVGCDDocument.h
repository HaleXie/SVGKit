/*
//  Document.h

 NOT a Cocoa / Apple document,
 NOT an SVG document,
 BUT INSTEAD: a DOM document (blame w3.org for the too-generic name).
 
 Required for SVG-DOM
 
 c.f.:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#i-Document
 
 interface Document : Node {
 readonly attribute DocumentType     doctype;
 readonly attribute DOMImplementation  implementation;
 readonly attribute Element          documentElement;
 Element            createElement(in DOMString tagName)
 raises(DOMException);
 DocumentFragment   createDocumentFragment();
 Text               createTextNode(in DOMString data);
 Comment            createComment(in DOMString data);
 CDATASection       createCDATASection(in DOMString data)
 raises(DOMException);
 ProcessingInstruction createProcessingInstruction(in DOMString target, 
 in DOMString data)
 raises(DOMException);
 Attr               createAttribute(in DOMString name)
 raises(DOMException);
 EntityReference    createEntityReference(in DOMString name)
 raises(DOMException);
 NodeList           getElementsByTagName(in DOMString tagname);
 // Introduced in DOM Level 2:
 Node               importNode(in Node importedNode, 
 in boolean deep)
 raises(DOMException);
 // Introduced in DOM Level 2:
 Element            createElementNS(in DOMString namespaceURI, 
 in DOMString qualifiedName)
 raises(DOMException);
 // Introduced in DOM Level 2:
 Attr               createAttributeNS(in DOMString namespaceURI, 
 in DOMString qualifiedName)
 raises(DOMException);
 // Introduced in DOM Level 2:
 NodeList           getElementsByTagNameNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 Element            getElementById(in DOMString elementId);
 };

 
 */

#import <Foundation/Foundation.h>

/** ObjectiveC won't allow this: @class Node; */
#import "SVGCDNode.h"
@class SVGCDElement;
#import "SVGCDElement.h"
//@class Comment;
#import "SVGCDComment.h"
@class SVGCDCDATASection;
#import "SVGCDCDATASection.h"
@class SVGCDDocumentFragment;
#import "SVGCDDocumentFragment.h"
@class SVGCDEntityReference;
#import "SVGCDEntityReference.h"
@class SVGCDNodeList;
#import "SVGCDNodeList.h"
@class SVGCDProcessingInstruction;
#import "SVGCDProcessingInstruction.h"
@class SVGCDDocumentType;
#import "SVGCDDocumentType.h"
@class SVGCDDOMImplementation;
#import "SVGCDDOMImplementation.h"

@interface SVGCDDocument : SVGCDNode

@property(nonatomic,strong,readonly) SVGCDDocumentType*     doctype;
@property(nonatomic,strong,readonly) SVGCDDOMImplementation*  implementation;
@property(nonatomic,strong,readonly) SVGCDElement*          documentElement;


-(SVGCDElement*) createElement:(NSString*) tagName __attribute__((ns_returns_retained));
-(SVGCDDocumentFragment*) createDocumentFragment __attribute__((ns_returns_retained));
-(SVGCDText*) createTextNode:(NSString*) data __attribute__((ns_returns_retained));
-(SVGCDComment*) createComment:(NSString*) data __attribute__((ns_returns_retained));
-(SVGCDCDATASection*) createCDATASection:(NSString*) data __attribute__((ns_returns_retained));
-(SVGCDProcessingInstruction*) createProcessingInstruction:(NSString*) target data:(NSString*) data __attribute__((ns_returns_retained));
-(SVGCDAttr*) createAttribute:(NSString*) data __attribute__((ns_returns_retained));
-(SVGCDEntityReference*) createEntityReference:(NSString*) data __attribute__((ns_returns_retained));

-(SVGCDNodeList*) getElementsByTagName:(NSString*) data;

// Introduced in DOM Level 2:
-(SVGCDNode*) importNode:(SVGCDNode*) importedNode deep:(BOOL) deep;

// Introduced in DOM Level 2:
-(SVGCDElement*) createElementNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName __attribute__((ns_returns_retained));

// Introduced in DOM Level 2:
-(SVGCDAttr*) createAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName;

// Introduced in DOM Level 2:
-(SVGCDNodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(SVGCDElement*) getElementById:(NSString*) elementId;

@end
