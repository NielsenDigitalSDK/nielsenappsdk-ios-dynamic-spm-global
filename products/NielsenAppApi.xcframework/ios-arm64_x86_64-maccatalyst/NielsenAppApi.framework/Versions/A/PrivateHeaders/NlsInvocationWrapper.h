/**
 * App SDK Application
 *
 * Copyright (C) 2018, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks: Opaque wrapper for NSInvocation to enable Swift interoperability
 *          (NSInvocation is marked NS_SWIFT_UNAVAILABLE)
 *
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Opaque wrapper class that encapsulates NSInvocation for Swift interoperability.
 * Since NSInvocation is NS_SWIFT_UNAVAILABLE, Swift code cannot directly hold
 * references to NSInvocation objects. This wrapper provides an interface that
 * Swift can use while keeping NSInvocation internal.
 */
@interface NlsInvocationWrapper : NSObject

/**
 * Creates a wrapper for a class method invocation.
 * @param classname The name of the class
 * @param selectorName The name of the selector
 * @return A wrapper configured for the class method, or nil if class/selector not found
 */
+ (nullable instancetype)wrapperForClass:(NSString *)classname
                                selector:(NSString *)selectorName;

/**
 * Creates a wrapper for an instance method invocation.
 * @param instance The object instance
 * @param selectorName The name of the selector
 * @return A wrapper configured for the instance method, or nil if selector not found
 */
+ (nullable instancetype)wrapperForInstance:(id)instance
                                   selector:(NSString *)selectorName;

/**
 * Sets an argument on the invocation at the specified index.
 * @param argument Pointer to the argument value
 * @param index The argument index (0-based, automatically offset by 2 for self/SEL)
 */
- (void)setArgument:(nullable void *)argument atIndex:(NSInteger)index;

/**
 * Invokes the wrapped invocation.
 */
- (void)invoke;

/**
 * Gets the return value from the invocation.
 * @param returnValue Pointer to store the return value
 */
- (void)getReturnValue:(nullable void *)returnValue;

/**
 * Invokes and gets the return value in one call.
 * @param returnValue Pointer to store the return value
 */
- (void)invokeAndGetReturnValue:(nullable void *)returnValue;

@end

NS_ASSUME_NONNULL_END
