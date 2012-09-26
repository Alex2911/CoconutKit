//
//  HLSAnimationStep+Protected.h
//  CoconutKit
//
//  Created by Samuel Défago on 8/21/12.
//  Copyright (c) 2012 Hortis. All rights reserved.
//

#import "HLSObjectAnimation.h"

/**
 * Protected interface for use by subclasses of HLSAnimationStep in their implementation, and to be included
 * from their implementation file
 */
@interface HLSAnimationStep (Protected)

/**
 * Setting an animation for an object
 */
- (void)addObjectAnimation:(HLSObjectAnimation *)objectAnimation forObject:(id)object;

/**
 * Retrieving the animation for an object (nil if not match is found)
 */
- (HLSObjectAnimation *)objectAnimationForObject:(id)object;

/**
 * All objects changed by the animation step, returned in the order they were added to it
 */
- (NSArray *)objects;

/**
 * Return YES iff the step is running
 */
@property (nonatomic, assign, getter=isRunning) BOOL running;

/**
 * Return YES iff the step is being terminated
 */
@property (nonatomic, assign, getter=isCancelling) BOOL terminating;

/**
 * This method must be implemented by subclasses to create and play the animation step (animated or not).
 * If animated = YES, the animation is expected to take place asynchronously, otherwise synchronously
 *
 * The super method implementation must not be called (it raises an exception)
 */
- (void)playAnimationAnimated:(BOOL)animated;

/**
 * This method must be implemented by subclasses to pause a running animation step
 *
 * The super method implementation must not be called (it raises an exception)
 */
- (void)pauseAnimation;

/**
 * This method must be implemented by subclasses to resume a paused animation step
 *
 * The super method implementation must not be called (it raises an exception)
 */
- (void)resumeAnimation;

/**
 * This method must be implemented by subclasses to return YES iff an animation step is paused
 *
 * The super method implementation must not be called (it raises an exception)
 */
- (BOOL)isAnimationPaused;

/**
 * This method must be implemented by subclasses to terminate the animation
 *
 * The super method implementation must not be called (it raises an exception)
 */
- (void)terminateAnimation;

/**
 * The corresponding animation step to be played during the reverse animation
 *
 * The super method implementation must be called first
 */
- (id)reverseAnimationStep;

/**
 * Return a string describing the involved object animations
 */
- (NSString *)objectAnimationsDescriptionString;

/**
 * Subclasses must register themselves for the asynchronous delegate events of the animation they implement,
 * and must call these methods from within their start / stop methods. The finished parameter must be set to
 * YES iff the animation could run to completion without being cancelled
 */
- (void)notifyAsynchronousAnimationStepWillStart;
- (void)notifyAsynchronousAnimationStepDidStopFinished:(BOOL)finished;

@end
