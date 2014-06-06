//
//  FRDStravaClient+Activity.h
//  FRDStravaClient
//
//  Created by Sebastien Windal on 4/21/14.
//

#import "FRDStravaClient.h"
#import "StravaActivity.h"
#import "StravaActivityZone.h"
#import "StravaActivityPhoto.h"
#import "StravaActivityComment.h"


@interface FRDStravaClient (Activity)


/**
 Fetch last activities for the current/logged-in Strava user/athlete.

 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-activities
 
 @params success Success callback, activities is a NSArray of `StravaActivity` objects.
 @params failure Failure callback
 
 */

-(void) fetchActivitiesForCurrentAthleteWithSuccess:(void (^)(NSArray *activities))success
                                            failure:(void (^)(NSError *error))failure;

/**
 Fetch activities for the current/logged-in Strava user/athlete with paging.
 Note, the first page pageIndex is 1 and not 0.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-activities
 
 @params pageSize how many activities per page
 @params pageIndex index of the page to fetch (first page is page 1)
 @params success Success callback, activities is a NSArray of `StravaActivity` objects, sorted newest first.
 @params failure Failure callback
 
 */
-(void) fetchActivitiesForCurrentAthleteWithPageSize:(NSInteger)pageSize
                                           pageIndex:(NSInteger)pageIndex
                                             success:(void (^)(NSArray *activities))success
                                             failure:(void (^)(NSError *error))failure;

/**
 Fetch activities for the current/logged-in Strava user/athlete older than the specified date.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-activities
 
 @params date fetch activities older than this date
 @params success Success callback, activities is a NSArray of `StravaActivity` objects, sorted oldest first.
 @params failure Failure callback
 
 */
-(void) fetchActivitiesForCurrentAthleteAfterDate:(NSDate *)date
                                          success:(void (^)(NSArray *activities))success
                                          failure:(void (^)(NSError *error))failure;

/**
 Fetch activities for the current/logged-in Strava user/athlete that are more recent than the specified date. Both
 success and failure callbacks are run on the main queue.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-activities
 
 @params date fetch activities more recent than this date
 @params success Success callback, activities is a NSArray of `StravaActivity` objects, sorted newest first.
 @params failure Failure callback
 
 */
-(void) fetchActivitiesForCurrentAthleteBeforeDate:(NSDate *)date
                                           success:(void (^)(NSArray *activities))success
                                           failure:(void (^)(NSError *error))failure;



/**
 Fetch friend activities, public activities performed by Strava athletes the curent user is following.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-feed
 
 @params success Success callback, activities is a NSArray of `StravaActivity` objects, sorted newest first.
 @params failure Failure callback
 
 */
-(void) fetchFriendActivitiesWithSuccess:(void (^)(NSArray *activities))success
                                 failure:(void (^)(NSError *error))failure;

/**
 Fetch friend activities with paging, public activities performed by Strava athletes the curent user is following.
 Note, the first page pageIndex is 1 and not 0.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-activities
 
 @params pageSize how many activities per page
 @params pageIndex index of the page to fetch (first page is page 1)
 @params success Success callback, activities is a NSArray of `StravaActivity` objects, sorted newest first.
 @params failure Failure callback
 
 */
-(void) fetchFriendActivitiesWithPageSize:(NSInteger)pageSize
                                pageIndex:(NSInteger)pageIndex
                                  success:(void (^)(NSArray *activities))success
                                  failure:(void (^)(NSError *error))failure;


/**
 Fetch an activity by activity Id. The StravaActivity object will contain detailed information if the activity is owned by current user,
 summary information otherwise.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#get-details
 
 @params activityId the activity ID to fetch
 @params includeAllEfforts Whether the `StravaActivity` object should include all segment efforts (in segmentEfforts property) or only important ones.
 @params success Success callback
 @params failure Failure callback
 
 */
-(void) fetchActivityWithId:(NSInteger)activityId
          includeAllEfforts:(BOOL)includeAllEfforts
                    success:(void (^)(StravaActivity *activity))success
                    failure:(void (^)(NSError *error))failure;

// photos



/**
 Retrieve a list of photos associated with an activity. Only works if activity is owned by current user.
 
 Strava API related documentation: http://strava.github.io/api/v3/photos/#list
 
 @params activityId the activity ID
 @params success Success callback, photos is an array of `StravaActivityPhoto` objects.
 @params failure Failure callback
 
 */
-(void) fetchPhotosForActivity:(NSInteger)activityId
                       success:(void (^)(NSArray *photos))success
                       failure:(void (^)(NSError *error))failure;

/**
 Time spent in each zone (power or heart rate) during the specified activity. Only works if activity is owned by current user and if
 current user is a premium user.
 
 Strava API related documentation: http://strava.github.io/api/v3/activities/#zones
 
 @params activityId the activity ID
 @params success Success callback, zones is an array of StravaActivityZone objects.
 @params failure Failure callback
 
 */
-(void) fetchZonesForActivity:(NSInteger)activityId
                      success:(void (^)(NSArray *zones))success
                      failure:(void (^)(NSError *error))failure;

/**
 Fetch comments for the specified activity.
 
 Strava API related documentation: http://strava.github.io/api/v3/comments/#list
 
 @params activityId the activity ID
 @params markdown wether the comment text should be markdown formatted or not
 @params pageSize number of comments per page
 @params pageIndex index of the page to fetch (first page is page 1)
 @params success Success callback, comments is an array of `StravaActivityComment` objects.
 @params failure Failure callback
 
 */
-(void) fetchCommentsForActivity:(NSInteger)activityId
                        markdown:(BOOL)markdown
                        pageSize:(NSInteger)pageSize
                       pageIndex:(NSInteger)pageIndex
                         success:(void (^)(NSArray *comments))success
                         failure:(void (^)(NSError *error))failure;

/**
 Fetch kudoers (athletes that gave a kudo) for the specified activity.
 
 Strava API related documentation: http://strava.github.io/api/v3/kudos/#list
 
 @params activityId the activity ID
 @params pageSize number of athletes/kudoers per page
 @params pageIndex index of the page to fetch (first page is page 1)
 @params success Success callback, athletes is an array of `StravaAthlete` objects.
 @params failure Failure callback
 
 */
-(void) fetchKudoersForActivity:(NSInteger)activityId
                       pageSize:(NSInteger)pageSize
                      pageIndex:(NSInteger)pageIndex
                        success:(void (^)(NSArray *athletes))success
                        failure:(void (^)(NSError *error))failure;


@end
