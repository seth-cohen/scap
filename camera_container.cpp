#include "camera_container.h"

CameraContainer::CameraContainer() {
}

CameraContainer::~CameraContainer() {
  Reset();
}

CameraContainer::port_iterator CameraContainer::begin() {
  return port_iterator(*this, 0);
}

CameraContainer::port_iterator CameraContainer::end() {
  return port_iterator(*this, cameraCount);
}

void CameraContainer::Reset() {
  if (list) {
    gp_list_free(list);
    list = NULL;
  }
  cameraCount = 0;
}

size_t CameraContainer::DetectAttachedCameras() {
  GPContext *context = gp_context_new();

  gp_list_new(&list);
  cameraCount = gp_camera_autodetect(list, context);

  return cameraCount;
}

CameraContainer::port_iterator::port_iterator(CameraContainer &cams, int offset)
  : container(cams), offset(offset) {
  if (offset < container.cameraCount) {
    const char* n;
    const char* p;
  
    gp_list_get_name(container.list, offset, &n);
    gp_list_get_value(container.list, offset, &p);
    portinfo.name.assign(n);
    portinfo.port.assign(p);
  }
}

CameraPort::CameraPort(const std::string &n, const std::string &p)
  : name(n), port(p) {}
