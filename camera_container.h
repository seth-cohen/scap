#include <cstddef>
#include <string>

#include <gphoto2/gphoto2-camera.h>

class CameraPort {
public:
  CameraPort() {};
  CameraPort(const std::string &n, const std::string &p);

  std::string name;
  std::string port;
};
  
class CameraContainer {
public:
  class port_iterator {
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Camera;
    using difference_type = long;
    using pointer = Camera*;
    using reference = Camera&;

    port_iterator(CameraContainer &cams, int offset);
    ~port_iterator(){};

    port_iterator& operator++() {offset++; return *this;}
    port_iterator operator++(int) {
      port_iterator clone(*this);
      offset++;
      return clone;
    }

    bool operator==(const port_iterator &other) {
      return &container == &other.container
	&& offset == other.offset; 
    }
    bool operator!=(const port_iterator &other) {
      return !(*this == other);
    }

    CameraPort* operator->() {
      return &portinfo;
    }

    std::string name;
    std::string port;
  private:
    CameraContainer &container;
    int offset;

    CameraPort portinfo;
  };
    
  CameraContainer();
  ~CameraContainer();
  
  size_t DetectAttachedCameras();
  void Reset();

  port_iterator begin();
  port_iterator end();

protected:
  
  CameraList *list;
  size_t cameraCount = 0;
};

