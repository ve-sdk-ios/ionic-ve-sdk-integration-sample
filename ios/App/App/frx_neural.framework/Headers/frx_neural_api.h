//
//  frx_neural_api.h
//  SimpleCameraSandbox
//
//  Created by Pavel Bulochkin on 1/29/20.
//  Copyright © 2020 Nickolai Nikishin. All rights reserved.
//

#ifndef frx_neural_api_h
#define frx_neural_api_h

#if defined (__GNUC__) || defined (__clang__)
#define EXPORT __attribute__((visibility("default")))
#else
#define EXPORT
#endif

#import <opencv2/core.hpp>
#import <opencv2/imgproc/imgproc.hpp>
#import <opencv2/highgui/highgui.hpp>
#import <opencv2/imgcodecs/ios.h>

//----------------------------------------------------------------------------------------------------------------------

class frx_position_camera
{
public:
    float frustum_l;
    float frustum_r;
    float frustum_t;
    float frustum_b;
    
    // STUB for perspective projection
    float frustum_n = -1000;
    float frustum_f = 1000;
    
    float model_r_x;
    float model_r_y;
    float model_r_z;
    float model_t_x;
    float model_t_y;
    
    float model_t_z = 0.0f;
    
    float model_view_m[16];
    float projection_m[16];
};

//----------------------------------------------------------------------------------------------------------------------

class frx_result
{
public:
    cv::Mat image_mesh;
    frx_position_camera camera_position;
    std::vector<float> landmarks;
    std::vector<float> face_characteristics;
    std::vector<float> face_vertices;
    std::vector<cv::Rect> rects_data;
};

//----------------------------------------------------------------------------------------------------------------------

enum frx_neural_type
{
    FRX_COREML_LANDMARKS_128  = 0,
    FRX_COREML_LANDMARKS_224  = 1
};

//----------------------------------------------------------------------------------------------------------------------

EXPORT
frx_result frx_process_frame(const cv::Mat& frame, frx_neural_type type);

//----------------------------------------------------------------------------------------------------------------------

EXPORT
void frx_reset_tracking();

//----------------------------------------------------------------------------------------------------------------------

#endif /* frx_neural_api_h */
