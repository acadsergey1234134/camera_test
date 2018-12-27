#include "videodev_qt.h"
#include <QCameraInfo>
#include <QDebug>

namespace linuxvideodevqt  {

void GetDeviceNames(bool bVerbose)
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    foreach (const QCameraInfo &cameraInfo, cameras) {
        if(bVerbose) {
            qDebug() << cameraInfo.deviceName()
                     << cameraInfo.description();
        }
    }

    if(bVerbose) {
        qDebug() << "Default camera"
                << QCameraInfo::defaultCamera().deviceName()
                 << QCameraInfo::defaultCamera().description();
    }
}

} //namespace linuxvideodevqt
