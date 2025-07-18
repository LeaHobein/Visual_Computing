#ifndef BLOB_DETECTION_HPP
#define BLOB_DETECTION_HPP

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

void detectAndDrawBlobs(cv::Mat& frameMat, cv::Mat& grayImage) {
    cvtColor(frameMat, grayImage, cv::COLOR_BGR2HSV);
    std::vector<int> lower = {35, 25, 0};
    std::vector<int> upper = {95, 255, 255};
    inRange(grayImage, lower, upper, grayImage);
    medianBlur(grayImage, grayImage, 5);

    // Blob detection auf schwarz-weiß Bild
    cv::Ptr<cv::SimpleBlobDetector> blobDetector = cv::SimpleBlobDetector::create();
    blobDetector->read("..\\blobdetectorparams1.xml");
    std::vector<cv::KeyPoint> keypoints;
    blobDetector->detect(grayImage, keypoints);

    // Kreise malen
    for(const cv::KeyPoint& k: keypoints) {
        cv::circle(frameMat, k.pt, 30, cv::Scalar(0,0,0), 2);
    }

    cv::Mat hsvImage;
    cvtColor(frameMat, hsvImage, cv::COLOR_BGR2HSV);
    std::vector<int> squareLower = {35, 50, 50};
    std::vector<int> squareUpper = {85, 255, 255};
    
    cv::Mat greenMask;
    inRange(hsvImage, squareLower, squareUpper, greenMask);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::morphologyEx(greenMask, greenMask, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(greenMask, greenMask, cv::MORPH_OPEN, kernel);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(greenMask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        double epsilon = 0.02 * cv::arcLength(contour, true);
        std::vector<cv::Point> approx;
        cv::approxPolyDP(contour, approx, epsilon, true);

        if (approx.size() == 4) {
            double area = cv::contourArea(approx);
            if (area > 1000) {

                for (const auto& corner : approx) {
                    cv::circle(frameMat, corner, 10, cv::Scalar(255, 255, 255), 2); // White outline
                }

                cv::polylines(frameMat, std::vector<std::vector<cv::Point>>{approx}, true, cv::Scalar(0, 255, 0), 2);
            }
        }
    }

    cv::cvtColor(grayImage, grayImage, cv::COLOR_GRAY2BGR);
}

#endif // BLOB_DETECTION_HPP 