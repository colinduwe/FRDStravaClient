//
//  StravaCommon.m
//  FRDStravaClient
//
//  Created by Sebastien Windal on 5/8/14.
//  Copyright (c) 2014 Sebastien Windal. All rights reserved.
//

#import "StravaCommon.h"
#import <MapKit/MapKit.h>


@implementation StravaCommon

+ (NSValueTransformer *)activityTypeJSONTransformer
{
    return [NSValueTransformer mtl_valueMappingTransformerWithDictionary:@{
                                                                           @"Ride": @(kActivityTypeRide),
                                                                           @"Run": @(kActivityTypeRun),
                                                                           @"Hike": @(kActivityTypeHike),
                                                                           @"Walk": @(kActivityTypeWalk),
                                                                           @"swim": @(kActivityTypeSwim),
                                                                           @"workout": @(kActivityTypeWorkout),
                                                                           @"nordicski": @(kActivityTypeNordicSki),
                                                                           @"alpineski": @(kActivityTypeAlpineSki),
                                                                           @"backcountryski": @(kActivityTypeBackcountrySki),
                                                                           @"iceskate": @(kActivityTypeIceSkate),
                                                                           @"inlineskate": @(kActivityTypeInlineSkate),
                                                                           @"kitesurf": @(kActivityTypeKitesurf),
                                                                           @"rollerski": @(kActivityTypeRollerSki),
                                                                           @"windsurf": @(kActivityTypeWindsurf),
                                                                           @"snowboard": @(kActivityTypeSnowboard),
                                                                           @"snowshoe": @(kActivityTypeSnowshoe)
                                                                           }
                                                            defaultValue:@(kActivityTypeUnknown)
                                                     reverseDefaultValue:@"unknown"];
}


+ (NSValueTransformer *)locationJSONTransformer
{
    return [MTLValueTransformer transformerUsingForwardBlock:^(NSArray *coordinates, BOOL *success, NSError **error) {
        CLLocationDegrees latitude = [coordinates[0] doubleValue];
        CLLocationDegrees longitude = [coordinates[1] doubleValue];
        return [NSValue valueWithMKCoordinate:CLLocationCoordinate2DMake(latitude, longitude)];
    } reverseBlock:^(NSValue *coordinateValue, BOOL *success, NSError **error) {
        CLLocationCoordinate2D coordinate = [coordinateValue MKCoordinateValue];
        return @[@(coordinate.latitude), @(coordinate.longitude)];
    }];
}


+ (NSDateFormatter *)dateFormatter {
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
    dateFormatter.dateFormat = @"yyyy-MM-dd'T'HH:mm:ss'Z'";
    return dateFormatter;
}

/* + (NSValueTransformer *)dateJSONTransformer
{
    static NSDateFormatter *dateFormatter = nil;
    
    if (dateFormatter == nil) {
        dateFormatter = [[NSDateFormatter alloc] init];
        //dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
        [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
        [dateFormatter setCalendar:[[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian]];
        dateFormatter.dateFormat = @"yyyy-MM-dd'T'HH:mm:ss'Z'";
    }
    
    return [MTLValueTransformer transformerUsingForwardBlock:^(NSString *str, BOOL *success, NSError **error) {
        return [dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date, BOOL *success, NSError **error) {
        return [dateFormatter stringFromDate:date];
    }];
}
 */

+ (NSValueTransformer *)dateJSONTransformer {
    return [MTLValueTransformer transformerUsingForwardBlock:^id(NSString *dateString, BOOL *success, NSError *__autoreleasing *error) {
        NSLog(@"%@", [self.dateFormatter dateFromString:dateString]);
        return [self.dateFormatter dateFromString:dateString];
    } reverseBlock:^id(NSDate *date, BOOL *success, NSError *__autoreleasing *error) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

@end
