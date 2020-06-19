#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<cmath>
#include<iostream>

Eigen::Vector3f scale2d(Eigen::Vector3f& point2d, const float Sx, const float Sy) {
    Eigen::Matrix3f s;
    s << Sx, 0.0, 0.0, \
        0.0, Sy, 0.0, \
        0.0, 0.0, 1.0;
    point2d = s * point2d;
    return point2d;
}

Eigen::Vector3f rotation2d(Eigen::Vector3f& point2d, const float angle) {
    float radian = angle * M_PI / 180.0;
    float sinr = sin(radian);
    float cosr = cos(radian);
    Eigen::Matrix3f r;
    r << cosr, -sinr, 0.0, \
        sinr, cosr, 0.0, \
        0.0, 0.0, 1.0;
    point2d = r * point2d;
    return point2d;
}

Eigen::Vector3f translation2d(Eigen::Vector3f& point2d, const float Tx, const float Ty) {
    Eigen::Matrix3f t;
    t << 1.0, 0.0, Tx, \
        0.0, 1.0, Ty, \
        0.0, 0.0, 1.0;
    point2d = t * point2d;
    return point2d;
}

int main(){
    float x = 2.0, y = 1.0;
    Eigen::Vector3f point2d(x, y, 1.0);
    rotation2d(point2d, 45.0);
    translation2d(point2d, 1.0, 2.0);
    std::cout << "x:" << point2d.x() << "y:" << point2d.y() << std::endl;
    return 0;
}
