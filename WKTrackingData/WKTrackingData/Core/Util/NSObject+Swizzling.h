//
//  NSObject+Swizzling.h
//  WKTrackingData
//
//  Created by wkj on 2020/1/7.
//  Copyright © 2020 wkj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Swizzling)

/// 交换某个类实例的方法
/// @param origSel_ 原实例方法
/// @param replaceSel_ 替换的实例方法
+ (BOOL)wk_swizzleMethod:(SEL)origSel_ withMethod:(SEL)replaceSel_ ;

/// 交换某个类的类方法
/// @param origSel_  原类方法
/// @param replaceSel_ 替换的类方法
+ (BOOL)wk_swizzleClassMethod:(SEL)origSel_ withClassMethod:(SEL)replaceSel_ ;

/// 交换某两个代理类的代理方法，如果原代理类 delegateClass 未实现 origSel_ 。
/// 则会给原代理类 delegateClass 添加 新代理类 replacedClass 的 notImpSel_ 实现。
/// 这样仍然能够监听到未实现的代理方法。
/// @param delegateClass 原代理类
/// @param origSel_ 想要监听的原代理类的代理方法
/// @param replacedClass 新的代理类
/// @param replaceSel_ 新的代理类的代理方法
/// @param notImpSel_ 新的代理类中供原代理类中未实现的代理sel提供的imp实现
+ (void)wk_swizzlingDelegate:(Class) delegateClass originSel:(SEL) origSel_ replacedClass:(Class) replacedClass replaceSel:(SEL) replaceSel_ delegateNotImp:(SEL) notImpSel_;

@end

NS_ASSUME_NONNULL_END
