#include "Camera.h"

Camera::Camera()
{
	offSetX = 0;
	offsetY = 0;
}

float& Camera::getOffSetX()
{
	return offSetX;
}

float& Camera::getOffSetY()
{
	return offsetY;
}
