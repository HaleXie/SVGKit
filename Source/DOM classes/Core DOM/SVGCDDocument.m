#import "SVGCDDocument.h"
#import "SVGCDDocument+Mutable.h"

#import "SVGCDDOMHelperUtilities.h"

#import "SVGCDNodeList+Mutable.h" // needed for access to underlying array, because SVG doesnt specify how lists are made mutable

#import "SVGKDefine_Private.h"

@implementation SVGCDDocument

@synthesize doctype;
@synthesize implementation;
@synthesize documentElement;



-(SVGCDElement*) createElement:(NSString*) tagName
{
	SVGCDElement* newElement = [[SVGCDElement alloc] initWithLocalName:tagName attributes:nil];
	
	SVGKitLogVerbose( @"[%@] WARNING: SVG Spec, missing feature: if there are known attributes with default values, Attr nodes representing them SHOULD BE automatically created and attached to the element.", [self class] );
	
	return newElement;
}

-(SVGCDDocumentFragment*) createDocumentFragment
{
	return [[SVGCDDocumentFragment alloc] init];
}

-(SVGCDText*) createTextNode:(NSString*) data
{
	return [[SVGCDText alloc] initWithValue:data];
}

-(SVGCDComment*) createComment:(NSString*) data
{
	return [[SVGCDComment alloc] initWithValue:data];
}

-(SVGCDCDATASection*) createCDATASection:(NSString*) data
{
	return [[SVGCDCDATASection alloc] initWithValue:data];
}

-(SVGCDProcessingInstruction*) createProcessingInstruction:(NSString*) target data:(NSString*) data
{
	return [[SVGCDProcessingInstruction alloc] initProcessingInstruction:target value:data];
}

-(SVGCDAttr*) createAttribute:(NSString*) n
{
	return [[SVGCDAttr alloc] initWithName:n value:@""];
}

-(SVGCDEntityReference*) createEntityReference:(NSString*) data
{
	NSAssert( FALSE, @"Not implemented. According to spec: Creates an EntityReference object. In addition, if the referenced entity is known, the child list of the EntityReference  node is made the same as that of the corresponding Entity  node. Note: If any descendant of the Entity node has an unbound namespace prefix, the corresponding descendant of the created EntityReference node is also unbound; (its namespaceURI is null). The DOM Level 2 does not support any mechanism to resolve namespace prefixes." );
	return nil;
}

-(SVGCDNodeList*) getElementsByTagName:(NSString*) data
{
	SVGCDNodeList* accumulator = [[SVGCDNodeList alloc] init];
	[SVGCDDOMHelperUtilities privateGetElementsByName:data inNamespace:nil childrenOfElement:self.documentElement addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(SVGCDNode*) importNode:(SVGCDNode*) importedNode deep:(BOOL) deep
{
	NSAssert( FALSE, @"Not implemented." );
	return nil;
}

// Introduced in DOM Level 2:
-(SVGCDElement*) createElementNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName
{
	SVGCDElement* newElement = [[SVGCDElement alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:namespaceURI attributes:nil];
	
	SVGKitLogVerbose( @"[%@] WARNING: SVG Spec, missing feature: if there are known attributes with default values, Attr nodes representing them SHOULD BE automatically created and attached to the element.", [self class] );
	
	return newElement;
}

// Introduced in DOM Level 2:
-(SVGCDAttr*) createAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName
{
	NSAssert( FALSE, @"This should be re-implemented to share code with createElementNS: method above" );
	SVGCDAttr* newAttr = [[SVGCDAttr alloc] initWithNamespace:namespaceURI qualifiedName:qualifiedName value:@""];
	return newAttr;
}

// Introduced in DOM Level 2:
-(SVGCDNodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	SVGCDNodeList* accumulator = [[SVGCDNodeList alloc] init];
	[SVGCDDOMHelperUtilities privateGetElementsByName:localName inNamespace:namespaceURI childrenOfElement:self.documentElement addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(SVGCDElement*) getElementById:(NSString*) elementId
{
	return [SVGCDDOMHelperUtilities privateGetElementById:elementId childrenOfElement:self.documentElement];
}

@end
