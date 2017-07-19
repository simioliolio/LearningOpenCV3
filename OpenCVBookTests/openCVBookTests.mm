//
//  openCVBookTests.m
//  openCVBookTests
//
//  Created by Simon Haycock on 19/07/2017.
//  Copyright © 2017 oxygn. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#import <XCTest/XCTest.h>


@interface openCVBookTests : XCTestCase

@end

@implementation openCVBookTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testChapter3Exercises {
    
    double a = -4.234;
    double absA = fabs(a);
    XCTAssertEqual(absA, 4.234);
    double roundA = round(absA);
    XCTAssertEqual(roundA, 4.0);
    double ceilingA = ceil(absA);
    XCTAssertEqual(ceilingA, 5.0);
    double floorA = floor(absA);
    XCTAssertEqual(floorA, 4.0);
    CvRNG rng = cvRNG(5438902);
    double randomNumber = cvRandReal(&rng);
    XCTAssertNotEqual(randomNumber, 0.0);
    cv::Point2f fPoint( 5.2, 54.2 );
    
    cv::Point2i iPoint = (cv::Point2i)fPoint;
    XCTAssertEqual(iPoint.x, 5);
    XCTAssertEqual(iPoint.y, 54);
    
    cv::Point_<int> iTPoint = (cv::Point_<int>)fPoint;
    XCTAssertEqual(iTPoint.x, 5);
    XCTAssertEqual(iTPoint.y, 54);
}

@end
