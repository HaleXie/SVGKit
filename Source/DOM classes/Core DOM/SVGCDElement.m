#import "SVGCDElement.h"

#import "SVGCDNamedNodeMap.h"
#import "SVGCDDOMHelperUtilities.h"

@interface SVGCDElement()
@property(nonatomic,strong,readwrite) NSString* tagName;
@end

@implementation SVGCDElement

@synthesize tagName;


- (id)initWithLocalName:(NSString*) n attributes:(NSMutableDictionary*) attributes {
    self = [super initType:SVGCD_DOMNodeType_ELEMENT_NODE name:n];
    if (self) {
        self.tagName = n;
		
		for( NSString* attributeName in attributes.allKeys )
		{
			[self setAttribute:attributeName value:[attributes objectForKey:attributeName]];
		}
    }
    return self;
}
- (id)initWithQualifiedName:(NSString*) n inNameSpaceURI:(NSString*) nsURI attributes:(NSMutableDictionary *)attributes
{
    self = [super initType:SVGCD_DOMNodeType_ELEMENT_NODE name:n inNamespace:nsURI];
    if (self) {
        self.tagName = n;
		
		for( SVGCDAttr* attribute in attributes.allValues )
		{
			[self.attributes setNamedItemNS:attribute inNodeNamespace:nsURI];
		}
    }
    return self;
}

-(NSString*) getAttribute:(NSString*) name
{
	/**
	 WARNING: the definition in the spec WILL CORRUPT unsuspecting Objective-C code (including a lot of the original SVGKit code!).
	 
	 The spec - instead of defining 'nil' - defines "" (empty string) as the
	 correct response.
	 
	 But in most of the modern, C-based, (non-scripting) languages, "" means 0.
	 
	 Very dangerous!
	 */
	SVGCDAttr* result = (SVGCDAttr*) [self.attributes getNamedItem:name];
	
	if( result == nil || result.value == nil )
		return @""; // according to spec
	else
		return result.value;
}

-(void) setAttribute:(NSString*) name value:(NSString*) value
{
	SVGCDAttr* att = [[SVGCDAttr alloc] initWithName:name value:value];
	
	[self.attributes setNamedItem:att];
}

-(void) removeAttribute:(NSString*) name
{
	[self.attributes removeNamedItem:name];
	
	NSAssert( FALSE, @"Not fully implemented. Spec says: If the removed attribute is known to have a default value, an attribute immediately appears containing the default value as well as the corresponding namespace URI, local name, and prefix when applicable." );
}

-(SVGCDAttr*) getAttributeNode:(NSString*) name
{
	return (SVGCDAttr*) [self.attributes getNamedItem:name];
}

-(SVGCDAttr*) setAttributeNode:(SVGCDAttr*) newAttr
{
	SVGCDAttr* oldAtt = (SVGCDAttr*) [self.attributes getNamedItem:newAttr.nodeName];
	
	[self.attributes setNamedItem:newAttr];
	
	return oldAtt;
}

-(SVGCDAttr*) removeAttributeNode:(SVGCDAttr*) oldAttr
{
	[self.attributes removeNamedItem:oldAttr.nodeName];
	
	NSAssert( FALSE, @"Not fully implemented. Spec: If the removed Attr  has a default value it is immediately replaced. The replacing attribute has the same namespace URI and local name, as well as the original prefix, when applicable. " );
	
	return oldAttr;
}

-(SVGCDNodeList*) getElementsByTagName:(NSString*) name
{
	SVGCDNodeList* accumulator = [[SVGCDNodeList alloc] init];
	[SVGCDDOMHelperUtilities privateGetElementsByName:name inNamespace:nil childrenOfElement:self addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(NSString*) getAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	SVGCDAttr* result = (SVGCDAttr*) [self.attributes getNamedItemNS:namespaceURI localName:localName];
	
	if( result == nil || result.value == nil )
		return @""; // according to spec
	else
		return result.value;
}

// Introduced in DOM Level 2:
-(void) setAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName value:(NSString*) value
{
	SVGCDAttr* att = [[SVGCDAttr alloc] initWithNamespace:namespaceURI qualifiedName:qualifiedName value:value];
	
	[self.attributes setNamedItemNS:att];
}

// Introduced in DOM Level 2:
-(void) removeAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	NSAssert( FALSE, @"Not implemented yet" );
}

// Introduced in DOM Level 2:
-(SVGCDAttr*) getAttributeNodeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	SVGCDAttr* result = (SVGCDAttr*) [self.attributes getNamedItemNS:namespaceURI localName:localName];
	
	return result;
}

// Introduced in DOM Level 2:
-(SVGCDAttr*) setAttributeNodeNS:(SVGCDAttr*) newAttr
{
	NSAssert( FALSE, @"Not implemented yet" );
	return nil;
}

// Introduced in DOM Level 2:
-(SVGCDNodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	SVGCDNodeList* accumulator = [[SVGCDNodeList alloc] init];
	[SVGCDDOMHelperUtilities privateGetElementsByName:localName inNamespace:namespaceURI childrenOfElement:self addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(BOOL) hasAttribute:(NSString*) name
{
	SVGCDAttr* result = (SVGCDAttr*) [self.attributes getNamedItem:name];
	
	return result != nil;
}

// Introduced in DOM Level 2:
-(BOOL) hasAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	NSAssert( FALSE, @"Not implemented yet" );
	return FALSE;
}

@end
